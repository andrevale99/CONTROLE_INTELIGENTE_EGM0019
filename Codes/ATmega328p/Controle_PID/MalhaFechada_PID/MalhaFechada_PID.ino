#define F_CPU 16000000UL

#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define MYUBRR F_CPU / 16 / BAUD - 1

#define BUFFER_MAX_LEN 128

#define QUANTIDADE_DE_DADOS 10
#define PERIODO_DE_AMOSTRAGEM (1000 / QUANTIDADE_DE_DADOS)

#define BOTAO PD4

#define ENCODER_A PD2

// Pode trocar para outro pino digital,
// caso queira desocupar o Pino INT1
#define ENCODER_B PD3

// O sentido de rotacao depende da posicao
// dos fios da ponte H, ou da referencial
#define ROTOR_SENTIDO_HORARIO(pwm) \
  OCR0A = (uint8_t)pwm; \
  OCR0B = 0;

// O sentido de rotacao depende da posicao
// dos fios da ponte H, ou da referencial
#define ROTOR_SENTIDO_ANTIHORARIO(pwm) \
  OCR0A = 0; \
  OCR0B = (uint8_t)pwm;

#define ATIVA_INT0_ISR EIMSK |= (1 << INT0)
#define DESATIVA_INT0_ISR EIMSK &= ~(1 << INT0)

#define PULSOS_POR_VOLTA 341.2f

#define RPM_MAX_LIMIT 160

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

volatile struct
{
  int16_t RPM;    // rotacoes por minuto
  int16_t omega;  // velocidade angula (rad/s)
  int32_t theta;  // posicao global (graus)

  // Pega a quantidade de pulsos do encoder
  // para calcular a posicao, caso necessario
  int32_t PulsosCanal;
} rotor;

struct
{
  float kp;
  float ki;
  float kd;

  float acaoP;
  float acaoI;
  float acaoD;

  float sinal;

  float erroAnterior;
} controle;

volatile int32_t Pulsos = 0;
volatile uint8_t flagsISR = 0;
uint16_t adcValue = 0;
int16_t SetPoint = 0;
float erro = 0.0;

float tempo = 0;

char buffer[BUFFER_MAX_LEN];

//=====================================================
//  FUNCS
//=====================================================

/// @brief Configuracao do pwm para o motor
void pwm_setup(void);

/// @brief Configuracao da interrupcao para
/// ler os sensores encoder
void external_intr_setup(void);

/// @brief Configuracao do TIMER1 para
/// fazer o periodo de amostragem
///
/// @param quantidade_de_dados quantos dados quer ler por segundo
void timer_setup(uint16_t quantidade_de_dados);

/// @brief Configuracao dos pinos digitais
void gpio_setup(void);

/// @brief Configuracao do ADC
void adc_setup(void);

/// @brief Funcao para ler o ADC
/// @param pino Pino que ADC que deseja ler
/// @return Valor ADC de 10 bits [0;1023]
uint16_t adc_read(uint8_t pino);

/// @brief Configuracao do periferico UART
/// @param ubrr Baud Rate da comunicacao
void USART_Init(unsigned int ubrr);

/// @brief Funcao para mandar um dado pela Serial
/// @param data o caractere que deseja mandar
void USART_Transmit(unsigned char data);

/// @brief Faz o map para [-255;255] usando o valor do ADC
/// @param valorADC Valor ADC
/// @return O valor entre [-255;255]
float map_setpoint(float valor, float min, float max, float newmin, float newmax);

ISR(TIMER1_COMPA_vect);

ISR(INT0_vect);

//=====================================================
//  MAIN
//=====================================================

