#ifndef __BLDC_MOTOR_H__
#define __BLDC_MOTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "err_code.h"

typedef uint8_t (*func_set_pwm)(float duty);
typedef uint8_t (*func_start_pwm)(void);
typedef uint8_t (*func_stop_pwm)(void);

typedef struct bldc_motor* bldc_motor_handle_t;


/**
 * @brief   Configuration structure.
 */
typedef struct {
	uint16_t 			kv;				/*!< Motor KV */
	func_set_pwm 		set_pwm;		/*!< Function set PWM */
	func_start_pwm 		start_pwm;		/*!< Function start PWM */
	func_stop_pwm 		stop_pwm;		/*!< Function stop PWM */
} bldc_motor_cfg_t;

/*
 * @brief   Initialize BLDC motor with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
bldc_motor_handle_t bldc_motor_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   config Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t bldc_set_config(bldc_motor_handle_t handle, bldc_motor_cfg_t config);

/*
 * @brief   Start BLDC motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t bldc_motor_start(bldc_motor_handle_t handle);

/*
 * @brief   Stop BLDC motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t bldc_motor_stop(bldc_motor_handle_t handle);

/*
 * @brief   Set PWM duty cycle.
 *
 * @param 	handle Handle structure.
 * @param 	duty PWM duty cycle.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t bldc_motor_set_pwm_duty(bldc_motor_handle_t handle, float duty);

/*
 * @brief   Destroy BLDC motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t bldc_motor_destroy(bldc_motor_handle_t handle);

#ifdef __cplusplus
}
#endif

#endif /* __BLDC_MOTOR_H__ */