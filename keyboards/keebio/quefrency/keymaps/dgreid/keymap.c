#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYM 1
#define _NUM 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_ESC,  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_BSPC, KC_HOME, \
    MO(_SYM),MO(_NUM),KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,           KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_END, \
    KC_DEL,  KC_PAUS, KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,           KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,  KC_PGUP, \
    KC_PSCR, KC_SLCK, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_DEL,  KC_PGDN, \
    KC_HOME, KC_END,  KC_LCTL, KC_LALT, KC_LGUI, KC_LCTL, MO(_SYM),         RSFT_T(KC_SPC), KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, MO(_SYM), KC_RCTL, KC_RCTL
  ),

  [_SYM] = LAYOUT_65_with_macro(
    _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, KC_EXLM,         KC_PLUS, KC_HASH, KC_PIPE, KC_PERC, KC_TILD, _______, _______, _______, \
    _______, _______, _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_DQT,  KC_BSLS,         KC_UNDS, KC_ASTR, KC_MINS, KC_EQL,  KC_GRV,  _______, _______, \
    _______, _______, _______, _______, _______, KC_TILD, KC_DLR,  KC_DLR,  KC_CIRC,         KC_SLSH, KC_COLN, KC_AMPR, KC_AT,   KC_AT,   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          LT(_NUM,KC_SPC), _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT_65_with_macro(
    _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_0,    KC_1,    KC_2,    KC_3,    KC_0,     _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_COMM, KC_4,    KC_5,    KC_6,    KC_0,     _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  KC_7,    KC_8,    KC_9,    KC_0,     _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};
