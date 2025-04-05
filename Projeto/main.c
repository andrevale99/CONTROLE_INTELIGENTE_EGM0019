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

//===================================================
//  VARIAVEIS
//===================================================

uint16_t adcResult = 0;

//===================================================
//  PROTOTIPOS
//===================================================

void setup_pwm_phase_correct(void);


void adc_setup(void);
uint16_t adc_read(uint8_t pino);

//===================================================
//  MAIN
//===================================================
int main()
{
  setup_pwm_phase_correct();
  adc_setup();

  Serial.begin(115200);

  for (;;)
  {
    adcResult = adc_read(0x00);
    Serial.println((adcResult));
  }

  return 0;
}
//===================================================
//  FUNCOES
//===================================================

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

  while (!(ADCSRA &= ~(1 << ADIF)));

  ADCSRA |= (1 << ADIF);

  adc_LSB = ADCL;
  adc_MSB = ADCH;

  ADCSRA |= (1 << ADSC);

  return (adc_MSB << 8) | adc_LSB;
}