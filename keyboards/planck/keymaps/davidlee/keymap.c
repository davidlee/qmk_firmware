#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

// set_unicode_input_mode(UC_OSX);

enum planck_layers {
  _CMK,  // Colemak-DH
  _GAM,  // Gaming / QWERTY
  _QTY,  // QWERTY
  _NUM,  // Numbers
  _SYM,  // Symbols
  _NAV,  // Navigation
  _MED,  // Media
  _FUN,  // Functions
  _PTR,  // Pointer
  _BTN,  // Buttons
  _ADJ,  // Adjust
};

enum planck_keycodes {
  MISNCTRL = SAFE_RANGE, // MISSION CONTROL
  LNCHPAD,               // LAUNCH PAD
  DND,                   // DO NOT DISTURB
  DICTATE,               // DICTATION
  CAP_WRD,
  BS_WORD,
  PTR_LCK,
  EXT_PTR,
  EXT_GAM,
  MIC_TGL,
  L_GAM,
  L_NUM
};

#define GRV_MEH  MT(MOD_MEH, KC_GRAVE)
#define SHIFT    OSM(MOD_LSFT) 
#define _noop__  KC_NO 
#define L_NAV    MO(_NAV)
#define BTN_BS   LT(_BTN,LCMD(KC_BSPC))

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTRL_O:
      return TAPPING_TERM;
    case CTRL_A:
      return TAPPING_TERM;
    case OPT_R: 
      return TAPPING_TERM + 20;
    case OPT_I:
      return TAPPING_TERM + 20;
    case CMD_S:
      return TAPPING_TERM - 10;
    case CMD_E:
      return TAPPING_TERM - 10;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // turn on ADJUST when both of these layers are active.
  state = update_tri_layer_state(state, _SYM, _NAV, _ADJ);

  switch (get_highest_layer(state)) {
    case _GAM:
      rgblight_enable();
      rgblight_setrgb (0x00,  0x55, 0x90);
      break;
    case _NUM:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x7A, 0x00);
      break;
    case _SYM:
      rgblight_enable();
      rgblight_setrgb (0x00,  0x00, 0xFF);        
      break;
    case _NAV:
      rgblight_enable();
      rgblight_setrgb (0x00,  0xFF, 0x00);
      break;
    case _MED:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x00, 0x00);
      break;
    case _FUN:
      rgblight_enable();
      rgblight_setrgb (0x7A,  0x55, 0x00);
      break;
    case _PTR:
      rgblight_enable();
      rgblight_setrgb (0x00,  0xFF, 0x7A);
      break;                  
    case _ADJ:
      rgblight_enable();
      rgblight_setrgb (0x7A,  0x00, 0xFF);
      break;
    default: 
      rgblight_disable();
      break;      
    }

  if (caps_is_active()) { //  FIXME unreliable. Toggling a layer while engaged turns lights off.
    rgblight_enable();
    rgblight_setrgb (0xFF, 0xFF, 0xFF);
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case MISNCTRL:
      if (record->event.pressed) {
        host_consumer_send(0x29F);
      } else { 
        host_consumer_send(0);
      }
      return false;

    case LNCHPAD:
      if (record->event.pressed) {
        host_consumer_send(0x2A0);
      } else {
        host_consumer_send(0);
      }
      return false;

    case DND:
      if (record->event.pressed) {
        host_consumer_send(0x9B);
      } else {
        host_consumer_send(0);
      }
      return false;

    case L_GAM: 
      layer_on(_GAM);
      return false;

    case PTR_LCK: //  TODO FIXME 
      //layer_on(_PTR);
      return false;

    case EXT_PTR:
      layer_off(_PTR);
      return false;

    case EXT_GAM:
      layer_off(_GAM);
      return false;

    case KC_CAPS:        
      return true; // process normal behaviour      

    case CAP_WRD:        
      if (record->event.pressed) {
       // enable_caps_word();
      } else {
        enable_caps_word();
      }
      return false;   

    case BS_WORD:        
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LOPT) SS_TAP(X_BSPACE));
      } else { 
        SEND_STRING(SS_UP(X_LOPT));
      }
      return false;   

    default:
      return true; /* Process all other keycodes normally */

  }
}

/* BLANK 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


// Keymap


/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl | Opt  |  Esc | Spc  | Tab  | Bspc | BkSp | Enter|   [  |   ]  | Menu | 
 * `-----------------------------------------------------------------------------------'
 */

 /* Home Row Mods / Layers (hold behaviours)
 * ,-----------------------------------------------------------------------------------.
 * | Meh  |      | Mouse| Fun  |      |      |      |      |      |      |      | Hyper|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Cmd  | Ctrl | Opt  |      | Shift|      |      | Shift| Opt  |      | Ctrl | Cmd  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Media|      |      |      |      |      |      |      |      | Media|      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd |  Num |  Sym | Btn  |  Nav | Cmd  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* GAM (Qwerty)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |  Spc |  Num | EXIT | Bspc | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  [   |  7   |  8   |  9   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|   '  |  (   |  4   |  5   |  6   |  )   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |CapWrd| En – | Em — |   -  |   =  |  `   |  1   |  2   |  3   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ##  |      |  .   |  0   |  Cmd |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* SYM 
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |      |      |      |      |      |   {  |  &   |  *   |  (   |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl |  Opt |  Cmd | Shift|   "  |   <  |  $   |  %   |  ^   |   >  |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |      |      |   _  |   +  |   ~  |  !   |  @   |  #   |  |   |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  ##  |   (  |  )   |  Cmd |  [   |   ]  |      |
 * `-----------------------------------------------------------------------------------'
 */


