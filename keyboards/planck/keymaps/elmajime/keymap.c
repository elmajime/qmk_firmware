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

enum MY_KEYCODES {
ESC_CURR,
DOT,
TAB_GUI,
QUEST,
RPAREN_RAISE,
LALT_RALT,
LPAREN_LOWER,
SAVE,
UNDO,
REDO,
REPLACE,
CLOSE,
CUT,
COPY,
PASTE,
OPEN,
UN,
DEUX,
TROIS,
QUATRE,
CINQ,
SIX,
SEPT,
HUIT,
NEUF,
ZERO,
DEGREES,
MIN,
MAX,
LCURLB,
RCURLB,
AROBASE,
PLUS,
MINUS,
DIVIDE,
MULTIPLY,
EQUAL,
HASHTAG,
LSQUARB,
RSQUARB,
PIPE,
CHAPEAU,
UNDERSCORE,
TILD,
FORWARD_SLSH
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
    ESC_CURR,  KC_B,    KC_2,     KC_P,       KC_O,    KC_7,          KC_SLSH,       KC_V,      KC_D,    KC_L,     KC_J,      KC_W,
    KC_Z,      KC_Q,    KC_U,     KC_I,       KC_E,    KC_M,          KC_C,          KC_T,      KC_S,    KC_R,     KC_N,      KC_SCLN,
    KC_QUOT,   KC_0,    KC_Y,     KC_X,       DOT,     KC_K,          QUEST,         KC_A,      KC_G,    KC_H,     KC_F,      KC_9 ,
    KC_LEFT,   KC_UP,   KC_LCTL,  LALT_RALT,  KC_SPC,  LPAREN_LOWER,  RPAREN_RAISE,  KC_LSFT,   KC_ENT,  TAB_GUI,  KC_DOWN,   KC_RGHT
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
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F12  | Save | Undo | Redo |Replce| BSPC | DEL  | NONE | NONE |Prev  | Play |Next  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Captr |Close | Cut  | Copy |Paste |Refrsh|Insert| Open |BK_LED| Vol- | Mute |Vol+  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Home | PgUp |      |      |      |             |      |      |      | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_ESC,           KC_F1,       KC_F2,    KC_F3,    KC_F4,    KC_F5,           KC_F6,      KC_F7,    KC_F8,    KC_F9,                KC_F10,               KC_F11,
    KC_F12,           SAVE,        UNDO,     REDO,     REPLACE,  KC_BSPC,         KC_DEL,     XXXXXXX,  XXXXXXX,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK,
    KC_PRINT_SCREEN,  CLOSE,       CUT,      COPY,     PASTE,    KC_WWW_REFRESH,  KC_INSERT,  OPEN,     BACKLIT,  KC_VOLD,              KC_KB_MUTE,           KC_VOLU,
    KC_HOME,          KC_PAGE_UP,  _______,  _______,  _______,  _______,         _______,    _______,  _______,  _______,              KC_PAGE_DOWN,         KC_END
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
    KC_1,     KC_3,     MIN,      MAX,      LCURLB,   RCURLB,   AROBASE,     PLUS,     MINUS,         DIVIDE,   MULTIPLY,  EQUAL,
    XXXXXXX,  HASHTAG,  LSQUARB,  RSQUARB,  PIPE,     CHAPEAU,  UNDERSCORE,  TILD,     FORWARD_SLSH,  KC_SLSH,  KC_PDOT,   KC_M,
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

    case ESC_CURR:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case DOT:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case TAB_GUI:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case QUEST:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case RPAREN_RAISE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case LALT_RALT:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case LPAREN_LOWER:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case SAVE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case UNDO:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case REDO:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case REPLACE
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case CLOSE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case CUT:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case OPEN:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case UN:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case DEUX:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case TROIS:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case QUATRE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case CINQ:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case SIX:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case SEPT:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case HUIT:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case NEUF:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case ZERO:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case DEGREES:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case MIN:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case MAX:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case LCURLB:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case RCURLB:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case AROBASE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case PLUS:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case MINUS:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case DIVIDE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case MULTIPLY:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case EQUAL:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case HASHTAG:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case LSQUARB:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case RSQUARB:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case PIPE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case CHAPEAU:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case UNDERSCORE:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }:
      return false;
      break;
    case TILD:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
      break;
    case FORWARD_SLSH:
      if (record->event.pressed) {
        register_code();
        unregister_code();
      }
      return false;
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
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
