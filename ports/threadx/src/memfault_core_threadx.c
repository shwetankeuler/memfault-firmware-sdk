//! @file
//!
//! Copyright (c) Memfault, Inc.
//! See License.txt for details
//!
//! A port of dependency functions for Memfault core subsystem using Threadx.

// #if configUSE_MUTEXES == 0
// #error "configUSE_MUTEXES must be enabled to use Memfault FreeRTOS port"
// #endif

// #if configUSE_RECURSIVE_MUTEXES == 0
// #error "configUSE_RECURSIVE_MUTEXES must be enabled to use Memfault FreeRTOS port"
// #endif

/*
implementation to get relative timings since boot
*/
uint64_t memfault_platform_get_time_since_boot_ms(void) {
  // Return time since boot in ms, this is used for relative timings.
  uint64_t ticks_since_boot = tx_time_get();

  // Convert to milliseconds
  return (ticks_since_boot * 1000) / 100; //TX_TIMER_TICKS_PER_SECOND is 100
}

// static SemaphoreHandle_t s_memfault_lock;

// SemaphoreHandle_t prv_init_memfault_mutex(void) {
// #if MEMFAULT_FREERTOS_PORT_USE_STATIC_ALLOCATION != 0
//   static StaticSemaphore_t s_memfault_lock_context;
//   return xSemaphoreCreateRecursiveMutexStatic(&s_memfault_lock_context);
// #else
//   return xSemaphoreCreateRecursiveMutex();
// #endif
// }

// void memfault_lock(void) {
//   xSemaphoreTakeRecursive(s_memfault_lock, portMAX_DELAY);
// }

// void memfault_unlock(void) {
//   xSemaphoreGiveRecursive(s_memfault_lock);
// }

// void memfault_freertos_port_boot(void) {
//   s_memfault_lock = prv_init_memfault_mutex();
// }
