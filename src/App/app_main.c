/**
 * @file app_main.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief アプリメイン (for STM32G031F8P6)
 * @version 0.1
 * @date 2026-06-07
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include "app_main.h"

// --------------------------------------------------------------------------
static uint8_t s_led_state = 0;

static void _rtc_update(void);

#ifdef DBG_APP
void _debug_pcb_check(void);
#endif // DBG_APP

// --------------------------------------------------------------------------
// [Static]

// printf()をUARTにポーティング
int __io_putchar(int ch)
{
    HAL_UART_Transmit(&hlpuart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

static void _rtc_update(void)
{
    RTC_DateTypeDef sdatestructureget;
    RTC_TimeTypeDef stimestructureget;
    static uint8_t s_prev_seconds ;

    HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);

#if 1
    if(s_prev_seconds != stimestructureget.Seconds) {
        s_prev_seconds  = stimestructureget.Seconds;
        printf("RTC: 20%02d/%02d/%02d %02d:%02d:%02d\r\n",
                sdatestructureget.Year,sdatestructureget.Month,sdatestructureget.Date, \
                stimestructureget.Hours,stimestructureget.Minutes,stimestructureget.Seconds);
    }
#endif
}

#ifdef DBG_APP
void _debug_pcb_check(void)
{
    // 基板動作確認: Lチカ！ LEDチカチカ！
    HAL_GPIO_WritePin(PCB_LED_GPIO_Port, PCB_LED_Pin, s_led_state);
    s_led_state = !s_led_state;
    // printf("LED: %s\r\n", s_led_state ? "ON" : "OFF");
}
#endif // DBG_APP
// --------------------------------------------------------------------------
// [APP]

void app_main_init(void)
{
    // printf()をUARTにポーティング
    setbuf(stdout, NULL);
    printf("STM32G031F8P6 Develop by Chimipupu\r\n");
}

void app_main(void)
{
#ifdef DBG_APP
    _debug_pcb_check(); // [DEBUG] 基板チェック
#endif // DBG_APP

    _rtc_update(); // RTC更新
}
