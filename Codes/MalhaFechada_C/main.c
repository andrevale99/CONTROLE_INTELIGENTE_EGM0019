#define F_CPU 16000000UL

#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define MYUBRR F_CPU / 16 / BAUD - 1

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

volatile uint32_t Pulsos = 0;

char buffer[32];

//=====================================================
//  FUNCS
//=====================================================

void pwm_setup(void);
void external_intr_setup(void);

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);

ISR(INT0_vect);

//=====================================================
//  MAIN
//=====================================================

int main(void)
{
  pwm_setup();
  external_intr_setup();
  USART_Init(MYUBRR);

  sei();

  while (1)
  {
    PORTD |= (1 << PD6) & ~(1 << PD5);
    for (uint8_t i = 0; i < 255; ++i)
    {
      OCR0A = i;
      _delay_ms(10);
    }

    for (uint8_t i = 254; i > 0; --i)
    {
      OCR0A = i;
      _delay_ms(10);
    }

    PORTD |= (1 << PD5) & ~(1 << PD6);
    for (uint8_t i = 0; i < 255; ++i)
    {
      OCR0B = i;
      _delay_ms(10);
    }

    for (uint8_t i = 254; i > 0; --i)
    {
      OCR0B = i;
      _delay_ms(10);
    }

    sprintf(buffer, "HELLO WORLD %ld\n", Pulsos);

    // Desativando todas as interrrupcao, nao eh legal fazer isso
    // Deve desativar uma interrupcao expecifica (melhor maneira)
    cli();
    for (uint8_t i = 0; buffer[i] != '\0'; ++i)
      USART_Transmit(buffer[i]);
    sei();

    _delay_ms(100);
  }
}

//=====================================================
//  FUNCS
//=====================================================

void pwm_setup()
{
  // Configurar PD6 (OC0A) como saída
  DDRD |= (1 << PD5) | (1 << PD6);

  // Modo Fast PWM com TOP=0xFF
  // COM0A1:0 = 10 → Clear OC0A on Compare Match (não-invertido)
  // WGM01:0 = 11 → Fast PWM
  // TCCR0A: COM0A1=1, COM0A0=0, WGM01=1, WGM00=1
  TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);

  // TCCR0B: CS01=1, CS00=1 (prescaler = 64), WGM02=0 (não usado neste modo)
  TCCR0B = (1 << CS01) | (1 << CS00);

  // Duty cycle inicial de 50%
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

ISR(INT0_vect)
{
  Pulsos++;
  PORTB ^= (1 << PB5);
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
