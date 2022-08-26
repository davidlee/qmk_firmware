#include "davidlee.h"
#include "keycodes.h"
#include "keymaps.h"
#include "combos.h"

#ifdef AUDIO_ENABLE
  float blip_song[][2] = SONG(BLIP);
  float arp_song[][2]  = SONG(ARP);
#endif

#define LAYER_MASK_DEFAULT (1 << _CMK | 1 << _HRM)

const int home_row_mod_keys[] = { A_CTL, R_OPT, S_CMD, T_SFT, N_SFT, E_CMD, I_OPT, O_CTL};

//
// Function Overrides
//


void keyboard_post_init_user(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & ALPHA TAP/HOLDs
}

// give precedence to tap rather than hold for home row mods, to avoid accidental mistypes
// note this gives hold precedence for eg SLS_CTL, DOT_OPT, COM_CMD
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  for(int i=0; i < sizeof(home_row_mod_keys) / sizeof(home_row_mod_keys[0]); i++) {
    if(home_row_mod_keys[i] == keycode) return false; 
  }
  return true; 
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

      case A_CTL:
      case O_CTL:
        return TAPPING_TERM + 40;
      case R_OPT:
      case I_OPT:
        return TAPPING_TERM + 70; // lazy ring fingers are the biggest culprit for misfires
      case S_CMD:
      case E_CMD:
        return TAPPING_TERM + 40;
      case T_SFT:
      case N_SFT:
        return TAPPING_TERM + 30;
      
      case SLS_CTL:
      case DOT_OPT:
      case COM_CMD:
        return TAPPING_TERM + 40; // doesn't matter as much due to permissive_hold

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
      break;

    case _GAM:
      rgblight_setrgb (0xFF,  0x00, 0x00);
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(arp_song);
        #endif       
      return false;

    case PTR_LCK:
      layer_on(_PTR);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(arp_song);
        #endif       
      return false; 

    // EXIT LAYERS

    case EXT_GAM:
      layer_off(_GAM);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(arp_song);
        #endif             
      return false;    

    case EXT_PTR:
      layer_off(_PTR);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif             
      return false;

    // other functions

    case CAP_WRD:        
      if (record->event.pressed) {
        caps_word_on();
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif
      }
      return false;    

    case BS_WORD:        
      if (record->event.pressed) {
        tap_code16(LOPT(KC_BSPC));
      }
      return false;

    case DEL_WORD:        
      if (record->event.pressed) {
        tap_code16(LOPT(KC_DELETE));
      }
      return false;

    case HRM_ON:        
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif        
        default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & HOME ROW MODS
      }

      return false;
    case HRM_OFF:        
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif        
        default_layer_set(_CMK); // COLEMAK without alpha tap-hold shenanigans 
      }

      return false;

    default:
      return true; /* Process all other keycodes normally */
  }
}