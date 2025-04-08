/**
   @author Andre Menezes de Freitas Vale

   @brief Codigo que utiliza da interrupcao externas PCINTXX
   para criar uma logica de semaforo simples

   @note O PWM é gerado pelo pino PB1 (OC1A) sem o auxilio de interrupcao,
   pois a configuracao do TIMER 1 permite isso, ou seja, a mudanca ocorrera
   de forma assincrona.

   Utiliza um potenciometro para mudar a frequencia, lendo a
   entrada analogica, e modificando o valor do OCR1A.

   Uma forma de melhorar ainda mais o codigo, seria de utilizar a
   interrupcao de vez a programacao procedural, mas como o pino PB1
   esta no modo "assincrono", nao tem necessidade disso.

*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdio.h>

#define BAUD 9600
#define MYUBRR F_CPU / 16 / BAUD - 1

#define GPIO_POT 0x00

#define ENCODER_A_PINX PIND
#define ENCODER_A_DDRX DDRD
#define ENCODER_A_PORTX PORTD
#define ENCODER_A_GPIO_INPUT PD2 // Pino de interrupcao externa INT0

#define ENCODER_B_PINX PINB
#define ENCODER_B_DDRX DDRB
#define ENCODER_B_PORTX PORTB
#define ENCODER_B_GPIO_INPUT PB4

#define ENCODER_A_LEVEL (ENCODER_A_PINX & (1 << ENCODER_A_GPIO_INPUT))
#define ENCODER_B_LEVEL (ENCODER_B_PINX & (1 << ENCODER_B_GPIO_INPUT))

//===================================================
//  VARIAVEIS
//===================================================

uint16_t adcResult = 0;
uint16_t DutyCycle = 0;

//===================================================
//  PROTOTIPOS
//===================================================

void PWMPhaseCorrect_setup(void);

void GPIOs_setup(void);

void ADC_setup(void);
uint16_t ADC_read(uint8_t pino);

void EXTI_setup(void);
ISR(INT0_vect);

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);

int16_t mapear_valor_potenciometro(uint16_t value);

//===================================================
//  MAIN
//===================================================
int main()
{
  PWMPhaseCorrect_setup();
  USART_Init(MYUBRR);
  GPIOs_setup();
  EXTI_setup();
  ADC_setup();

  sei();

  while (1)
  {
    // adcResult = ADC_read(GPIO_POT);
    // DutyCycle = 15000 * (float)adcResult / 1024;
    // OCR1A = DutyCycle;

    for (uint16_t i = 0; i < 1024; i++)
    {
      adcResult = i;
      // DutyCycle = mapear_valor_potenciometro(adcResult);
      DutyCycle = 15000 * (float)adcResult / 1024;
      OCR1A = DutyCycle;
      _delay_ms(2);
    }

    for (uint16_t i = 1023; i > 0; i--)
    {
      adcResult = i;
      // DutyCycle = mapear_valor_potenciometro(adcResult);
      DutyCycle = 15000 * (float)adcResult / 1024;
      OCR1A = DutyCycle;
      _delay_ms(2);
    }
  }

  return 0;
}
//===================================================
//  FUNCOES
//===================================================

/**
   @brief Configuracao do Pino PB1 (OCA1) para
   gerar o sinal PWM para o motor.

   @note O nome da funcao ja explica que modo esta o
   contador TIMER_1.
*/
void PWMPhaseCorrect_setup(void)
{
  // Pino OC1A (PORTB1) como OUTPUT para PWM
  DDRB |= (1 << DDB1);

  // OC1A clear on compare match
  TCCR1A |= (1 << COM1A1) | (1 << WGM11);

  // Prescale de 1 no modo Fast PWM com o TOP em ICR1
  TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS10);

  OCR1A = (uint16_t)15000;

  ICR1 = 15000;
}

/**
 * @brief Configuracao das GPIOS. Configura
 * os pinos para a leitura dos encoder.
 *
 * @note As GPIOS de input dos encoders estao
 * no modo INPUT em PULLUP.
 */
void GPIOs_setup(void)
{
  // Modo INPUT
  ENCODER_A_DDRX &= ~(1 << ENCODER_A_GPIO_INPUT);
  ENCODER_B_DDRX &= ~(1 << ENCODER_B_GPIO_INPUT);

  // Ativando os PULLUPS
  ENCODER_A_PORTX |= (1 << ENCODER_A_GPIO_INPUT);
  ENCODER_B_PORTX |= (1 << ENCODER_B_GPIO_INPUT);
}

/**
   @brief Inicializacao do ADC

   @note Ativa o ADC com o prescale de 16e6/128 e
   referencia no AVCC/AREF
*/
void ADC_setup()
{
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADMUX |= (1 << REFS0);
}

/**
   @brief Funcao para pegar o valor do adc
   @param pino Pino que deseja ler
   @return Valor da conversao ADC em um valor de 16 bits

   @note Retorna um valor de 16 bits pela facilidade,
   ja que a resolucao do arduino e de 10 bits
*/
uint16_t ADC_read(uint8_t pino)
{
  static uint8_t adc_LSB;
  static uint8_t adc_MSB;

  ADMUX |= pino;

  ADCSRA |= (1 << ADSC);

  while (!(ADCSRA &= ~(1 << ADIF)))
    ;

  ADCSRA |= (1 << ADIF);

  adc_LSB = ADCL;
  adc_MSB = ADCH;

  ADCSRA |= (1 << ADSC);

  return (adc_MSB << 8) | adc_LSB;
}

/**
   @brief Configura o Pino INT0 (PD2) para
   interrupcao externa, deteccao de borda de
   descida
*/
void EXTI_setup(void)
{
  EICRA |= (1 << ISC01);

  EIMSK |= (1 << INT0);
}

/// @brief Funcao de Ingerrupcao
ISR(INT0_vect)
{
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
  UCSR0B |= (1 << TXEN0) | (1 << TXCIE0);

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

/**
 * @brief pega o valor do potenciometro e varia
 * entre -255 e 254
 */
int16_t mapear_valor_potenciometro(uint16_t value)
{
  return ((value / 1023) * 510 - 255);
}