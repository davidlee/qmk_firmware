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

enum tapdance_keycodes {
    TD_SCLN,
    TD_QUOT
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

#define KC_NAV TG(_NAV)

// a key for mdash
#define KC_MDASH LALT(KC_MINS)

// semicolon w/ tapdance for colon
#define SCLN TD(TD_SCLN)
#define QUOT TD(TD_QUOT)

//
// Keymap
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  F13 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift?|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  |  F14 |  NAV |  Cmd | Spc  | Tab  | Entr | Bksp | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F13,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SCLN,    KC_BSLS,
  ESC_NAV, LCTL_A,  LALT_R,  LCMD_S,  HOME_T,  KC_G,    KC_M,    RSFT_N,  RCMD_E,  LALT_I,  RCTL_O,  QUOT,
  KC_LSPO, KC_Z,    RALT_X,  KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, RALT_DOT,KC_SLSH, KC_RSPC,
  KC_LEAD, KC_F14,  KC_NAV,ESC_CMD, SPC_NUM, TAB_LWR, ENT_RSE, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   –  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  {   |      |      |      |      |      |      |      |      |      |      |  }   |   
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______, KC_MDASH,KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  KC_LCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RCBR, 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  |      |      |      |      |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  [   |  F10 |  F1  |  F2  |  F3  |      |      |      |      |      |      |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,
  _______, KC_F11,  KC_F5,   KC_F5,   KC_F7,   _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  KC_LBRC, KC_F10,  KC_F1,   KC_F2,   KC_F4,   _______, _______, _______, _______, _______, _______, KC_RBRC,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |  *   |  4   |  5   |  6   |  +   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  ^   |  &   |  *   |      |  /   |  1   |  2   |  3   |  -   |NumLck|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   |  _   |PrScr |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PEQL,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_NLCK,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_UNDS, KC_PSCR
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | HOME |   Up | PGUP |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left |  Down| Right|      | LOCK |  Left| Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | END  |      | PGDN | INS  | DEL  |  HOME| PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_HOME, KC_UP,   KC_PGUP, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LOCK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, KC_END,  _______, KC_PGDN, KC_INS,  KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Colemk|  b3  |      |  mU  |  whU |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  b1  |  mL  |  mD  |  mR  |      |      | ACL2 | ACL1 | ACL0 |      | Del  | 
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  b2  |  whL |  whR |  whD |      |      |      |      |      |      |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  COLEMAK, KC_BTN3 , _______,KC_MS_U, KC_WH_U, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, KC_DEL,
  _______, KC_BTN2, KC_WH_L, KC_WH_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

//
// ADJUST layer
// 

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Colemak key
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;     
  }
  return true;
};

//
// Leader Key
//

LEADER_EXTERNS();

bool leader_found;
#ifdef AUDIO_ENABLE
float leader_start_song[][2]   = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2]    = SONG(MARIO_GAMEOVER);
#endif

void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading      = false;
    leader_found = false;

    // COLEMAK & turn other layers off
    SEQ_ONE_KEY(KC_C) {
      layer_clear();
      set_single_persistent_default_layer(_COLEMAK);
      leader_found = true;
    } 

    // TAB - TOGGLE NUMBER LAYER
    SEQ_ONE_KEY(KC_TAB) { 
      layer_invert(_NUMBER);
      leader_found = true;
    }     

    // ESC - TOGGLE NAV LAYER
    SEQ_ONE_KEY(KC_ESC) {
      layer_invert(_NAV);
      leader_found = true;
    }     

    // Q — RESET 
    SEQ_ONE_KEY(KC_Q) {
      reset_keyboard();
      leader_found = true;
    }

    // B — toggle RGB light
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

//
// tap dances
//

// tap dance on yr colon

// Send ; on Single Tap, : on Double Tap
void dance_scln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SCLN);
    } else {
        register_code16(KC_COLN);
    }
}

void dance_scln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SCLN);
    } else {
        unregister_code16(KC_COLN);
    }
}

// Send ' on Single Tap, " on Double Tap
void dance_quot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOT);
    } else {
        register_code16(KC_DQUO);
    }
}

void dance_quot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    } else {
        unregister_code16(KC_DQUO);
    }
}

// All tap dance functions 
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_scln_finished, dance_scln_reset),
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quot_finished, dance_quot_reset),
};

//
// per key tapping term
//
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCLN:
            return 150;
        case QUOT:
            return 150;
        case ESC_NAV:
            return 150;            
        default:
            return TAPPING_TERM;
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
