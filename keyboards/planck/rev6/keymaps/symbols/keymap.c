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
  QWERTY = SAFE_RANGE,
  NORMAL
};

/* #define ARROWS TT(_ARROWS) */
#define SYSTEM TT(_SYSTEM)
#define KBOARD MO(_KBOARD)
#define FMWARE MO(_FMWARE)

/* #define NUMSPAC LT(_NUMBER, KC_SPC) */
/* #define SHFTESC LSFT_T(KC_ESC) */
#define SFTESC LSFT_T(KC_ESC)
/* #define NUM__E LT(_NUMBER, KC_E) */
/* #define SFTSPC LSFT_T(KC_SPC) */
/* #define NUMESC LT(_NUMBER, KC_ESC) */
#define OS_NUM OSL(_NUMBER)
#define ARRSPC LT(_ARROWS, KC_SPC)
/* #define OS_SFT OSM(MOD_LSFT) */
#define SYM__F LT(_SYMBOL, KC_F)
#define SYM__J LT(_SYMBOL, KC_J)

#define ALT__V  ALT_T(KC_V)
#define ALT__M  ALT_T(KC_M)
#define GUI__D  GUI_T(KC_D)
#define GUI__K  GUI_T(KC_K)
#define CTL__S  CTL_T(KC_S)
#define CTL__L  CTL_T(KC_L)

#define ALTRGHT A(KC_RGHT)
#define ALTLEFT A(KC_LEFT)
#define CTLRGHT C(KC_RGHT)
#define CTLLEFT C(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Qwerty

| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -_  |
| Bsp  |   A  | A(S) | G(D) | C(F) |   G  |   H  | C(J) | G(K) | A(L) |   ;  |  '"  |
|   ~  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
| CTRL |  GUI |  ALT |System| Bsp  |S(Esc)|N(Spc)|Arrows| Left | Down |  Up  | Right|

|      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
|      |   A  | C(S) | G(D) |Sym(F)|   G  |   H  |Sym(J)| G(K) | C(L) |   ;  |      |
| Tab  |   Z  |   X  |   C  | A(V) |   B  |   N  | A(M) |   ,  |   .  |   /  | Enter|
|      |      |      |System|OS_Num|S(Esc)|A(Spc)| Bsp  |      |      |      |      |
 */

// NOTE: what to put on right thumb secondary: backspace or enter
// TODO: handle accidental homerow mod combos

