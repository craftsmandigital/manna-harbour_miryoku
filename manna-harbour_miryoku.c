// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"


uint16_t my_key_pressed_timer = 0;

// --------------------------------------------------------------------------------
// combos stuff
enum combo_events {
  JK_ESC,
  DF_TAB,
  NAV_TOGLE,
  SYM_TOGLE,
  NUM_TOGLE,
  MOUSE_TOGLE,
  GUI_NUM,
};

// Macro stuff
enum custom_keycodes {
	PAREN = SAFE_RANGE,
    BRACKET,
    CURLEY,
	QUOT,
	DQUOT,
	MY_END,
	MY_HOME,
	MY_PASTE,
	MY_COPY,
 	MY_PGUP,
	MY_PGDN,
	MY_GUI_NUM,
	MY_UNDRDO,
	_AA, // Åå
	_AE, // æÆ
	_OE, // øØ
};

// --------------------------------------------------------------------------------
// combos stuff
const uint16_t PROGMEM jk_combo[] =  {LSFT_T(KC_J),		LCTL_T(KC_K),	COMBO_END};
const uint16_t PROGMEM df_combo[] =  {LSFT_T(KC_F), 	LCTL_T(KC_D),	COMBO_END};
const uint16_t PROGMEM nav_combo[] = {LT(U_NAV, KC_SPC),	LSFT_T(KC_J),	COMBO_END};
const uint16_t PROGMEM sym_combo[] = {LSFT_T(KC_F),		OSL(U_SYM),		COMBO_END};
const uint16_t PROGMEM num_combo[] = {LSFT_T(KC_F),		LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {LT(U_MOUSE, KC_DOT),LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM gui_num_combo[] = {LCTL_T(KC_K), LALT_T(KC_L), COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [DF_TAB] = COMBO(df_combo, KC_TAB),
  [NAV_TOGLE] = COMBO(nav_combo, TG(U_NAV)),
  [SYM_TOGLE] = COMBO(sym_combo, TG(U_SYM)),
  [NUM_TOGLE] = COMBO(num_combo, TG(U_NUM)),
  [GUI_NUM] = COMBO(gui_num_combo, MY_GUI_NUM),
  [MOUSE_TOGLE] = COMBO(mouse_combo, TG(U_MOUSE)),
  // [QW_SFT] = COMBO(qw_combo, KC_LSFT)
  // [SD_LAYER] = COMBO(layer_combo, MO(_LAYER)),
};

// --------------------------------------------------------------------------------
// Leader stuff
//LEADER_EXTERNS();

void leader_start_user(void) {
    // Do something when the leader key is pressed
}


void leader_end_user(void) {
    if (leader_sequence_one_key(KC_X)) {
	    register_code(KC_LCTL);
        register_code(KC_F4);
        unregister_code(KC_F4);
        unregister_code(KC_LCTL);
        // SEND_STRING(SS_DOWN(KC_LCTL)SS_TAP(KC_F4)SS_UP(KC_LCTL));
    } else if (leader_sequence_one_key(KC_Q)) {
	    register_code(KC_LALT);
        register_code(KC_F4);
        unregister_code(KC_F4);
        unregister_code(KC_LALT);
    } else if (leader_sequence_two_keys(KC_X, KC_X)) {
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
    } 
}








/*  void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
	
	SEQ_ONE_KEY(KC_X) {
      // Anything you can do in a macro.
	  register_code(KC_LCTRL);
      register_code(KC_F4);
      unregister_code(KC_F4);
      unregister_code(KC_LCTRL);
      // SEND_STRING(SS_DOWN(KC_LCTRL)SS_TAP(KC_F4)SS_UP(KC_LCTL));
    }

    SEQ_ONE_KEY(KC_Q) {	  
	  register_code(KC_LALT);
      register_code(KC_F4);
      unregister_code(KC_F4);
      unregister_code(KC_LALT);
    }
    SEQ_TWO_KEYS(KC_X, KC_X) {
      SEND_STRING(SS_LCTL(SS_LSFT("t")));
    }
  }
} */


// --------------------------------------------------------------------------------
// Macro stuff
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	

    switch (keycode) {
    case PAREN:
        if (record->event.pressed) {
            // when key ( is pressed
            SEND_STRING("()"SS_TAP(X_LEFT));
        }
        break;
    case BRACKET:
        if (record->event.pressed) {
			// when key [ is pressed
            SEND_STRING("[]"SS_TAP(X_LEFT));
        }
        break;
    case CURLEY:
        if (record->event.pressed) {
            // when key { is pressed
            SEND_STRING("{}"SS_TAP(X_LEFT));
        }
        break;
    case QUOT:
        if (record->event.pressed) {
            // when key ' is pressed
            SEND_STRING("''"SS_TAP(X_LEFT));
        }
        break;
    case DQUOT:
        if (record->event.pressed) {
            // when key " is pressed
            SEND_STRING("\"\""SS_TAP(X_LEFT));
        }
        break;
	// The four next keys goes to their extremes on long tapp
	// and do shorter travel on short press
    case MY_END:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			// goes by word to the right when short pressed.
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_RGHT);
				unregister_code(KC_LCTL);
			} else {
				// goes to end of line on long press
				tap_code(KC_END);
			}
		}
        break;
		case MY_HOME:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_LEFT);
				unregister_code(KC_LCTL);
			} else {
				tap_code(KC_HOME);
			}
		}
        break;
		case MY_COPY:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_C);
				unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_A);
				unregister_code(KC_LCTL);
			}
		}
		break;
		case MY_UNDRDO:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_Z);
				unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_Y);
				unregister_code(KC_LCTL);
			}
		}
        break;
		case MY_PASTE:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			register_code(KC_LCTL);
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LSFT);
				tap_code(KC_V);
				unregister_code(KC_LSFT);
			} else {
				tap_code(KC_V);
			}
			unregister_code(KC_LCTL);
		}
        break;
		case MY_PGDN:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				tap_code(KC_PGDN);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_END);
				unregister_code(KC_LCTL);
				
			}
		}
        break;
		case MY_PGUP:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				tap_code(KC_PGUP);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_HOME);
				unregister_code(KC_LCTL);
				
			}
		}
		break;
		// Nordic caracter stuff is dependent of autohotkey
		// https://www.thenickmay.com/how-to-expand-text-for-free-with-autohotkey/
		// When keypress is shifted then keypress is different the char "-" becoms a "_"
		// auto hotkey schipt handles this and expand the right nordic character
		case _AA	:	// å Å
		if (record->event.pressed) {
				SEND_STRING("-&a");  // Becomes _&a when shifted
		}
		break;
		case _AE	:	// æ Æ
		if (record->event.pressed) {
				SEND_STRING("-&e");  // Becomes _&e when shifted
		}
		break;
		// case _OE	:	// ø Ø
		// if (record->event.pressed) {
				// SEND_STRING("-&o");  // Becomes _&o when shifted
		// }
		// break;
		case RGUI_T(_OE)	:	// ø Ø
		// This was extremely difficult to program, because of the nature of GUI modifier
		// It is also triggered on tap. luckyly the solution was quite easy. The solution was found on website under:
		// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md#changing-tap-function.
		// The moust obious solution was something like the website under. 
		// But doestnt work because of the nature of the GUI modifier
		// https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/#a-workaround-for-mod-tap
		
		if (record->tap.count && record->event.pressed) {
			SEND_STRING("-&o"); // Send KC_DQUO on tap
			return false;        // Return false to ignore further processing of key
		}
		break;

    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case MY_GUI_NUM:
	// This is a oneshotlayer and oneshot modifier at the same time
	// SYM layer and GUI modifier at once.
	// This makes it easy to switch apps in the taskbar in windows 10. 
	// The state before next key pressed is num layer and gui modifier.
	// When user press a nuber key, then it triggers to open or switching to that app in taskbar
        if (record->event.pressed) {
            // layer_on(U_NUM);
            set_oneshot_layer(U_NUM, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
			
			set_oneshot_mods(MOD_RGUI);
        } else {
			// clear_oneshot_layer_state(ONESHOT_PRESSED);
		}
        break;

    }

};




