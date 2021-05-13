#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"

// to build this keymap
// make ergodox_ez:dvorak_42_key:teensy

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _SYMBOL 1
#define _NUMPAD 2
#define _FUNCTION 3
#define _SPECIAL 4

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  SYMBOL,
  NUMPAD,
  FUNCTION,
  SPECIAL,
  RAISE,
  LOWER,
  ADJUST,
};

#define SYMB MO(_SYMBOL)  // Momentary toggle layer SYMBOL.
#define NUMP MO(_NUMPAD)  // Momentary toggle layer NUMPAD.
#define LAY_FUNC MO(_FUNCTION)  // Momentary toggle layer FUNCTION.
#define LAY_SPECIAL MO(_SPECIAL)  // Momentary toggle layer SPECIAL.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_ergodox(
      // left hand
      KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   LAY_FUNC,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   LAY_SPECIAL,
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   NUMP,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL,

      // left thumb
                      //--------------+-----------//
                      //              |           //
                              KC_LALT,   KC_CAPS, //
                      //              |           //
      //--------------+---------------+-----------//
      //              |               |           //
                                         KC_INS,  //
      //              |               |           //
            SYMB,             KC_LGUI,//----------//
      //              |               |           //
                                         KC_LALT, //
      //              |               |           //
      //              |               |           //
      //--------------+---------------+-----------//

      // right hand
      LAY_FUNC,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      LAY_SPECIAL,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_TILD,
                    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      NUMP,         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
                             KC_RSFT, KC_RALT, KC_RGUI, KC_SLSH, KC_RCTL,

      // right thumb
      //-----------------+----------------//
      //                 |                //
           KC_HOME,            KC_RGUI,   //
      //                 |                //
      //-----------------+-----------------+-----------//
      //                 |                 |           //
           KC_END,
      //                 |                 |           //
      //-----------------|                 |           //
      //                 |                 |           //
          KC_TAB,              KC_BSPC,        KC_SPC  //
      //                 |                 |           //
      //-----------------+-----------------+-----------//

  ),
  [_SYMBOL] = LAYOUT_ergodox(
      // left hand
      KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_LGUI,
      KC_TAB,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_Y,   KC_LALT,
      KC_ESC,  KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_DQT,
      KC_LSFT, KC_SCLN, KC_Q,    KC_TILD, KC_DLR,  KC_DLR,   NUMP,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL,

      // left thumb
                      //--------------+-----------//
                      //              |           //
                              KC_LALT,   KC_CAPS, //
                      //              |           //
      //--------------+---------------+-----------//
      //              |               |           //
                                         KC_INS,  //
      //              |               |           //
            SYMB,             KC_LGUI,//----------//
      //              |               |           //
                                         NUMP,    //
      //              |               |           //
      //              |               |           //
      //--------------+---------------+-----------//

      // right hand
      KC_RGUI,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      LAY_FUNC, KC_EXLM, KC_PLUS, KC_HASH, KC_PIPE, KC_PERC, KC_TILD,
                KC_BSLS, KC_UNDS, KC_ASTR, KC_MINS, KC_EQL,  KC_GRV,
      KC_ESC,   KC_CIRC, KC_SLSH, KC_COLN, KC_AMPR, KC_QUES, KC_AT,
                         KC_RSFT, KC_RALT, KC_RGUI, KC_SLSH, KC_RCTL,

      // right thumb
      //-----------------+----------------//
      //                 |                //
           KC_HOME,            KC_RGUI,   //
      //                 |                //
      //-----------------+-----------------+-----------//
      //                 |                 |           //
           KC_END,
      //                 |                 |           //
      //-----------------|                 |           //
      //                 |                 |           //
          KC_RALT,             KC_BSPC,       LAY_FUNC //
      //                 |                 |           //
      //-----------------+-----------------+-----------//

  ),
  [_NUMPAD] = LAYOUT_ergodox(
      // left hand
      KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LGUI,
      KC_TAB,  KC_QUOT, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_LALT,
      KC_ESC,  KC_A,    KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LCTL,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL,

      // left thumb
                      //--------------+-----------//
                      //              |           //
                              KC_LALT,   KC_CAPS, //
                      //              |           //
      //--------------+---------------+-----------//
      //              |               |           //
                                         KC_INS,  //
      //              |               |           //
            SYMB,             KC_LGUI,//----------//
      //              |               |           //
                                         NUMP,    //
      //              |               |           //
      //              |               |           //
      //--------------+---------------+-----------//

      // right hand
      KC_RGUI,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      LAY_FUNC, KC_0,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
                KC_COMM, KC_4,    KC_5,    KC_6,    KC_0,    KC_ENT,
      KC_ESC,   KC_DOT,  KC_1,    KC_2,    KC_3,    KC_0,    KC_SLSH,
                         KC_RSFT, KC_RALT, KC_RGUI, KC_SLSH, KC_RCTL,

      // right thumb
      //-----------------+----------------//
      //                 |                //
           KC_HOME,            KC_RGUI,   //
      //                 |                //
      //-----------------+-----------------+-----------//
      //                 |                 |           //
           KC_END,
      //                 |                 |           //
      //-----------------|                 |           //
      //                 |                 |           //
          KC_RALT,             KC_BSPC,        KC_SPC  //
      //                 |                 |           //
      //-----------------+-----------------+-----------//
  ),
  [_FUNCTION] = LAYOUT_ergodox(
      // left hand
      KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LGUI,
      KC_TAB,  KC_PGUP, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, LAY_FUNC,
      KC_ESC,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    NUMP,
      KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL,

      // left thumb
                      //--------------+-----------//
                      //              |           //
                              KC_LALT,   KC_CAPS, //
                      //              |           //
      //--------------+---------------+-----------//
      //              |               |           //
                                         KC_INS,  //
      //              |               |           //
            SYMB,             KC_LGUI,//----------//
      //              |               |           //
                                         KC_LALT, //
      //              |               |           //
      //              |               |           //
      //--------------+---------------+-----------//

      // right hand
      KC_RGUI,  KC_6,    KC_F10,  KC_F11,  KC_F12,  KC_0,    KC_BSPC,
      LAY_FUNC, KC_0,    KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_TILD,
                KC_COMM, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_ENT,
      KC_ESC,   KC_DOT,  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_SLSH,
                         KC_RSFT, KC_RALT, KC_RGUI, KC_SLSH, KC_RCTL,

      // right thumb
      //-----------------+----------------//
      //                 |                //
           KC_HOME,            KC_RGUI,   //
      //                 |                //
      //-----------------+-----------------+-----------//
      //                 |                 |           //
           KC_END,
      //                 |                 |           //
      //-----------------|                 |           //
      //                 |                 |           //
          KC_RALT,             KC_BSPC,        KC_SPC  //
      //                 |                 |           //
      //-----------------+-----------------+-----------//
  ),
  [_SPECIAL] = LAYOUT_ergodox(
      // left hand
      KC_DEL,  KC_1,    KC_2,          KC_3,          KC_4,          KC_5,    KC_LGUI,
      KC_TAB,  KC_PGUP, KC_PGUP,       LCTL(KC_UP),   KC_PGDN,       KC_HOME, LAY_FUNC,
      KC_ESC,  KC_PGDN, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), KC_END,
      KC_LSFT, KC_SCLN, KC_Q,          KC_J,          KC_K,          KC_X,    NUMP,
      KC_LCTL, KC_LALT, KC_LGUI,       KC_LALT,       KC_LCTL,

      // left thumb
                      //--------------+-----------//
                      //              |           //
                              KC_LALT,   KC_CAPS, //
                      //              |           //
      //--------------+---------------+-----------//
      //              |               |           //
                                         KC_INS,  //
      //              |               |           //
            SYMB,             KC_LGUI,//----------//
      //              |               |           //
                                         KC_LALT, //
      //              |               |           //
      //              |               |           //
      //--------------+---------------+-----------//

      // right hand
      KC_RGUI,  KC_6,    KC_F10,             KC_F11,               KC_F12,  KC_0,    KC_BSPC,
      LAY_FUNC, KC_0,    KC_MPRV,            KC_MPLY,              KC_MNXT, KC_VOLU,  KC_TILD,
                KC_COMM, KC_F4,              KC_F5,                KC_F6,   KC_VOLD,  KC_ENT,
      KC_ESC,   KC_DOT,  KC_BRIGHTNESS_UP,   KC_BRIGHTNESS_DOWN,   KC_F3,   KC_MUTE,  KC_SLSH,
                         KC_RSFT,            KC_RALT,              KC_RGUI, KC_SLSH, KC_RCTL,

      // right thumb
      //-----------------+----------------//
      //                 |                //
           KC_HOME,            KC_RGUI,   //
      //                 |                //
      //-----------------+-----------------+-----------//
      //                 |                 |           //
           KC_END,
      //                 |                 |           //
      //-----------------|                 |           //
      //                 |                 |           //
          KC_RALT,             KC_BSPC,        KC_SPC  //
      //                 |                 |           //
      //-----------------+-----------------+-----------//
  ),
};
