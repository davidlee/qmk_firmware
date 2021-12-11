#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define COMBO_COUNT 2

#define MUSIC_MASK (keycode != KC_NO)

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY 1

#define CAPSWORD_USE_SHIFT 1

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT 1

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD 1

// Apply the modifier on keys that are tapped during a short hold of a modtap
// #define PERMISSIVE_HOLD 1

// allow leader
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING 1                           

// hopefully this allows use with iphone ... nope
// #define USB_MAX_POWER_CONSUMPTION 100

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// mouse emulation

// combined mode                                
#define MK_COMBINED 1
// #define MK_MOMENTARY_ACCEL 1                                
// #define MK_3_SPEED 16

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       8
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    10
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      10
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    50