// --------------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined MIRYOKU_LAYERS_FLIP
  [U_BASE] = LAYOUT_miryoku(
  #if defined MIRYOKU_ALPHAS_COLEMAK
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_D,              KC_H,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_K,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_COLEMAKDHK
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_K,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_DVORAK
    KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,
    LGUI_T(KC_A),      LALT_T(KC_O),      LCTL_T(KC_E),      LSFT_T(KC_U),      KC_I,              KC_D,              LSFT_T(KC_H),      LCTL_T(KC_T),      LALT_T(KC_N),      LGUI_T(KC_S),
    KC_SLSH,           ALGR_T(KC_Q),      KC_J,              KC_K,              KC_X,              KC_B,              KC_M,              KC_W,              ALGR_T(KC_V),      KC_Z,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_HALMAK
    KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,
    LGUI_T(KC_S),      LALT_T(KC_H),      LCTL_T(KC_N),      LSFT_T(KC_T),      KC_COMM,           KC_DOT,            LSFT_T(KC_A),      LCTL_T(KC_E),      LALT_T(KC_O),      LGUI_T(KC_I),
    KC_F,              ALGR_T(KC_M),      KC_V,              KC_C,              KC_SLSH,           KC_G,              KC_P,              KC_X,              ALGR_T(KC_K),      KC_Y,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_WORKMAN
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_H),      LSFT_T(KC_T),      KC_G,              KC_Y,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_O),      LGUI_T(KC_I),
    KC_Z,              ALGR_T(KC_X),      KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_QWERTY
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #else
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_FUN, KC_DEL),   LT(U_NUM, KC_BSPC),  LT(U_SYM, KC_ENT),   LT(U_MOUSE, KC_TAB), LT(U_NAV, KC_SPC),   LT(U_MEDIA, KC_ESC), U_NP,              U_NP
  #endif
  ),
  #if defined MIRYOKU_NAV_INVERTEDT
  [U_NAV] = LAYOUT_miryoku(
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DEL,  KC_BSPC, KC_ENT,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [U_MOUSE] = LAYOUT_miryoku(
    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_BTN2, KC_BTN3, KC_BTN1, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [U_MEDIA] = LAYOUT_miryoku(
    U_NU,    U_NU,    KC_VOLU, U_NU,    U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    U_NU,    KC_MPRV, KC_VOLD, KC_MNXT, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_MUTE, KC_MPLY, KC_MSTP, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  #else
  [U_NAV] = LAYOUT_miryoku(
    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DEL,  KC_BSPC, KC_ENT,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [U_MOUSE] = LAYOUT_miryoku(
    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_BTN2, KC_BTN3, KC_BTN1, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [U_MEDIA] = LAYOUT_miryoku(
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_MUTE, KC_MPLY, KC_MSTP, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  #endif
  [U_NUM] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MINS, KC_0,    KC_DOT,  U_NP,    U_NP
  ),
  [U_SYM] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_UNDS, KC_LPRN, KC_RPRN, U_NP,    U_NP
  ),
  [U_FUN] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_TAB,  KC_SPC,  KC_APP,  U_NP,    U_NP
  )
,
#else
  [U_BASE] = LAYOUT_miryoku(
  #if defined MIRYOKU_ALPHAS_COLEMAK
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_D,              KC_H,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_K,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_COLEMAKDHK
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_K,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_DVORAK
    KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,
    LGUI_T(KC_A),      LALT_T(KC_O),      LCTL_T(KC_E),      LSFT_T(KC_U),      KC_I,              KC_D,              LSFT_T(KC_H),      LCTL_T(KC_T),      LALT_T(KC_N),      LGUI_T(KC_S),
    KC_SLSH,           ALGR_T(KC_Q),      KC_J,              KC_K,              KC_X,              KC_B,              KC_M,              KC_W,              ALGR_T(KC_V),      KC_Z,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_HALMAK
    KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,
    LGUI_T(KC_S),      LALT_T(KC_H),      LCTL_T(KC_N),      LSFT_T(KC_T),      KC_COMM,           KC_DOT,            LSFT_T(KC_A),      LCTL_T(KC_E),      LALT_T(KC_O),      LGUI_T(KC_I),
    KC_F,              ALGR_T(KC_M),      KC_V,              KC_C,              KC_SLSH,           KC_G,              KC_P,              KC_X,              ALGR_T(KC_K),      KC_Y,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP
  #elif defined MIRYOKU_ALPHAS_WORKMAN
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_H),      LSFT_T(KC_T),      KC_G,              KC_Y,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_O),      LGUI_T(KC_I),
    KC_Z,              ALGR_T(KC_X),      KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP












  //---------------------------------------------------- START ------------------------------------------------------------------------------------------
  #elif defined MIRYOKU_ALPHAS_QWERTY
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,               KC_I,              KC_O,             KC_P,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      RGUI_T(_OE),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              QK_LEAD,           _AA,               _AE,
    U_NP,              U_NP,              LT(U_MEDIA, KC_COMM),LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_DOT), LT(U_FUN, KC_ENT),   LT(U_NUM, KC_BSPC),  OSL(U_SYM),          U_NP,              U_NP
  #else
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LT(U_MEDIA, KC_ESC), LT(U_NAV, KC_SPC),   LT(U_MOUSE, KC_TAB), LT(U_SYM, KC_ENT),   LT(U_NUM, KC_BSPC),  LT(U_FUN, KC_DEL),   U_NP,              U_NP
  #endif
  ),
  #if defined MIRYOKU_NAV_VI
  [U_NAV] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    MY_UNDRDO,MY_PASTE,MY_COPY, U_CUT,   KC_APP,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_LEFT,  KC_DOWN,	KC_UP,   KC_RGHT, KC_CAPS,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    MY_HOME,  MY_PGDN,	MY_PGUP, MY_END,  KC_INS,
    U_NP,    U_NP,    U_NA,    TG(U_NAV), U_NA,    KC_ENT,   KC_BSPC,	KC_DEL,  U_NP,    U_NP
  ),
  [U_MOUSE] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    TG(U_MOUSE),KC_BTN1,KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),
  [U_MEDIA] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),
  //---------------------------------------------------- END ------------------------------------------------------------------------------------------
















  #else
  [U_NAV] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,     KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [U_MOUSE] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),
  [U_MEDIA] = LAYOUT_miryoku(
    QK_REBOOT,   U_NA,    U_NA,    U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),
  #endif
  //---------------------------------------------------- START ------------------------------------------------------------------------------------------
  [U_NUM] = LAYOUT_miryoku(
    KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_PERC, KC_1,    KC_2,    KC_3,    KC_EQL , U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    U_NA,    KC_0,    KC_DOT,  U_NA,    TG(U_NUM), U_NA,    U_NP,    U_NP
  ),
  [U_SYM] = LAYOUT_miryoku(
	KC_PLUS, KC_EXLM, KC_SCLN, QUOT,    KC_ASTR, KC_CIRC, KC_TILD, KC_HASH, KC_UNDS, KC_AMPR,
	KC_MINS, KC_QUES, KC_COLN, DQUOT,   KC_SLSH, CURLEY,  PAREN,   BRACKET, KC_DLR,  KC_DOT,
	KC_PERC, KC_TRNS, KC_TRNS, KC_GRV,  KC_EQL,  KC_RCBR, KC_RPRN, KC_RBRC, KC_TRNS, KC_TRNS,
	U_NP,    U_NP,    KC_PIPE, KC_BSLS, KC_LT,   KC_GT,   KC_AT,   TG(U_SYM), U_NP,    U_NP
  ),
  [U_FUN] = LAYOUT_miryoku(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    QK_REBOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  )
#endif
};
