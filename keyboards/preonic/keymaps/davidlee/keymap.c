#include QMK_KEYBOARD_H
#include "davidlee.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BS_WORD, 
  TAB_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP,
  ESC_CTL, A_CTL,   R_OPT,   S_CMD,   T_SFT,   KC_G,    KC_M,    N_SFT,   E_CMD,   I_OPT,   O_CTL,   QOT_CTL,
  KC_LSFT, Z_MEH,   KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  SLS_MEH, ENT_SFT,
  FN,      KC_LCTL, KC_LOPT, CMD_TAB, SPC_NUM, E_FUN,   NAV,     BS_SFT,  ENT_PTR, _______, _______, _______
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TAB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_U,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_MPLY, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_D,
  _______, _______, _______, KC_TAB,  KC_SPC,  XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_AMPR, 
  SIRI,    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS,
  _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_COLN, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT,
  _______, _______, _______, EM_DASH, XXXXXXX, _______, KC_0,    _______, KC_DOT,  _______, _______, _______
),


[_FUN] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  FN,      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  FN,
  _______, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _______, _______, DT_DOWN, DT_UP,   DT_PRNT, _______,
  _______, _______, _______, GAM_LCK, _______, XXXXXXX, _______, _______, _______, _______, _______, _______
),

[_GAM] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  EXT_GAM, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_PTR] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, EXT_PTR,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
  _______, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______,
  _______, _______, _______, _______, KC_SPC,  _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

};


