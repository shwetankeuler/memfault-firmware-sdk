//@Euler Motors Property
//! A port of dependency functions for Memfault metrics subsystem using Threadx.

#include "memfault/core/compiler.h"
#include "memfault/metrics/platform/timer.h"
#include "tx_api.h"

/*
Implementation for timer dependency of memfault, note that for threadx, the timer tick is 10ms, any period below 10mms will not work
@arguments
period_sec: unsigned integer value of time period for timer count in seconds, note that this value can not be less than 10ms
callback : memfault callback to be attached
*/
bool memfault_platform_metrics_timer_boot(uint32_t period_sec,
                                          MemfaultPlatformTimerCallback callback) {
    tx_timer_create(&memfault_timer, "memfault_timer", callback,
	                0x1, (period_sec * 100), (period_sec * 100), TX_AUTO_ACTIVATE);
    return true;
}
