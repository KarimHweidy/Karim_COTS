/**
 * @file EXTI_cfg
 * @author Karim Hweidy
 * @brief this file configures the EXTI module in prebuilt configurations method
 * @version
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_


/**
 * @details configure the reference voltage selection , options are : 1- ADC_u8AREF
 *                                                                    2- ADC_u8AVCC
 *                                                                    3- ADC_u8Reserved
 *                                                                    4- ADC_u8Internal_Voltage_REF
 */
#define   ADC_REFERENCE_VOLTAGE              ADC_u8AVCC

/**
 * @details configure the ADC left adjust, options are :     1- ENABLED
 *                                                           2- DISABLED
 */
#define ADC_LEFT_ADJUST                       ENABLED

/**
 * @details configure the ADC pre scaler, options are :     1- ADC_u8Prescaler2_0
 *                                                          2- ADC_u8Prescaler2
 *                                                          3- ADC_u8Prescaler4
 *                                                          4- ADC_u8Prescaler8
 *                                                          5- ADC_u8Prescaler16
 *                                                          6- ADC_u8Prescaler32
 *                                                          7- ADC_u8Prescaler64
 *                                                          8- ADC_u8Prescaler128
 */

#define   ADC_PRESCALER               ADC_u8Prescaler64

/**
 * @details configure the ADC ENABLE, options are :     1- ENABLED
 *                                                           2- DISABLED
 */
#define ADC_ENABLE                       ENABLED



#endif
