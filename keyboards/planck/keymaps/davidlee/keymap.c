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
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  EXT_PTR,
  EXT_GAM,
  MIC_TGL,
  L_GAM,
  L_NUM
};


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

// other mod-tap keys
#define Z_MED    LT(_MED, KC_Z)
#define SLS_MED  LT(_MED, KC_SLSH)
#define F_FUN    LT(_FUN, KC_F)

// hold for mouse layer
#define W_PTR     LT(_PTR, KC_W)
#define QUO_PTR   LT(_PTR, KC_QUOTE)

// left side mods
#define ESC_CTL  LCTL_T(KC_ESC)
#define TAB_MEH  MT(MOD_MEH, KC_TAB)

// bottom row mods
#define ESC_CMD  LCMD_T(KC_ESCAPE)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define TAB_SYM  LT(_SYM, KC_TAB)

#define BS_NAV   LT(_NAV, KC_BSPC)
#define ENT_CMD  MT(MOD_LGUI, KC_ENTER)

// right side mods
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
#define CMD_QOT  MT(MOD_LGUI, KC_QUOTE)

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
#define CMD_PLUS LCMD(KC_PLUS)

#define GRV_MEH  MT(MOD_MEH, KC_GRAVE)
#define OS_SFT   OSM(MOD_LSFT) 
#define _noop__  KC_NO 

#define BTN_BS   LT(_BTN,LALT(KC_BSPC))
#define FN       KC_ROPT // requires karabiner

#define Q_HYP    MT(MOD_HYPR, KC_Q)
#define W_MEH    MT(MOD_MEH, KC_W)

#define G_FN     MT(MOD_RALT, KC_G)
#define M_FN     MT(MOD_RALT, KC_M)

#define N_CMD    MT(MOD_RGUI, KC_N)
#define Y_MEH    MT(MOD_MEH, KC_Y)
#define SCLN_HYP MT(MOD_HYPR, KC_SCOLON)

