// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_hungarian.h
#include "keymap_extras/keymap_hungarian.h"


// missing: backtick


enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

#define KM_LOW_TAB  LT(1, KC_TAB)
#define KM_RSE_BSP  LT(2, KC_BSPC)
#define KM_LGUI_SPC LGUI_T(KC_SPC)
#define KM_LALT_S   LALT_T(KC_S)
#define KM_LSFT_D   LSFT_T(KC_D)
#define KM_LCTL_F   LCTL_T(KC_F)
#define KM_RCTL_J   RCTL_T(KC_J)
#define KM_RSFT_K   RSFT_T(KC_K)
#define KM_RALT_L   LALT_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q        , KC_W      , KC_E      , KC_R      , KC_T      ,       KC_Y        , KC_U      , KC_I      , KC_O      , KC_P,
    KC_A        , KM_LALT_S , KM_LSFT_D , KM_LCTL_F , KC_G      ,       KC_H        , KM_RCTL_J , KM_RSFT_K , KM_RALT_L , HU_COLN,
    KC_Z        , KC_X      , KC_C      , KC_V      , KC_B      ,       KC_N        , KC_M      , KC_COMM   , KC_DOT    , KC_SLSH,
                                          KM_LOW_TAB, KM_LGUI_SPC,      KC_ENT      , KM_RSE_BSP
  ),

  [1] = LAYOUT(
    KC_ESC      , HU_PIPE   , HU_SLSH   , HU_QUOT   , HU_DQUO   ,       HU_HASH     , HU_UACU   , HU_IACU   , HU_OACU   , HU_ODAC,
    HU_LABK     , HU_EQL    , HU_LBRC   , HU_LPRN   , HU_LCBR   ,       HU_PERC     , HU_AACU   , HU_EACU   , HU_ODIA   , HU_UDIA,
    HU_RABK     , HU_AMPR   , HU_RBRC   , HU_LPRN   , HU_RCBR   ,       HU_DLR      , HU_AT     , HU_EURO   , HU_TILD   , HU_UDAC,
                                          _______   , _______   ,       _______     , _______
  ),

  [2] = LAYOUT(
    KC_ESC      , HU_7      , HU_8      , HU_9      , HU_ASTR   ,       KC_PGUP     , KC_PRVWD  , KC_UP     , KC_NXTWD  , KC_DLINE,
    _______     , HU_4      , HU_5      , HU_6      , HU_PLUS   ,       KC_PGDN     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_DEL,
    HU_0        , HU_1      , HU_2      , HU_3      , HU_PERC   ,       KC_PSCR     , KC_LSTRT  , XXXXXXX   , KC_LEND   , XXXXXXX,
                                          _______   , _______   ,       _______     , _______
  ),

  [3] = LAYOUT(
    KC_ESC      , KC_F7     , KC_F8     , KC_F9     , _______   ,       _______     , _______   , _______   , _______   , _______,
    _______     , KC_F4     , KC_F5     , KC_F6     , _______   ,       _______     , KC_VOLD   , KC_MUTE   , KC_VOLU   , _______,
    _______     , KC_F1     , KC_F2     , KC_F3     , _______   ,       _______     , KC_MPRV   , KC_MPLY   , KC_MNXT   , _______,
                                          _______   , _______   ,       _______     , _______
  ),
};

// https://docs.qmk.fm/#/feature_key_overrides
const key_override_t dot_shift_exclm_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, HU_EXLM);
const key_override_t coln_shift_scln_override = ko_make_basic(MOD_MASK_SHIFT, HU_COLN, HU_SCLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &dot_shift_exclm_override,
    &coln_shift_scln_override,
    NULL // Null terminate the array of overrides!
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SLSH:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}
