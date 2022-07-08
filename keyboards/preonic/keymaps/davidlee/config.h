#pragma once

#ifndef USB_MAX_POWER_CONSUMPTION
#  define USB_MAX_POWER_CONSUMPTION 250
#endif


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif

#define COMBO_COUNT 1 // mouse layer

#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY 1
#define IGNORE_MOD_TAP_INTERRUPT 1
#define TAPPING_FORCE_HOLD 1                                
#define TAP_CODE_DELAY 5      // 100
#define PERMISSIVE_HOLD_PER_KEY 1

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER
#define COMBO_TERM (TAPPING_TERM/5) // time to get all combo keys down
#define COMBO_HOLD (COMBO_TERM*4)   // time to hold to trigger delayed combo
// #define ADAPTIVE_TERM COMBO_HOLD    // use COMBO_HOLD time as a standard threshold (same reaction time)

#define CAPSWORD_USE_SHIFT 1

#define QMK_KEYS_PER_SCAN 4

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       8
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      7
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    30

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    10
#undef MOUSEKEY_WHEEL_INTERVAL                                 
#define MOUSEKEY_WHEEL_INTERVAL 16
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3
