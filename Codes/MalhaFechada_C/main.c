#define F_CPU 16000000UL

#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define MYUBRR F_CPU / 16 / BAUD - 1

#define BUFFER_MAX_LEN 32

#define PERIODO_DE_AMOSTRAGEM 20

#define ENCODER_A PD2

// Pode trocar para outro pino digital,
// caso queira desocupar o Pino INT1
#define ENCODER_B PD3

#define ROTOR_SNETIDO_HORARIO(pwm) \
  OCR0A = (uint8_t)pwm;            \
  OCR0B = 0;
#define ROTOR_SNETIDO_ANTIHORARIO(pwm) \
  OCR0A = 0;                           \
  OCR0B = (uint8_t)pwm;

#define PULSOS_POR_VOLTA (float)1024.

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

volatile int32_t Pulsos = 0;
volatile int32_t RPM = 0;

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

/// @brief Configuracao do periferico UART
/// @param ubrr Baud Rate da comunicacao
void USART_Init(unsigned int ubrr);

/// @brief Funcao para mandar um dado pela Serial
/// @param data o caractere que deseja mandar
void USART_Transmit(unsigned char data);

ISR(TIMER1_COMPA_vect);

ISR(INT0_vect);

//=====================================================
//  MAIN
//=====================================================

int main(void)
{
  pwm_setup();
  external_intr_setup();
  USART_Init(MYUBRR);
  timer_setup(PERIODO_DE_AMOSTRAGEM);

  ROTOR_SNETIDO_HORARIO(254);

  sei();

  while (1)
  {
    RPM = ((float)Pulsos / PULSOS_POR_VOLTA) * (60000 / PERIODO_DE_AMOSTRAGEM);
  }
}

//=====================================================
//  FUNCS
//=====================================================

void pwm_setup()
{
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

void external_intr_setup(void)
{
  // Interrupcao Externa no Pino INT0 (PD2)
  // na borda de descida
  EICRA |= (1 << ISC01);

  EIMSK |= (1 << INT0);
}

void timer_setup(uint16_t quantidade_de_dados)
{
  TCCR1B |= (1 << WGM12) | (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = (uint16_t)62500 / quantidade_de_dados;
}

ISR(TIMER1_COMPA_vect)
{
  sprintf(buffer, "%ld %ld\n", Pulsos, RPM);
  for (uint8_t i = 0; buffer[i] != '\0'; ++i)
    USART_Transmit(buffer[i]);
  Pulsos = 0;
}

ISR(INT0_vect)
{
  if ((PIND & 0x0C))
    Pulsos++;
  else
    Pulsos--;
}

/**
 * @brief Inicializacao do USART
 * @param ubrr Valor calculado do baud rate
 *
 * @note A definicao MYUBRR ja faz o calculo (datasheet)
 * e inicializa somento o TX, para o RX (1<<RXEN0) no
 * registrador UCSR0B
 */
void USART_Init(unsigned int ubrr)
{
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

/**
 * @brief Transmissao de um byte pelo USART0
 * @param data caractere
 *
 * @note Essa funcao é utilizada quando nao for utilizada
 * as interrupcoes para envio de dado
 */
void USART_Transmit(unsigned char data)
{
  /* Wait for empty transmit buffer */
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}