/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  Ins |  Del |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |      |  Left| Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | Undo |  Cut |  Copy| Paste| Paste|      |  Home| PGDN | PGUP | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd | Spc  |  Tab |      |  ##  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PTR
 * ,-----------------------------------------------------------------------------------.
 * |      | Exit |  ##  | LOCK |      |      | Exit |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | Ctrl |  Opt |  Cmd | Shift|      | Lock | mL   |  mD  |  mU  |  mR  |  ##  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      | Exit | whL  |  whD |  whD | whR  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b2  |  b1  |  b3  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


/* FUN 
 * ,-----------------------------------------------------------------------------------.
 * | RESET| ScrLk| Pause|  ##  |CapWrd|      |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift| Game |  DnD |  F4  |  F5  |  F6  |  F11 |MisCtl|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |LchPad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd |  Spc | Tab  |      | Bspc |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Cmd [| Cmd -| Cmd =| Cmd ]|      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |MicTgl| Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ##  |  Cut |  Copy| Paste|      | Power|      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Stop | Play | Mute |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* BTN 
 * ,-----------------------------------------------------------------------------------.
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Tab  |  Spc |  ##  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* ADJ 
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | GAM  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_planck_grid(
  GRV_MEH, KC_Q,    W_PTR,   F_FUN,   KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP,
  ESC_CMD, CTRL_A,  OPT_R,   KC_S,    SHIFT_T, KC_G,    KC_M,    SHIFT_N, KC_E,    OPT_I,   CTRL_O,  CMD_QOT,
  SHIFT,   Z_MED,   KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  SLS_MED, SHIFT,
  KC_ROPT, KC_LCTL, KC_LOPT, ESC_CMD, SPC_NUM, TAB_SYM, BTN_BS,  BS_NAV,  ENT_CMD, KC_LBRC, KC_RBRC, KC_LEAD
),

[_GAM] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  L_NUM,   EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_NUM] = LAYOUT_planck_grid(
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_QUOT, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_RPRN, _______,
  KC_CAPS, CAP_WRD, EN_DASH, EM_DASH, KC_MINS, KC_EQL,  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______, _______, _noop__, _______, _noop__, KC_PDOT, KC_0,    KC_RCMD, _______, _______, _______
),

[_SYM] = LAYOUT_planck_grid(
  KC_TILD, _noop__, _noop__, _noop__, _noop__, _noop__, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,
  KC_ROPT, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DQUO, KC_LT,   KC_DLR,  KC_PERC, KC_CIRC, KC_GT,   _______,
  KC_CAPS, _noop__, _noop__, _noop__, KC_UNDS, KC_PLUS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,
  _______, _______, _______, _noop__, _noop__, _______, KC_LPRN, KC_RPRN, KC_RCMD, KC_LBRC, KC_RBRC, _______
),

[_NAV] = LAYOUT_planck_grid(
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, KC_INS,  KC_DEL,  _noop__, _noop__, _______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _noop__,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _noop__, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENTER,
  _______, _______, _______, KC_LCMD, KC_SPACE,KC_TAB,  _noop__, _______, _noop__, _______, _______, _______
),

[_PTR] = LAYOUT_planck_grid(
  _noop__, _noop__, _______, PTR_LCK, _noop__, _noop__, EXT_PTR, _noop__, _noop__, _noop__, _noop__, _noop__,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, PTR_LCK, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  KC_LSFT, _noop__, _noop__, _noop__, _noop__, _noop__, EXT_PTR, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _noop__,
  _______, _______, _______, _noop__, _noop__, _noop__, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  RESET,   KC_SLCK, KC_PAUS, _______, CAP_WRD, _noop__, _noop__, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, L_GAM,    DND,    KC_F4,   KC_F5,   KC_F6,   KC_F11,  MISNCTRL, 
  KC_CAPS, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, KC_F1,   KC_F2,   KC_F3,   KC_F10,  LNCHPAD, 
  _______, _______, _______, KC_LCMD, KC_SPC,  KC_TAB,  _noop__, KC_BSPC, _______, _______, _______, _______

),

[_MED] = LAYOUT_planck_grid(
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, CMD_LBRC,CMD_MINS,CMD_PLUS,CMD_RBRC,_______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, MIC_TGL, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, CUT,     COPY,    PASTE,   _noop__, KC_PWR,  _noop__, _noop__, _noop__, _______, _______,
  _______, _______, _______, _noop__, _noop__, _noop__, KC_STOP, KC_MPLY, KC_MUTE, _______, _______, _______ 
),

[_BTN] = LAYOUT_planck_grid(
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, _______,
  KC_LCMD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, KC_RCMD,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, _______,
  _______, _______, _______, _______, KC_TAB,  KC_SPACE,_noop__, _noop__, _______, _______, _______, _______
),

[_ADJ] = LAYOUT_planck_grid(
  _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, L_GAM,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};
