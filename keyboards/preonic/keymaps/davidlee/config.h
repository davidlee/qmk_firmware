#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// allow leader
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING                           

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// mouse emulation

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          30
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    10
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      8
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    40
