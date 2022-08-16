#include QMK_KEYBOARD_H

enum planck_layers {
  _CMK,   // Colemak-DH
  _NAV,   // Navigation
  _NUM,   // Numbers 
  _FUN,   // Function keys
  _GAM,   // Gaming / QWERTY
  _PTR,   // Pointer
  _MOD_L, // Modifiers Left
  _MOD_R, // Modifiers Right
};

enum planck_keycodes {
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

// alpha mod / layer taps
#define Z_MEH   MT(MOD_MEH, KC_Z)
#define D_MOD   LT(_MOD_L, KC_D)

#define H_MOD   LT(_MOD_R, KC_H)
#define SLS_MEH MT(MOD_MEH, KC_SLSH)

// home row mods 
#define A_CTL  MT(MOD_LCTL, KC_A)
#define R_OPT  MT(MOD_LALT, KC_R)
#define S_CMD  MT(MOD_LGUI, KC_S)
#define T_SFT  MT(MOD_LSFT, KC_T)
#define N_SFT  MT(MOD_RSFT, KC_N)
#define E_CMD  MT(MOD_RGUI, KC_E)
#define I_OPT  MT(MOD_LALT, KC_I)
#define O_CTL  MT(MOD_RCTL, KC_O)

// left side 
#define TAB_HYP  MT(MOD_HYPR, KC_TAB)
#define ESC_CTL  LCTL_T(KC_ESCAPE)
#define ENT_SFT  KC_SFTENT

// bottom row 
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define E_FUN    LT(_FUN, KC_E)

#define NAV      MO(_NAV) 
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)
#define ENT_PTR  LT(_PTR, KC_ENTER)


// right side 
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
#define QOT_CTL  MT(MOD_RCTL, KC_QUOTE)
// #define ENT_OPT  MT(MOD_LALT, KC_ENTER)

// clipboard
#define UNDO   LCMD(KC_Z)
#define REDO   SCMD(KC_Z)
#define CUT    LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE  LCMD(KC_V)

// misc
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)

  float layer_song[][2] = SONG(BLIP);
#endif

//
// Combos
//

// N,O combo turns on PTR layer
const uint16_t PROGMEM ptr_combo[]       = {SLS_MEH, I_OPT, COMBO_END};
// N,S is backspace word
const uint16_t PROGMEM bs_word_combo[]   = {N_SFT, E_CMD, COMBO_END};
// A,R is caps word
const uint16_t PROGMEM caps_word_combo[] = {A_CTL, R_OPT, COMBO_END};
// ESC, DEL is RESET
const uint16_t PROGMEM reset_combo[]     = {ESC_CTL, DEL_HYP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(ptr_combo,        PTR_LCK),
  COMBO(bs_word_combo,    BS_WORD),
  COMBO(caps_word_combo,  CAP_WRD),
  COMBO(reset_combo,      RESET),
};

//
// KEYMAP
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CMK] = LAYOUT_planck_grid(
  // KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BS_WORD, 
  TAB_HYP, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DEL_HYP,
  ESC_CTL, A_CTL,   R_OPT,   S_CMD,   T_SFT,   KC_G,    KC_M,    N_SFT,   E_CMD,   I_OPT,   O_CTL,   QOT_CTL,
  KC_LSFT, Z_MEH,   KC_X,    KC_C,    D_MOD,   KC_V,    KC_K,    H_MOD,   KC_COMM, KC_DOT,  SLS_MEH, ENT_SFT,
  FN,      KC_LCTL, KC_LOPT, CMD_TAB, SPC_NUM, E_FUN,   NAV,     BS_SFT,  ENT_PTR, _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
  // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TAB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, XXXXXXX, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_U,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
  KC_CAPS, UNDO,    CUT,     COPY,    KC_MPLY, PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_D,
  _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
  // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_AMPR, 
  SIRI,    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_0,    KC_PLUS,
  _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_COLN, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT,
  _______, _______, _______, EM_DASH, _______, _______, KC_0,    _______, KC_DOT,  _______, _______, _______
),

[_PTR] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, EXT_PTR,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
  _______, _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN3, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______
),

[_FUN] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,   KC_F18, KC_F19,  KC_F20,  _______,
  _______, _______, _______, GAM_LCK, _______, _______, _______, _______, _______, _______, _______, _______
),

[_GAM] = LAYOUT_planck_grid(
  // KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  EXT_GAM, EXT_GAM, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_MOD_L] = LAYOUT_planck_grid(
  _______, _______, PASTE,   FN,      _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, _______, _______, _______, _______, _______, _______,
  _______, UNDO,    CUT,     COPY,    _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_MOD_R] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_RSFT, KC_RCMD, KC_LOPT, KC_RCTL, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

//
// Function Overrides
//

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case D_MOD:
      case H_MOD:

      case A_CTL:
      case R_OPT:
      case S_CMD:
      case T_SFT:
      
      case N_SFT:
      case E_CMD:
      case I_OPT:
      case O_CTL:

      case SLS_MEH:
      case Z_MEH:
        return false; // Do not select the hold action when another key is tapped.
      default:
        return true; // Immediately select the hold action when another key is tapped.
      }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

      case A_CTL:
      case O_CTL:
        return TAPPING_TERM + 40;
      case R_OPT:
      case I_OPT:
        return TAPPING_TERM + 80;   
      case S_CMD:
      case E_CMD:
        return TAPPING_TERM + 0;
      case T_SFT:
      case N_SFT:
        return TAPPING_TERM + 40;
      
      case D_MOD:
      case H_MOD:
      case SLS_MEH:
      case Z_MEH:
        return TAPPING_TERM + 0;

      default:
        return TAPPING_TERM;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_enable();

  switch (get_highest_layer(state)) {
    case _NUM:
      rgblight_setrgb (0x55,  0x7A, 0xFF);
      break;

    case _NAV:
      rgblight_setrgb (0x77,  0xFF, 0x00);
      break;

    case _PTR:
      rgblight_setrgb (0x33,  0xFF, 0xAA);
      break;

    case _FUN:
      rgblight_setrgb (0x00,  0x00, 0xEE);
      break;

    case _GAM:
      rgblight_setrgb (0xFF,  0x00, 0x00);
      
      #ifdef AUDIO_ENABLE
        PLAY_SONG(layer_song);
      #endif
      
      break;

    case _MOD_L:
    case _MOD_R:
      rgblight_setrgb (0x33,  0x9A, 0xFF);
      #ifdef AUDIO_ENABLE
        PLAY_SONG(layer_song);
      #endif
      break;

    case _CMK:
    default: 
      rgblight_setrgb (0x00,  0x00, 0x00);      
      break;      
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
