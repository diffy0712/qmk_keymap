// Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#pragma once

#define MASTER_LEFT

#undef TAPPING_TERM
#undef QUICK_TAP_TERM

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 230

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Enable caps word feature on both shifts
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
