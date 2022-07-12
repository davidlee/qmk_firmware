#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

enum preonic_layers {
  _CMK,  // Colemak-DH
  _GAM,  // Gaming / QWERTY
  _NAV,  // Navigation
  _NUM,  // Numbers 
  _PAD,  // Number Pad
  _MED,  // Media
  _FUN,  // Functions
  _PTR,  // Pointer
};

enum preonic_keycodes {
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  PAD_LCK,
  GAM_LCK,
  EXT_PTR,
  EXT_GAM,
  EXT_PAD,
  BS_WORD,
  ZERO_PT,
};

//
// custom keycodes
//

#define FN       KC_F24 // requires karabiner
#define MICMUTE  KC_F16 // 
#define XXXXXXX  KC_NO

// Left-hand home row mods 
#define A_CTRL   LCTL_T(KC_A)
#define R_OPT    LALT_T(KC_R)
#define S_CMD    LGUI_T(KC_S)
#define T_SHIFT  LSFT_T(KC_T)

// Right-hand home row mods
#define N_SHIFT  RSFT_T(KC_N)
#define E_CMD    RGUI_T(KC_E)
#define I_OPT    LALT_T(KC_I)
#define O_CTRL   RCTL_T(KC_O)

// top row mod / layer-taps
#define Q_HYP    MT(MOD_HYPR, KC_Q)
#define W_MEH    MT(MOD_MEH, KC_W)
#define F_FUN    LT(_FUN, KC_F)
#define P_PAD    LT(_PAD, KC_P)

#define Y_MEH    MT(MOD_MEH, KC_Y)
#define SCLN_HYP MT(MOD_HYPR, KC_SCOLON)

// other mod-tap keys
#define Z_MED    LT(_MED, KC_Z)
#define ESC_CMD  LCMD_T(KC_ESCAPE)

// left side mods
#define FN_SFT   LSFT_T(FN)

// bottom row mods
#define ESC_OPT  LOPT_T(KC_ESC)
#define TAB_PAD  LT(_PAD, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define SYM      MO(_SYM)
#define MIN_FUN  LT(_FUN, KC_MINS)

#define E_NAV    LT(_NAV, KC_E)
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)

#define ENT_MED  LT(_MED, KC_ENTER)

// right side mods
#define CMD_QOT  MT(MOD_RGUI, KC_QUOTE)
#define ENT_SFT  KC_SFTENT

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

#define PRV_DTP LCTL(KC_LEFT)
#define NXT_DTP LCTL(KC_RIGHT)
#define MSN_CTL LCTL(KC_UP)
#define APP_CTL LCTL(KC_DOWN)

//
// Combos
//

// N,U,I combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[] = {N_SHIFT, KC_U, I_OPT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(ptr_combo,  PTR_LCK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB,  Q_HYP,   W_MEH,   F_FUN,   P_PAD,   KC_B,    KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,KC_DEL,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT, KC_G,    KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  FN_SFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
  FN,      KC_F17,  KC_F18,  KC_TAB,  SPC_NUM, MIN_FUN, E_NAV,   BS_SFT,  ENT_MED, PRV_DTP, NXT_DTP, MSN_CTL
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, REDO,    _______, _______, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL ,CMD_RBRC,KC_BSPC,
  CAP_WRD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SPC,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  FN,      XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PLUS, KC_COLN, KC_BSPC,
  CAP_WRD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC,
  KC_CAPS, XXXXXXX, EN_DASH, EM_DASH, KC_MINS, KC_EQL,  XXXXXXX, KC_UNDS, KC_COMM, KC_DOT,  KC_BSLS, _______,
  _______, _______, _______, PAD_LCK, _______, KC_SPC,  XXXXXXX, _______, _______, _______, _______, _______
),

[_PAD] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, EXT_PAD, XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
  _______, EXT_PAD, EXT_PAD, EXT_PAD, KC_SPC,  _______, KC_DOT,  KC_BSPC, KC_0,    _______, _______, _______
),

[_FUN] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  RESET, 
  ESC_CMD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, GAM_LCK, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, 
  _______, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, 
  XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_SPACE,_______, XXXXXXX, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX

),

[_MED] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_STOP, KC_F16,  KC_F16,  _______,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______ 
),

[_PTR] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, EXT_PTR,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_GAM] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  _______, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

};

//
// Function Overrides
//


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case R_OPT: 
      return TAPPING_TERM + 20;
    case I_OPT:
      return TAPPING_TERM + 20;
    case S_CMD: 
      return TAPPING_TERM + 10;
    case E_CMD:
      return TAPPING_TERM + 10;
    case T_SHIFT: 
      return TAPPING_TERM + 40; // Don't use these for shifting alphas, just as mods
    case N_SHIFT:               // so set them for minimum interruptions when typing
      return TAPPING_TERM + 40;
    case SPC_NUM:
      return TAPPING_TERM - 40;
    case BS_SFT:
      return TAPPING_TERM - 40;
    case E_NAV:
      return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _GAM:
      rgblight_enable();
      rgblight_setrgb (0x00,  0x55, 0x90);
      break;
    case _NUM:
      rgblight_enable();
      rgblight_setrgb (0x55,  0x7A, 0xFF);
      break;
    case _NAV:
      rgblight_enable();
      rgblight_setrgb (0x33,  0xFF, 0x00);
      break;
    case _MED:
      rgblight_enable();
      rgblight_setrgb (0x33,  0xAA, 0xFF);
      break;
    case _FUN:
      rgblight_enable();
      rgblight_setrgb (0x3A,  0x9A, 0x3A);
      break;
    case _PTR:
      rgblight_enable();
      rgblight_setrgb (0x00,  0xFF, 0x7A);
      break;                          
    default: 
      rgblight_disable();
      break;      
    }

  if (caps_is_active()) { 
    rgblight_enable();
    rgblight_setrgb (0xFF, 0xFF, 0xFF);
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_case_modes(keycode, record)) {
    return false;
  }

  switch (keycode) {

    // LOCK LAYERS

    case GAM_LCK:
      layer_on(_GAM);
      return false;

    case PTR_LCK:
      layer_on(_PTR);
      return false;

    case PAD_LCK:
      layer_on(_PAD);
      return false;

    // EXIT LAYERS

    case EXT_GAM:
      layer_off(_GAM);
      return false;    

    case EXT_PTR:
      layer_off(_PTR);
      return false;

    case EXT_PAD:
      layer_off(_PAD);
      return false;

    // 

    case CAP_WRD:        
      if (record->event.pressed) {
       enable_caps_word();
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
