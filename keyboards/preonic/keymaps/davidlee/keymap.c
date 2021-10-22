#include QMK_KEYBOARD_H
#include "features/casemodes.h"

// TODO a way to hold down space bar ... its a thing for eg panning in Mural

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _HOMEROWMODS,
  _NUMBER,
  _LOWER,
  _RAISE,
  _NAV,
  _MOUSE,
  _ADJUST
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  HOMEROWMODS,
  LOWER,
  RAISE,
  NAV,
  NUMBER,
  MOUSE,
  K_RESET,
  HR_MODS
};

//
// tap dance stuff
//

enum tapdance_keycodes {
    TD_SCLN,
    TD_QUOT,
    TD_SHFT
};

// tap dance states
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

//
// keycode aliases for legibility
//

// Left-hand home row mods 
#define CTRL_A LCTL_T(KC_A)
#define OPT_R LALT_T(KC_R)
#define CMD_S LCMD_T(KC_S)
#define SHIFT_T LSFT_T(KC_T)
#define RALT_X RALT_T(KC_X)

// Right-hand home row mods
#define SHIFT_N RSFT_T(KC_N)
#define CMD_E RCMD_T(KC_E)
#define OPT_I LALT_T(KC_I)
#define CTRL_O RCTL_T(KC_O)
#define RALT_DOT RALT_T(KC_DOT)

// hold W for mouse layer
#define W_MOUS LT(_MOUSE, KC_W)

// tap for grave, hold for CTRL
#define CTL_ESC LCTL_T(KC_ESC)

// tap for spc, hold for cmd
#define SPC_CMD LCMD_T(KC_SPACE)
// tap for tab, hold for lower
#define TAB_LWR LT(_LOWER, KC_TAB)
// tap for return, hold for raise
#define ENT_RSE LT(_RAISE, KC_ENT)
// hold spc for number pad
#define SPC_NUM LT(_NUMBER, KC_SPC)
// hold backspace for NAV layer
#define BS_NAV LT(_NAV, KC_BSPC)
// hold opt, tap delete
#define DEL_OPT LALT_T(KC_DEL)

// a key for mdash
#define KC_MDASH LALT(KC_MINS)

// TAP DANCE KEYS
// semicolon w/ tapdance for colon
#define SCLN TD(TD_SCLN)
// quote or double tap for double quote
#define QUOT TD(TD_QUOT)

// L shift tap dances
#define SFT_LCK TD(TD_SHFT)

// CLIPBOARD management
#define KC_UNDO  LCMD(KC_Z)
#define KC_CUT   LCMD(KC_X)
#define KC_COPY  LCMD(KC_C)
#define KC_CMDV  LCMD(KC_V)
#define KC_REDO  LSFT(LCMD(KC_Z))

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)

