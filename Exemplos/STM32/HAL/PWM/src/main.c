#include <stm32f4xx_hal.h>

//===========================================
//  VARIAVEIS
//===========================================

TIM_HandleTypeDef htim1;
TIM_OC_InitTypeDef sConfigOC = {0};

//===========================================
//  PROTOTIPOS
//===========================================

// @brief Configuracoes dos clocks do sistemas
void SystemClock_Config(void);

// @brief Configuracao do Timer para gerar
// sinal PWM
void TIMER_Config(void);

void GPIO_Config(void);

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void);

//===========================================
//  MAIN
//===========================================
int main(void)
{
    GPIO_Config();
    TIMER_Config();
    HAL_Init();

    uint16_t dutyCycle = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_2);
    while (1)
    {
        while (dutyCycle < __HAL_TIM_GET_AUTORELOAD(&htim1))
        {
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ++dutyCycle);
            HAL_Delay(1);
        }
        while (dutyCycle > 0)
        {
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, --dutyCycle);
            HAL_Delay(1);
        }
    }

    return 0;
}

//===========================================
//  FUNCOES
//===========================================

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}

void TIMER_Config(void)
{
    // Habilita o clock do TIM1
    __HAL_RCC_TIM1_CLK_ENABLE();

    // Timer base configuration
    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 1024; // Prescale da contador
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 15625;                         // Valor Maximo de contagem
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; // Fator de divisao da fonte do TIMER
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_PWM_Init(&htim1);

    // Configuração do canal 2 para PWM do TIMER 1
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 15000; // Valor de comparacao para realizar o PWM
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2);

    // Configuração do canal 3 para PWM do TIMER 1
    sConfigOC.OCMode = TIM_OCMODE_PWM2;
    sConfigOC.Pulse = 15000; // Valor de comparacao para realizar o PWM
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3);

    // Inicia o PWM no canal 2 do TIMER 1
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    // Inicia o PWM no canal 3 do TIMER 1
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void GPIO_Config(void)
{
    // Habilita clock do GPIOA
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Alternate Function Push Pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1; // AF1 para TIM1 em PA9
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Alternate Function Push Pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1; // AF1 para TIM1 em PA10
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
        /* USER CODE END Error_Handler_Debug */
    }
}