/* Copyright 2023 Brian Low
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

#define _MAC 0
#define _SPCL 1
#define _NUM 2

enum custom_keycodes
{
  VIM_CMD = SAFE_RANGE,
  VIM_SAVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Colemak
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MODE |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  | Enter|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      | LGUI | CMD  | Space| / LALT  /       \ CTRL \  | Bspc | SPCL |  DEL |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_MAC] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_CAPS,
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, _______, _______, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LGUI, MO(_NUM), KC_LCMD, KC_SPC, KC_LALT, KC_LCTL, KC_BSPC, MO(_SPCL), KC_DEL, _______),

    /*
     * Symbols
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | MUTE |      |  (   |   =  |   )  |      |                    |   !  |   @  |   #  |   $  |   %  |  &   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | VOL+ |   '  |  {   |   _  |   }  |  "   |-------.    ,-------| Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | VOL- |   -  |  [   |      |   ]  |  +   |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      | ESCAPE|/  Save /       \      \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_SPCL] = LAYOUT(
        KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,
        KC_MUTE, _______, KC_LPRN, KC_EQUAL, KC_RPRN, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR,
        KC_VOLU, KC_QUOT, KC_LCBR, KC_UNDS, KC_RCBR, KC_DQT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        KC_VOLD, KC_MINS, KC_LBRC, _______, KC_RBRC, KC_PLUS, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, VIM_CMD, VIM_SAVE, _______, _______, _______, _______, _______),
    /*
     * Colemak
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MODE |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   !  |   @  |   #  |   $  |  %   |                    |   ^  |   &  |   *  |   (  |   )  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Enter|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      | ESCAPE|/  Save /       \      \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_NUM] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_CAPS,
        KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
        KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, _______, _______, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        _______, _______, _______, VIM_CMD, VIM_SAVE, _______, _______, _______, _______, _______)};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    {ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case VIM_CMD:
    if (record->event.pressed)
    {
      tap_code16(LCTL(KC_C));
      return 0;
    }
  case VIM_SAVE:
    if (record->event.pressed)
    {
      tap_code16(LCTL(KC_S));
      return 0;
    }
  }
  return 1;
}
