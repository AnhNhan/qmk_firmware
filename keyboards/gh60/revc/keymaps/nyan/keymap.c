#include QMK_KEYBOARD_H
#include "version.h"
#define ______ KC_TRNS

#define _DEFAULT 0
#define _FN 1
#define _FN2 2
#define _WASD 3

LEADER_EXTERNS();

// Tap Dance Declarations
enum kc_tap_dances {
  CT_CLN = 0,
  CT_QUOT,
  CT_LBRC,
  CT_RBRC,
  CT_EQL,
  CT_BSLS,
};

enum custom_keycodes {
  ARW_THN = SAFE_RANGE,
  ARW_THK,
  DBL_CLN,
  HTTPS,
  GFYC,
  YOUT,
  INDENT,
  EUNHAPK,
  RINSPY,
  PST_ENT,
  RANDOM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
     * Map not correct yet
     * ,-----------------------------------------------------------.
     * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab / FN2  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  [|  ]|  Backsp  |
     * |-----------------------------------------------------------|
     * |Ctrl     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     * |-----------------------------------------------------------|
     * |Shift   |  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift  |FN |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |      Space           |Alt |Left |Down|Right|
     * `-----------------------------------------------------------'
     */
	[_DEFAULT] = LAYOUT_all(
        KC_GESC,      KC_1,    KC_2,    KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,       KC_0,     KC_MINS,  TD(CT_EQL), TD(CT_BSLS),    KC_GRV, \
    LT(_FN2, KC_TAB), KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,     KC_Z,     KC_U,     KC_I,     KC_O,       KC_P, TD(CT_LBRC), TD(CT_RBRC),     KC_BSPC, \
        MO(_FN),      KC_A,    KC_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L, TD(CT_CLN), TD(CT_QUOT),      ______,   KC_SFTENT, \
        KC_LSPO,   KC_LCTL,    KC_Y,    KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,     KC_SLSH,     KC_RSPC,   TG(_WASD), \
        KC_LCTL,   KC_LGUI, KC_LALT,                      KC_SPC,                                   KC_RALT, KC_RGUI,      KC_APP,      KC_RCTL),
	[_FN] = LAYOUT_all(
        KC_GESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   ______,   ______, \
        ______,  ARW_THN,    KC_UP,  ARW_THK,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_HOME,  KC_PGUP,  KC_PSCR,  KC_SLCK,  KC_PAUS,   ______,  DBL_CLN,   ______,   ______,   ______, \
        ______,   ______,   ______,   KC_INS,   KC_DEL,   KC_END,  KC_PGDN,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,                       INDENT,                                           ______,   ______,   ______,   ______),
	[_FN2] = LAYOUT_all(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   RANDOM,   ______,  EUNHAPK,   RINSPY,   ______,   ______,   ______,   ______,   ______,  KC_ASUP,  KC_ASRP,    RESET,   ______, \
        ______,   ______,   ______,   ______,   ______,     GFYC,   ______,   ______,   ______,   ______,  KC_ASDN,  KC_ASTG,   ______,   ______, \
        ______,   ______,     YOUT,   ______,   ______,  PST_ENT,   ______,   ______,   ______,   ______,   ______,    HTTPS,    KC_UP,   ______, \
        ______,   ______,   ______,                       ______,                                           ______,  KC_LEFT,  KC_DOWN,  KC_RGHT),
	[_WASD] = LAYOUT_all(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    KC_UP,   ______, \
        ______,   ______,   ______,                       ______,                                           ______,  KC_LEFT,  KC_DOWN,  KC_RGHT)
};

const uint16_t PROGMEM fn_actions[] = {
//   [0]  = ACTION_FUNCTION(LED_WASD),
//   [1]  = ACTION_FUNCTION(LED_FN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case INDENT:
            if (record->event.pressed) {
                SEND_STRING("    ");
            }
            break;
        case ARW_THN:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case ARW_THK:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case DBL_CLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            break;
        case HTTPS:
            if (record->event.pressed) {
                SEND_STRING("https://");
            }
            break;
        case YOUT:
            if (record->event.pressed) {
                SEND_STRING("https://youtu.be/");
            }
            break;
        case GFYC:
            if (record->event.pressed) {
                SEND_STRING("https://gfycat.com/");
            }
            break;
        case EUNHAPK:
            if (record->event.pressed) {
                SEND_STRING(":eunhapeek:\n");
            }
            break;
        case RINSPY:
            if (record->event.pressed) {
                SEND_STRING(":yerinspy:\n");
            }
            break;
        case PST_ENT:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_V));
                tap_code16(KC_ENT);
            }
            break;
        case RANDOM:
            if (record->event.pressed) {
                tap_random_base64();
            }
            break;
    }
    return true;
};

// tap dance semicolon

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_SCLN);
    } else {
        register_code (KC_RSFT);
        register_code (KC_SCLN);
    }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_SCLN);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_SCLN);
    }
}

// tap dance quot

void dance_quot_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_QUOT);
    } else {
        register_code (KC_RSFT);
        register_code (KC_QUOT);
    }
}

void dance_quot_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_QUOT);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_QUOT);
    }
}
// tap dance lbrc

void dance_lbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LBRC);
    } else {
        register_code (KC_RSFT);
        register_code (KC_LBRC);
    }
}

void dance_lbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LBRC);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_LBRC);
    }
}
// tap dance rbrc

void dance_rbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_RBRC);
    } else {
        register_code (KC_RSFT);
        register_code (KC_RBRC);
    }
}

void dance_rbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_RBRC);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_RBRC);
    }
}
// tap dance eql

void dance_eql_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_EQL);
    } else {
        register_code (KC_RSFT);
        register_code (KC_EQL);
    }
}

void dance_eql_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_EQL);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_EQL);
    }
}
// tap dance bsls

void dance_bsls_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_BSLS);
    } else {
        register_code (KC_RSFT);
        register_code (KC_BSLS);
    }
}

void dance_bsls_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_BSLS);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_BSLS);
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Esc, twice for Caps Lock
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [CT_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quot_finished, dance_quot_reset),
    [CT_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_finished, dance_lbrc_reset),
    [CT_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_finished, dance_rbrc_reset),
    [CT_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_eql_finished, dance_eql_reset),
    [CT_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_bsls_finished, dance_bsls_reset),
};

void matrix_scan_user(void) {
    uint32_t layer = layer_state;

    if (layer & (1<<_FN)) {
        gh60_wasd_leds_on();
    } else {
        gh60_wasd_leds_off();
    }

    if (layer & (1<<_WASD)) {
        gh60_poker_leds_on();
    } else {
        gh60_poker_leds_off();
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // My own actual leader sequences

        // T+R => Ctrl+Shift+T - re-open closed tab
        SEQ_TWO_KEYS(KC_T, KC_R) {
            SEND_STRING(SS_LCTRL(SS_LSFT("t")));
        }
        // N+N => Ctrl+Shift+N - open a new window
        SEQ_TWO_KEYS(KC_N, KC_N) {
            SEND_STRING(SS_LCTRL(SS_LSFT("n")));
        }
        // W+Q => Esc+:wq - quit vim
        SEQ_TWO_KEYS(KC_N, KC_N) {
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            SEND_STRING(":wq");
        }
        SEQ_ONE_KEY(KC_F) { SEND_STRING(SS_LCTL("akf")); } // Select all and format
        // D+D => select all + copy
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }
        // reset keyboard to bootloader
        SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
            reset_keyboard();
        }
        //tableflip (LEADER - TF)
        SEQ_TWO_KEYS(KC_T, KC_F) {
            unicode_input_start();

            register_hex(0x0028);
            register_hex(0x30ce);
            register_hex(0x0ca0);
            register_hex(0x75ca);
            register_hex(0x0ca0);
            register_hex(0x0029);
            register_hex(0x30ce);
            register_hex(0x5f61);
            register_hex(0x253b);
            register_hex(0x2501);
            register_hex(0x253b);

            unicode_input_finish();
        }
        SEQ_ONE_KEY(KC_B) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " ");
            tap_code16(KC_ENTER);
            SEND_STRING ("Built at: " QMK_BUILDDATE);
        }
        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git push");
        }
        SEQ_THREE_KEYS(KC_G, KC_F, KC_P) {
            SEND_STRING("git push --force-with-lease");
        }
        SEQ_ONE_KEY (KC_1) {
            // ¯\_(ツ)_/¯
            unicode_input_start(); register_hex(0xaf); unicode_input_finish();
            register_code (KC_RALT); tap_code16 (KC_MINS); unregister_code (KC_RALT);
            register_code (KC_RSFT); tap_code16 (KC_8); unregister_code (KC_RSFT);
            unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
            register_code (KC_RSFT); tap_code16 (KC_9); tap_code16(KC_7); unregister_code (KC_RSFT);
            unicode_input_start (); register_hex(0xaf); unicode_input_finish();
        }

        SEQ_ONE_KEY (KC_2) {
            // 凸(ツ)凸
            unicode_input_start(); register_hex(0x51F8); unicode_input_finish();
            register_code (KC_RSFT); tap_code16 (KC_8); unregister_code (KC_RSFT);
            unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
            register_code (KC_RSFT); tap_code16 (KC_9); unregister_code (KC_RSFT);
            unicode_input_start (); register_hex(0x51F8); unicode_input_finish();
        }

        /*  ", "    => LdrKey > " " */
        SEQ_ONE_KEY(KC_SPC) {
            SEND_STRING(", ");
        }
        /*  ". "    => LdrKey > " " > " " */
        SEQ_TWO_KEYS(KC_SPC, KC_SPC) {
            SEND_STRING(". ");
        }
        /*  `   => LdrKey > Escape */
        SEQ_ONE_KEY(KC_GESC) {
            SEND_STRING("`");
        }
        /*  ``` => LdrKey > Escape > Escape > Escape */
        SEQ_THREE_KEYS(KC_GESC, KC_GESC, KC_GESC) {
            SEND_STRING("```");
        }

        // Default sequences, so it's not loney here
        SEQ_ONE_KEY(KC_F) {
            // Anything you can do in a macro.
            SEND_STRING("QMK is awesome.");
        }
        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }
        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
        SEQ_THREE_KEYS(KC_C, KC_C, KC_C) {
            SEND_STRING("Per key timing is great!!!");
        }
    }
};
