#include QMK_KEYBOARD_H
#include "print.h"

#define _BASE       0
#define _NUMPAD     1
#define _WORKSPACE  2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_F22, KC_F23, KC_F24, KC_NO,
                KC_F20, KC_F21, KC_F22, TO(_NUMPAD),
                KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, TO(_WORKSPACE),
                RCTL(KC_INS), RCTL(KC_HOME), KC_NO
                ),
    [_NUMPAD] = LAYOUT(/* numpad */
                KC_KP_0, KC_KP_PLUS, KC_KP_SLASH, TO(_BASE),
                KC_KP_7, KC_KP_8, KC_KP_9, KC_NLCK,
                KC_KP_4, KC_KP_5, KC_KP_6, TO(_WORKSPACE),
                KC_KP_1, KC_KP_2, KC_KP_3
                ),
    [_WORKSPACE] = LAYOUT(/* numpad */
                LGUI(KC_0), KC_NO, KC_NO, TO(_BASE),
                LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), TO(_NUMPAD),
                LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_NO,
                LGUI(KC_1), LGUI(KC_2), LGUI(KC_3)
                ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            setrgb(RGB_PURPLE, &led[0]); 
            setrgb(0, 0, 0, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _NUMPAD:
            setrgb(0, 0, 0, &led[0]); 
            setrgb(RGB_PURPLE, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _WORKSPACE:
            setrgb(0, 0, 0, &led[0]);
            setrgb(0, 0, 0, &led[1]);
            setrgb(RGB_PURPLE, &led[2]);
            break;
    }
    rgblight_set();
    return state;
}

void keyboard_post_init_user(void) {
    setrgb(RGB_PURPLE, &led[0]); 
    setrgb(0, 0, 0, &led[1]);
    setrgb(0, 0, 0, &led[2]);
    rgblight_set();
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder (top) */
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _WORKSPACE:
                if (clockwise) {
                    tap_code16(LGUI(KC_DOT));
                } else {
                    tap_code16(LGUI(KC_COMMA));
                }
                break;
        }
    } else if (index == 1) { /* Second encoder (middle) */  
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _WORKSPACE:
                if (clockwise) {
                    tap_code16(LGUI(KC_DOT));
                } else {
                    tap_code16(LGUI(KC_COMMA));
                }
                break;
        }
    } else if (index == 2) { /* Third encoder (bottom) */  
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;
            case _WORKSPACE:
                if (clockwise) {
                    tap_code16(LGUI(KC_DOT));
                } else {
                    tap_code16(LGUI(KC_COMMA));
                }
                break;
        }
    }
}
