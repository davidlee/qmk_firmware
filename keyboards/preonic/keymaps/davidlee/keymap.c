#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

enum preonic_layers {
  _CMK,  // Colemak-DH
  _TYP,  // Typing, no home row mods
  _GAM,  // Gaming / QWERTY
  _NAV,  // Navigation
  _NUM,  // Numbers 
  _PAD,  // Number Pad
  _FUN,  // Functions
  _PTR,  // Pointer
};

enum preonic_keycodes {
  CAP_WRD = SAFE_RANGE,
  TYP_LCK,
  PTR_LCK,
  PAD_LCK,
  GAM_LCK,
  EXT_PTR,
  EXT_GAM,
  EXT_PAD,
  EXT_TYP,
  BS_WORD,
  ZERO_PT,
};

//
// custom keycodes
//

#define FN       KC_F24
#define MICMUTE  KC_F23
#define SIRI     KC_F21

#define PTR      LT(_PTR, KC_F20)

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
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)

#define SPC_NUM  LT(_NUM, KC_SPC)
#define MIN_FUN  LT(_FUN, KC_MINS)

#define E_NAV    LT(_NAV, KC_E)
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)

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

#define PREV_DT LCTL(KC_LEFT)
#define NEXT_DT LCTL(KC_RIGHT)
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
  KC_TAB,  Q_HYP,   W_MEH,   KC_F,    P_PAD,   KC_B,    KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,KC_DEL,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT, KC_G,    KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  FN_SFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
  PTR,     KC_LCTL, KC_LOPT, CMD_TAB, SPC_NUM, MIN_FUN, E_NAV,   BS_SFT,  KC_ENT,  KC_F20,  SIRI,    FN
),

[_TYP] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_Q,   KC_W,     _______, _______, _______, _______, _______, _______, KC_Y,    KC_SCLN, _______,
  _______, KC_A,   KC_R,     KC_S,    KC_T,    _______, _______, KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
  _______, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PLUS, KC_COLN, KC_BSPC,
  CAP_WRD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC,
  KC_CAPS, EM_DASH, KC_MINS, KC_EQL,  KC_UNDS, KC_HASH, KC_GRV,  KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH, _______,
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
  _______, KC_MSEL, KC_MUTE, KC_MSTP, KC_MPLY, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, GAM_LCK, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, 
  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, 
  EXT_TYP, XXXXXXX, XXXXXXX, KC_TAB,  KC_SPACE,_______, XXXXXXX, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, TYP_LCK

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

#define ALPHA_MOD_TAP_ADJUSTMENT 20;
#define THUMB_KEY_TAP_ADJUSTMENT 40;


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case Q_HYP:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case W_MEH:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    
    case Y_MEH:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case SCLN_HYP:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    
    case A_CTRL:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case R_OPT: 
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case S_CMD: 
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case T_SHIFT: 
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT; 

    case N_SHIFT:               
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case E_CMD:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case I_OPT:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;
    case O_CTRL:
      return TAPPING_TERM + ALPHA_MOD_TAP_ADJUSTMENT;

    
    case SPC_NUM:
      return TAPPING_TERM - THUMB_KEY_TAP_ADJUSTMENT;
    case BS_SFT:
      return TAPPING_TERM - THUMB_KEY_TAP_ADJUSTMENT;
    case E_NAV:
      return TAPPING_TERM - THUMB_KEY_TAP_ADJUSTMENT;
    
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_CMD:
        case FN_SFT:
        case ENT_SFT:
        case E_NAV:
        case SPC_NUM: // unsure
        case BS_SFT:
        case CMD_QOT:
          // Immediately select the hold action when another key is tapped.
          return true;
        default:
          // Do not select the hold action when another key is tapped.
         return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _NUM:
      rgblight_enable();
      rgblight_setrgb (0x55,  0x7A, 0xFF);
      break;
    case _FUN:
      rgblight_enable();
      rgblight_setrgb (0x3A,  0x9A, 0x3A);
      break;
    case _NAV:
      rgblight_enable();
      rgblight_setrgb (0x99,  0xFF, 0x00);
      break;
    case _PAD:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0xAA, 0xFF);
      break;
    case _PTR:
      rgblight_enable();
      rgblight_setrgb (0x99,  0xFF, 0xAA);
      break;                          
    case _GAM:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x00, 0x00);
      break;
    case _TYP:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x33, 0xFF);
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

    case TYP_LCK:
      layer_on(_TYP);
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

    case EXT_TYP:
      layer_off(_TYP);
      return false;

    // other functions

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
