#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

// set_unicode_input_mode(UC_OSX);

enum planck_layers {
  _CMK,  // Colemak-DH
  _NUM,  // Numbers
  _NAV,  // Navigation
  _MED,  // Media
  _FUN,  // Functions
  _PTR,  // Pointer
  _BTN,  // Buttons
  _GAM,  // Gaming / QWERTY
};

enum planck_keycodes {
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  EXT_PTR,
  EXT_GAM,
  L_GAM,
  // SHIFTY,
  BACKSPACE_WORD,
};

//
// custom keycodes
//

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
#define P_PTR    LT(_PTR, KC_P)

#define Y_MEH    MT(MOD_MEH, KC_Y)
#define SCLN_HYP MT(MOD_HYPR, KC_SCOLON)

// other mod-tap keys
#define Z_MED    LT(_MED, KC_Z)

// hold for mouse layer
#define W_PTR     LT(_PTR, KC_W)
#define QUO_PTR   LT(_PTR, KC_QUOTE)

// left side mods
#define GRV_MEH  MT(MOD_MEH, KC_GRAVE)
#define ESC_CMD  RCMD_T(KC_ESCAPE) // use RCMD here so that Cmd-T works
#define TAB_MEH  MT(MOD_MEH, KC_TAB)

// bottom row mods
#define SPC_NUM  LT(_NUM, KC_SPC)
#define BS_NAV   LT(_NAV, KC_BSPC)
#define SHIFTY   OSM(MOD_LSFT)

#define L_BTN    MO(_BTN)
#define L_FUN    MO(_FUN)

// right side mods
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
#define CMD_QOT  MT(MOD_LGUI, KC_QUOTE) // use LCMD here so that Cmd-N works

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

#define FN       KC_F24 // requires karabiner
#define XXXXXXX  KC_NO

//

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case R_OPT: 
      return TAPPING_TERM + 20;
    case I_OPT:
      return TAPPING_TERM + 20;
    case SPC_NUM:
      return TAPPING_TERM - 20;
    case BS_NAV:
      return TAPPING_TERM - 20;
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
      rgblight_setrgb (0xFF,  0x7A, 0x00);
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
    // prevent rolls from interfering with home row mods
    // adapted from https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation   

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

    case BACKSPACE_WORD:        
      if (record->event.pressed) {
        register_code(KC_LOPT);
        tap_code(KC_BSPC);
        unregister_code(KC_LOPT);
      }
      return false;

    default:
      return true; /* Process all other keycodes normally */

  }
}

//
// COMBOS
//

// N,U,I combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[] = {N_SHIFT, KC_U, I_OPT, COMBO_END};

// backspace whole word on N,E
const uint16_t PROGMEM bspc_combo[] = {N_SHIFT, E_CMD, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(ptr_combo, PTR_LCK),
    COMBO(bspc_combo, BACKSPACE_WORD),
};


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
 * |  Esc |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (   |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Tab  | Spc  |  FUN | Shift| BkSp | Enter|      |      |      | 
 * `-----------------------------------------------------------------------------------'
 *
 * Home Row Mods / Layers (hold behaviours)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | Hyper|  Meh |  FUN |  PTR |      |      |      |      |  Meh | Hyper|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  MED |      |      |      |      |      |      |      |      |      | Shift|                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  NUM |  FUN | Shift|  NAV |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |   )  |  1   |   2  |   3  |   4  |   5  |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl |  Opt |  Cmd | Shift|   _  |  [   |  4   |  5   |  6   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |CapWd | En – | Em — |   -  |   =  |  :   |  1   |  2   |  3   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ##  |      |  .   |  0   |      |      |      |      |
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
 * |      |      |      |  Tab | Spc  |      |      |  ##  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* FUN 
 * ,-----------------------------------------------------------------------------------.
 * | RESET| ScrLk| Pause|  ##  |  PTR |      |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|  GAM |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab |  Spc |      |      | Bspc |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |      | Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ##  |  Cut |  Copy| Paste|      | Power|      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab |  Spc |      | Stop | Play | Mute |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PTR
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Exit | LOCK |  ##  |      |      | whL  |  mU  |  whR |  whU |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | Ctrl |  Opt |  Cmd | Shift|      | Exit | mL   |  mD  |  mR  |  whD |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
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
 * |      |      |      |  Tab | Spc  |  ##  |      |      |      |      |      |      |
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
 * |      | Ctrl | Alt  | GUI  |  Spc |  EXIT| EXIT | Bspc | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_planck_grid(
  GRV_MEH, Q_HYP,   W_MEH,   F_FUN,   P_PTR,    KC_B,   KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,DEL_HYP,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT,  KC_G,   KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  KC_LSPO, Z_MED,   KC_X,    KC_C,    KC_D,     KC_V,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  _______, _______, _______, KC_TAB,  SPC_NUM,  L_FUN,  SHIFTY,  BS_NAV,  KC_ENTER,_______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
  KC_RPRN, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  FN,      KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_UNDS, KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, _______,
  KC_CAPS, CAP_WRD, EN_DASH, EM_DASH, KC_MINS, KC_EQL,  KC_COLN, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______, _______, XXXXXXX, _______, XXXXXXX, KC_PDOT, KC_0,    XXXXXXX, _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL ,CMD_RBRC,XXXXXXX,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENTER,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  RESET,   KC_SLCK, KC_PAUS, _______, PTR_LCK, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, L_GAM,   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, 
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, XXXXXXX, KC_BSPC, _______, _______, _______, _______

),

[_MED] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, CUT,     COPY,    PASTE,   XXXXXXX, KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_STOP, KC_MPLY, KC_MUTE, _______, _______, _______ 
),

[_PTR] = LAYOUT_planck_grid(
  XXXXXXX, XXXXXXX, EXT_PTR, PTR_LCK, _______, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, EXT_PTR,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_BTN] = LAYOUT_planck_grid(
  _______, KC_HYPR, KC_MEH,  KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCMD, KC_MEH,  KC_HYPR, _______,
  KC_LCMD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, FN,      FN,      KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, KC_RCMD,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, _______,
  _______, _______, _______, KC_TAB,  KC_SPACE,_______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______
),

[_GAM] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,EXT_GAM, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

};
