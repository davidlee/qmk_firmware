#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200 // Timeout window in ms in which the double tap can occur.
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// #define USE_I2C
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
