#pragma once

// #define COMBO_COUNT 1

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

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// allow opt-cmd-esc
#define GRAVE_ESC_ALT_OVERRIDE    

// allow leader
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING


// mouse stuff
#define MK_KINETIC_SPEED                                

#define MOUSEKEY_DELAY 8
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_MOVE_DELTA 2    
#define MOUSEKEY_INITIAL_SPEED 4
#define MOUSEKEY_BASE_SPEED 1
#define MOUSEKEY_DECELERATED_SPEED 1                        
#define MOUSEKEY_ACCELERATED_SPEED 500

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32                                
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
// #define MOUSEKEY_TIME_TO_MAX 100
// #define MOUSEKEY_MAX_SPEED 20
// #define MOUSEKEY_WHEEL_DELAY 20
// #define MOUSEKEY_WHEEL_INTERVAL 40                                
// #define MOUSEKEY_WHEEL_MAX_SPEED 2
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 100                                
// // #define MK_COMBINED
// #define MK_3_SPEED 75                             
                            
/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
