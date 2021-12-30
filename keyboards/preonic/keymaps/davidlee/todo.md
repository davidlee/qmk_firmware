# TODO

 - PLANCK support -- reorganise into userspace
 - split into multiple files 

 - make CMD-ESC behave like CMD-backtick (for Planck) - 
   see https://beta.docs.qmk.fm/using-qmk/simple-keycodes/feature_advanced_keycodes#alt-+-escape-for-alt-+-tab-id-alt-escape-for-alt-tab
 - or just swap tab, tilde

 - add progamming word case support, refactor shift keys, etc from https://github.com/andrewjrae/kyria-keymap#case-modes
   -  https://github.com/andrewjrae/kyria-keymap/blob/master/features/casemodes.c

 * improve magic shift
   - when you double-tap it then hit an alpha without pausing for the TAPPING_TERM there is no effect.
   - tapping should cancel Caps Lock .. wait, it does if you pause after - same issue again.
   - it just doesn't work that well. needs some tracing & debugging
   - FIGURE out how to make tapping SHIFT disable CAPS Lck