// Keymap
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MENU |  Fn  | Opt  |  Cmd | Spc  | Lwr  | Rse  | Bksp |   ⬅️    ⬇️     ⬆️     ➡️  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SCLN,    KC_DEL, // see if we can use other tab
  CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QUOT,
  SFT_LCK, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LEAD, XXXXXXX, DEL_OPT, SPC_CMD, SPC_NUM, TAB_LWR, ENT_RSE, BS_NAV,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, RALT_DOT,KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* HomeRowMods
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
  _______, _______, RALT_X,  _______, _______, _______, _______, _______, _______, RALT_DOT,_______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Mouse 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  b3  |      |  b2  |  b1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  b1  |  mL  |  mDn |  mUp |  mR  |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  b3  |  b3  |  b2  |  b1  |      |  b2  | whLt | whDn |  whUp| whRt |      |                                               
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BTN3, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_ACL0, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, KC_BTN3, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  -   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  *   |  4   |  5   |  6   |  +   |NumLck|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |  /   |  1   |  2   |  3   |  =   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  0   |  .   |  ,   |PrScr |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PEQL,
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NLCK,
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_PENT,
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PCMM, KC_PSCR
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  |      |      | Eject| Play |CMD-[ |CMD-] |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      |      | Shft | Cmd  | Alt  | Ctrl |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  |      | Prev | Next | Vol- | Vol+ | Mute | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, 
  _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, KC_EJCT, KC_MPLY, CMD_LBRC,CMD_RBRC,_______, 
  _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______, 
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  `   |  7   |   5  |   3  |   1  |   9  |  8   |  0   |   2  |   4  |  6   |      |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  $   |   @  |   #  |   !  |   %  |  (   |  -   |   =  |  [   |  ]   |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ^   |   &  |   *  |   ~  |   \  |  ––  |  _   |   +  |  {   |  }   |      |  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  KC_GRV,  KC_7,   KC_5,     KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,    _______, 
  KC_GRV,  KC_DLR, KC_AT,    KC_HASH, KC_EXLM, KC_PERC, KC_LPRN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_RPRN, 
  _______, KC_PERC,KC_AMPR,  KC_ASTR, KC_TILD, KC_BSLS, KC_MDASH,KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Undo| Cut  | Copy | Paste| Redo | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  INS |  Left| Down | Up   | Right|  DEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  HOME| PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_UNDO, KC_CUT , KC_COPY, KC_CMDV, KC_REDO,
  _______, _______, _______, _______, _______, _______, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Qwerty|      |      |      |      |      |      |      |      |      |      |  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |HRMODS|Colemk|      |      |      |      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  K_RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, HR_MODS, COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, 
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
  // Process case modes
  if (!process_case_modes(keycode, record)) {
      return false;
  }

  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        layer_on(_HOMEROWMODS);
      }
      return false;
      break; 
    case QWERTY:
      if (record->event.pressed) {
        // set_single_persistent_default_layer(_COLEMAK); // not implemented yet
        // layer_on(_HOMEROWMODS);
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
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}
void startup_user()
{
  PLAY_SONG(tone_startup);
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
    layer_on(_HOMEROWMODS);    
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif  
  }
}

//
// tap dances
//

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'shift' tap dance.
static td_tap_t shft_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Send ; on Single Tap, : on Double Tap
void td_scln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SCLN);
    } else {
        register_code16(KC_COLN);
    }
}

void td_scln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SCLN);
    } else {
        unregister_code16(KC_COLN);
    }
}

// Send ' on Single Tap, " on Double Tap
void td_quot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOT);
    } else {
        register_code16(KC_DQUO);
    }
}

void td_quot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    } else {
        unregister_code16(KC_DQUO);
    }
}

// LEFT shift - tap for one shot, double tap to caps word, triple for caps lock
// 
void td_shft_finished(qk_tap_dance_state_t *state, void *user_data) {
    shft_tap_state.state = cur_dance(state);
    switch (shft_tap_state.state) {
      case TD_SINGLE_TAP: 
        set_oneshot_mods(MOD_LSFT);
        break;
      case TD_DOUBLE_SINGLE_TAP: 
        toggle_caps_word();
        break;
      case TD_SINGLE_HOLD: 
      case TD_DOUBLE_HOLD: 
        register_code(KC_LSFT); 
        break;
      case TD_DOUBLE_TAP: 
        toggle_caps_word();
        break;
      case TD_TRIPLE_TAP: 
        tap_code(KC_CAPS); 
        break;
      case TD_TRIPLE_HOLD: break;
      case TD_UNKNOWN: break;
      case TD_NONE: break;
    }
}

void td_shft_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shft_tap_state.state) {
      case TD_SINGLE_TAP: 
        disable_caps_word();
        break;
      case TD_DOUBLE_SINGLE_TAP: break;
      case TD_SINGLE_HOLD: 
      case TD_DOUBLE_HOLD: 
        unregister_code(KC_LSFT);
        disable_caps_word();
        break;
      case TD_DOUBLE_TAP: break;
      case TD_TRIPLE_TAP: break;
      case TD_TRIPLE_HOLD: break;
      case TD_UNKNOWN: break;
      case TD_NONE: break;
  }
  shft_tap_state.state = TD_NONE;
}


// All tap dance functions 
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_scln_finished, td_scln_reset),
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_quot_finished, td_quot_reset),
    [TD_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_shft_finished, td_shft_reset)
};

//
// per key tapping term 
// TODO set tapping term to lower numbers on the home row mods
//
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OPT_I:
            // My ring finger tends to linger on the key 
            // This tapping term allows me to type "ion" reliably.
            return TAPPING_TERM + 50;
        case CTRL_O:
            return TAPPING_TERM + 10;
        // These next mod taps are used very frequently during typing.
        // As such, the lower the tapping term, the faster the typing.
        case CMD_S:
            return TAPPING_TERM + 15;
        case CMD_E:
            return TAPPING_TERM + 15;
        case SCLN:
          return TAPPING_TERM;
        case QUOT:
          return TAPPING_TERM;
        case SFT_LCK:
          return TAPPING_TERM + 20;
        default:
          return TAPPING_TERM;
    }
}
