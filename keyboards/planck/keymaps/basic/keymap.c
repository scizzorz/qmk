#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define _ KC_TRNS
#define X KC_NO

#define BASE 0
#define PURP 1
#define ORNG 2
#define BLUE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | Entr |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |      |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  A   |  B   |  C   |    Space    |  C   |  B   |  A   | Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {GUI_T(KC_TAB),KC_A,KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH)},
  {KC_LCTL, M(BLUE), KC_LALT, M(ORNG), M(PURP), KC_SPC,  KC_SPC,  M(ORNG), M(PURP), KC_LGUI, KC_RCTL, M(BLUE)}
},

[PURP] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT },
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT},
  {_      , _      , X      , X      , X      , X      , X      , X      , X      , X      , X      , KC_RSFT},
  {_      , _      , _      , _      , _      , _      , _      , _      , _      , _      , _      , _      }
},

[ORNG] = {
  {X      , X      , X      , X      , X      , X      , X      , KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_PIPE},
  {X      , X      , X      , X      , X      , X      , X      , KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSLS},
  {_      , _      , X      , X      , X      , X      , X      , X      , X      , X      , X      , KC_RSFT},
  {_      , _      , _      , _      , _      , _      , _      , _      , _      , _      , _      , _      }
},

[BLUE] = {
  {MU_ON,   X      , KC_UP,   X      , X      , X      , X      , X      , KC_INS,  X      , KC_PSCR, KC_DEL },
  {MU_OFF,  KC_LEFT, KC_DOWN, KC_RGHT, X      , X      , KC_HOME, KC_PGDN, KC_PGUP, KC_END,  X      , X      },
  {_      , _      , KC_MUTE, KC_VOLD, KC_VOLU, X      , X      , X      , X      , X      , X      , KC_RSFT},
  {RESET,   _      , _      , _      , _      , _      , _      , _      , _      , _      , _      , _      }
},

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case PURP:
    case ORNG:
    case BLUE:
      if (record->event.pressed) {
        layer_on(id);
      } else {
        layer_off(id);
      }
      break;
  }
  return MACRO_NONE;
};
