#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _SYMBOL 1
#define _NUMPAD 2
#define _FUNCTION 3

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  SYMBOL,
  NUMPAD,
  FUNCTION,
  RAISE,
  LOWER,
  ADJUST,
};

#define KC_SYMB MO(_SYMBOL)  // Momentary toggle layer SYMBOL.
#define KC_NUMP MO(_NUMPAD)  // Momentary toggle layer NUMPAD.
#define KC_FUNC MO(_FUNCTION)  // Momentary toggle layer FUNCTION.

#define KC_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     DEL ,APP ,VOLD,MUTE,VOLU,LGUI,               RGUI,MPRV,MPLY,MNXT,DOWN,BSPC,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,TILD,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,ENT ,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     BSPC,SCLN, Q  , J  , K  , X  ,NUMP,     RGUI, B  , M  , W  , V  , Z  ,SLSH,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
                       LALT,LCTL,SYMB,         SPC ,RSFT,RALT
  //                  `----+----+----'        `----+----+----'
  ),

 [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,BSPC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LBRC,RBRC,LCBR,RCBR,    ,               EXLM,PLUS,HASH,PIPE,PERC,TILD,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LT  ,GT  ,LPRN,RPRN,DQT ,               BSLS,UNDS,ASTR,MINS,EQL ,GRV ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,TILD,DLR ,    ,FUNC,     FUNC,CIRC,SLSH,COLN,AMPR,QUES,AT  ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,PGUP, UP ,PGDN,HOME,                0  , 1  , 2  , 3  ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LEFT,DOWN,RGHT,END ,               COMM, 4  , 5  , 6  , 0  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,DOT , 7  , 8  , 9  , 0  ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_FUNCTION] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGUP,PGUP, UP ,PGDN, ESC,                   , F1 , F2 , F3 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGDN,LEFT,DOWN,RGHT, END,                   , F4 , F5 , F6 ,F11 ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , F7 , F8 , F9 ,F12 ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,   ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

};
