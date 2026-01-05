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

enum planck_layers {
    _ERGO_L,
    _BEPO,
    _NavNum,
    _Functions,
    _Symbols,
    _Keyboard,
    _Combine,
};

enum planck_keycodes { EXCL_CHAP = SAFE_RANGE, COMMA_SEMI, QUEST_TICK, DOT_DOUBLE };

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
#define RPAREN_RAISE LT(_KEYBOARD, KC_MINS)
#define CHAPEAU KC_LBRC
#define MC_ACIRC
#define MC_CED
#define MC_OE
#define MC_OCIRC
#define MC_MICRO
#define MC_UCIRC
#define MC_AEG
#define MC_EGR
#define MC_EEG
#define MC_ECIRC
#define MC_ICIRC
#define MC_ITRE
#define MC_UGR
#define MC_AE

#define line_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Ergo-L
     * ,-----------------------------------------------------------------------------------.
     * |  Tab |   Q  |   C  |   O  |   P  |   W  |   J  |   M  |   D  |Comb/!|   Y  | BckSp|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Esc |   A  |   S  |   E  |   N  |   F  |   L  |   R  |   T  |   |  |   U  | Enter|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Maj |   Z  |   X  |   ?  |   V  |   B  |  :.  |   H  |   G  |  ;,  |   K  |  Maj |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Fnctns|  Kbd | LGUI | LALT |Space | LCTL |NAVNUM|Space |Symbls| RGUI | RALT |  DEL |
     * `-----------------------------------------------------------------------------------'
     */
    [_ERGO_L] = LAYOUT_ortho_4x12(line_12(KC_TAB, KC_Q, KC_C, KC_O, KC_P, KC_W, KC_J, KC_M, KC_D, KC_SLSH, KC_Y, KC_BSPC), line_12(KC_ESC, KC_A, KC_S, KC_E, KC_N, KC_F, KC_L, KC_R, KC_T, KC_I, KC_U, KC_ENT), line_12(KC_LSFT, KC_Z, KC_X, KC_COMM, KC_V, KC_B, KC_SCLN, KC_H, KC_G, KC_COMM, KC_K, KC_RSFT), line_12(MO(_Functions), MO(_Keyboard), KC_LGUI, KC_LALT, KC_SPC, KC_LCTL, MO(_NavNum), KC_SPC, MO(_Symbols), KC_RGUI, KC_RALT, KC_DEL)),

    /* Nav-num
     * ,-----------------------------------------------------------------------------------.
     * |      |  Tab | Home |   Up |  End | PgUp |   /  |   7  |   8  |   9  |   *  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | CapsL| Left | Down | Right|PgDown|   -  |   4  |   5  |   6  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | N/A  | Vol- | Mute | Vol+ |  N/A |   ,  |   1  |   2  |   3  |   .  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NavNum] = LAYOUT_ortho_4x12(line_12(KC_TRNS, KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PAST, KC_TRNS), line_12(KC_TRNS, KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_P0, KC_TRNS), line_12(KC_TRNS, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_COMM, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_TRNS), line_12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)),

    /* Functions
     * ,-----------------------------------------------------------------------------------.
     * |      |  Tab | Home |   Up |  End | PgUp |   /  |   7  |   8  |   9  |   *  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | CapsL| Left | Down | Right|PgDown|   -  |   4  |   5  |   6  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | N/A  | Vol- | Mute | Vol+ |  N/A |   ,  |   1  |   2  |   3  |   .  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_Functions] = LAYOUT_ortho_4x12(line_12(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS), line_12(KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS), line_12(KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS), line_12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)),

    /* Symbols (AltGr)
     * ,-----------------------------------------------------------------------------------.
     * |      |  ^   |   <  |   >  |   $  |   %  |   @  |   &  |   *  |   '  |   `  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   {  |   (  |   )  |   }  |   =  |   \  |   +  |   -  |   /  |   "  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   ~  |   [  |   ]  |   _  |   #  |   |  |   !  |   ;  |   :  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_Symbols] = LAYOUT_ortho_4x12(line_12(KC_TRNS, KC_CIRC, KC_LT, KC_GT, KC_DLR, KC_PERC, KC_AT, KC_AMPR, KC_ASTR, KC_4, KC_GRV, KC_TRNS), line_12(KC_TRNS, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_PEQL, KC_INT1, KC_PPLS, KC_PMNS, KC_PSLS, KC_DQUO, KC_TRNS), line_12(KC_TRNS, KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH, KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, KC_TRNS), line_12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)),

    TODO accents(mais maintenant c est _Combine)
        /* Accents
         * ,-----------------------------------------------------------------------------------.
         * |      |  â   |  ç   |  oe  |  ô   | N/A  | N/A  | greek| N/A  | N/A  |  û   |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |  à   |  é   |  è   |  ê   | N/A  | N/A  | N/A  |  î   |  ï   |  ù   |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |  ae  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |
         * `-----------------------------------------------------------------------------------'
         */
        [_ACCENTS] = LAYOUT_ortho_4x12(line_12(KC_TRNS, MC_ACIRC, MC_CED, MC_OE, MC_OCIRC, KC_NO, KC_NO, MC_MICRO, KC_NO, KC_NO, MC_UCIRC, KC_TRNS), line_12(KC_TRNS, MC_AEG, MC_EGR, MC_EEG, MC_ECIRC, KC_NO, KC_NO, KC_NO, MC_ICIRC, MC_ITRE, MC_UGR, KC_TRNS), line_12(KC_TRNS, MC_AE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO), line_12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)),

    /* Keyboard
     * ,-----------------------------------------------------------------------------------.
     * |      | Boot | Debug| N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | N/A  |Mu_prv|Mu_nxt|AudOff| AudOn| N/A  |ERGO_L| BéPO | N/A  | N/A  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_Keyboard] = LAYOUT_ortho_4x12(

        line_12(KC_TRNS, QK_BOOT, DB_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS), line_12(KC_TRNS, KC_NO, MU_PREV, MU_NEXT, AU_ON, AU_OFF, KC_NO, PDF(ERGO_L), PDF(BEPO), KC_NO, KC_NO, KC_TRNS), line_12(KC_TRNS, KC_NO, KC_NO, MU_ON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO), line_12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)),

    /* Bépo
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   B  |   é  |   P  |   O  |   è  |  !^  |   V  |   D  |   L  |   J  |  Z   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  W   |   A  |   U  |   I  |   E  |  ,;  |   C  |   T  |   S  |   R  |   N  |  M   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ù%  |   à  |   Y  |   X  |  .:  |   K  |  ?'  |   Q  |   G  |   H  |   F  |  ç   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Left |  Up  |LCTRL$| LALT |Space |FUNCTS|CHARS |LShift|Enter | Tab  |Down  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_BEPO] = LAYOUT_ortho_4x12(line_12(QK_GESC, KC_B, KC_2, KC_P, KC_O, KC_7, EXCL_CHAP, KC_V, KC_D, KC_L, KC_J, KC_W), line_12(KC_Z, KC_Q, KC_U, KC_I, KC_E, COMMA_SEMI, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN), line_12(KC_QUOT, KC_0, KC_Y, KC_X, DOT_DOUBLE, KC_K, QUEST_TICK, KC_A, KC_G, KC_H, KC_F, KC_9), line_12(KC_LEFT, KC_UP, LCTL_T(KC_RBRC), KC_LALT, KC_SPC, KC_5, RPAREN_RAISE, KC_LSFT, KC_ENT, LGUI_T(KC_TAB), KC_DOWN, KC_RGHT)),
    // // old [_BEPO] = LAYOUT( KC_ESC, KC_B, KC_2, KC_P, KC_O, KC_7, EXCL_CHAP, KC_V, KC_D, KC_L, KC_J, KC_W, KC_Z, KC_Q, KC_U, KC_I, KC_E, COMMA_SEMI, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN, KC_QUOT, KC_0, KC_Y, KC_X, DOT_DOUBLE, KC_K, QUEST_TICK, KC_A, KC_G, KC_H, KC_F, KC_9, KC_LEFT, KC_UP, KC_LCTL, TD(TD_LALT_RALT), KC_SPC, LPAREN_LOWER, RPAREN_RAISE, KC_LSFT, KC_ENT, LGUI_T(KC_TAB), KC_DOWN, KC_RIGHT),
    // /* Qwerty
    //  * ,-----------------------------------------------------------------------------------.
    //  * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | DEL  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |      |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_QWERTY] = LAYOUT_ortho_4x12(KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_TRNS, KC_L, KC_SCLN, KC_DEL, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    // /* Arrows_and_numpad
    //  * ,-----------------------------------------------------------------------------------.
    //  * |      |  N/A |  N/A |  Up  | N/A  | N/A  |VerNum|  =   |   7  |   8  |   9  |   /  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | N/A  |  N/A | Left | Down | Right| N/A  | N/A  | Tab  |   4  |   5  |   6  |   *  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | N/A  |  N/A |  N/A | N/A  | N/A  | N/A  | N/A  | N/A  |   3  |   2  |   1  |   -  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | N/A  |  N/A | LAlt | LCtrl|LShift|      |      | N/A  |   0  |   .  | Enter|   +  |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_ARR_NUM] = LAYOUT_ortho_4x12(KC_TRNS, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NUM, KC_EQL, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_PAST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_NO, KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_NO, KC_P0, KC_PDOT, KC_PENT, KC_PPLS),
    // /* Lower
    //  * ,-----------------------------------------------------------------------------------.
    //  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | F12  | Save | Undo | Redo |Replce| BSPC | DEL  | NONE | NONE | NONE | NONE | NONE |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |Captr |Close | Cut  | Copy |Paste |      |Insert| Open |      | NONE | NONE | NONE |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |ADJUST|      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_FUNCTIONS] = LAYOUT_ortho_4x12(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SAVE, UNDO, REDO, REPLACE, KC_BSPC, KC_DEL, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_PSCR, CLOSE, CUT, COPY, PASTE, KC_NO, KC_INS, OPEN, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PAGE_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_DOWN, KC_END),
    // // old [_LOWER] = LAYCURRENCIES), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SAVE, UNDO, REDO, REPLACE, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_PRINT_SCREEN, CLOSE, CUT, COPY, PASTE, KC_WWW_REFRESH, KC_INSERT, OPEN, XXXXXXX, KC_VOLD, KC_KB_MUTE, KC_VOLU, KC_HOME, KC_PAGE_UP, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAGE_DOWN, KC_END),
    // /* Raise
    //  * ,-----------------------------------------------------------------------------------.
    //  * |      | & (1)| é (2)| " (3)| ' (4)| ( (5)| - (6)| è (7)| _ (8)| ç (9)| à (0)| = (°)|
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |  &   |   "  |   <  |   >  |   {  |   }  |   @  |   +  |   -  |   /  |   *  |   =  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |  €   |   #  |   [  |   ]  |   |  |   ^  |   _  |   ~  |   \  |   !  |   .  |   ,  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |LCTRL€| RALT |      |             |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_CHARS] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DEGREES, KC_1, KC_3, LANGLEB, RANGLEB, LCURLB, RCURLB, AROBASE, PLUS, MINUS, DIVIDE, MULTIPLY, EQUAL, RALT(KC_E), HASHTAG, LSQUARB, RSQUARB, PIPE, CHAPEAU, UNDERSCORE, TILD, FORWARD_SLSH, KC_SLSH, KC_PDOT, KC_M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    // // old [_RAISE]TD(TD_CURRENCIES), UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, ZERO, DEGREES, KC_1, KC_3, LANGLEB, RANGLEB, LCURLB, RCURLB, AROBASE, PLUS, MINUS, DIVIDE, MULTIPLY, EQUAL, XXXXXXX, HASHTAG, LSQUARB, RSQUARB, PIPE, CHAPEAU, UNDERSCORE, TILD, FORWARD_SLSH, KC_SLSH, KC_PDOT, KC_M, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    // /* Adjust (Lower + Raise)
    //  *                      v------------------------RGB CONTROL--------------------v
    //  * ,-----------------------------------------------------------------------------------.
    //  * |  N/A | N/A  |  N/A | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  N/A |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Debug|      |MUSmod|Aud on|Audoff|      |      |Bépo  |Qwerty|ArrNum|      |      |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Reset|AuPrev|AuNext|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * |      |      |      |      |      |             |      |      |      |      |      |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    // [_ADJUST] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, KC_NO, DB_TOGG, KC_TRNS, MU_NEXT, AU_ON, AU_OFF, KC_NO, KC_NO, DF(_BEPO), DF(_QWERTY), DF(_ARR_NUM), KC_TRNS, KC_TRNS, QK_BOOT, AU_PREV, AU_NEXT, MU_ON, MU_OFF, MI_ON, MI_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

uint16_t lastKeyCode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods      = get_mods();
    bool    anyShift  = (mods == MOD_BIT(KC_LSFT) || (mods == MOD_BIT(KC_RSFT)));
    uint8_t lastShift = mods & MOD_BIT(KC_LSFT) ? MOD_BIT(KC_LSFT) : MOD_BIT(KC_RSFT);
    if (!anyShift) lastShift = 0;

    switch (keycode) {
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
