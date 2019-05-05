/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define _DVORAK 0 // default layer
#define _SYMBOL 1 // symbols
#define _NUMPAD 2 // numbers/motion
#define _FUNCTION 3 // functions keys/motion

// Blank template at the bottom

enum customKeycodes {
	DVORAK = SAFE_RANGE,
	SYMBOL,
	NUMPAD,
	FUNCTION,
};

#define SYMB MO(_SYMBOL)  // Momentary toggle layer SYMBOL.
#define NUMP MO(_NUMPAD)  // Momentary toggle layer NUMPAD.
#define LAY_FUNC MO(_FUNCTION)  // Momentary toggle layer FUNCTION.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_gergo(
    KC_TAB,  KC_QUOTE,  KC_COMM,   KC_DOT,   KC_P, KC_Y,                                   KC_F, KC_G, KC_C, KC_R, KC_L, KC_TILD,
    KC_ESC,  KC_A,  KC_O,   KC_E,   KC_U, KC_I, NUMP,                       KC_DEL,    KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT,
    KC_LSFT, KC_SCLN,  KC_Q,   KC_J,   KC_K, KC_X, SYMB, KC_CAPS,     KC_RGUI, KC_BSPC, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SLSH,
      KC_LALT, KC_LCTL, SYMB, NUMP,                                      KC_BSPC, KC_SPC, KC_RSFT, KC_RALT
    ),
[_SYMBOL] = LAYOUT_gergo(
    KC_TRNS,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_Y,                                   KC_EXLM, KC_PLUS, KC_HASH, KC_PIPE, KC_PERC, KC_TILD,
    KC_TRNS,  KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_DQT, KC_TRNS,                        KC_TRNS, KC_BSLS, KC_UNDS, KC_ASTR, KC_MINS, KC_EQL,  KC_GRV,
    KC_TRNS,  KC_SCLN, KC_Q,    KC_TILD, KC_DLR,  KC_DLR, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_CIRC, KC_SLSH, KC_COLN, KC_AMPR, KC_QUES, KC_AT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  LAY_FUNC, KC_TRNS, KC_TRNS
    ),
[_NUMPAD] = LAYOUT_gergo(
    KC_TRNS,  KC_QUOT, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME,                                             KC_0,    KC_1,    KC_2,    KC_3,    KC_0, KC_TRNS,
    KC_TRNS,  KC_A,    KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_TRNS,                          KC_TRNS,  KC_COMM, KC_4,    KC_5,    KC_6,    KC_0, KC_ENT,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS, KC_TRNS,  KC_DOT,  KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
[_FUNCTION] = LAYOUT_gergo(
    KC_TRNS,  KC_QUOT, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME,                                             KC_0,    KC_F1,    KC_F2,    KC_F3, KC_F10, KC_TRNS,
    KC_TRNS,  KC_A,    KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_TRNS,                          KC_TRNS,  KC_COMM, KC_F4,    KC_F5,    KC_F6, KC_F11, KC_ENT,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS, KC_TRNS,  KC_DOT,  KC_F7,    KC_F8,    KC_F9, KC_F12, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
