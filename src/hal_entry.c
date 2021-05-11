/* HAL-only entry function */
#include "hal_data.h"

uint32_t period = 92500;

void hal_entry(void)
{

    /*Initialize servo control timer*/
    g_servo_control.p_api->open(g_servo_control.p_ctrl, g_servo_control.p_cfg);

    while(1)
    {
        g_servo_control.p_api->dutyCycleSet(g_servo_control.p_ctrl,period, TIMER_PWM_UNIT_PERCENT_X_1000, 0);
        R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MILLISECONDS);
    }
}
