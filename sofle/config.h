
/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#undef TAPPING_TERM
#undef QUICK_TAP_TERM

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 225

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Enable caps word feature on both shifts
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
