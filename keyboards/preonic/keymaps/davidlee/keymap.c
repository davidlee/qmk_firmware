#include QMK_KEYBOARD_H

#include "davidlee.h"
#include "features/casemodes.h"


enum userspace_layers {
  _COLEMAK,
  _QWERTY,
  _HOMEROWMODS,
  _NUMBER,
  _LOWER,
  _RAISE,
  _NAVS,
  _MOUSE,
  _ADJUST,
};

enum userspace_custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  HOMEROWMODS,
  LOWER,
  RAISE,
  NAV,
  NUMBER,
  MOUSE,
  K_RESET,
  HR_MODS,
  MINMASK
};

enum tapdance_keycodes {
    TD_SCLN,
    TD_QUOT,
    TD_SHFT,
    TD_DOT,
};

//
// keycode aliases for legibility
//
#define W_MOUS   LT(_MOUSE, KC_W)
#define TAB_LWR  LT(_LOWER, KC_TAB)
#define BS_RSE   LT(_RAISE, KC_BSPC)
#define SFT_NAV  LT(_NAVS,KC_LSFT)
#define OSL_RSE  OSL(_RAISE)

#ifdef TAP_DANCE_ENABLE
  #define SCLN     TD(TD_SCLN)
  #define QUOT     TD(TD_QUOT)
  #define SFT_LCK  TD(TD_SHFT)
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OPT_I:
      return TAPPING_TERM + 30;
    case CTRL_O:
      return TAPPING_TERM;
    case OPT_R: 
      return TAPPING_TERM + 30;
    case CMD_S:
      return TAPPING_TERM;
    case CMD_E:
      return TAPPING_TERM;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // turn on ADJUST when both LOWER and RAISE are active.
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  switch (get_highest_layer(state)) {
    case _NUMBER:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x7A, 0x00);
      break;
    case _LOWER:
      rgblight_enable();
      rgblight_setrgb (0xFF,  0x00, 0x00);
      break;
    case _RAISE:
      rgblight_enable();
      rgblight_setrgb (0x00,  0x00, 0xFF);        
      break;
    case _NAVS:      
      rgblight_enable();
      rgblight_setrgb (0x00,  0xFF, 0x00);
      break;
    case _MOUSE:
      rgblight_enable();
      rgblight_setrgb (0x00,  0xFF, 0x7A);
      break;                  
    case _ADJUST:
      rgblight_enable();
      rgblight_setrgb (0x7A,  0x00, 0xFF);
      break;
    default: 
      rgblight_disable();
      break;      
    }

  return state;
}

// Keymap
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  BS  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Fn    |      |      |  Esc | Spc  | Tab  | BkSp | Shift| Enter|   -  |   ?? | MENU |   << TAP
 * |Fn    | Ctrl | Opt  |  Cmd | NUM  | LWR  | RSE  | NAV  |      |      |      |      |   << HOLD
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  TAB_MEH, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SCLN,    DEL_HYP,
  ESC_CTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QUOT,
  SFT_LCK, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SFT_LCK,
  KC_ROPT, KC_LCTL, KC_LOPT, ESC_CMD, SPC_NUM, TAB_LWR, BS_RSE,  SFT_NAV, KC_ENT,  KC_MINS, OSL_RSE, KC_LEAD
),

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SCLN,    _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* HRM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Mouse|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Ctrl | Alt  | Cmd  | Shift|      |      |Shift | Alt  | Cmd  | Ctrl |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | rAlt |      |      |      |      |      | rAlt |      |      |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_HOMEROWMODS] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, W_MOUS,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, CTRL_A,  OPT_R,   CMD_S,   SHIFT_T, _______, _______, SHIFT_N, CMD_E,   OPT_I,   CTRL_O,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* PTR 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  b3  |      |  b2  |  b1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b1  |  mL  |  mDn |  mUp |  mR  |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  b3  |  b3  |  b2  |  b1  |      |  b2  | whL  | whDn |  whUp| whR  |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BTN3, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_ACL0, _______, KC_ACL2, KC_ACL1, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, KC_BTN3, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  *   |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | SHFT | NumLk|ScrLk | Paus |      |  /   |  1   |  2   |  3   |  =   | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  .   |  0   |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
  _______, SFT_LCK, KC_NLCK, KC_SLCK, KC_PAUS, _______, KC_PSLS, KC_1,    KC_2,    KC_3,    KC_PEQL, KC_PENT,
  _______, _______, _______, _______, _______, _______, KC_PDOT, KC_0,    _______, _______, _______, _______
),


// TODO separate FUN and MEDIA LAYERS 

/* LWR
 * ,-----------------------------------------------------------------------------------.
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  |      | Eject| Stop | Play |CMD-[ |CMD-] |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      |      | Shft | Cmd  | Opt  | Ctrl |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  |      | Prev | Next | Vol- | Vol+ | Mute |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, 
  _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, KC_EJCT, KC_STOP, KC_MPLY, CMD_LBRC,CMD_RBRC,_______, 
  _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______, 
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),

/* RSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   `  |   *  |   ^  |  "   |  '   | PGUP |   (  |   )  |   [  |   ]  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   $  |   @  |   #  |  !   |  ?   |  ––  |   -  |   =  |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   %  |   &  |  :   |  ;   | PGDN |   _  |   +  |   |  |   \  | Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, KC_GRV, KC_ASTR,  KC_CIRC, KC_DQUO, KC_QUOT, KC_PGUP, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,   
  _______, KC_DLR, KC_AT,    KC_HASH, KC_EXLM, KC_QUES, KC_MDASH,KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______, 
  _______, KC_TILD,KC_PERC,  KC_AMPR, KC_COLN, KC_SCLN, KC_PGDN, KC_UNDS, KC_PLUS, KC_PIPE, KC_BSLS, KC_ENTER, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Undo| Cut  | Copy | Paste|      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |PLY M1|PLY M2|      |  INS |  Left| Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CAPS  |RecStp|      |REC M1|REC M2|      |      |  HOME| PGDN | PGUP | END  | CAPS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | SPC  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
                    */
