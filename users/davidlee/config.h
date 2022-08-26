#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(COLEMAK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif

#define COMBO_COUNT 17

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY 1
#define IGNORE_MOD_TAP_INTERRUPT 1 // necessary for home row mods
#define TAPPING_FORCE_HOLD 1       // allows mod tap to resolve to a mod after a tap                                
#define TAP_CODE_DELAY 5      
#define PERMISSIVE_HOLD_PER_KEY 1

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER
#define COMBO_TERM (TAPPING_TERM/5) // time to get all combo keys down - keep it short
#define COMBO_HOLD (COMBO_TERM*4)   // time to hold to trigger delayed combo
#define ADAPTIVE_TERM COMBO_HOLD    // use COMBO_HOLD time as a standard threshold (same reaction time)

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

// custom keycodes
//

// function keys remapped in Karabiner
#define FN       KC_F24
#define SIRI     KC_F21

// meh key for application launch shortcuts, using Raycast
#define Z_MEH   MT(MOD_MEH, KC_Z)
#define SLS_MEH MT(MOD_MEH, KC_SLSH)

// home row mods 
#define A_CTL  MT(MOD_LCTL, KC_A)
#define R_OPT  MT(MOD_LALT, KC_R)
#define S_CMD  MT(MOD_LGUI, KC_S)
#define T_SFT  MT(MOD_LSFT, KC_T)

#define N_SFT  MT(MOD_RSFT, KC_N)
#define E_CMD  MT(MOD_RGUI, KC_E)
#define I_OPT  MT(MOD_LALT, KC_I)
#define O_CTL  MT(MOD_RCTL, KC_O)

// left side 
#define TAB_HYP  MT(MOD_HYPR, KC_TAB) // don't do much with HYPER, except a few Raycast shortcuts
#define ESC_CTL  LCTL_T(KC_ESCAPE)
#define ENT_SFT  KC_SFTENT

// bottom row 
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define E_FUN    LT(_FUN, KC_E) // not used to E on thumb yet ...

#define NAV      MO(_NAV) 
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)
#define ENT_PTR  LT(_PTR, KC_ENTER)

// right side 
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
#define QOT_CTL  MT(MOD_RCTL, KC_QUOTE)

// clipboard
#define UNDO   LCMD(KC_Z)
#define CUT    LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE  LCMD(KC_V)

// misc
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)
#endif
