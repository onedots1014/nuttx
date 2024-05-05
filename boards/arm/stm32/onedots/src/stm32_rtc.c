#include <nuttx/timers/rtc.h>
#include <stm32_rtc.h>

int stm32_rtc_initialize(void)
{
    struct rtc_lowerhalf_s *lower;
    lower = stm32_rtc_lowerhalf();
    rtc_initialize(0, lower);

    return 0;
}

