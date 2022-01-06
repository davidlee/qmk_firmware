#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif

#define COMBO_COUNT 2          

#define TAPPING_TERM_PER_KEY 1
#define IGNORE_MOD_TAP_INTERRUPT 1
// #define TAPPING_FORCE_HOLD 1
// #define PERMISSIVE_HOLD 1 

#define CAPSWORD_USE_SHIFT 1

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT 150
// #define AUTO_SHIFT_NO_SETUP

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING 1                           

// #define QMK_KEYS_PER_SCAN 4

// #define MK_COMBINED 1
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       8
#define MOUSEKEY_WHEEL_DELAY    10
#define MOUSEKEY_MAX_SPEED      8
#define MOUSEKEY_TIME_TO_MAX    50
