#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

enum planck_layers {
  _CMK,  // Colemak-DH
  _GAM,  // Gaming / QWERTY
  _NUM,  // Numbers 
  _SYM,  // Symbols
  _PAD,  // Number Pad
  _NAV,  // Navigation
  _MED,  // Media
  _FUN,  // Functions
  _PTR,  // Pointer
};

enum planck_keycodes {
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  L_GAM,
  EXT_PTR,
  EXT_GAM,
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
#define P_PAD    LT(_PAD, KC_P)

#define Y_MEH    MT(MOD_MEH, KC_Y)
#define SCLN_HYP MT(MOD_HYPR, KC_SCOLON)

// other mod-tap keys
#define Z_MED    LT(_MED, KC_Z)

// left side mods
#define ESC_CMD  RCMD_T(KC_ESCAPE)

// bottom row mods
#define TAB_CMD  RCMD_T(KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define TAB_FUN  LT(_FUN, KC_TAB)

// #define SHIFTY   OSM(MOD_LSFT)
#define E_SYM    LT(_SYM, KC_E)
#define BS_NAV   LT(_NAV, KC_BSPC)
#define ENT_CMD  MT(MOD_RGUI, KC_ENTER)
#define ENT_SFT  KC_SFTENT

// right side mods
#define CMD_QOT  MT(MOD_RGUI, KC_QUOTE)

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

#define MICMUTE SCMD(KC_M)
//
// Combos
//

// N,U,I combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[] = {N_SHIFT, KC_U, I_OPT, COMBO_END};

// backspace whole word on N,E
const uint16_t PROGMEM bspc_combo[] = {N_SHIFT, E_CMD, COMBO_END};

// L,U combo → [
const uint16_t PROGMEM lbrc_combo[] = {KC_L, KC_U, COMBO_END};

// U,Y combo → ]
const uint16_t PROGMEM rbrc_combo[] = {KC_U, Y_MEH, COMBO_END};

// S,T combo → -
const uint16_t PROGMEM mins_combo[] = {S_CMD, T_SHIFT, COMBO_END};

// R,S combo → _
const uint16_t PROGMEM unds_combo[] = {R_OPT, S_CMD, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(ptr_combo,  PTR_LCK),
  COMBO(bspc_combo, BACKSPACE_WORD),
  COMBO(lbrc_combo, KC_LBRC),
  COMBO(rbrc_combo, KC_RBRC),
  COMBO(mins_combo, KC_MINUS),
  COMBO(unds_combo, KC_UNDERSCORE),
};


//
// Keymap
//

/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (   |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Tab  | Spc  |      |   E  | BkSp | Enter|      |      |      | 
 * `-----------------------------------------------------------------------------------'
 *
 * Home Row Mods / Layers (hold behaviours)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | Hyper|  Meh |  FUN |  PAD |      |      |      |      |  Meh | Hyper|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      | Shift|  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  MED |      |      |      |      |      |      |      |      |      | Shift|                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Opt |  Cmd |  NUM |  SYM | Shift|  NAV | Shift|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |  Fn  |      |      |      |      |      |      |   -  |   =  |   +  |   :  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapWrd| Caps |      |      |      |      |      |   _  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Esc |  ##  |      |  Spc | Bspc | Enter|      |      |      |
 * `-----------------------------------------------------------------------------------'

/* FUN 
 * ,-----------------------------------------------------------------------------------.
 * | RESET| ScrLk| Pause|  ##  |  PTR |      |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|  GAM |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab | Spc  |      |      | Bspc |  Cmd |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   !  |   @  |   #  |   $  |      |      |  -   |   =  |   +  |   :  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   <  |   {  |   [  |   (  |      |      |  )   |   ]  |   }  |   >  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   %  |   ^  |   &  |   *  |      |      |  _   | Em — | En – |   \  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  ##  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |CapWrd|      |      | Back | Cmd -| Cmd =| Fwd  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift| CAPS |      | Left | Down | Up   | Right| Spc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | Undo |  Cut |  Copy| Paste| Paste|      | Home | PGDN | PGUP | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab | Spc  |      |      |  ##  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PAD 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |  ##  |      |      |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  .   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |MicMut| Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ##  |      |      |      |      | Power|      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Stop | Play | Mute |      |      |      |
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

//======================================================================================

/* GAM (Qwerty)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |  Spc |  EXIT| EXIT | Bspc | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_planck_grid(
  KC_GRV,  Q_HYP,   W_MEH,   F_FUN,   P_PAD,    KC_B,   KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,KC_DEL,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT,  KC_G,   KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  KC_LSPO, Z_MED,   KC_X,    KC_C,    KC_D,     KC_V,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
  _______, _______, KC_LOPT, TAB_CMD, SPC_NUM,  TAB_FUN,E_SYM,   BS_NAV,  ENT_SFT, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
  FN,      _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_COLN, _______,
  KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  CAP_WRD, KC_CAPS, _______, _______, _______, _______, _______, KC_UNDS, KC_COMM, KC_DOT,  KC_BSLS, KC_ENTER,
  _______, _______, _______, KC_ESC,  _______, XXXXXXX, KC_SPC,  _______, _______, _______, _______, _______
),

[_SYM] = LAYOUT_planck_grid(
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_COLN, KC_BSPC,
  ESC_CMD, KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,   KC_PIPE,
  KC_LSFT, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_UNDS, EM_DASH, EN_DASH, KC_BSLS, ENT_SFT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_PAD] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_RBRC, KC_SPACE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_ENTER,
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_DOT,  _______, _______, _______
),


[_NAV] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL ,CMD_RBRC,KC_BSPC,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SPACE,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENTER,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  RESET,   KC_SLCK, KC_PAUS, _______, PTR_LCK, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, 
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, L_GAM,   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, 
  _______, _______, _______, TAB_CMD, KC_SPACE,XXXXXXX, XXXXXXX, KC_BSPC, _______, _______, _______, _______

),

[_MED] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MICMUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_STOP, KC_MPLY, KC_MUTE, _______, _______, _______ 
),

[_PTR] = LAYOUT_planck_grid(
  XXXXXXX, XXXXXXX, EXT_PTR, PTR_LCK, _______, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, EXT_PTR,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_GAM] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,_______, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

};

//
// Function Overrides
//

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case T_SHIFT:
    case N_SHIFT:
      return true;
    default:
     return false;
  }
}

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
      return TAPPING_TERM - 10;
    case N_SHIFT:
      return TAPPING_TERM - 10;
    case SPC_NUM:
      return TAPPING_TERM - 40;
    case BS_NAV:
      return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // state = update_tri_layer_state(state, _NUM, _NAV, _BTN);

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