[_QWERTY] = LAYOUT_planck_grid(
    XXXXXXX, KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    XXXXXXX, KC_A,    CTL__S,  GUI__D, SYM__F, KC_G,   KC_H,   SYM__J,  GUI__K,  CTL__L,  KC_SCLN, XXXXXXX,
    KC_TAB,  KC_Z,    KC_X,    KC_C,   ALT__V, KC_B,   KC_N,   ALT__M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, SYSTEM, OS_NUM, SFTESC, ARRSPC, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ## Number

|      |  @   |  &   |  =   |  ^   |  #   |  ~   |  $   |  !   | \|   |  +   |      |
|      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  \`  |
|      |  %   |  [   |  {   |  (   | \|   |  *   |  )   |  }   |  ]   |  \   |      |
|      |      |      |      |      | Spc  | \\/  |      |      |      |      |Normal|

|      |  @   |  &   |  =   |  ^   |  #   |  -   |  $   |  !   | \|   |  +   |      |
|      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
|      |  %   |  [   |  {   |  (   |      |  *   |  )   |  }   |  ]   |  \   |      |
|      |      |      |      |      | \\/  |      |      |      |      |      |Normal|

|      |      |  -   |  =   |      |      |      |  _   |      |      |  +   |      |
|      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
|      |      |  [   |  {   |  (   |      |  *   |  )   |  }   |  ]   |      |      |
|Normal|      |      |      |      | \\/  |      |      |      |      |      |      |
 */

[_NUMBER] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX, XXXXXXX, KC_PLUS, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX, KC_ASTR, KC_RPRN, KC_RCBR, KC_RBRC, _______, _______,
    NORMAL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## Symbol

|      |      |      |  =   |      |  ~   |      |  _   |      |  \|  |  %   |      |
|      |  &   |  -   |  $   |      |  \`  |  #   |      |      |  "   |  '   |      |
|      |      |      |  ^   |      |      |  *   |  @   |      |  !   |  \   |      |
|Normal|      |      |      |      |      |      |      |      |      |      |Normal|
 */

[_SYMBOL] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, KC_EQL,  XXXXXXX, KC_TILD, XXXXXXX, KC_UNDS, XXXXXXX, KC_PIPE, KC_PERC, _______,
    _______, KC_AMPR, KC_MINS, KC_DLR,  XXXXXXX, KC_GRV,  KC_HASH, XXXXXXX, XXXXXXX, KC_DQUO, KC_QUOT, _______,
    _______, XXXXXXX, XXXXXXX, KC_CIRC, XXXXXXX, XXXXXXX, KC_ASTR, KC_AT,   XXXXXXX, KC_EXLM, KC_BSLS, _______,
    NORMAL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## Arrows

|      |      | M_Up |A(->) |C(<-) |      |      |C(->) |M_Acc1|M_Acc2|      |      |
|      | M_L  |M_Down| M_R  |      |      | Left | Down |  Up  |Right |C(<-) |      |
|      |      |Wh_Up |Wh_Dn |      |A(<-) |      |P_Down| P_Up |      |      |      |
|      |      |      |M_Btn2|M_Btn1|      |      | \\/  |      |      |      |Normal|

|      |      |A(->) | M_Up |C(<-) |      |      |C(->) |M_Acc1|M_Acc2|      |      |
|      |      | M_L  |M_Down| M_R  |      | Left | Down |  Up  |Right |C(<-) |      |
|      |      |      |Wh_Up |Wh_Dn |A(<-) |      |P_Down| P_Up |      |      |      |
|Normal|      |      |      |M_Btn2|M_Btn1| \\/  |      |      |      |      |      |
 */

[_ARROWS] = LAYOUT_planck_grid(
    _______, XXXXXXX, ALTRGHT, KC_MS_U, CTLLEFT, XXXXXXX, XXXXXXX, CTLRGHT, KC_ACL1, KC_ACL2, XXXXXXX, _______,
    _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTLLEFT, _______,
    _______, XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, ALTLEFT, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______,
    NORMAL,  _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______
),

/* ## System

|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
|      |      |Pr_Scn|Pr_Scn|      |      |Brght-| Vol- | Vol+ |Brght+| Mute |      |
|      |      |      |      |      |      |      | Mute |P_Trac|N_Trac|      | Play |
|Normal|      |KBoard| \\/  |      |      |      |      |      |      |      |      |
 */

[_SYSTEM] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, XXXXXXX, KC_PSCR, KC_PSCR, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, KC_MUTE, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX, KC_MPLY,
    NORMAL,  _______, KBOARD,  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## KBoard

|------|      |      |      |      |      |      |      |      |      |      |      |
|      |      |      |      |      |      | Hue- | Sat- | Sat+ | Hue+ |Mode+ |      |
|      |      |      |      |      |      |      |Mode- |Brght-|Brght+|      |RGB_Tg|
|Normal|FMWare| \\/  | \\/  |      |      |      |      |      |      |      |      |
 */

[_KBOARD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD,  RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_VAD, RGB_VAI, XXXXXXX, RGB_TOG,
    NORMAL,  FMWARE,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ## FMWare

|      |      |      |EEPROM|Reset |      |      |      |      |      |      |      |
|      |      |Reset |Debug |      |      |      |      |      |      |      |      |
|------|      |      |      |      |      |      |      |      |      |      |      |
|      | \\/  | \\/  | \\/  |      |      |      |      |      |      |      |      |
 */

[_FMWARE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, QK_BOOT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

bool is_left_mod(uint16_t keycode) {
    switch (keycode) {
        case ALT__V:
        case GUI__D:
        case CTL__S:
            return true;
    }
    return false;
}

bool is_right_mod(uint16_t keycode) {
    switch (keycode) {
        case ALT__M:
        case GUI__K:
        case CTL__L:
            return true;
    }
    return false;
}

bool is_left_key(int row) {
    return row <= 2;
}

bool is_right_key(int row) {
    return row >= 4 && row <= 6;
}

void tap_if_needed(uint16_t keycode, int count) {
    if (count == 0) {
        tap_code16(keycode);
        dprintf("TAPPED: 0x%04X\n", keycode);
        dprintf("----------------------------------\n");
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t mod;
    static int count;
    static bool l_mod_active = false;
    static bool r_mod_active = false;
    bool is_l_mod = is_left_mod(keycode);
    bool is_r_mod = is_right_mod(keycode);
    bool is_l_key = is_left_key(record->event.key.row);
    bool is_r_key = is_right_key(record->event.key.row);

    if (record->event.pressed) {
        dprintf("\nDOWN: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    } else {
        dprintf("\nUP:   0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    }
    dprintf("l: %u, r: %u, m: %04X\n", l_mod_active, r_mod_active, mod);
    dprintf("time: %5u, int: %u, count: %u\n", record->event.time, record->tap.interrupted, record->tap.count);
    dprintf("----------------------------------\n");

    // TEST:
    return true;

    // opposite side
    if ((l_mod_active && !is_l_key) || (r_mod_active && !is_r_key)) {
        return true;
    }

    // same side
    if (record->event.pressed && (l_mod_active || r_mod_active)) {
        clear_mods();
        tap_if_needed(mod, count);
        if (is_l_mod || is_r_mod) {
            tap_if_needed(keycode, record->tap.count);
        }
        return true;
    }

    // activate mod
    if (record->event.pressed && (is_l_mod || is_r_mod)) {
        l_mod_active = is_l_mod;
        r_mod_active = is_r_mod;
        mod = keycode;
        count = record->tap.count;
        return true;
    }

    // disactivate mod
    if (l_mod_active || r_mod_active) {
        l_mod_active = false;
        r_mod_active = false;
        return true;
    }

    if (keycode == NORMAL) {
            layer_clear();
            return false;
    }

    return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case NUM__E: */
        /* case NUMESC: */
        case SFTESC:
        /* case SFTSPC: */
        case ARRSPC:
        /* case NUMSPAC: */
        /* case SHFTESC: */
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case SFTSPC: */
        case ARRSPC:
        case SYM__J:
        case SYM__F:
        /* case NUMSPAC: */
        case ALT__V:
        case ALT__M:
        case GUI__D:
        case GUI__K:
        case CTL__S:
        case CTL__L:
            return false;
        default:
            return true;
    }
}
