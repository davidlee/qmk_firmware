#include "tap_dances.h"

//
// tap dances
//

// https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance#complex-examples-id-complex-examples

#ifdef AUDIO_ENABLE
float caps_lock_on_sound[][2]  = SONG(CAPS_LOCK_ON_SOUND);
float caps_lock_off_sound[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif

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
