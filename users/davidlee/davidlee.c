#include "davidlee.h"

enum my_layers {
  _CMK,   // Colemak-DH
  _NAV,   // Navigation
  _NUM,   // Numbers 
  _FUN,   // Function keys
  _GAM,   // Gaming / QWERTY
  _PTR,   // Pointer

};

enum my_keycodes {
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  GAM_LCK,
  EXT_PTR,
  EXT_GAM,
  BS_WORD,
};

//
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

//
// Combos
//

// I + / = turn on PTR layer
const uint16_t PROGMEM ptr_combo[]       = {SLS_MEH, I_OPT, COMBO_END};
// N + S = backspace word
const uint16_t PROGMEM bs_word_combo[]   = {N_SFT, E_CMD, COMBO_END};
// A + R = caps word
const uint16_t PROGMEM caps_word_combo[] = {A_CTL, R_OPT, COMBO_END};
// ESC + DEL = RESET
const uint16_t PROGMEM reset_combo[]     = {ESC_CTL, DEL_HYP, COMBO_END};