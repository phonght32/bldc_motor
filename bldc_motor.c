#include "stdlib.h"
#include "stddef.h"

#include "bldc_motor.h"

/**
 * @brief   BLDC motor structure.
 */
typedef struct bldc_motor {
	uint16_t 			kv;				/*!< Motor KV */
	uint32_t 			freq;			/*!< PWM frequency */
	float 				duty;			/*!< PWM duty cycle */
	uint8_t 			is_run;			/*!< Running status */
	func_set_pwm 		set_pwm;		/*!< Function set PWM */
	func_start 			start;			/*!< Function start PWM */
	func_stop 			stop;			/*!< Function stop PWM */
} bldc_motor_t;

bldc_motor_handle_t bldc_motor_init(void)
{
	bldc_motor_handle_t handle = calloc(1, sizeof(bldc_motor_handle_t));
	if (handle == NULL) 
	{
		return NULL;
	}

	return handle;
}

err_code_t bldc_motor_set_config(bldc_motor_handle_t handle, bldc_motor_cfg_t config)
{
	/* Check if handle structure is NULL */
	if (handle == NULL) 
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->kv = config.kv;
	handle->freq = 50;
	handle->duty = 0.0;
	handle->is_run = 0;
	handle->set_pwm = config.set_pwm;
	handle->start = config.start;
	handle->stop = config.stop;

	return ERR_CODE_SUCCESS;
}

err_code_t bldc_motor_config(bldc_motor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL) 
	{
		return ERR_CODE_NULL_PTR;
	}

	/* Nothing to do */

	return ERR_CODE_SUCCESS;
}

err_code_t bldc_motor_start(bldc_motor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL) 
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->start();
	handle->is_run = 1;

	return ERR_CODE_SUCCESS;
}

err_code_t bldc_motor_stop(bldc_motor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL) 
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->stop();
	handle->is_run = 0;

	return ERR_CODE_SUCCESS;
}

err_code_t bldc_motor_set_pwm_duty(bldc_motor_handle_t handle, float duty)
{
	/* Check if handle structure is NULL */
	if (handle == NULL) 
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->set_pwm(duty);
	handle->duty = duty;

	return ERR_CODE_SUCCESS;
}

err_code_t bldc_motor_destroy(bldc_motor_handle_t handle)
{
	if (handle != NULL)
	{
		free(handle);
	}

	return ERR_CODE_SUCCESS;
}
