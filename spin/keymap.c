#include QMK_KEYBOARD_H

#define _BASE       0
#define _NUMPAD     1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_F22, KC_F23, KC_F24, TG(_NUMPAD),
                KC_F20, KC_F21, KC_F22, KC_MEDIA_PLAY_PAUSE,
                KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, LGUI(KC_TAB),
                LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB), LCTL(LGUI(KC_RIGHT))
                ),
    [_NUMPAD] = LAYOUT(/* numpad */
                KC_KP_0, KC_KP_PLUS, KC_KP_SLASH, KC_TRNS,
                KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS,
                KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS,
                KC_KP_1, KC_KP_2, KC_KP_3
                ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder (top) */
        if (clockwise) {
            tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder (middle) */  
        if (clockwise) {
            tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 2) { /* Third encoder (bottom) */  
        if (clockwise) {
            register_code(KC_LCTRL);
            register_code(KC_LGUI);
            register_code(KC_RIGHT);

            unregister_code(KC_LCTRL);
            unregister_code(KC_LGUI);
            unregister_code(KC_RIGHT);
        } else {
            register_code(KC_LCTRL);
            register_code(KC_LGUI);
            register_code(KC_LEFT);

            unregister_code(KC_LCTRL);
            unregister_code(KC_LGUI);
            unregister_code(KC_LEFT);
        }
    }
}
