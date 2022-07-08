#include QMK_KEYBOARD_H
#include "davidlee.h"
#include "features/casemodes.h"

#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

enum planck_layers {
  _CMK,  // Colemak-DH
  _GAM,  // Gaming / QWERTY
  _NAV,  // Navigation
  _NUM,  // Numbers 
  _PAD,  // Number Pad
  _MED,  // Media
  _EDT,  // Edit / Clipboard
  _FUN,  // Functions
  _PTR,  // Pointer
};

enum planck_keycodes {
  CAP_WRD = SAFE_RANGE,
  PTR_LCK,
  L_GAM,
  EXT_PTR,
  EXT_GAM,
  BS_WORD,
  ZERO_PT,
  EDT,
};

//
// custom keycodes
//

#define FN       KC_F24 // requires karabiner
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
#define ESC_EDT  LT(_EDT, KC_ESC)

// bottom row mods
#define ESC_OPT  LOPT_T(KC_ESC)
// #define TAB_CMD  RCMD_T(KC_TAB)
#define TAB_EDT  LT(_EDT, KC_TAB)
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

#define MICMUTE SCMD(KC_M)

#define PRV_DTP LCTL(KC_LEFT)
#define NXT_DTP LCTL(KC_RIGHT)
#define MSN_CTL LCTL(KC_UP)
#define APP_CTL LCTL(KC_DOWN)


#define EDT MO(_EDT)

//
// Combos
//

// N,U,I combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[] = {N_SHIFT, KC_U, I_OPT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(ptr_combo,  PTR_LCK),
};


//
// Keymap
//



/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  BS  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MicMut|DskTp-|DskTp+| Tab  | Spc  |   -  |   E  | BkSp | Enter|   ?? |MsnCtl|  Fn  | 
 * `-----------------------------------------------------------------------------------'
 *
 * Home Row Mods / Layers (hold behaviours)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      | Hyper|  Meh |  FUN |  PAD |      |      |      |      |  Meh | Hyper|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Cmd | Ctrl |  Opt |  Cmd | Shift|      |      |Shift |  Cmd |  Opt | Ctrl |  Cmd |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MicMut|      |      |  EDT |  NUM |  FUN |  NAV | Shift|  MED |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   [  |   ]  |      |      |   {  |   }  |   +  |   :  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsWd|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Spc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      | En – | Em — |   -  |   =  |      |   _  |   ,  |   .  |   \  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |CmdEsc|  ##  |      |      | Shift| Enter|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* SYM = Shift + NUM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   {  |   }  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   _  |   +  |      |      |   <  |   >  |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ##  |      |      |  ##  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* FUN 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |  Cut |  Copy| Paste|      |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|  GAM |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Brt- |  Brt+|      |      |      |      |  F1  |  F2  |  F3  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab | Spc  |  ##  |      | Bspc | Enter|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      | Undo |  Cut |  Copy| Paste| Paste|      | Back | Cmd -| Cmd =| Fwd  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Opt |  Cmd | Shift|      |      | Left | Down | Up   | Right| Spc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | Undo |  Cut |  Copy| Paste| Paste|      | Home | PGDN | PGUP | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab | Spc  |      |  ##  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PAD 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |  ##  |      |   /  |  7   |  8   |  9   |  0   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl |  Opt |  Cmd |      |      |   *  |  4   |  5   |  6   |  -   | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |   ,  |  1   |  2   |  3   |  +   | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Tab |  Spc |      |   .  | Bspc |  0   |  =   |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Play | Stop | Mute |MicMut|      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  ##  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* PTR (chord NUI)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | whL  |  mU  |  whR |  whU |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | Ctrl |  Opt |  Cmd | Shift|      | Exit | mL   |  mD  |  mR  |  whD | Exit |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b2  |  b1  |  b3  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* EDT 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo |  Cut |  Copy| Paste| Redo |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo |  Cut |  Copy| Paste| Redo |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

//======================================================================================

/* GAM (Qwerty)
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  BS  |
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
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  TAB_MEH, Q_HYP,   W_MEH,   F_FUN,   P_PAD,   KC_B,    KC_J,    KC_L,    KC_U,    Y_MEH,   SCLN_HYP,KC_DEL,
  ESC_CMD, A_CTRL,  R_OPT,   S_CMD,   T_SHIFT, KC_G,    KC_M,    N_SHIFT, E_CMD,   I_OPT,   O_CTRL,  CMD_QOT,
  FN_SFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
  KC_F16,  PRV_DTP, NXT_DTP, TAB_EDT, SPC_NUM, MIN_FUN, E_NAV,   BS_SFT,  ENT_MED, ZERO_PT, MSN_CTL, FN
),

[_NAV] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL ,CMD_RBRC,KC_BSPC,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SPC,
  KC_CAPS, UNDO,    CUT,     COPY,    PASTE,   PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  FN,      XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PLUS, KC_COLN, KC_BSPC,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC,
  KC_CAPS, XXXXXXX, EN_DASH, EM_DASH, KC_MINS, KC_EQL,  XXXXXXX, KC_UNDS, KC_COMM, KC_DOT,  KC_BSLS, _______,
  _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  RESET,   _______, CUT,     COPY,    PASTE,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, 
  ESC_CMD, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, L_GAM,   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, 
  XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_SPACE,_______, XXXXXXX, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX

),

[_PAD] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSPC,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
  _______, _______, _______, _______,  KC_SPC,  _______, KC_DOT,  KC_BSPC, KC_0,    KC_EQL,  _______, _______
),

[_MED] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_STOP, KC_F16,  KC_F16,  _______,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______ 
),

[_EDT] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
  _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______ 
),

[_PTR] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
  EXT_PTR, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, EXT_PTR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, EXT_PTR,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_TAB,  KC_SPACE,XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_GAM] = LAYOUT_planck_grid(
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
    case _EDT:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0xFF, 0x3A);
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

    case BS_WORD:        
      if (record->event.pressed) {
        tap_code16(LOPT(KC_BSPC));
      }
      return false;

    case ZERO_PT:        
      if (record->event.pressed) {
       // ...
       }
      return false;
    default:
      return true; /* Process all other keycodes normally */
  }
}
