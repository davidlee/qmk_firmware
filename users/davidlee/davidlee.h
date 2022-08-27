#pragma once
#include QMK_KEYBOARD_H

enum userspace_layers {
  _CMK,   // Colemak-DH
  _HRM,   // Home Row Mods / alpha hold-taps
  _NUM,   // Numbers 
  _FUN,   // Function keys
  _NAV,   // Navigation
  _MED,   // Media & right hand mods
  _GAM,   // Gaming / QWERTY
  _PTR,   // Pointer
};

#ifdef AUDIO_ENABLE
  #define BLIP  SD_NOTE(_C0), SD_NOTE(_C1), TD_NOTE(_C3)
  #define ARP   ED_NOTE(_C1), ED_NOTE(_DS1), ED_NOTE(_G1),  ED_NOTE(_C2), ED_NOTE(_DS2), ED_NOTE(_G2),  ED_NOTE(_C3), ED_NOTE(_G3), ED_NOTE(_C3), ED_NOTE(_G2), ED_NOTE(_DS2), ED_NOTE(_C2)
#endif