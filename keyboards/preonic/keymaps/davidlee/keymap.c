#include QMK_KEYBOARD_H

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _NUMBER,
  _NAV,
  _ADJUST
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  NUMBER
};

// Left-hand home row mods
#define LCTL_A LCTL_T(KC_A)
#define LALT_R LALT_T(KC_R)
#define LCMD_S LCMD_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define RALT_X RALT_T(KC_X)


// Right-hand home row mods
#define RSFT_N RSFT_T(KC_N)
#define RCMD_E RCMD_T(KC_E)
#define LALT_I LALT_T(KC_I)
#define RCTL_O RCTL_T(KC_O)
#define RALT_DOT RALT_T(KC_DOT)


// side esc — hold for NAV
#define ESC_NAV LT(_NAV, KC_ESC)

// tap for esc, hold for cmd
#define ESC_CMD LCMD_T(KC_ESC)
// tap for return, hold for raise
#define ENT_RSE LT(_RAISE, KC_ENT)
// tap for tab, hold for lower
#define TAB_LWR LT(_LOWER, KC_TAB)
// hold spc for number pad
#define SPC_NUM LT(_NUMBER, KC_SPC)

// tap for \, hold for right shift
#define RSFT_SLSH RSFT_T(KC_BSLS)

// tap for —, hold for hyper
#define HYPE HYPR_T(KC_UNDS)
// tap for =, hold for RALT
#define RALT_EQL RALT_T(KC_EQL)

#define KC_MDASH LALT(KC_MINS)

//
// Keymap
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Leader|  Ctrl|  Alt |  Cmd | Spc  | Tab  | Entr | Bksp |  Del |Hyper | Alt  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  ESC_NAV, LCTL_A,  LALT_R,  LCMD_S,  HOME_T,  KC_G,    KC_M,    RSFT_N,  RCMD_E,  LALT_I,  RCTL_O,  KC_QUOT,
  KC_LSFT, KC_Z,    RALT_X,  KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, RALT_DOT,KC_SLSH, RSFT_SLSH,
  KC_LEAD, KC_LCTRL,KC_LALT, ESC_CMD, SPC_NUM, TAB_LWR, ENT_RSE, KC_BSPC, KC_DEL,  HYPE,    RALT_EQL, _______ // KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   –  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |   
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______, KC_MDASH,KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F10 |  F7  |  F8  |  F9  |      |      |      |      |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      |      |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F1  |  F2  |  F3  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, KC_F10,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,
  _______, KC_F11,  KC_F5,   KC_F5,   KC_F7,   _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F12,  KC_F1,   KC_F2,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |   8  |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |   8  |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |   5  |  6   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |   2  |  3   |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, _______
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | HOME |   Up | PGUP |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left |  Down| Right| LOCK | LOCK |  Left| Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | END  |      | PGDN |      | INS  |  HOME| PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_HOME, KC_UP,   KC_PGUP, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LOCK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, KC_END,  _______,KC_PGDN, _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Colemk| Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  COLEMAK, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

//
// Adjust layer and friends
// 

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
      } else {
        layer_off(_NUMBER);
      }
      return false;      
    case NAV:
      if (record->event.pressed) { 
        layer_on(_NAV);
      } else { 
        layer_off(_NAV);
      }
      return false;      
  }
  return true;
};

//
// Leader Key
//

bool leader_found;
#ifdef AUDIO_ENABLE
float leader_start_song[][2]   = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2]    = SONG(MARIO_GAMEOVER);
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading      = false;
    leader_found = false;

    SEQ_ONE_KEY(KC_C) {
      layer_clear();
      set_single_persistent_default_layer(_COLEMAK);
      leader_found = true;
    } 

    SEQ_ONE_KEY(KC_TAB) { 
      layer_invert(_NUMBER);
      leader_found = true;
    }     

    SEQ_ONE_KEY(KC_ESC) {
      layer_invert(_NAV);
      leader_found = true;
    }     

    SEQ_ONE_KEY(KC_Q) {
      reset_keyboard();
      leader_found = true;
    }

    SEQ_ONE_KEY(KC_B) {
      rgblight_toggle();
      leader_found = true;
    }

    leader_end();
  }    
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end(void) {
  if (leader_found) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif  
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
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
