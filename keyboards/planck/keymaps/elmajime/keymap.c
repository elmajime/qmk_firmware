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
  _BEPO,
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  BEPO = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define DOT LSFT(KC_COMM)
#define QUEST LSFT(KC_M)
#define SAVE LCTL(KC_S)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define REPLACE LCTL(KC_R)
#define CLOSE LCTL(KC_W)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_P)
#define OPEN LCTL(KC_O)
#define UN LSFT(KC_1)
#define DEUX LSFT(KC_2)
#define TROIS LSFT(KC_3)
#define QUATRE LSFT(KC_4)
#define CINQ LSFT(KC_5)
#define SIX LSFT(KC_6)
#define SEPT LSFT(KC_7)
#define HUIT LSFT(KC_8)
#define NEUF LSFT(KC_9)
#define ZERO LSFT(KC_0)
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

// Tap Dance keycodes
enum td_keycodes {
  TD_ESC_CURRENCIES,
  TD_TAB_GUI,
  TD_LALT_RALT,
  TD_LPAREN_LOWER,
  TD_RPAREN_RAISE,
  TD_CHAPEAU
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_TRIPLE_SINGLE_TAP, // Send triple single taps

} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void TD_ESC_CURRENCIES_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_ESC_CURRENCIES_reset(qk_tap_dance_state_t *state, void *user_data);

void TD_TAB_GUI_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_TAB_GUI_reset(qk_tap_dance_state_t *state, void *user_data);

void TD_LALT_RALT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_LALT_RALT_reset(qk_tap_dance_state_t *state, void *user_data);

void TD_LPAREN_LOWER_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_LPAREN_LOWER_reset(qk_tap_dance_state_t *state, void *user_data);

void TD_RPAREN_RAISE_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_RPAREN_RAISE_reset(qk_tap_dance_state_t *state, void *user_data);

void TD_CHAPEAU_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_CHAPEAU_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Bépo
 * ,-----------------------------------------------------------------------------------.
 * |ESC_$€|   B  |   é  |   P  |   O  |   è  |   !  |   V  |   D  |   L  |   J  |  Z   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  W   |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ù   |   à  |   Y  |   X  |   .  |   K  |   ?  |   Q  |   G  |   H  |   F  |  ç   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Left |  Up  |LCTRL |LRALT |Space |Lower |Raise |Shift |Enter | Tab  |Down  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_planck_grid(
    TD_ESC_CURRENCIES,  KC_B,    KC_2,     KC_P,       KC_O,    KC_7,          KC_SLSH,       KC_V,      KC_D,    KC_L,     KC_J,      KC_W,
    KC_Z,      KC_Q,    KC_U,     KC_I,       KC_E,    KC_M,          KC_C,          KC_T,      KC_S,    KC_R,     KC_N,      KC_SCLN,
    KC_QUOT,   KC_0,    KC_Y,     KC_X,       DOT,     KC_K,          QUEST,         KC_A,      KC_G,    KC_H,     KC_F,      KC_9 ,
    KC_LEFT,   KC_UP,   KC_LCTL,  TD_LALT_RALT,  KC_SPC,  TD_LPAREN_LOWER,  TD_RPAREN_RAISE,  KC_LSFT,   KC_ENT,  TD_TAB_GUI,  KC_DOWN,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     _______,  _______,  KC_Y,      KC_U,     KC_I,     KC_O,     KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     _______,  _______,  KC_H,      KC_J,     KC_K,     KC_L,     KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______,  _______,  KC_N,      KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    _______, _______, _______, _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |      |      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |      |      |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   K  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     _______,  _______,    KC_J,    KC_L,     KC_U,     KC_Y,     KC_SCLN,
    KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     _______,  _______,    KC_H,    KC_N,     KC_E,     KC_I,     KC_O,  
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     _______,  _______,    KC_K,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |ESC_$€|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F12  | Save | Undo | Redo |Replce| BSPC | DEL  | NONE | NONE |Prev  | Play |Next  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Captr |Close | Cut  | Copy |Paste |Refrsh|Insert| Open |BK_LED| Vol- | Mute |Vol+  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Home | PgUp |      |      |      |             |      |      |      | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    TD_ESC_CURRENCIES,  KC_F1,       KC_F2,    KC_F3,    KC_F4,    KC_F5,           KC_F6,      KC_F7,    KC_F8,    KC_F9,                KC_F10,               KC_F11,
    KC_F12,             SAVE,        UNDO,     REDO,     REPLACE,  KC_BSPC,         KC_DEL,     XXXXXXX,  XXXXXXX,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK,
    KC_PRINT_SCREEN,    CLOSE,       CUT,      COPY,     PASTE,    KC_WWW_REFRESH,  KC_INSERT,  OPEN,     BACKLIT,  KC_VOLD,              KC_KB_MUTE,           KC_VOLU,
    KC_HOME,            KC_PAGE_UP,  _______,  _______,  _______,  _______,         _______,    _______,  _______,  _______,              KC_PAGE_DOWN,         KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 *|QK_GESC|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   °  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  &   |   "  |   <  |   >  |   {  |   }  |   @  |   +  |   -  |   /  |   *  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NONE |   #  |   [  |   ]  |   |  |   ^  |   _  |   ~  |   \  |   !  |   .  |   ,  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    QK_GESC,  UN,       DEUX,     TROIS,    QUATRE,   CINQ,     SIX,         SEPT,     HUIT,          NEUF,     ZERO,      DEGREES,
    KC_1,     KC_3,     LANGLEB,      RANGLEB,      LCURLB,   RCURLB,   AROBASE,     PLUS,     MINUS,         DIVIDE,   MULTIPLY,  EQUAL,
    XXXXXXX,  HASHTAG,  LSQUARB,  RSQUARB,  PIPE,     TD_CHAPEAU,  UNDERSCORE,  TILD,     FORWARD_SLSH,  KC_SLSH,  KC_PDOT,   KC_M,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,       _______,  _______,   _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Bépo  |Azerty|Qwerty|Colemk|Plover|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______,  QK_BOOT,  DEBUG,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_DEL ,
    _______,  _______,  MU_MOD,   AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,  BEPO,     QWERTY,   COLEMAK,  PLOVER,   _______,
    _______,  MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,    MI_OFF,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEPO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEPO);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    default:
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
        default:
          break;
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case MO(_RAISE):
    case MO(_LOWER):
      return false;
    default:
      return true;
  }
}

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        // Handling cases like www
        if (state->interrupted) return TD_TRIPLE_SINGLE_TAP;
        else if (!state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Handle the possible states for each tapdance keycode you define:

void TD_ESC_CURRENCIES_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_ESC);
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 escape within tapping term
            tap_code16(KC_ESC);
            register_code16(KC_ESC);
            break;
        case TD_TRIPLE_SINGLE_TAP: // Allow nesting of 3 escape within tapping term
            tap_code16(KC_ESC);
            tap_code16(KC_ESC);
            register_code16(KC_ESC);
            break;
        case TD_DOUBLE_HOLD:
            register_code16(KC_RBRC);
            break;
        case TD_TRIPLE_HOLD:
            register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            register_code16(KC_E);
            break;
        default:
            break;
    }
}

