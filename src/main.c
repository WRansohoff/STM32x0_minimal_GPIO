#include "main.h"

/**
 * Main program.
 */
int main(void) {
  #ifdef VVC_F0
    // Enable the GPIOB peripheral in 'RCC_AHBENR'.
    RCC->AHBENR   |= RCC_AHBENR_GPIOBEN;
  #elif  VVC_L0
    RCC->IOPENR   |= RCC_IOPENR_IOPBEN;
  #endif

  // Initialize the GPIOB pins.
  // Reset all options, because the L0 lines reset to 0xFFFFFFFF.
  // B1 should be set to 'input' mode with pull-up.
  GPIOB->MODER  &= ~(0x3 << (BUTTON_PIN*2));
  GPIOB->PUPDR  &= ~(0x3 << (BUTTON_PIN*2));
  GPIOB->PUPDR  |=  (0x1 << (BUTTON_PIN*2));
  // B3 is connected to an LED on the 'Nucleo' board.
  //    It should be set to push-pull low-speed output.
  GPIOB->MODER  &= ~(0x3 << (LED_PIN*2));
  GPIOB->MODER  |=  (0x1 << (LED_PIN*2));
  GPIOB->OTYPER &= ~(1 << LED_PIN);
  GPIOB->PUPDR  &= ~(0x3 << (LED_PIN*2));

  // Keep track of whether the button is pressed.
  uint8_t button_down = 0;
  while (1) {
    // Invert the IDR register since '0' means 'pressed'.
    uint32_t idr_val = ~GPIOB->IDR;
    if (idr_val & (1 << BUTTON_PIN)) {
      // The button is pressed; if it was not already
      // pressed, change the LED state.
      if (!button_down) {
        GPIOB->ODR ^= (1 << LED_PIN);
      }
      button_down = 1;
    }
    else {
      button_down = 0;
    }
  }
}
