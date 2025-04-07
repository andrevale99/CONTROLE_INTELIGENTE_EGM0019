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

#include <stdint.h>

#define GPIO_POT PC0

#define ENCODER_A_PINX PIND
#define ENCODER_A_PORTX PORTD
#define ENCODER_A_GPIO_INPUT PD2 // Pino de interrupcao externa INT0
#define ENCODER_B_PINX PINB
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

void setup_pwm_phase_correct(void);

void setup_gpios(void);

void adc_setup(void);
uint16_t adc_read(uint8_t pino);

void setup_external_interrupt(void);
ISR(INT0_vect);
//===================================================
//  MAIN
//===================================================
int main()
{
  setup_pwm_phase_correct();
  setup_external_interrupt();
  adc_setup();

  sei();

  while (1)
  {
    adcResult = adc_read(GPIO_POT);
    DutyCycle = 15000 * (float)adcResult / 1024;
    OCR1A = DutyCycle;

    if (ENCODER_A_LEVEL && ENCODER_B_LEVEL)
      ;
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
void setup_pwm_phase_correct(void)
{
  // Pino OC1A (PORTB1) como OUTPUT para PWM
  DDRB |= (1 << DDB1);

  // OC1A clear on compare match
  TCCR1A |= (1 << COM1A1) | (1 << WGM11);

  // Prescale de 1024 no modo Fast PWM com o TOP em ICR1
  TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS12) | (1 << CS10);

  OCR1A = (uint16_t)15000 * 1;

  ICR1 = 15000;
}

/**
 * @brief Configuracao das GPIOS. Configura
 * os pinos para a leitura dos encoder.
 */
void setup_gpios(void)
{
  ENCODER_A_PORTX &= ~(0 << ENCODER_A_GPIO_INPUT);
  ENCODER_B_PORTX &= ~(0 << ENCODER_B_GPIO_INPUT);
}

/**
   @brief Inicializacao do ADC

   @note Ativa o ADC com o prescale de 16e6/128 e
   referencia no AVCC/AREF
*/
void adc_setup()
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
uint16_t adc_read(uint8_t pino)
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
void setup_external_interrupt(void)
{
  EICRA |= (1 << ISC01);

  EIMSK |= (1 << INT0);
}

ISR(INT0_vect)
{
}