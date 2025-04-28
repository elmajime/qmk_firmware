/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum planck_layers { _BEPO, _QWERTY, _ARR_NUM, _FUNCTIONS, _CHARS, _ADJUST };

enum planck_keycodes { BEPO = SAFE_RANGE, QWERTY, ARROW_NUM, BACKLIT, EXT_PLV, EXCL_CHAP, COMMA_SEMI, QUEST_TICK, DOT_DOUBLE };

#define SAVE LCTL(KC_S)
#define UNDO LCTL(KC_W)
#define REDO LCTL(KC_Y)
#define REPLACE LCTL(KC_R)
#define CLOSE LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define OPEN LCTL(KC_O)
// #define UN LSFT(KC_1)
// #define DEUX LSFT(KC_2)
// #define TROIS LSFT(KC_3)
// #define QUATRE LSFT(KC_4)
// #define CINQ LSFT(KC_5)
// #define SIX LSFT(KC_6)
// #define SEPT LSFT(KC_7)
// #define HUIT LSFT(KC_8)
// #define NEUF LSFT(KC_9)
// #define ZERO LSFT(KC_0)
#define DEGREES LSFT(KC_MINS)
#define LANGLEB KC_NUBS
#define RANGLEB LSFT(KC_NUBS)
#define LCURLB RALT(KC_4)
#define RCURLB RALT(KC_EQL)
#define AROBASE RALT(KC_0)
#define PLUS KC_PPLS
#define MINUS KC_PMNS
#define DIVIDE KC_PSLS
#define MULTIPLY KC_PAST
#define EQUAL KC_EQL
#define HASHTAG RALT(KC_3)
#define LSQUARB RALT(KC_5)
#define RSQUARB RALT(KC_MINS)
#define PIPE RALT(KC_6)
#define UNDERSCORE KC_8
#define TILD RALT(KC_2)
#define FORWARD_SLSH RALT(KC_8)
#define LPAREN_LOWER LT(3, KC_5)
#define RPAREN_RAISE LT(4, KC_MINS)
#define CHAPEAU KC_LBRC

// // Tap Dance keycodes
// enum td_keycodes { TD_CURRENCIES, TD_LALT_RALT };

// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP, // Send two single taps
//     TD_TRIPLE_TAP,
//     TD_TRIPLE_HOLD,
//     TD_TRIPLE_SINGLE_TAP, // Send triple single taps

// } td_state_t;

// // Create a global instance of the tapdance state type
// static td_state_t td_state;

// // Declare your tapdance functions:

// // Function to determine the current tapdance state
// td_state_t cur_dance(qk_tap_dance_state_t *state);

// // `finished` and `reset` functions for each tapdance keycode
// void TD_CURRENCIES_finished(qk_tap_dance_state_t *state, void *user_data);
// void TD_CURRENCIES_reset(qk_tap_dance_state_t *state, void *user_data);

// void TD_LALT_RALT_finished(qk_tap_dance_state_t *state, void *user_data);
// void TD_LALT_RALT_reset(qk_tap_dance_state_t *state, void *user_data);

// void TD_RPAREN_RAISE_finished(qk_tap_dance_state_t *state, void *user_data);
// void TD_RPAREN_RAISE_reset(qk_tap_dance_state_t *state, void *user_data);

// void TD_CHAPEAU_finished(qk_tap_dance_state_t *state, void *user_data);
// void TD_CHAPEAU_reset(qk_tap_dance_state_t *state, void *user_data);

