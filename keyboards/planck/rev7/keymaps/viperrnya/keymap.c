/* Copyright 2015-2023 Jack Humbert
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
#include "keymap_croatian.h"
//#include "rules.mk"

enum planck_layers { _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _PLOVER, _ADJUST };

enum planck_keycodes { QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, BACKLIT, EXT_PLV, EXT_NUM, EXT_FUN };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Č  |  Ć   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | AltGr| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak (Numpad)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   7  |   8  |   9  |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   4  |   5  |   6  |      |      |      |      |      |      |      | Exit |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   1  |   2  |   3  |      |      |      |      |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | AltGr|   0  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_7,     KC_8,  KC_9,    KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
    KC_TAB,  KC_4,     KC_5,  KC_6,    KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   EXT_NUM,
    KC_LSFT, KC_1,     KC_2,  KC_3,    KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_RALT,  KC_0,  KC_LALT, LOWER,  KC_RSFT, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak (Function)
 * ,-----------------------------------------------------------------------------------.
 * | F1   |  F2  |   F3 |   F4 |   F5 |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Exit |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11, KC_F12,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  EXT_FUN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QWERTY, KC_NO,  KC_NO,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, LOWER, KC_NO, KC_NO, RAISE, KC_NO,  KC_NO,  KC_NO,  KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ?  |   *  |   Š  |   Đ  |   Ž  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   +  |   @  | Home | End  | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | AltGr| GUI  | Alt  |      |             |      |   <  |   >  | Prev | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    ALGR(HR_1), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,    KC_BSPC,
    KC_DEL,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PAST,    KC_LBRC,    KC_RBRC, KC_BSLS,
    KC_LSFT,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PPLS,    ALGR(HR_V), KC_HOME,    KC_END,  KC_MPLY,
    KC_LCTL,    KC_RALT, KC_LGUI, KC_LALT, _______, _______, _______, _______,    KC_NUBS,    S(HR_LABK), KC_MPRV, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ¸  |   !  |   "  |   #  |   $  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ?  |   *  |   '  |   `  |   ¨  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   +  |   @  | Pg Up| Pg Dn| Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | AltGr| GUI  | Alt  |      |             |      |   \  |   |  | Prev | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PAST,    KC_MINS,    ALGR(HR_7), KC_TILD,
    KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PPLS,    ALGR(HR_V), KC_PGUP,    KC_PGDN,    KC_MPLY,
    KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, _______, _______, _______, _______,    ALGR(HR_W), ALGR(HR_Q), KC_MPRV,    KC_MNXT
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
 * |      |Reset |Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-| Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CLRMEM|MUSmod|Aud on|Audoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |QWERTY|NUMPAD| FUNC |PLOVER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_CAPS,
    XXXXXXX, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, QWERTY,  COLEMAK, DVORAK,  PLOVER,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* defining layers*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty\n");
                set_single_persistent_default_layer(_QWERTY);
                /*layer_on(_QWERTY);*/
                layer_off(_DVORAK);
                layer_off(_COLEMAK);
                layer_off(_PLOVER);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
				print("mode just switched to numpad\n");
                /*set_single_persistent_default_layer(_COLEMAK);*/
                layer_on(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
				print("mode just switched to function\n");
                /*set_single_persistent_default_layer(_DVORAK);*/
                layer_on(_DVORAK);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
				print("mode just switched to plover\n");
				
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
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
                print("exited plover layer\n");
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
        case EXT_NUM:
            if (record->event.pressed) {
                print("exited numpad layer\n");
                layer_off(_COLEMAK);
                layer_off(_DVORAK);
                layer_off(_PLOVER);
            }
            return false;
            break;
        case EXT_FUN:
            if (record->event.pressed) {
                print("exited function layer\n");
                layer_off(_DVORAK);
                layer_off(_COLEMAK);
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}


/* defining custom keycodes*/

const key_override_t comm_key_override =
    ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_COMM, S(HR_8), ~0, MOD_MASK_SA);  // CTRL , is (
const key_override_t dot_key_override =
    ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_DOT, S(HR_9), ~0, MOD_MASK_SA);  // CTRL . is )
const key_override_t comm2_key_override =
    ko_make_basic(MOD_MASK_ALT, KC_COMM, ALGR(HR_F));  // ALT , is [
const key_override_t dot2_key_override =
    ko_make_basic(MOD_MASK_ALT, KC_DOT, ALGR(HR_G));  // ALT . is ]
const key_override_t comm3_key_override =
    ko_make_basic(MOD_MASK_CS, KC_COMM, ALGR(HR_B));  // CTRL + SHIFT , is {
const key_override_t dot3_key_override =
    ko_make_basic(MOD_MASK_CS, KC_DOT, ALGR(HR_N));  // CTRL + SHIFT . is }

const key_override_t** key_overrides = (const key_override_t*[]){
    &comm_key_override,
    &comm2_key_override,
    &comm3_key_override,
    &dot_key_override,
    &dot2_key_override,
    &dot3_key_override,
    NULL
};


/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}