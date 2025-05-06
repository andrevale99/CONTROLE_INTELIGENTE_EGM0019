#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void pwm_init()
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

int main(void)
{
  pwm_init();

  while (1)
  {
    PORTD |= (1 << PD6) & (~(1 << PD5));
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

    PORTD |= (1 << PD5) & (~(1 << PD6));
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
  }
}
