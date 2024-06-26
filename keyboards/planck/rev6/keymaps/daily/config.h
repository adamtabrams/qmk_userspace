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

// General Configs
#define NO_ACTION_ONESHOT
#define FORCE_NKRO

// Layer Toggle
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

// Mouse Configs
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_1 4
#define MK_C_OFFSET_UNMOD 14
#define MK_C_OFFSET_2 28
// for MK_W lower is faster
#define MK_W_INTERVAL_UNMOD 80

// Tap-Hold Configs
#define TAPPING_TERM 155
// #define TAPPING_TERM 165
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM 120
#define QUICK_TAP_TERM_PER_KEY
