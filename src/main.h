#ifndef _VVC_MAIN_H
#define _VVC_MAIN_H

#include <stdint.h>
#ifdef VVC_F0
  #include "stm32f0xx.h"
#elif  VVC_L0
  #include "stm32l0xx.h"
#endif

// Define GPIOB pin mappings for our LED and button.
#define BUTTON_PIN (1)
#define LED_PIN    (3)

#endif
