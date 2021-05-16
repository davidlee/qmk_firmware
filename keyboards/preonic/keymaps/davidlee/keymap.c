#include QMK_KEYBOARD_H

enum preonic_layers {
  _COLEMAK,
  _FNKEY,  
  _NUMBER,
  _LOWER,
  _RAISE,
  _NAV,
  _MOUSE,
  _ADJUST
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  NUMBER,
  MOUSE,
  BASE
};

enum tapdance_keycodes {
    TD_SCLN,
    TD_QUOT
};

// COMBOS
enum combos {
  SHIFTS_CAPS
};

const uint16_t PROGMEM caps_combo[] = {KC_LSPO, KC_RSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SHIFTS_CAPS] = COMBO(caps_combo, KC_CAPS)
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

// hold W for mouse layer
#define W_MOUS LT(_MOUSE, KC_W)

// tap for grave, hold for CTRL
#define CTL_ESC LCTL_T(KC_ESC)

// tap for esc, hold for cmd
#define ESC_CMD LCMD_T(KC_ESC)
// tap for tab, hold for lower
#define TAB_LWR LT(_LOWER, KC_TAB)
// tap for return, hold for raise
#define ENT_RSE LT(_RAISE, KC_ENT)
// hold spc for number pad
#define SPC_NUM LT(_NUMBER, KC_SPC)
// hold backspace for NAV layer
#define BS_NAV LT(_NAV, KC_BSPC)

// #define KC_NAV TG(_NAV)

// a key for mdash
#define KC_MDASH LALT(KC_MINS)

// semicolon w/ tapdance for colon
#define SCLN TD(TD_SCLN)
#define QUOT TD(TD_QUOT)

// shift on lower, tap for braces
#define LCBR_SH LSFT_T(KC_LCBR)
#define RCBR_SH RSFT_T(KC_RCBR)

// shift on raise, tap for brackets
#define LBRC_SH LSFT_T(KC_LBRC)
#define RBRC_SH RSFT_T(KC_RBRC)


#define KC_UNDO  LCMD(KC_Z)
#define KC_CUT   LCMD(KC_X)
#define KC_COPY  LCMD(KC_C)
#define KC_CMDV  LCMD(KC_V)

