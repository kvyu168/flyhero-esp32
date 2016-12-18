/*
 * PWM_Generator.cpp
 *
 *  Created on: 11. 12. 2016
 *      Author: michp
 */

#include <PWM_Generator.h>

void PWM_Generator::Init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();


	const uint32_t PERIOD_US = 500;
	const uint32_t PULSE_US = 0;

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_15 | GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	uint32_t PclkFreq = HAL_RCC_GetPCLK1Freq();


	// 8 MHz timer frequency
	// 1000 ticks = 125 us
	// 2000 ticks = 250 us
	// 4000 ticks period 500 us => PWM frequency 2 kHz

	this->htim.Instance = TIM2;
	this->htim.Init.Prescaler = (uint16_t)((PclkFreq) / 8000000) - 1;
	this->htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	this->htim.Init.Period = PERIOD_US * 8 - 1;
	this->htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&this->htim);

	TIM_OC_InitTypeDef sConfig;
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = PULSE_US * 8;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_1);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = PULSE_US * 8;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_2);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = PULSE_US * 8;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_3);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = PULSE_US * 8;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_4);
}

void PWM_Generator::SetPulse(uint16_t ticks, uint8_t index)
{
	TIM_OC_InitTypeDef sConfig;

	if (index == 0) {
		sConfig.OCMode = TIM_OCMODE_PWM1;
		sConfig.Pulse = ticks;
		sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
		sConfig.OCFastMode = TIM_OCFAST_DISABLE;
		sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
		sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
		HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_1);

		HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_1);
	}
	else if (index == 1) {
		sConfig.OCMode = TIM_OCMODE_PWM1;
		sConfig.Pulse = ticks;
		sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
		sConfig.OCFastMode = TIM_OCFAST_DISABLE;
		sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
		sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
		HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_2);

		HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_2);
	}
	else if (index == 2) {
		sConfig.OCMode = TIM_OCMODE_PWM1;
		sConfig.Pulse = ticks;
		sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
		sConfig.OCFastMode = TIM_OCFAST_DISABLE;
		sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
		sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
		HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_3);

		HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_3);
	}
	else {
		sConfig.OCMode = TIM_OCMODE_PWM1;
		sConfig.Pulse = ticks;
		sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
		sConfig.OCFastMode = TIM_OCFAST_DISABLE;
		sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
		sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
		HAL_TIM_PWM_ConfigChannel(&this->htim, &sConfig, TIM_CHANNEL_4);

		HAL_TIM_PWM_Start(&this->htim, TIM_CHANNEL_4);
	}
}

void PWM_Generator::Arm()
{
	this->SetPulse(2000, 0);
	this->SetPulse(2000, 1);
	this->SetPulse(2000, 2);
	this->SetPulse(2000, 3);

	HAL_Delay(2000);

	this->SetPulse(1000, 0);
	this->SetPulse(1000, 1);
	this->SetPulse(1000, 2);
	this->SetPulse(1000, 3);

	HAL_Delay(1000);

	this->SetPulse(950, 0);
	this->SetPulse(950, 1);
	this->SetPulse(950, 2);
	this->SetPulse(950, 3);

	/*for (uint16_t p = 1020; p <= 2000; p += 10) {
		this->SetPulse(p, 0);
		this->SetPulse(p, 1);
		this->SetPulse(p, 2);
		this->SetPulse(p, 3);
		HAL_Delay(15);
	}

	HAL_Delay(50);

	for (uint16_t p = 2000; p >= 1000; p -= 10) {
		this->SetPulse(p, 0);
		this->SetPulse(p, 1);
		this->SetPulse(p, 2);
		this->SetPulse(p, 3);
		HAL_Delay(15);
	}*/
}