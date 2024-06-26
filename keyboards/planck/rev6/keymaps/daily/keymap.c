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

|   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
|   A  | C(S) | G(D) |Sym(F)|   G  |      |      |   H  |Sym(J)| G(K) | C(L) |   ;  |
|   Z  |   X  |   C  | A(V) |   B  |      |      |   N  | A(M) |   ,  |   .  |   /  |
|      |      |System|OS_Num|S(Esc)|OS_Num| Bsp  |A(Spc)| Tab  |      |      |      |
 */

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   XXXXXXX, XXXXXXX, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,
    KC_A,    CTL__S,  GUI__D, SYM__F,  KC_G,   XXXXXXX, XXXXXXX, KC_H,   SYM__J, GUI__K,  CTL__L,  KC_SCLN,
    KC_Z,    KC_X,    KC_C,   ALT__V,  KC_B,   XXXXXXX, XXXXXXX, KC_N,   ALT__M, KC_COMM, KC_DOT,  KC_SLSH,
    XXXXXXX, XXXXXXX, SYSTEM, OS_NUM,  SFTESC, OS_NUM,  KC_BSPC, ARRSPC, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ## Number

|      |      |      |      |      |      |      |      |      |      |      |      |
|  1   |  2   |  3   |  4   |  5   |      |      |  6   |  7   |  8   |  9   |  0   |
|      |      |      |      |      |      |      |      |      |      |      |      |
|      |      |      |      |      | \\/  |      |      |      |      |      |      |
 */

[_NUMBER] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## Symbol

|  "   |      |  [   |  ]   |  #   |      |      |      |  _   |  &   |  \|  |  %   |
|  @   |  '   |  (   |  )   | \`   |      |      |  ^   |  =   |  *   |  -   |  !   |
|      |  $   |  {   |  }   |      |      |      |      |  +   |      |  ~   |  \   |
|      |      |      |      | foo  |      |      | Tab  |      |      |      |      |
 */

// TODO: left thumb: hold layer or common key/action

[_SYMBOL] = LAYOUT_planck_grid(
    KC_DQUO, XXXXXXX, KC_LBRC, KC_RBRC, KC_HASH, _______, _______, XXXXXXX, KC_UNDS, KC_AMPR, KC_PIPE, KC_PERC,
    KC_AT,   KC_QUOT, KC_LPRN, KC_RPRN, KC_GRV,  _______, _______, KC_CIRC, KC_EQL,  KC_ASTR, KC_MINS, KC_EXLM,
    XXXXXXX, KC_DLR,  KC_LCBR, KC_RCBR, XXXXXXX, _______, _______, XXXXXXX, KC_PLUS, XXXXXXX, KC_TILD, KC_BSLS,
    _______, _______, _______, _______, OS_NUM,  _______, _______, KC_TAB,  _______, _______, _______, _______
),

/* ## Arrows

|      |A(->) | M_Up |C(<-) |      |      |      |      |C(->) |M_Acc1|M_Acc2|      |
|      | M_L  |M_Down| M_R  |      |      |      | Left | Down |  Up  |Right |C(<-) |
|      |      |Wh_Up |Wh_Dn |A(<-) |      |      |      |P_Down| P_Up |      |      |
|      |      |      |M_Btn2|M_Btn1|      |      | \\/  |      |      |      |      |

|      |A(->) | M_Up |      |      |      |      |      |C(<-) |M_Acc1|M_Acc2|      |
|      | M_L  |M_Down| M_R  |      |      |      | Left | Down |  Up  |Right |C(->) |
|      |C(<-) |Wh_Up |Wh_Dn |A(<-) |      |      |      |P_Down| P_Up |      |      |
|      |      |      |M_Btn2|M_Btn1|      |      | \\/  |      |      |      |      |
 */

[_ARROWS] = LAYOUT_planck_grid(
    XXXXXXX, ALTRGHT, KC_MS_U, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, CTLLEFT, KC_ACL1, KC_ACL2, XXXXXXX,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTLRGHT,
    XXXXXXX, CTLLEFT, KC_WH_D, KC_WH_U, ALTLEFT, _______, _______, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
    _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______, _______
),