[_NAVS]= LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, UNDO,    CUT,     COPY,    PASTE,   _______,
  _______, _______, _______, DM_PLY1, DM_PLY2, _______, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  KC_CAPS, DM_RSTP, _______, DM_REC1, DM_REC2, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
  _______, _______, _______, _______, KC_SPACE,_______, _______, _______, _______, _______, _______, _______
),

/* ADJ
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Qwerty|      |      |      |      |      |      |      |      |      |      |  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |      | Mask |      |      |      |      |Leader|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |HRMods|Colemk|      |      |      |      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  K_RESET, _______, _______, _______, _______, _______, MINMASK, _______, _______, _______, _______, KC_LEAD, 
  _______, _______, HR_MODS, COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),

};

//
// process record
//

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_case_modes(keycode, record)) {
      return false;
  }

  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        startup_user();
      }
      return false;
      break; 
    case QWERTY:
      if (record->event.pressed) {
        layer_clear();
        // need COLEMAK on for mods, etc.
        set_single_persistent_default_layer(_COLEMAK);
        layer_on(_QWERTY);
      }
      return false;
      break;       
    case HR_MODS:
      if (record->event.pressed) {
        layer_invert(_HOMEROWMODS);
      }
      return false;
      break;       
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      }     
      return false;
      break; 
    case K_RESET:
      if (record->event.pressed) {
        reset_keyboard();
      }     
      return false;
      break;                          
  }
  return true;
};

//
// musics
//

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(NO_SOUND); 
#endif

void matrix_init_user(void) {
  startup_user();
}

void startup_user()
{
  layer_clear();
  set_single_persistent_default_layer(_COLEMAK);
  layer_on(_HOMEROWMODS); 

  #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_startup);
  #endif
}

//
// Leader Key
//

LEADER_EXTERNS();

bool leader_found;
#ifdef AUDIO_ENABLE
float leader_succeed_song[][2] = SONG(CAPS_LOCK_ON_SOUND);
float leader_fail_song[][2]    = SONG(CAPS_LOCK_OFF_SOUND);
#endif

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading      = false;
    leader_found = false;
    
    // Q — RESET 
    SEQ_ONE_KEY(KC_Q) {
      reset_keyboard();
      leader_found = true;
    }

    
    leader_end();
  }    
}

void leader_end(void) {
  if (leader_found) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
  startup_user();   
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif  
  }
}

//
// tap dances
//

// https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance#complex-examples-id-complex-examples

#ifdef AUDIO_ENABLE
float caps_lock_on_sound[][2]  = SONG(CAPS_LOCK_ON_SOUND);
float caps_lock_off_sound[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif

td_state_t cur_dance(qk_tap_dance_state_t *state);

void td_shft_finished(qk_tap_dance_state_t *state, void *user_data);
void td_shft_reset(qk_tap_dance_state_t *state, void *user_data);


td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
      if (state->interrupted || !state->pressed) 
        return TD_SINGLE_TAP;
      else 
        return TD_SINGLE_HOLD;

    } else if (state->count == 2) {
        if (state->interrupted) 
          return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) 
          return TD_DOUBLE_HOLD;
        else 
          return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
          return TD_TRIPLE_TAP;
        else 
          return TD_TRIPLE_HOLD;
    } else 
      return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'shift' tap dance.
static td_tap_t shft_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


// shift - tap for one shot, double tap to caps word, triple for caps lock
// 
void td_shft_finished(qk_tap_dance_state_t *state, void *user_data) {
    shft_tap_state.state = cur_dance(state);
    switch (shft_tap_state.state) {

      case TD_SINGLE_TAP: 
        set_oneshot_mods(MOD_LSFT);
        break;

      case TD_SINGLE_HOLD: 
        register_code(KC_LSFT);         
        break;

      case TD_DOUBLE_TAP: 
      case TD_DOUBLE_SINGLE_TAP: 
        enable_caps_word();
        break;

      case TD_DOUBLE_HOLD: 
      case TD_TRIPLE_TAP:
        #ifdef AUDIO_ENABLE
          PLAY_SONG(caps_lock_on_sound); 
        #endif
        tap_code(KC_CAPS);
        break;

      case TD_UNKNOWN: 
      case TD_NONE: 
      case TD_TRIPLE_HOLD:
        break;
    }
}

void td_shft_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shft_tap_state.state) {
      case TD_SINGLE_TAP: 
        disable_caps_word();
        break;

      case TD_SINGLE_HOLD: 
      case TD_DOUBLE_HOLD: 
        unregister_code(KC_LSFT);
        disable_caps_word();
        break;

      case TD_DOUBLE_TAP: 
      case TD_DOUBLE_SINGLE_TAP:
      case TD_TRIPLE_TAP: 
      case TD_TRIPLE_HOLD: 
        unregister_code(KC_LSFT);
        break;

      case TD_UNKNOWN: 
      case TD_NONE: 
        break;
  }
  shft_tap_state.state = TD_NONE;
}

// All tap dance functions 
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_shft_finished, td_shft_reset)
};