#define P_PTR    LT(_PTR, KC_P)
#define D_FUN    LT(_FUN, KC_D)


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

  if (caps_is_active()) { 
    rgblight_enable();
    rgblight_setrgb (0xFF, 0xFF, 0xFF);
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process case modes
  if (!process_case_modes(keycode, record)) {
    return false;
  }

  switch (keycode) {
    // prevent rolls from interfering with home row mods
    // adapted from https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation   
    //
    case RSFT_T(KC_N): 
      if (record->tap.count == 1 && record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_RCMD)) {
          unregister_mods(MOD_BIT(KC_RCMD));
          tap_code(KC_E);
          tap_code(KC_N);
          add_mods(MOD_BIT(KC_RCMD));
          return false;
        }
      }
      return true;

    case LSFT_T(KC_T): 
      if (record->tap.count == 1 && record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LCMD)) {
          unregister_mods(MOD_BIT(KC_LCMD));
          tap_code(KC_S);
          tap_code(KC_T);
          add_mods(MOD_BIT(KC_LCMD));
          return false;
        }
        // this is problematic because we're reserving ROPT for Fn
        // we could use say F24 instead, but then we couldn't use mod-tap for it

        // if (get_mods() & MOD_BIT(KC_LOPT)) {
        //   unregister_mods(MOD_BIT(KC_LOPT));
        //   tap_code(KC_R);
        //   tap_code(KC_S);
        //   add_mods(MOD_BIT(KC_LOPT));
        //   return false;
        // }        
      }
      return true;

    case L_GAM: 
      layer_on(_GAM);
      return false;

    case PTR_LCK:
      layer_on(_PTR);
      return false;

    case EXT_PTR:
      layer_off(_PTR);
      return false;

    case EXT_GAM:
      layer_off(_GAM);
      return false;

    case CAP_WRD:        
      if (record->event.pressed) {
       enable_caps_word();
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
 * |      |      |      |  Esc | Spc  | Tab  |Shiƒt | BkSp | Enter|      |      |      | 
 * `-----------------------------------------------------------------------------------'
 *
 * Home Row Mods / Layers (hold behaviours)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | Hyper|  Meh |      |  PTR |      |      |      |      |  Meh | Hyper|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|  Fn  |  Fn  | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  MED |      |      |  FUN |      |      |      |      |      |  MED |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd |  NUM |      |  BTN |  NAV |  Cmd |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |  `   |  1   |   2  |   3  |   4  |   5  |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl |  Opt |  Cmd | Shift|   '  |  [   |  4   |  5   |  6   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |CapWd | En – | Em — |   -  |   =  |  ;   |  1   |  2   |  3   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ##  |      |      |      |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Back | Cmd -| Cmd =| Fwd  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |      | Left | Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | Undo |  Cut |  Copy| Paste| Paste|      | Home | PGDN | PGUP | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd | Spc  |  Tab |      |  ##  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* FUN 
 * ,-----------------------------------------------------------------------------------.
 * | RESET| ScrLk| Pause|      |      |      |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift| Game |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ##  |      |      |  F1  |  F2  |  F3  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Cmd |  Spc | Tab  |      | Bspc |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |MicTgl| Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ##  |  Cut |  Copy| Paste|      | Power|      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Stop | Play | Mute |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PTR
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Exit | LOCK |  ##  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | Ctrl |  Opt |  Cmd | Shift|      | Exit | mL   |  mD  |  mU  |  mR  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      | whL  |  whD |  whD | whR  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b2  |  b1  |  b3  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* BTN 
 * ,-----------------------------------------------------------------------------------.
 * |      | Hyper|  Meh |  Cmd | Shift|      |      | Shift|  Cmd |  Meh | Hyper|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|  Fn  |  Fn  | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Tab  |  Spc |  ##  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

//======================================================================================

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_planck_grid(
  GRV_MEH, Q_HYP,   W_MEH,   KC_F,    P_PTR,    KC_B,    KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,DEL_HYP,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT,  KC_G,    KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  KC_LSFT, Z_MED,   KC_X,    KC_C,    D_FUN,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  SLS_MED, KC_RSFT,
  _noop__, _noop__, _noop__, ESC_CMD, SPC_NUM,  TAB_SYM, OS_SFT,  BS_NAV,  ENT_CMD, _noop__, _noop__, _noop__
),

[_NUM] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  FN,      KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_QUOT, KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, _______,
  KC_CAPS, CAP_WRD, EN_DASH, EM_DASH, KC_MINS, KC_EQL,  KC_SCLN, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______, _______, _noop__, _______, _noop__, KC_PDOT, KC_0,    KC_RCMD, _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, CMD_LBRC,CMD_MINS,CMD_PLUS,CMD_RBRC,_noop__,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _noop__,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   _noop__, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENTER,
  _______, _______, _______, KC_LCMD, KC_SPACE,KC_TAB,  _noop__, _______, _noop__, _______, _______, _______
),

[_PTR] = LAYOUT_planck_grid(
  _noop__, _noop__, EXT_PTR, PTR_LCK, _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  KC_LSFT, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _noop__,
  _______, _______, _______, _noop__, _noop__, _noop__, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  RESET,   KC_SLCK, KC_PAUS, _______, PTR_LCK, _noop__, _noop__, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, L_GAM,   _noop__, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, 
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, 
  _______, _______, _______, KC_LCMD, KC_SPC,  KC_TAB,  _noop__, KC_BSPC, _______, _______, _______, _______

),

[_MED] = LAYOUT_planck_grid(
  _______, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _noop__, _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, MIC_TGL, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, CUT,     COPY,    PASTE,   _noop__, KC_PWR,  _noop__, _noop__, _noop__, _______, _______,
  _______, _______, _______, _noop__, _noop__, _noop__, KC_STOP, KC_MPLY, KC_MUTE, _______, _______, _______ 
),

[_BTN] = LAYOUT_planck_grid(
  _______, KC_HYPR, KC_MEH,  KC_LCMD, KC_LSFT, _noop__, _noop__, KC_RSFT, KC_RCMD, KC_MEH,  KC_HYPR, _______,
  KC_LCMD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, FN,      FN,      KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, KC_RCMD,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _noop__, _noop__, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, _______,
  _______, _______, _______, _______, KC_TAB,  KC_SPACE,_______, _noop__, _noop__, _______, _______, _______
),

[_GAM] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  L_NUM,   EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

};
