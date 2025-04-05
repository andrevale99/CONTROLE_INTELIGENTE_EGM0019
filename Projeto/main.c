/**
 * @author Andre Menezes de Freitas Vale
 *
 * @brief Codigo que utiliza da interrupcao externas PCINTXX
 * para criar uma logica de semaforo simples
 *
 * @note O PWM é gerado pelo pino PB1 (OC1A) sem o auxilio de interrupcao,
 * pois a configuracao do TIMER 1 permite isso, ou seja, a mudanca ocorrera
 * de forma assincrona.
 *
 * Utiliza um potenciometro para mudar a frequencia, lendo a
 * entrada analogica, e modificando o valor do OCR1A.
 *
 * Uma forma de melhorar ainda mais o codigo, seria de utilizar a
 * interrupcao de vez a programacao procedural, mas como o pino PB1
 * esta no modo "assincrono", nao tem necessidade disso.
 *
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

uint16_t limit = 0;

//===================================================
//  PROTOTIPOS
//===================================================

void setup_pwm_phase_correct(void);

//===================================================
//  MAIN
//===================================================
int main()
{
    setup_pwm_phase_correct();

    for (;;)
    {

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

    OCR1A = (uint16_t)150;

    ICR1 = 15000;
}