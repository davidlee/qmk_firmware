#include QMK_KEYBOARD_H
#include "davidlee.h"

#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

enum preonic_layers {
  _CMK,  // Colemak-DH
  _MOD,  // HOME ROW MODS layer
  _GAM,  // Gaming / QWERTY
  _NAV,  // Navigation
  _NUM,  // Numbers 
  _PTR,  // Pointer
};

enum preonic_keycodes {
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

#define FN       KC_F24
#define SIRI     KC_F21

#define MIN_PTR  LT(_PTR, KC_MINUS)

#define XXXXXXX  KC_NO

#define OS_MOD   OSL(_MOD)

// alpha mod / layer taps
#define Z_MEH   MT(MOD_MEH, KC_Z)
#define SLS_MEH MT(MOD_MEH, KC_SLSH)
#define SCN_OPT MT(MOD_LALT, KC_SCOLON)

// left side mods
#define ESC_CTL  LCTL_T(KC_ESCAPE)
#define FN_SFT   LSFT_T(FN)
#define TAB_MEH MT(MOD_MEH, KC_TAB)

// bottom row mods
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define MIN_MOD  LT(_MOD, KC_MINS)

#define E_NAV    LT(_NAV, KC_E)
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)
#define ENT_MOD  LT(_MOD, KC_ENTER)
#define ENT_OPT  MT(MOD_LALT, KC_ENTER)
#define MOD      MO(_MOD)

// right side mods
#define CMD_QOT  MT(MOD_RGUI, KC_QUOTE)
#define ENT_SFT  KC_SFTENT
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)

// clipboard
#define UNDO   LCMD(KC_Z)
#define REDO   SCMD(KC_Z)
#define CUT    LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE  LCMD(KC_V)

// misc
#define EN_DASH LOPT(KC_MINUS)
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

#define MSN_CTL LCTL(KC_UP)
#define APP_CTL LCTL(KC_DOWN)


#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)

  float layer_song[][2] = SONG(BLIP);
#endif

//
// Combos
//

// N,U,I combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[] = {KC_N, KC_U, KC_I, COMBO_END};
// N,S is backspace word
const uint16_t PROGMEM bs_word_combo[] = {KC_N, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(ptr_combo,  PTR_LCK),
  COMBO(bs_word_combo,  BS_WORD),
};


//
// the actual KEYMAP
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BS_WORD, 
  TAB_MEH, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SCN_OPT, DEL_HYP,
  ESC_CTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    CMD_QOT,
  CAP_WRD, Z_MEH,   KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  SLS_MEH, ENT_OPT,
  FN,      KC_LCTL, KC_LOPT, CMD_TAB, SPC_NUM, MIN_PTR, E_NAV,   BS_SFT,  ENT_MOD, _______, _______, SIRI
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TAB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL ,CMD_RBRC,_______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, UNDO,    CUT,     COPY,    KC_MPLY, PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_COLN, KC_LBRC, KC_RBRC, KC_UNDS, KC_BSLS, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_PERC, KC_ASTR,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS,
  KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_MINS, KC_EQL,  KC_COMM, KC_1,    KC_2,    KC_3,    KC_AMPR, _______,
  _______, _______, _______, KC_DLR,  _______, KC_CIRC, KC_DOT,  _______, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_PTR] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, RESET,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, GAM_LCK, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, EXT_PTR,
  KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_GAM] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  _______, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_MOD] = LAYOUT_preonic_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCMD, KC_LOPT, KC_RCTL, _______,
  _______, UNDO,    CUT,     COPY,    XXXXXXX, PASTE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

//
// Function Overrides
//

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Z_MEH:
        case SCN_OPT:
        case SLS_MEH:
          return false; // Do not select the hold action when another key is tapped.
        default:
          return true; // Immediately select the hold action when another key is tapped.
        }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_enable();

  switch (get_highest_layer(state)) {
    case _NUM:
      rgblight_setrgb (0x55,  0x7A, 0xFF);
      break;

    case _NAV:
      rgblight_setrgb (0x99,  0xFF, 0x00);
      break;

    case _PTR:
      rgblight_setrgb (0x99,  0xFF, 0xAA);
      break;

    case _GAM:
      rgblight_setrgb (0xFF,  0x00, 0x00);
      
      #ifdef AUDIO_ENABLE
        PLAY_SONG(layer_song);
      #endif
      
      break;

    case _MOD:
      rgblight_setrgb (0xFF,  0x33, 0xFF);
      #ifdef AUDIO_ENABLE
        PLAY_SONG(layer_song);
      #endif
      break;

    case _CMK:
    default: 
      rgblight_setrgb (0x00,  0x00, 0x00);      
      break;      
    }

  if (caps_is_active()) { 
    rgblight_setrgb (0xFF, 0xFF, 0xFF);
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // LOCK LAYERS

    case GAM_LCK:
      layer_on(_GAM);
      return false;

    case PTR_LCK:
      layer_on(_PTR);
      return false;

    // EXIT LAYERS

    case EXT_GAM:
      layer_off(_GAM);
      return false;    

    case EXT_PTR:
      layer_off(_PTR);
      return false;

    // other functions

    case CAP_WRD:        
      if (record->event.pressed) {
        caps_word_on();
        #ifdef AUDIO_ENABLE
          PLAY_SONG(layer_song);
        #endif
      }
      return false;    

    case BS_WORD:        
      if (record->event.pressed) {
        tap_code16(LOPT(KC_BSPC));
      }
      return false;

    default:
      return true; /* Process all other keycodes normally */
  }
}