void TD_ESC_CURRENCIES_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 escape within tapping term
            unregister_code16(KC_ESC);
            break;
        case TD_TRIPLE_SINGLE_TAP: // Allow nesting of 3 escape within tapping term
            unregister_code16(KC_ESC);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code16(KC_RBRC);
            break;
        case TD_TRIPLE_HOLD:
            unregister_code16(KC_E);
            unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void TD_TAB_GUI_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case TD_TRIPLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void TD_TAB_GUI_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case TD_TRIPLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case TD_TRIPLE_HOLD:
            unregister_mods(MOD_BIT(KC_RGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void TD_LALT_RALT_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case TD_TRIPLE_HOLD:
            register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void TD_LALT_RALT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case TD_TRIPLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void TD_LPAREN_LOWER_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_5);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_5);
            register_code16(KC_5);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_5);
            tap_code16(KC_5);
            register_code16(KC_5);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        default:
            break;
    }
}

void TD_LPAREN_LOWER_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_5);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_5);
            break;
        case TD_TRIPLE_TAP:
            unregister_code16(KC_5);
            break;
        case TD_SINGLE_HOLD:
            layer_off(_LOWER);
            break;
        default:
            break;
    }
}

void TD_RPAREN_RAISE_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_MINS);
            register_code16(KC_MINS);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_MINS);
            tap_code16(KC_MINS);
            register_code16(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        default:
            break;
    }
}

void TD_RPAREN_RAISE_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_MINS);
            break;
        case TD_TRIPLE_TAP:
            unregister_code16(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            layer_off(_RAISE);
            break;
        default:
            break;
    }
}

void TD_CHAPEAU_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING("^");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("^^");
            break;
        default:
            break;
    }
}

void TD_CHAPEAU_reset(qk_tap_dance_state_t *state, void *user_data) {

}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CURRENCIES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_ESC_CURRENCIES_finished,TD_ESC_CURRENCIES_reset),
    [TD_TAB_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_TAB_GUI_finished,TD_TAB_GUI_reset),
    [TD_LALT_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_LALT_RALT_finished,TD_LALT_RALT_reset),
    [TD_LPAREN_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_LPAREN_LOWER_finished,TD_LPAREN_LOWER_reset),
    [TD_RPAREN_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_RPAREN_RAISE_finished,TD_RPAREN_RAISE_reset),
    [TD_CHAPEAU] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,TD_CHAPEAU_finished,TD_CHAPEAU_reset)
};