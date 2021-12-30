#include "davidlee.h"


//
// RGB status lights
// 

bool caps_is_active(void) {
  return (IS_HOST_LED_ON(USB_LED_CAPS_LOCK));
}