// void TD_LPAREN_LOWER_finished(qk_tap_dance_state_t *state, void *user_data);
// void TD_LPAREN_LOWER_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Bépo
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   B  |   é  |   P  |   O  |   è  |  !^  |   V  |   D  |   L  |   J  |  Z   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  W   |   A  |   U  |   I  |   E  |  ,;  |   C  |   T  |   S  |   R  |   N  |  M   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ù%  |   à  |   Y  |   X  |  .:  |   K  |  ?'  |   Q  |   G  |   H  |   F  |  ç   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Left |  Up  |LCTRL$| RALT |Space |FUNCTS|CHARS |LShift|Enter | Tab  |Down  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_BEPO] = LAYOUT_ortho_4x12(QK_GESC, KC_B, KC_2, KC_P, KC_O, KC_7, EXCL_CHAP, KC_V, KC_D, KC_L, KC_J, KC_W, KC_Z, KC_Q, KC_U, KC_I, KC_E, COMMA_SEMI, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN, KC_QUOT, KC_0, KC_Y, KC_X, DOT_DOUBLE, KC_K, QUEST_TICK, KC_A, KC_G, KC_H, KC_F, KC_9, KC_LEFT, KC_UP, LCTL_T(KC_RBRC), KC_RALT, KC_SPC, LPAREN_LOWER, RPAREN_RAISE, KC_LSFT, KC_ENT, LGUI_T(KC_TAB), KC_DOWN, KC_RGHT),
    // old [_BEPO] = LAYOUT( KC_ESC, KC_B, KC_2, KC_P, KC_O, KC_7, EXCL_CHAP, KC_V, KC_D, KC_L, KC_J, KC_W, KC_Z, KC_Q, KC_U, KC_I, KC_E, COMMA_SEMI, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN, KC_QUOT, KC_0, KC_Y, KC_X, DOT_DOUBLE, KC_K, QUEST_TICK, KC_A, KC_G, KC_H, KC_F, KC_9, KC_LEFT, KC_UP, KC_LCTL, TD(TD_LALT_RALT), KC_SPC, LPAREN_LOWER, RPAREN_RAISE, KC_LSFT, KC_ENT, LGUI_T(KC_TAB), KC_DOWN, KC_RIGHT),
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | DEL  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_TRNS, KC_L, KC_SCLN, KC_DEL, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Arrows_and_numpad
     * ,-----------------------------------------------------------------------------------.
     * |      |  N/A |  N/A |  Up  | N/A  | N/A  |VerNum|  =   |   7  |   8  |   9  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | N/A  |  N/A | Left | Down | Right| N/A  | N/A  | Tab  |   4  |   5  |   6  |   *  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | N/A  |  N/A |  N/A | N/A  | N/A  | N/A  | N/A  | N/A  |   3  |   2  |   1  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | N/A  |  N/A | LAlt | LCtrl|LShift|      |      | N/A  |   0  |   .  | Enter|   +  |
     * `-----------------------------------------------------------------------------------'
     */
    [_ARR_NUM] = LAYOUT_ortho_4x12(KC_TRNS, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NUM, KC_EQL, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_PAST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_NO, KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_NO, KC_P0, KC_PDOT, KC_PENT, KC_PPLS),
    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | F12  | Save | Undo | Redo |Replce| BSPC | DEL  | NONE | NONE | NONE | NONE | NONE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Captr |Close | Cut  | Copy |Paste |      |Insert| Open |      | NONE | NONE | NONE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |ADJUST|      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTIONS] = LAYOUT_ortho_4x12(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SAVE, UNDO, REDO, REPLACE, KC_BSPC, KC_DEL, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_PSCR, CLOSE, CUT, COPY, PASTE, KC_NO, KC_INS, OPEN, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PAGE_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_DOWN, KC_END),
    // old [_LOWER] = LAYCURRENCIES), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SAVE, UNDO, REDO, REPLACE, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_PRINT_SCREEN, CLOSE, CUT, COPY, PASTE, KC_WWW_REFRESH, KC_INSERT, OPEN, XXXXXXX, KC_VOLD, KC_KB_MUTE, KC_VOLU, KC_HOME, KC_PAGE_UP, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAGE_DOWN, KC_END),
    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      | & (1)| é (2)| " (3)| ' (4)| ( (5)| - (6)| è (7)| _ (8)| ç (9)| à (0)| = (°)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  &   |   "  |   <  |   >  |   {  |   }  |   @  |   +  |   -  |   /  |   *  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | NONE |   #  |   [  |   ]  |   |  |   ^  |   _  |   ~  |   \  |   !  |   .  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_CHARS] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DEGREES, KC_1, KC_3, LANGLEB, RANGLEB, LCURLB, RCURLB, AROBASE, PLUS, MINUS, DIVIDE, MULTIPLY, EQUAL, KC_NO, HASHTAG, LSQUARB, RSQUARB, PIPE, CHAPEAU, UNDERSCORE, TILD, FORWARD_SLSH, KC_SLSH, KC_PDOT, KC_M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    // old [_RAISE]TD(TD_CURRENCIES), UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, ZERO, DEGREES, KC_1, KC_3, LANGLEB, RANGLEB, LCURLB, RCURLB, AROBASE, PLUS, MINUS, DIVIDE, MULTIPLY, EQUAL, XXXXXXX, HASHTAG, LSQUARB, RSQUARB, PIPE, CHAPEAU, UNDERSCORE, TILD, FORWARD_SLSH, KC_SLSH, KC_PDOT, KC_M, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* Adjust (Lower + Raise)
     *                      v------------------------RGB CONTROL--------------------v
     * ,-----------------------------------------------------------------------------------.
     * |  N/A | N/A  |  N/A | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  N/A |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Debug|      |MUSmod|Aud on|Audoff|      |      |Bépo  |Qwerty|ArrNum|      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Reset|AuPrev|AuNext|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, KC_NO, DB_TOGG, KC_TRNS, MU_NEXT, AU_ON, AU_OFF, KC_NO, KC_NO, DF(_BEPO), DF(_QWERTY), DF(_ARR_NUM), KC_TRNS, KC_TRNS, QK_BOOT, AU_PREV, AU_NEXT, MU_ON, MU_OFF, MI_ON, MI_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
    // oldJUST] = LAYOUT_planck_gr(_______, QK_BOOT, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, _______, BACKLIT, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, BEPO, QWERTY, COLEMAK, PLOVER, _______, _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

    // [6] = LAYOUT_ortho_4x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Bépo
    //  * ,-----------------------------------------------------------------------------------.
    //  * | ESC  |   B  |   é  |   P  |   O  |   è  |   !  |   V  |   D  |   L  |   J  |  Z   |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |  W   |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M   |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |  ù   |   à  |   Y  |   X  |   .  |   K  |   ?  |   Q  |   G  |   H  |   F  |  ç   |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Left |  Up  |LCTRL |LRALT |Space |Lower |Raise |Shift |Enter | Tab  |Down  |Right |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_BEPO] = LAYOUT_planck_grid(KC_ESC, KC_B, KC_2, KC_P, KC_O, KC_7, EXCL_CHAP, KC_V, KC_D, KC_L, KC_J, KC_W, KC_Z, KC_Q, KC_U, KC_I, KC_E, COMMA_SEMI, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN, KC_QUOT, KC_0, KC_Y, KC_X, DOT_DOUBLE, KC_K, QUEST_TICK, KC_A, KC_G, KC_H, KC_F, KC_9, KC_LEFT, KC_UP, KC_LCTL, TD(TD_LALT_RALT), KC_SPC, LPAREN_LOWER, RPAREN_RAISE, KC_LSFT, KC_ENT, LGUI_T(KC_TAB), KC_DOWN, KC_RIGHT),

    // /* Qwerty
    //  * ,-----------------------------------------------------------------------------------.
    //  * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |      |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_QWERTY] = LAYOUT_planck_grid(KC_Q, KC_W, KC_E, KC_R, KC_T, _______, _______, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, _______, _______, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // /* Colemak
    //  * ,-----------------------------------------------------------------------------------.
    //  * |   Q  |   W  |   F  |   P  |   G  |      |      |   J  |   L  |   U  |   Y  |   ;  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |   A  |   R  |   S  |   T  |   D  |      |      |   H  |   N  |   E  |   I  |   O  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |   Z  |   X  |   C  |   V  |   B  |      |      |   K  |   M  |   ,  |   .  |   /  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |      |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_COLEMAK] = LAYOUT_planck_grid(KC_Q, KC_W, KC_F, KC_P, KC_G, _______, _______, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_A, KC_R, KC_S, KC_T, KC_D, _______, _______, KC_H, KC_N, KC_E, KC_I, KC_O, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // /* Lower
    //  * ,-----------------------------------------------------------------------------------.
    //  * | $ €  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | F12  | Save | Undo | Redo |Replce| BSPC | DEL  | NONE | NONE |Prev  | Play |Next  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |Captr |Close | Cut  | Copy |Paste |Refrsh|Insert| Open |      | Vol- | Mute |Vol+  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Home | PgUp |      |      |      |             |      |      |      | PgDn | End  |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_LOWER] = LAYOUT_planck_grid(TD(TD_CURRENCIES), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SAVE, UNDO, REDO, REPLACE, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_PRINT_SCREEN, CLOSE, CUT, COPY, PASTE, KC_WWW_REFRESH, KC_INSERT, OPEN, XXXXXXX, KC_VOLD, KC_KB_MUTE, KC_VOLU, KC_HOME, KC_PAGE_UP, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAGE_DOWN, KC_END),

    // /* Raise
    //  * ,-----------------------------------------------------------------------------------.
    //  *|QK_GESC|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   °  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |  &   |   "  |   <  |   >  |   {  |   }  |   @  |   +  |   -  |   /  |   *  |   =  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | NONE |   #  |   [  |   ]  |   |  |   ^  |   _  |   ~  |   \  |   !  |   .  |   ,  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |             |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_RAISE] = LAYOUT_planck_grid(TD(TD_CURRENCIES), UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, ZERO, DEGREES, KC_1, KC_3, LANGLEB, RANGLEB, LCURLB, RCURLB, AROBASE, PLUS, MINUS, DIVIDE, MULTIPLY, EQUAL, XXXXXXX, HASHTAG, LSQUARB, RSQUARB, PIPE, CHAPEAU, UNDERSCORE, TILD, FORWARD_SLSH, KC_SLSH, KC_PDOT, KC_M, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // /* Plover layer (http://opensteno.org)
    //  * ,-----------------------------------------------------------------------------------.
    //  * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_PLOVER] = LAYOUT_planck_grid(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX),

    // /* Adjust (Lower + Raise)
    //  *                      v------------------------RGB CONTROL--------------------v
    //  * ,-----------------------------------------------------------------------------------.
    //  * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |BK_LED|MUSmod|Aud on|Audoff|AGnorm|AGswap|Bépo  |Azerty|Qwerty|Colemk|Plover|
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |             |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_ADJUST] = LAYOUT_planck_grid(_______, QK_BOOT, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, _______, BACKLIT, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, BEPO, QWERTY, COLEMAK, PLOVER, _______, _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

// #ifdef AUDIO_ENABLE
// float plover_song[][2]    = SONG(PLOVER_SOUND);
// float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
// #endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

uint16_t lastKeyCode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods      = get_mods();
    bool    anyShift  = (mods == MOD_BIT(KC_LSFT) || (mods == MOD_BIT(KC_RSFT)));
    uint8_t lastShift = mods & MOD_BIT(KC_LSFT) ? MOD_BIT(KC_LSFT) : MOD_BIT(KC_RSFT);
    if (!anyShift) lastShift = 0;

    switch (keycode) {
            //         case BEPO:
            //             if (record->event.pressed) {
            //                 set_single_persistent_default_layer(_BEPO);
            //             }
            //             return false;
            //             break;
            //         case QWERTY:
            //             if (record->event.pressed) {
            //                 // print("mode just switched to qwerty and this is a huge string\n");
            //                 set_single_persistent_default_layer(_QWERTY);
            //             }
            //             return false;
            //             break;
            //         case COLEMAK:
            //             if (record->event.pressed) {
            //                 set_single_persistent_default_layer(_COLEMAK);
            //             }
            //             return false;
            //             break;
            //         case BACKLIT:
            //             if (record->event.pressed) {
            //                 register_code(KC_RSFT);
            // #ifdef BACKLIGHT_ENABLE
            //                 backlight_step();
            // #endif
            // #ifdef KEYBOARD_planck_rev5
            //                 writePinLow(E6);
            // #endif
            //             } else {
            //                 unregister_code(KC_RSFT);
            // #ifdef KEYBOARD_planck_rev5
            //                 writePinHigh(E6);
            // #endif
            //             }
            //             return false;
            //             break;
            //         case PLOVER:
            //             if (record->event.pressed) {
            // #ifdef AUDIO_ENABLE
            //                 stop_all_notes();
            //                 PLAY_SONG(plover_song);
            // #endif
            //                 layer_off(_RAISE);
            //                 layer_off(_LOWER);
            //                 layer_off(_ADJUST);
            //                 layer_on(_PLOVER);
            //                 if (!eeconfig_is_enabled()) {
            //                     eeconfig_init();
            //                 }
            //                 keymap_config.raw  = eeconfig_read_keymap();
            //                 keymap_config.nkro = 1;
            //                 eeconfig_update_keymap(keymap_config.raw);
            //             }
            //             return false;
            //             break;
            //         case EXT_PLV:
            //             if (record->event.pressed) {
            // #ifdef AUDIO_ENABLE
            //                 PLAY_SONG(plover_gb_song);
            // #endif
            //                 layer_off(_PLOVER);
            //             }
            //             return false;
            //             break;

        case EXCL_CHAP:
            if (record->event.pressed) {
                clear_mods();
                lastKeyCode = KC_SLSH;

                if (anyShift) {
                    mods &= ~(lastShift);
                    lastKeyCode = CHAPEAU;
                }

                set_mods(mods);
                register_code16(lastKeyCode);
                if (anyShift) mods |= lastShift;
                set_mods(mods);
            }
            break;
        case COMMA_SEMI:
            if (record->event.pressed) {
                clear_mods();
                lastKeyCode = KC_M;

                if (anyShift) {
                    mods &= ~(lastShift);
                    lastKeyCode = KC_COMM;
                }

                set_mods(mods);
                register_code16(lastKeyCode);
                if (anyShift) mods |= lastShift;
                set_mods(mods);
            }
            break;
        case DOT_DOUBLE:
            if (record->event.pressed) {
                clear_mods();
                lastKeyCode = S(KC_COMM);

                if (anyShift) {
                    mods &= ~(lastShift);
                    lastKeyCode = KC_DOT;
                }

                set_mods(mods);
                register_code16(lastKeyCode);
                if (anyShift) mods |= lastShift;
                set_mods(mods);
            }
            break;
        case QUEST_TICK:
            if (record->event.pressed) {
                clear_mods();
                lastKeyCode = S(KC_M);

                if (anyShift) {
                    mods &= ~(lastShift);
                    lastKeyCode = KC_4;
                }

                set_mods(mods);
                register_code16(lastKeyCode);
                if (anyShift) mods |= lastShift;
                set_mods(mods);
            }
            break;
        default:
            break;
    }

    switch (keycode) {
        case KC_RSFT:
        case KC_LSFT:
        case EXCL_CHAP:
        case COMMA_SEMI:
        case DOT_DOUBLE:
        case QUEST_TICK:
            if (!record->event.pressed) {
                unregister_code16(lastKeyCode);
            }
            break;
        default:
            break;
    }

    return true;
}

// bool     muse_mode      = false;
// uint8_t  last_muse_note = 0;
// uint16_t muse_counter   = 0;
// uint8_t  muse_offset    = 70;
// uint16_t muse_tempo     = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (muse_mode) {
//         if (IS_LAYER_ON(_RAISE)) {
//             if (clockwise) {
//                 muse_offset++;
//             } else {
//                 muse_offset--;
//             }
//         } else {
//             if (clockwise) {
//                 muse_tempo += 1;
//             } else {
//                 muse_tempo -= 1;
//             }
//         }
//     } else {
//         if (clockwise) {
// #ifdef MOUSEKEY_ENABLE
//             tap_code(KC_MS_WH_DOWN);
// #else
//             tap_code(KC_PGDN);
// #endif
//         } else {
// #ifdef MOUSEKEY_ENABLE
//             tap_code(KC_MS_WH_UP);
// #else
//             tap_code(KC_PGUP);
// #endif
//         }
//     }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
// #ifdef AUDIO_ENABLE
//             static bool play_sound = false;
// #endif
//             if (active) {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) {
//                     PLAY_SONG(plover_song);
//                 }
// #endif
//                 layer_on(_ADJUST);
//             } else {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) {
//                     PLAY_SONG(plover_gb_song);
//                 }
// #endif
//                 layer_off(_ADJUST);
//             }
// #ifdef AUDIO_ENABLE
//             play_sound = true;
// #endif
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//         default:
//             break;
//     }
//     return true;
// }

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//     switch (keycode) {
//         case MO(_RAISE):
//         case MO(_LOWER):
//             return false;
//         default:
//             return true;
//     }
// }

// // Determine the tapdance state to return
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else
//             return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted)
//             return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed)
//             return TD_DOUBLE_HOLD;
//         else
//             return TD_DOUBLE_TAP;
//     } else if (state->count == 3) {
//         // Handling cases like www
//         if (state->interrupted)
//             return TD_TRIPLE_SINGLE_TAP;
//         else if (!state->pressed)
//             return TD_TRIPLE_TAP;
//         else
//             return TD_TRIPLE_HOLD;
//     } else
//         return TD_UNKNOWN;
// }

// // Handle the possible states for each tapdance keycode you define:

// void TD_CURRENCIES_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             tap_code(KC_RBRC);
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             tap_code(KC_RBRC);
//             tap_code(KC_RBRC);
//             break;
//         case TD_DOUBLE_TAP:
//             register_code16(RALT(KC_E)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
//             break;
//         default:
//             break;
//     }
// }

// void TD_CURRENCIES_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case TD_DOUBLE_TAP:
//             unregister_code16(RALT(KC_E));
//             break;
//         default:
//             break;
//     }
// }

// void TD_LALT_RALT_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_HOLD:
//             register_mods(MOD_BIT(KC_LALT));
//             break;
//         case TD_DOUBLE_HOLD:
//             register_mods(MOD_BIT(KC_RALT));
//             break;
//         default:
//             break;
//     }
// }

// void TD_LALT_RALT_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case TD_SINGLE_HOLD:
//             unregister_mods(MOD_BIT(KC_LALT));
//             break;
//         case TD_DOUBLE_HOLD:
//             unregister_mods(MOD_BIT(KC_RALT));
//             break;
//         default:
//             break;
//     }
// }

// // Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_CURRENCIES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_CURRENCIES_finished, TD_CURRENCIES_reset),
//     [TD_LALT_RALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_LALT_RALT_finished, TD_LALT_RALT_reset),
// };