#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(COLEMAK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif

#define COMBO_COUNT 18

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY 1
#define IGNORE_MOD_TAP_INTERRUPT 1 // necessary for home row mods
#define TAPPING_FORCE_HOLD 1       // allows mod tap to resolve to a mod after a tap
#define TAP_CODE_DELAY 5
#define PERMISSIVE_HOLD_PER_KEY 1  // we want permissive hold for all tap-hold keys except home row mods

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER
#define COMBO_TERM 20               // time to get all combo keys down - keep it short!
#define COMBO_HOLD 30               // time to hold to trigger delayed combo

#define CAPSWORD_USE_SHIFT 1
#define QMK_KEYS_PER_SCAN 4

#define DYNAMIC_MACRO_NO_NESTING 1

#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       2
#define MOUSEKEY_MOVE_DELTA     128
#define MOUSEKEY_INITIAL_SPEED  1000
#define MOUSEKEY_BASE_SPEED     10000
#define MOUSEKEY_DECELERATED_SPEED 1000
#define MOUSEKEY_ACCELARATED_SPEED 6000
//#define MOUSEKEY_MAX_SPEED      7
//#define MOUSEKEY_TIME_TO_MAX    30

#define MOUSEKEY_WHEEL_DELAY    10
#define MOUSEKEY_WHEEL_INTERVAL 16
#define MOUSEKEY_WHEEL_MAX_SPEED 3

