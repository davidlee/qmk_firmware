#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action.h"
#include "version.h"

#include "wrappers.h"
#include "process_records.h"

#ifdef TAP_DANCE_ENABLE
#    include "tap_dances.h"
#endif

bool caps_is_active(void);

//
// keycode aliases 
//


