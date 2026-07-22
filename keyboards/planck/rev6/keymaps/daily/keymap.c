/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _ARROWS,
  _SYSTEM,
  _KBOARD,
  _FMWARE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define SYSTEM TT(_SYSTEM)
#define KBOARD MO(_KBOARD)
#define FMWARE MO(_FMWARE)

#define SFTESC LSFT_T(KC_ESC)
#define OS_NUM OSL(_NUMBER)
#define ARRSPC LT(_ARROWS, KC_SPC)

#define ALTRGHT A(KC_RGHT)
#define ALTLEFT A(KC_LEFT)
#define CTLRGHT C(KC_RGHT)
#define CTLLEFT C(KC_LEFT)

/* ## Homerow Mods

|   A  |   S  |  (D) |  (F) |      |  Sym  |      |  (J) |  (K) |   L  |   ;  |      |
|   A  |  (S) |  (D) |   F  |      |  Ctl  |      |   J  |  (K) |  (L) |   ;  |      |
|   A  |  (S) |  (D) |  (F) |      |Ctl+Sym|      |  (J) |  (K) |  (L) |   ;  |      |
|   A  |  (S) |   D  |  (F) |      |  Gui  |      |  (J) |   K  |  (L) |   ;  |      |
|  (A) |  (S) |   D  |   F  |      |  Alt  |      |   J  |   K  |  (L) |  (;) |      |
 */

// const uint16_t PROGMEM lctl[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM lsym[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM lctlsym[] = {KC_S, KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM lgui[] = {KC_S, KC_F, COMBO_END};
// const uint16_t PROGMEM lalt[] = {KC_A, KC_S, COMBO_END};

// const uint16_t PROGMEM rctl[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM rsym[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM rctlsym[] = {KC_J, KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM rgui[] = {KC_J, KC_L, COMBO_END};
// const uint16_t PROGMEM ralt[] = {KC_L, KC_SCLN, COMBO_END};

// combo_t key_combos[] = {
//     COMBO(lctl, KC_LCTL),
//     COMBO(lsym, MO(_SYMBOL)),
//     COMBO(lctlsym, LM(_SYMBOL, MOD_LCTL)),
//     COMBO(lgui, KC_LGUI),
//     COMBO(lalt, KC_LALT),
//
//     COMBO(rctl, KC_RCTL),
//     COMBO(rsym, MO(_SYMBOL)),
//     COMBO(rctlsym, LM(_SYMBOL, MOD_RCTL)),
//     COMBO(rgui, KC_RGUI),
//     COMBO(ralt, KC_RALT),
// };

#define SYM__F LT(_SYMBOL, KC_F)
#define SYM__J LT(_SYMBOL, KC_J)

#define ALT__A   ALT_T(KC_A)
#define ALT__SC  ALT_T(KC_SCLN)
#define GUI__D   GUI_T(KC_D)
#define GUI__K   GUI_T(KC_K)
#define CTL__S   CTL_T(KC_S)
#define CTL__L   CTL_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Qwerty

|   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  | Bsp  |
|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  '"  |
|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Sft  |
|      |      |System|OS_Num|S(Esc)| Bsp  |Arr( )| Ntr  | Alt  | Gui  | Ctl  | Ntr  |
 */

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   XXXXXXX, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ALT__A,  CTL__S,  GUI__D, SYM__F, KC_G,   XXXXXXX, KC_H,   SYM__J,  GUI__K,  CTL__L,  ALT__SC, KC_QUOT,
    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   XXXXXXX, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    XXXXXXX, XXXXXXX, SYSTEM, OS_NUM, SFTESC, KC_BSPC, ARRSPC, KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL, KC_ENT
),

/* ## Symbol

|  @   |  *   |  ^   |  $   |  ~   |      |      |  _   |  =   | \|   |  %   |      |
|  &   |  *   |  (   |  )   |      |      |  #   |  -   | \[   | \]   |  :   | \`   |
|      |      |  {   |  }   |      |      |  !   |  +   |  <   |  >   |  \   |      |
|      |      |      |      |      |      |      | Tab  |      |      |      |      |
 */

[_SYMBOL] = LAYOUT_planck_grid(
    KC_AT,   KC_ASTR, KC_CIRC, KC_DLR,  KC_TILD, XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL,  KC_PIPE, KC_PERC, _______,
    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_HASH, KC_MINS, KC_LBRC, KC_RBRC, KC_COLN, KC_GRV,
    XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_EXLM, KC_PLUS, KC_LABK, KC_RABK, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_TAB,  _______, _______, _______, _______
),