//
// Keymap
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MENU |      |      |  Cmd | Spc  | Lwr  | Rse  | Bksp |  ⬅️  |  ⬇️  |  ⬆️  |  ➡️  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    W_MOUS,  KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SCLN,    KC_BSLS,
  CTL_ESC, LCTL_A,  LALT_R,  LCMD_S,  HOME_T,  KC_G,    KC_M,    RSFT_N,  RCMD_E,  LALT_I,  RCTL_O,  QUOT,
  KC_LSPO, KC_Z,    RALT_X,  KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, RALT_DOT,KC_SLSH, KC_RSPC,
  KC_LEAD, _______, _______, ESC_CMD, SPC_NUM, TAB_LWR, ENT_RSE, BS_NAV,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* FNKEY
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNKEY] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  b3  |      |  b2  |  b1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b1  |  mL  |  mDn |  mUp |  mR  | BASE | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  b3  |  b2  |  b1  |      |  b2  | whLt | whDn |  whUp| whRt |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BTN3, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______, _______,
  BASE,    _______, _______, _______, _______, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, BASE,
  _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE |      |      |      |      |      |  *   |  4   |  5   |  6   |  +   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |  /   |  1   |  2   |  3   |  -   |NumLck|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   |  _   |PrScr |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PEQL,
  BASE,    _______, _______, _______, _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
  KC_CAPS, _______, _______, _______, _______, _______, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_NLCK,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_UNDS, KC_PSCR
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |  F12 |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE |  F11 |  F4  |  F5  |  F6  |      |      |  _   |   +  |  {   |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  {   |  F10 |  F1  |  F2  |  F3  |      |      |      |      |      |      |   }  |  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, 
  KC_GRV,  KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, _______, _______, 
  BASE,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, 
  LCBR_SH, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, _______, _______, RCBR_SH, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE |   <  |   >  |   &  |   *  |   !  |   ?  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  [   |      |   .  |   ,  |      |      |      |      |      |   {  |   }  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
  BASE,    KC_LT,   KC_GT,   KC_AMPR, KC_ASTR, KC_EXLM, KC_QUES, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  LBRC_SH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RBRC_SH,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Undo| Cut  | Copy | Paste|      | // TODO undo etc
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | LOCK |  Left| Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | INS  |  HOME| PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_HOME, KC_UP,   KC_PGUP, _______, _______, KC_UNDO, KC_CUT , KC_COPY, KC_CMDV, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LOCK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, KC_END,  _______, KC_PGDN, _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* ADJUST??
 * ,-----------------------------------------------------------------------------------.
 * |      |AU_ON |AU_OFF|AU_TOG|      |      |      |      |      |      |      |      |  <- emoji
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MU_ON |MU_OFF|MU_TOG|MU_MOD|      |      |      |      |      |      |      |  <- symbols like »·›•
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | BASE |CK_TOG|CK_UP |CK_DN |CK_RST|      | MOUSE|      |      |      |      |      |  <- word / para movement shortcuts
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, AU_ON,   AU_OFF, AU_TOG,   _______, _______, _______, _______, _______, _______, _______, _______,
  _______, MU_ON,   MU_OFF, MU_TOG,   MU_MOD,  _______, _______, _______, _______, _______, _______, _______,
  BASE,    CK_TOGG, CK_UP,  CK_DOWN,  CK_RST,  _______, MOUSE,   _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

//
// RGB status lights
// 

layer_state_t layer_state_set_user(layer_state_t state) {
  // turn on ADJUST when both LOWER and RAISE are active.
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  switch (get_highest_layer(state)) {
    case _FNKEY:
      rgblight_enable();
      rgblight_setrgb (0x5A,  0x5A, 0x00);
      break;      
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
    case _NAV:
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

// Colemak key
//
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break; 
    case BASE:
      if (record->event.pressed) {
        layer_clear();
      }   
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
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
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};
#endif

void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}
void startup_user()
{
  // _delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}
//
// Leader Key
//

LEADER_EXTERNS();

bool leader_found;
#ifdef AUDIO_ENABLE
// float leader_start_song[][2]   = SONG(CAPS_LOCK_ON_SOUND);
float leader_succeed_song[][2] = SONG(TERMINAL_SOUND);
float leader_fail_song[][2]    = SONG(CAPS_LOCK_OFF_SOUND);
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

    // M - TOGGLE MOUSE LAYER
    SEQ_ONE_KEY(KC_M) { 
      layer_invert(_MOUSE);
      leader_found = true;
    }     

    // SPC - TOGGLE NUMBER LAYER
    SEQ_ONE_KEY(KC_SPC) { 
      layer_invert(_NUMBER);
      leader_found = true;
    }     

    // TAB - TOGGLE LOWER LAYER
    SEQ_ONE_KEY(KC_TAB) { 
      layer_invert(_LOWER);
      leader_found = true;
    }     

    // ENTER - TOGGLE RAISE LAYER
    SEQ_ONE_KEY(KC_ENT) { 
      layer_invert(_RAISE);
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

    // ESC — send CMD-ALT-ESC
    SEQ_ONE_KEY(KC_Q) {
      
      leader_found = true;
    }    

    // F — toggle FNKEYS :: TODO FF for one shot
    // FIXME doesn't seem to be working
    SEQ_ONE_KEY(KC_F) {
      layer_invert(_FNKEY);
      leader_found = true;
    }

    // todo leader key to toggle CMD being a one shot symbol layer key
    leader_end();
  }    
}

void leader_end(void) {
  if (leader_found) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
    layer_clear();
    set_single_persistent_default_layer(_COLEMAK);    
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
          return 180;
        case QUOT:
          return 175;
        // case ESC_NAV:
        //   return 150;            
        default:
          return TAPPING_TERM;
    }
}
