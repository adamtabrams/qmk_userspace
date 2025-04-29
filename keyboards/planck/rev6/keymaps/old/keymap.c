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
  _ARROWS,
  _SYSTEM,
  _KBOARD,
  _FMWARE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NORMAL
};

#define ARROWS TT(_ARROWS)
#define SYSTEM TT(_SYSTEM)
#define KBOARD MO(_KBOARD)
#define FMWARE MO(_FMWARE)

#define NUMSPAC LT(_NUMBER, KC_SPC)
#define SHFTESC LSFT_T(KC_ESC)

#define ALT__S  ALT_T(KC_S)
#define ALT__L  ALT_T(KC_L)
#define GUI__D  GUI_T(KC_D)
#define GUI__K  GUI_T(KC_K)
#define CTL__F  CTL_T(KC_F)
#define CTL__J  CTL_T(KC_J)

#define ALTRGHT A(KC_RGHT)
#define ALTLEFT A(KC_LEFT)
#define CTLRGHT C(KC_RGHT)
#define CTLLEFT C(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Qwerty

| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -_  |
| Bsp  |   A  | A(S) | G(D) | C(F) |   G  |   H  | C(J) | G(K) | A(L) |   ;  |  '"  |
|   !  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
| CTRL |  GUI |  ALT |System| Bsp  |S(Esc)|N(Spc)|Arrows| Left | Down |  Up  | Right|
 */

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_BSPC, KC_A,    ALT__S,  GUI__D, CTL__F, KC_G,    KC_H,    CTL__J, GUI__K,  ALT__L,  KC_SCLN, KC_QUOT,
    KC_EXLM, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, SYSTEM, KC_BSPC,SHFTESC, NUMSPAC, ARROWS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* ## Number

|      |  @   |  &   |  =   |  *   |  #   |  ^   |  $   |  +   | \|   |  %   |      |
|      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  \`  |
|      |      |  [   |  {   |  (   |  ~   |  !   |  )   |  }   |  ]   |  \   |      |
|      |      |      |      |      | Spc  | \\/  |      |      |      |      |Normal|
 */

[_NUMBER] = LAYOUT_planck_grid(
    _______, KC_AT,   KC_AMPR, KC_EQL,  KC_ASTR, KC_HASH, KC_CIRC, KC_DLR,  KC_PLUS, KC_PIPE, KC_PERC, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    _______, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_EXLM, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, _______,
    _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, NORMAL
),

/* ## Arrows

|      |      | M_Up |A(->) |C(<-) |      |      |C(->) |M_Acc1|M_Acc2|      |      |
|      | M_L  |M_Down| M_R  |      |      | Left | Down |  Up  |Right |C(<-) |      |
|      |      |Wh_Up |Wh_Dn |      |A(<-) |      |P_Down| P_Up |      |      |      |
|      |      |      |M_Btn2|M_Btn1|      |      | \\/  |      |      |      |Normal|
 */

[_ARROWS] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_MS_U, ALTRGHT, CTLLEFT, XXXXXXX, XXXXXXX, CTLRGHT, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTLLEFT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, ALTLEFT, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______, NORMAL
),

/* ## System

|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
|      |      |Pr_Scn|Pr_Scn|      |      |Brght-| Vol- | Vol+ |Brght+| Mute |      |
|      |      |      |      |      |      |      | Mute |P_Trac|N_Trac|      | Play |
|KBoard|      |      | \\/  |      |      |      |      |      |      |      |Normal|
 */

[_SYSTEM] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, XXXXXXX, KC_PSCR, KC_PSCR, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, KC_MUTE, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX, KC_MPLY,
    KBOARD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NORMAL
),

/* ## KBoard

|------|      |      |      |      |      |      |      |      |      |      |      |
|      |      |      |      |      |      | Hue- | Sat- | Sat+ | Hue+ |Mode+ |      |
|      |      |      |      |      |      |      |Mode- |Brght-|Brght+|      |RGB_Tg|
| \\/  |      |      | \\/  |      |      |      |      |      |      |      |FMWare|
 */

[_KBOARD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD,  RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_VAD, RGB_VAI, XXXXXXX, RGB_TOG,
    _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, FMWARE
),

/* ## FMWare

|      |      |      |EEPROM|Reset |      |      |      |      |      |      |      |
|      |      |Reset |Debug |      |      |      |      |      |      |      |      |
|------|      |      |      |      |      |      |      |      |      |      |      |
| \\/  |      |      | \\/  |      |      |      |      |      |      |      | \\/  |
 */

[_FMWARE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, QK_BOOT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
)

};

bool is_left_mod(uint16_t keycode) {
    switch (keycode) {
        case ALT__S:
        case GUI__D:
        case CTL__F:
            return true;
    }
    return false;
}

bool is_right_mod(uint16_t keycode) {
    switch (keycode) {
        case ALT__L:
        case GUI__K:
        case CTL__J:
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
        case NUMSPAC:
        case SHFTESC:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUMSPAC:
        case ALT__S:
        case ALT__L:
        case GUI__D:
        case GUI__K:
        case CTL__F:
        case CTL__J:
            return false;
        default:
            return true;
    }
}