/* ## System

|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
|      |      |Pr_Scn|Pr_Scn|      |      |Brght-| Vol- | Vol+ |Brght+| Mute |      |
|      |      |      |      |      |      |      | Mute |P_Trac|N_Trac|      | Play |
|      |      |KBoard| \\/  |      |      |      |      |      |      |      |      |
 */

/* TODO: update this */
[_SYSTEM] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, XXXXXXX, KC_PSCR, KC_PSCR, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, KC_MUTE, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX, KC_MPLY,
    _______, KBOARD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ## KBoard

|      |      |      |      |      |      |      |      |      |      |      |      |
|      |      |      |      |      |      | Hue- | Sat- | Sat+ | Hue+ |Mode+ |      |
|      |      |      |      |      |      |      |Mode- |Brght-|Brght+|      |RGB_Tg|
|FMWare| \\/  | \\/  |      |      |      |      |      |      |      |      |      |
 */

/* TODO: update this */
[_KBOARD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD,  RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_VAD, RGB_VAI, XXXXXXX, RGB_TOG,
    FMWARE,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ## FMWare

|      |      |EEPROM|Reset |      |      |      |      |      |      |      |      |
|      |Reset |Debug |      |      |      |      |      |      |      |      |      |
|      |      |      |      |      |      |      |      |      |      |      |      |
| \\/  | \\/  | \\/  |      |      |      |      |      |      |      |      |      |
 */

[_FMWARE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

void tap_if_needed(uint16_t keycode, bool count) {
    if (!count) {
        tap_code16(keycode);
        dprintf("TAPPED: 0x%04X\n", keycode);
        dprintf("----------------------------------\n");
    }
}

int8_t determine_side(keyrecord_t *record) {
    switch (record->event.key.row) {
        case 0:
        case 1:
        case 2:
            return -1;
        case 4:
        case 5:
        case 6:
            return 1;
    }
    return 0;
}

int8_t determine_mod_side(uint16_t keycode) {
    switch (keycode) {
        case ALT__V:
        case GUI__D:
        case CTL__S:
            return -1;
        case ALT__M:
        case GUI__K:
        case CTL__L:
            return 1;
    }
    return 0;
}

int8_t process_mod(int8_t mods, uint16_t keycode, keyrecord_t *record) {
    int8_t side = determine_mod_side(keycode);
    if (record->event.pressed) {
        if (mods == 0 && side != 0) {
            return side;
        }
        if (mods * side > 0) {
            return side;
        }
    } else {
        if (mods * side > 0) {
            return -1 * side;
        }
    }
    return 0;
}

void debug_print(int8_t mods, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        dprintf("\nDOWN: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    } else {
        dprintf("\nUP:   0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
    }
    dprintf("mods: %d\n", mods);
    dprintf("time: %5u, int: %u, count: %u\n", record->event.time, record->tap.interrupted, record->tap.count);
    dprintf("----------------------------------\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static int8_t mods;
    static uint16_t prev_key;
    static bool prev_count;
    static bool shift_on;

    debug_print(mods, keycode, record);

    if (keycode == SFTESC && !record->tap.count) {
        shift_on = record->event.pressed;
        return true;
    }

    // opposite side as active mod
    if (mods != 0 && determine_side(record) * mods < 0) {
        if (record->event.pressed) {
            tap_code16(keycode);
        }
        return false;
    }

    int8_t delta = process_mod(mods, keycode, record);
    mods += delta;

    // first mod pressed
    if (mods != 0 && delta == mods) {
        prev_key = keycode;
        prev_count = record->tap.count;
        return true;
    }

    if (record->event.pressed && determine_side(record) * mods > 0) {
        dprintf("SPECIAL: 0x%04X\n", keycode);
        dprintf("----------------------------------\n");
        clear_mods();
        if (shift_on) {
            register_code(KC_LSFT);
        }
        tap_if_needed(prev_key, prev_count);
        tap_code16(keycode);
        prev_key = 0;
        prev_count = 0;
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
