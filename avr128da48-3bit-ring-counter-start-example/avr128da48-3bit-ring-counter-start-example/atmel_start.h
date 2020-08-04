#ifndef ATMEL_START_H_INCLUDED
#define ATMEL_START_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "include/driver_init.h"
#include "include/atmel_start_pins.h"

typedef enum {
	KEY_NO_ACTION,
	KEY_PRESSED,
	KEY_RELEASED,
} buttonState_t;

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void atmel_start_init(void);

#ifdef __cplusplus
}
#endif
#endif
