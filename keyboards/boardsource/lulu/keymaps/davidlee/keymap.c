#include QMK_KEYBOARD_H
#include "davidlee.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CMK] = LAYOUT(
// COLEMAK
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
TAB_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP,
ESC_MEH, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QOT_MEH,
KC_LSFT, Z_CTL,   X_OPT,   C_CMD,   KC_D,    KC_V,    XXXXXXX, XXXXXXX, KC_K,    KC_H,    COM_CMD, DOT_OPT, SLS_CTL, ENT_SFT,
                           FN,      CMD_TAB, SPC_NUM, E_FUN,   NAV,     BS_SFT,  ENT_MED, _______
  ),

  [_HRM] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, A_CTL,   R_OPT,   S_CMD,   T_SFT,   _______,                   _______, N_SFT,   E_CMD,   I_OPT,   O_CTL,   _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
KC_TAB,  _______, _______, _______, _______, _______,                   KC_WH_U, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_U,
KC_ESC,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______,                   KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _______, _______, KC_WH_D, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_D,
                           _______, KC_TAB,  KC_SPC,  MO_PTR,  _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_LPRN,                   KC_RPRN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_AMPR,
SIRI,    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LBRC,                   KC_RBRC, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS,
_______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______, _______, KC_COLN, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT,
                           _______, EM_DASH, _______, _______, KC_0,    _______, KC_DOT,  _______
  ),

  [_FUN] = LAYOUT(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
FN,      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    _______, KC_LSFT, KC_RGUI, KC_RALT, KC_RCTL, FN,
KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _______, _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
                           GAM_LCK, _______, _______, _______, MO_PTR,  _______, _______, _______
  ),

  [_MED] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
KC_TAB,  _______, _______, KC_MSTP, KC_MPLY, _______,                   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
FN,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,                   _______, KC_LSFT, KC_RGUI, KC_RALT, KC_RCTL, FN,
_______, DM_REC1, DM_REC2, DM_PLY2, DM_PLY1, DM_RSTP, _______, _______, _______, KC_MPLY, _______, _______, _______, _______,
                           _______, MO_PTR,  _______, _______, _______, _______, _______, _______
  ),

  [_GAM] = LAYOUT(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LGUI,
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                           E_FUN,   KC_LALT, KC_SPC,  KC_LCTL, NAV,     KC_BSPC, KC_ENT,  EXT_GAM
  ),

  [_PTR] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, EXT_PTR,
_______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
_______, UNDO,    CUT,     COPY,    PASTE,   PASTE,   PASTE,   XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______,
                           _______, KC_SPC,  _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, EXT_PTR
  ),

};
