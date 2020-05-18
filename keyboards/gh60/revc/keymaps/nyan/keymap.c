#include QMK_KEYBOARD_H
#define ______ KC_TRNS

#define _DEFAULT 0
#define _FN 1
#define _WASD 2
#define _SFX 3

// Tap Dance Declarations
enum kc_tap_dances {
  CT_CLN = 0,
  CT_QUOT,
  CT_LBRC,
  CT_RBRC,
  CT_MINS,
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
        KC_GESC,      KC_1,    KC_2,    KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,       KC_0, TD(CT_MINS),  TD(CT_EQL), TD(CT_BSLS),    KC_GRV, \
        LT(2,KC_TAB), KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,     KC_Z,     KC_U,     KC_I,     KC_O,       KC_P, TD(CT_LBRC), TD(CT_RBRC),     KC_BSPC, \
        MO(1)  ,      KC_A,    KC_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L, TD(CT_CLN), TD(CT_QUOT),      KC_DEL,      KC_ENT, \
        KC_LSPO,   KC_LCTL,    KC_Y,    KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,     KC_SLSH,     KC_RSPC,       MO(1), \
        KC_LCTL,   KC_LGUI, KC_LALT,                      KC_SPC,                                   KC_RALT, KC_RGUI,      KC_APP,     KC_RCTL),
	[_FN] = LAYOUT_all(
        KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   ______,   ______, \
        ______,  ARW_THN,    KC_UP,  ARW_THK,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_HOME,  KC_PGUP,  KC_PSCR,  KC_SLCK,  KC_PAUS,   ______,  DBL_CLN,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   KC_DEL,   KC_END,  KC_PGDN,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,                       INDENT,                                           ______,   ______,   ______,   ______),
	[_WASD] = LAYOUT_all(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   RANDOM,   ______,  EUNHAPK,   RINSPY,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    RESET,   ______, \
        ______,   ______,   ______,   ______,   ______,     GFYC,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,     YOUT,   ______,   ______,  PST_ENT,   ______,   ______,   ______,   ______,   ______,    HTTPS,    KC_UP,   ______, \
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
// tap dance mins

void dance_mins_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_MINS);
    } else {
        register_code (KC_RSFT);
        register_code (KC_MINS);
    }
}

void dance_mins_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_MINS);
    } else {
        unregister_code (KC_RSFT);
        unregister_code (KC_MINS);
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
    [CT_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mins_finished, dance_mins_reset),
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
};