/* ## Number

|  @   |  *   |  ^   |  $   |  ~   |      |      |  _   |  =   | \|   |  %   |      |
|  1   |  2   |  3   |  4   |  5   |      |  6   |  7   |  8   |  9   |  0   |      |
|      |      |      |      |      |      |  !   |  +   |  <   |  >   |  /   |      |
|      |      |      | \\/  |      |      |      |      |      |      |      |      |
 */

[_NUMBER] = LAYOUT_planck_grid(
    KC_AT,   KC_ASTR, KC_CIRC, KC_DLR,  KC_TILD, XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL,  KC_PIPE, KC_PERC, _______,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM, KC_PLUS, KC_LABK, KC_RABK, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## Arrows

|      |A(->) | M_Up |C(->) |      |      |      |C(<-) |M_Acc1|M_Acc2|      |      |
|      | M_L  | M_Dn | M_R  |      |      | Left | Down |  Up  |Right |      |      |
|      |      |Wh_Up |Wh_Dn |A(<-) |      |      | P_Dn | P_Up |      |      |      |
|      |      |      |M_Btn2|M_Btn1|      | \\/  |      |      |      |      |      |
 */

[_ARROWS] = LAYOUT_planck_grid(
    XXXXXXX, ALTRGHT, MS_UP,   CTLRGHT, XXXXXXX, XXXXXXX, XXXXXXX, CTLLEFT, MS_ACL1, MS_ACL2, XXXXXXX, _______,
    XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, MS_WHLU, MS_WHLD, ALTLEFT, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, MS_BTN2, MS_BTN1, _______, _______, _______, _______, _______, _______, _______
),

/* ## System

|  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |Pr_Scn|      |
|  F6  |  F7  |  F8  |  F9  | F10  |      |Brght-| Vol- | Vol+ |Brght+|      |      |
| F11  | F12  |      |      |      |      |      | Mute |P_Trac|N_Trac|      |      |
|      |KBoard| \\/  |      |      |      | Play |      |      |      |      |      |
 */

[_SYSTEM] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX,
    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
    _______, KBOARD,  _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______
),

/* ## KBoard

|      |      |      |      |      |      |      |      |      |      |Mode+ |      |
|      |      |      |      |      |      | Hue- | Sat- | Sat+ | Hue+ |      |      |
|      |      |      |      |      |      |      |Mode- |Brght-|Brght+|      |      |
|FMWare| \\/  | \\/  |      |      |      |RGB_Tg|      |      |      |      |      |
 */

[_KBOARD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, UG_PREV, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_HUED, UG_SATD,  UG_SATU, UG_HUEU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT,  UG_VALD, UG_VALU, XXXXXXX, XXXXXXX,
    FMWARE,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ## FMWare

|      |      |EEPROM|Reset |      |      |      |      |      |      |      |      |
|      |      |Debug |      |      |      |      |      |      |      |      |      |
|------|      |      |      |      |      |      |      |      |      |      |      |
| \\/  | \\/  | \\/  |      |      |      |      |      |      |      |      |      |
 */

[_FMWARE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

void debug_print(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        dprintf("\nDOWN: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    } else {
        dprintf("\nUP:   0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    }
    dprintf("time: %5u, int: %u, count: %u\n", record->event.time, record->tap.interrupted, record->tap.count);
    dprintf("----------------------------------\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // debug_print(keycode, record);
    return true;
}

// interval within which a double press counts as repeated taps
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTESC:
        case ARRSPC:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// while pressed, consider held if another key is pressed (rolling mod)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTESC:
            return true;
        default:
            return false;
    }
}
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case ARRSPC:
//             return false;
//         default:
//             return true;
//     }
// }

char chordal_hold_handedness(keypos_t key) {
    if (key.row >= 0 && key.row <= 2) {
        return 'L';
    }
    if (key.row >= 4 && key.row <= 6) {
        return 'R';
    }
    return '*';
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    if (tap_hold_record->event.type != KEY_EVENT || other_record->event.type != KEY_EVENT) {
        // dprint("\nONE\n");
        return true; // Return true on combos or other non-key events.
    }

    char tap_hold_hand = chordal_hold_handedness(tap_hold_record->event.key);
    if (tap_hold_hand == '*') {
        // dprintf("\nTWO: %c\n", tap_hold_hand);
        return true;
    }
    char other_hand = chordal_hold_handedness(other_record->event.key);
    // dprintf("\nTHREE: %c %c\n", tap_hold_hand, other_hand);
    return other_hand == '*' || tap_hold_hand != other_hand;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  //debug_mouse=true;
}