int main(void) {
  pwm_setup();
  external_intr_setup();
  gpio_setup();
  adc_setup();
  // USART_Init(MYUBRR);
  timer_setup(QUANTIDADE_DE_DADOS);

  Serial.begin(9600);

  // Sem velocidade
  ROTOR_SENTIDO_HORARIO(0);

  controle.kp = 0.3;
  controle.ki = 1.0;
  controle.kd = 0.0;

  sei();

  while (1) {

    if ((PIND & (1 << PIND4)) == 0) {
      adcValue = adc_read(0x00);
      SetPoint = map_setpoint(adcValue, 0, 1023, -RPM_MAX_LIMIT, RPM_MAX_LIMIT);
    }

    if (flagsISR & 0x01) {
      DESATIVA_INT0_ISR;  // Desativa a interrupcao

      rotor.theta = ((float)rotor.PulsosCanal / PULSOS_POR_VOLTA) * 360;
      rotor.RPM = ((float)Pulsos / PULSOS_POR_VOLTA) * (60000 / PERIODO_DE_AMOSTRAGEM);

      // if (rotor.RPM < 0)
      //   rotor.RPM = -1 * rotor.RPM;

      erro = (float)SetPoint - ((float)rotor.RPM);

      controle.acaoP = controle.kp * erro;
      controle.acaoI += controle.ki * erro * ((float)PERIODO_DE_AMOSTRAGEM / 1000.) * 1.5;
      controle.acaoD = controle.kd * (erro - controle.erroAnterior) / ((float)PERIODO_DE_AMOSTRAGEM / 1000.);


      // anti-windup (para nao ficar
      // incrementando a integração infinitamente)
      if (controle.sinal >= 255) {
        controle.acaoI = 252;
        controle.sinal = 254;
      }
      // if (controle.acaoI <= -252) {
      //   controle.acaoI = -252;
      //   controle.sinal = -254;
      // }

      controle.erroAnterior = erro;

      controle.sinal = controle.acaoP + controle.acaoI + controle.acaoD;

      // Serial.print(170);
      // Serial.print("\t");
      // Serial.print(-170);
      // Serial.print("\t");
      Serial.print(tempo++ * PERIODO_DE_AMOSTRAGEM / 1000.);
      Serial.print("\t");
      Serial.print(rotor.RPM);
      Serial.print("\t");
      Serial.print(SetPoint);
      Serial.print("\t");
      Serial.print(erro);
      Serial.print("\t");
      Serial.print(controle.acaoP);
      Serial.print("\t");
      Serial.print(controle.acaoI);
      Serial.print("\t");
      Serial.print(controle.acaoD);
      Serial.print("\t");
      Serial.print(controle.sinal);
      Serial.print("\n");

      Pulsos = 0;

      flagsISR ^= (1 << 0);

      ATIVA_INT0_ISR;  // Reativa a interrupcao
    }

    if (controle.sinal <= 0) {
      ROTOR_SENTIDO_HORARIO(-controle.sinal);
    } else {
      ROTOR_SENTIDO_ANTIHORARIO(controle.sinal);
    }
  }
}

//=====================================================
//  FUNCS
//=====================================================

void pwm_setup() {
  // Configurar PD6 (OC0A) e
  // PD5 (OC0B) como saída
  DDRD |= (1 << PD5) | (1 << PD6);

  // Modo Fast PWM com TOP=0xFF
  // COM0A1:0 = 10 → Clear OC0A on Compare Match (não-invertido)
  // COM0B1:0 = 10 → Clear OC0B on Compare Match (não-invertido)
  // WGM01:0 = 11 → Fast PWM
  TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);

  // TCCR0B: CS01=1, CS00=1 (prescaler = 64)
  TCCR0B = (1 << CS01) | (1 << CS00);

  // Comparaca para ver os periodos
  OCR0A = 0;
  OCR0B = 0;
}

void external_intr_setup(void) {
  // Interrupcao Externa no Pino INT0 (PD2)
  // na borda de descida
  EICRA |= (1 << ISC01);

  ATIVA_INT0_ISR;
}

void timer_setup(uint16_t quantidade_de_dados) {
  TCCR1B |= (1 << WGM12) | (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = (uint16_t)62500 / quantidade_de_dados;
}

void gpio_setup(void) {
  DDRD &= ~(1 << BOTAO);
  PORTD |= (1 << BOTAO);
}

void adc_setup(void) {
  ADMUX |= (1 << REFS0);
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t pino) {
  static uint8_t adc_LSB;
  static uint8_t adc_MSB;

  ADMUX |= pino;
  ADCSRA |= (1 << ADSC);

  while (!(ADCSRA &= ~(1 << ADIF)))
    ;

  ADCSRA |= (1 << ADIF);

  adc_LSB = ADCL;
  adc_MSB = ADCH;

  return (adc_MSB << 8) | adc_LSB;
}

void USART_Init(unsigned int ubrr) {
  /*Set baud rate */
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;

  /*Enable transmitter
  Desativa a interrupcao Data Empty
  Desativa a interrupcao complete*/
  UCSR0B |= (1 << TXEN0);

  /* Set frame format: 8data, 2stop bit */
  UCSR0C |= (1 << USBS0) | (1 << UCSZ00);
}

void USART_Transmit(unsigned char data) {
  /* Wait for empty transmit buffer */
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}

float map_setpoint(float valor, float min, float max, float newmin, float newmax) {
  return ((valor - min) * (newmax - newmin) / (max - min) + newmin);
}

ISR(TIMER1_COMPA_vect) {
  flagsISR |= (1 << 0);
}

ISR(INT0_vect) {
  if ((PIND & 0x0C)) {
    Pulsos++;
    rotor.PulsosCanal++;
  } else {
    Pulsos--;
    rotor.PulsosCanal--;
  }
}