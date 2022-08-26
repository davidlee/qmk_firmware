#include "davidlee.h"

enum custom_layers {
  _CMK,   // Colemak-DH
  _ATH,   // Home Row Mods / alpha hold-taps
  _NAV,   // Navigation
  _NUM,   // Numbers 
  _FUN,   // Function keys
  _MED,   // Media & right hand mods
  _GAM,   // Gaming / QWERTY
  _PTR,   // Pointer

};

enum custom_keycodes {
  CAP_WRD = SAFE_RANGE, // NEW_SAFE_RANGE
  PTR_LCK,
  GAM_LCK,
  EXT_PTR,
  EXT_GAM,
  BS_WORD,
  ATH_ON,  // ALPHA TAP / HOLD
  ATH_OFF,
};

//
// custom keycodes
//

// function keys remapped in Karabiner
#define FN       KC_F24
#define SIRI     KC_F21

// clipboard
#define UNDO   LCMD(KC_Z)
#define CUT    LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE  LCMD(KC_V)

// misc
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

// alpha hold-tap keys
//
// home row mods 
#define A_CTL  MT(MOD_LCTL, KC_A)
#define R_OPT  MT(MOD_LALT, KC_R)
#define S_CMD  MT(MOD_LGUI, KC_S)
#define T_SFT  MT(MOD_LSFT, KC_T)

#define N_SFT  MT(MOD_RSFT, KC_N)
#define E_CMD  MT(MOD_RGUI, KC_E)
#define I_OPT  MT(MOD_LALT, KC_I)
#define O_CTL  MT(MOD_RCTL, KC_O)
//
// right hand side mods 
#define SCN_OPT MT(MOD_RALT, KC_SCOLON)
#define SLS_CTL MT(MOD_RCTL, KC_SLASH)
#define DOT_OPT MT(MOD_RALT, KC_DOT)
#define COM_CMD MT(MOD_RGUI, KC_COMMA)

// non-alpha / outer dual-function keys
//
// leftmost column 
#define TAB_MEH  MT(MOD_MEH, KC_TAB)
#define ESC_CTL  LCTL_T(KC_ESCAPE)
#define ENT_SFT  KC_SFTENT
//
// bottom row 
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define E_FUN    LT(_FUN, KC_E) // not used to E on thumb yet ...

#define NAV      MO(_NAV) 
#define BS_SFT   MT(MOD_LSFT, KC_BSPC)
#define ENT_MED  LT(_MED, KC_ENTER)
//
// rightmost column 
#define DEL_MEH  MT(MOD_MEH,  KC_DEL)
#define QOT_CTL  MT(MOD_RCTL, KC_QUOTE)


#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)

  float layer_song[][2] = SONG(BLIP);
#endif

#define LAYER_MASK_DEFAULT (1 << _CMK | 1 << _ATH)

//
// Combos
//

// R + S = left CMD
const uint16_t PROGMEM combo_lcmd[]      = {R_OPT, S_CMD, COMBO_END};
const uint16_t PROGMEM combo_lcmd2[]     = {KC_R,  KC_S,  COMBO_END};
// E + I = right CMD
const uint16_t PROGMEM combo_rcmd[]      = {E_CMD, I_OPT, COMBO_END};
const uint16_t PROGMEM combo_rcmd2[]     = {KC_E,  KC_I,  COMBO_END};

// W + F = (
const uint16_t PROGMEM combo_lprn[]      = {KC_W, KC_F, COMBO_END};
// F + P = )
const uint16_t PROGMEM combo_rprn[]      = {KC_F, KC_P, COMBO_END};

// X + C = [
const uint16_t PROGMEM combo_lbrc[]      = {KC_X, KC_C, COMBO_END};
// C + D = ]
const uint16_t PROGMEM combo_rbrc[]      = {KC_C, KC_D, COMBO_END};

// N + S = backspace word
const uint16_t PROGMEM combo_bs_word[]   = {N_SFT, E_CMD, COMBO_END};
const uint16_t PROGMEM combo_bs_word2[]  = {KC_N,  KC_E,  COMBO_END};
// A + R = caps word
const uint16_t PROGMEM combo_caps_word[] = {A_CTL, R_OPT, COMBO_END};
const uint16_t PROGMEM combo_caps_word2[]= {KC_A, KC_R,   COMBO_END};

// N + U = turn on PTR layer
const uint16_t PROGMEM combo_ptr[]       = {N_SFT, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ptr2[]      = {KC_N,  KC_U, COMBO_END};
// U + Y = Turn ON Alpha Tap/Hold layer
const uint16_t PROGMEM combo_ath_on[ ]   = {KC_U,  KC_Y,  COMBO_END};
// , + . = Turn OFF Alpha Tap/Hold layer
const uint16_t PROGMEM combo_ath_off[]   = {COM_CMD, DOT_OPT, COMBO_END};

// ESC + DEL = RESET
const uint16_t PROGMEM combo_reset[]     = {ESC_CTL, DEL_MEH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_lcmd,       KC_LGUI),
  COMBO(combo_lcmd2,      KC_LGUI),
  COMBO(combo_rcmd,       KC_RGUI),
  COMBO(combo_rcmd2,      KC_RGUI),

  COMBO(combo_lbrc,       KC_LBRC),
  COMBO(combo_rbrc,       KC_RBRC),
  COMBO(combo_lprn,       KC_LPRN),
  COMBO(combo_rprn,       KC_RPRN),

  COMBO(combo_bs_word,    BS_WORD),
  COMBO(combo_bs_word2,   BS_WORD),
  COMBO(combo_caps_word,  CAP_WRD),
  COMBO(combo_caps_word2, CAP_WRD),

  COMBO(combo_ptr,        PTR_LCK),
  COMBO(combo_ptr2,       PTR_LCK),
  COMBO(combo_ath_on,     ATH_ON),
  COMBO(combo_ath_off,    ATH_OFF),

  COMBO(combo_reset,      RESET),
};

//
// Function Overrides
//

void keyboard_post_init_user(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & ALPHA TAP/HOLDs
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

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
        return TAPPING_TERM + 70;   
      case S_CMD:
      case E_CMD:
        return TAPPING_TERM + 30;
      case T_SFT:
      case N_SFT:
        return TAPPING_TERM + 30;
      
      case SLS_CTL:
      case DOT_OPT:
      case COM_CMD:
        return TAPPING_TERM + 40;

      default:
        return TAPPING_TERM; 
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {  
  return update_tri_layer_state(state, _NUM, _MED, _PTR);
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
    
    case _MED:
      rgblight_setrgb (0x00,  0xAA, 0xFF);

    case _GAM:
      rgblight_setrgb (0xFF,  0x00, 0x00);
      
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

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
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

    case ATH_ON:        
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(layer_song);
        #endif        
        default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & HOME ROW MODS
      }

      return false;
    case ATH_OFF:        
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(layer_song);
        #endif        
        default_layer_set(_CMK); // COLEMAK without alpha tap-hold shenanigans 
      }

      return false;

    default:
      return true; /* Process all other keycodes normally */
  }
}