/* Copyright (C) 2021 Adam Abrams
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#pragma once

/* General Configs */

#define FORCE_NKRO
#define ONESHOT_TIMEOUT 1000
#define ONESHOT_TAP_TOGGLE 2
// #define NO_ACTION_ONESHOT

/* Layer Toggle */

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
// #define TAPPING_TOGGLE 3

/* Mouse Configs */

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_1 4
#define MK_C_OFFSET_UNMOD 18
// #define MK_C_OFFSET_UNMOD 14
// #define MK_C_OFFSET_UNMOD 20
#define MK_C_OFFSET_2 28
#define MK_W_INTERVAL_UNMOD 80
// ^ lower MK_W means faster

/* Tap-Hold Configs */

// interval within which a press is considered a tap
#define TAPPING_TERM 140
// #define TAPPING_TERM 160
// #define TAPPING_TERM 155
// #define TAPPING_TERM 165

// interval within which a double press counts as repeated taps
#define QUICK_TAP_TERM 110
// #define QUICK_TAP_TERM 120
// #define QUICK_TAP_TERM 100
#define QUICK_TAP_TERM_PER_KEY

// while pressed, consider held if another key is tapped
#define PERMISSIVE_HOLD

// while pressed, consider held if another key is pressed (rolling mod)
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


#define COMBO_MUST_HOLD_MODS
