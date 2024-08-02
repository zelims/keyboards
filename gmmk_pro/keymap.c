#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Esc    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | DEL    |        | Mute   |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | `~     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BackSp |        | Intl1  |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      |        | Intl2  |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Caps   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | Enter           |        | Intl3  |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+        +--------+
    //    | Shift           | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | Shift           +--------+ Intl4  |
    //    +-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+ Up     +--------+
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+
    //    | Ctrl   | Alt    | Super  |                            Space                             | Alt    | MO(1)  | Ctrl   | Left   | Down   | Right  |
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE, 
        KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,   KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME, 
        KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, 
        KC_CAPS, KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN, 
        KC_LSFT,          KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,                                 KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    |        | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | F24    | PrScr  |        |        |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    |        | R_TOG  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    |        |        | R_VAL  |        |        |        |        |        |        |        |        |        |        | QK_BOOT|        |        |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    |        |        | R_VAD  |        |        |        |        |        |        |        |        |        |                 |        |        |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+        +--------+
    //    |                 | R_HUI  |        |        |        |        | NK_TOGG|        |        |        |        |                 +--------+        |
    //    +-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+ R_MOD  +--------+
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+
    //    |        |        |        |                                                              |        |        |        | R_SPD  | R_RMOD | R_SPI  |
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+

    [1] = LAYOUT(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PSCR,           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           _______,
        KX_CATG, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    #if defined(KEY_CANCELLATION_ENABLE)
    if (key_cancellation_is_enabled()) {
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_W, 255, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_A, 255, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_S, 255, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_D, 255, 0, 0);
        for (uint8_t i = 0; i < 8; i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_SIDE_LEFT[i], 255, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_SIDE_RIGHT[i], 255, 0, 0);
        }
    }
    #endif

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 0; i < 8; i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_SIDE_LEFT[i], 255, 255, 255);
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_SIDE_RIGHT[i], 255, 255, 255);
        }

        for (uint8_t i = 0; i < sizeof(LED_LIST_ALPHAKEYS) / sizeof(LED_LIST_ALPHAKEYS[0]); i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_LIST_ALPHAKEYS[i], 255, 255, 255);
        }
        
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_CAPS, 255, 255, 255);
    }

    switch(get_highest_layer(layer_state | default_layer_state)) {
        case 1:
            // set function key lights
            for (uint8_t i = 0; i < sizeof(LED_LIST_FUNCKEYS) / sizeof(LED_LIST_FUNCKEYS[0]); i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(LED_LIST_FUNCKEYS[i], 0, 255, 0);
            }
            // caps lock for key cancellation
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_CAPS, 255, 0, 0);

            // illuminate prtsc
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_DEL, 255, 255, 0);
            break;
        default:
            break;
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE

#if defined(KEY_CANCELLATION_ENABLE)
const key_cancellation_t PROGMEM key_cancellation_list[] = {
    // on key down
    //       |    key to be released
    //       |     |
    [0] = {KC_D, KC_A},
    [1] = {KC_A, KC_D},
    [2] = {KC_W, KC_S},
    [3] = {KC_S, KC_W},
};
#endif // KEY_CANCELLATION_ENABLE

void keyboard_post_init_keymap(void) {
    // keyboard_post_init_user() moved to userspace
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_WHITE); // Default startup colour
    #endif // RGB_MATRIX_ENABLE
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE