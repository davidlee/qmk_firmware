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

// Left-hand home row mods 
#define CTRL_A   LCTL_T(KC_A)
#define OPT_R    LALT_T(KC_R)
#define CMD_S    LCMD_T(KC_S)
#define SHIFT_T  LSFT_T(KC_T)
#define RALT_X   RALT_T(KC_X)

// Right-hand home row mods
#define SHIFT_N  RSFT_T(KC_N)
#define CMD_E    RCMD_T(KC_E)
#define OPT_I    LALT_T(KC_I)
#define CTRL_O   RCTL_T(KC_O)
#define RALT_DOT RALT_T(KC_DOT)

// other mod-tap keys
#define	Z_MED    LT(_MED, KC_Z)
#define	SLS_MED  LT(_MED, KC_SLSH)
#define	F_FUN 	 LT(_FUN, KC_F)


// hold for mouse layer
#define W_PTR     LT(_PTR, KC_W)
#define QUO_PTR   LT(_PTR, KC_QUOTE)

// left side mods
#define ESC_CTL  LCTL_T(KC_ESC)
#define TAB_MEH  MT(MOD_MEH, KC_TAB)

// bottom row mods
#define ESC_CMD  LCMD_T(KC_ESCAPE)
#define SPC_NUM  LT(_NUM, KC_SPC)
#define TAB_SYM  LT(_SYM, KC_TAB)

#define BS_NAV   LT(_NAV, KC_BSPC)
#define ENT_CMD  MT(MOD_LGUI, KC_ENTER)

// right side mods
#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
#define CMD_QOT  MT(MOD_LGUI, KC_QUOTE)

// clipboard
#define UNDO   LCMD(KC_Z)
#define REDO   SCMD(KC_Z)
#define CUT    LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE  LCMD(KC_V)

// misc
#define EN_DASH LOPT(KC_MINUS)
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_PLUS LCMD(KC_PLUS)
