#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT,
    _FN,
    _FN2,
    _WASD,
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

    [_DEFAULT] = LAYOUT_all( /* 0: qwerty */
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
LT(_FN2, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        TT(_FN),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ASST,   KC_ENT,
        SC_LSPO,  TG(_FN),   KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC, TG(_WASD),
        KC_LCTL,  KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),

    [_FN] = LAYOUT_all( /* 1: fn */
        _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______, _______,
        _______,  ARW_THN,    KC_UP,  ARW_THK,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_HOME,  KC_PGUP,  KC_PSCR,  KC_SCRL,  KC_PAUS,   _______,  DBL_CLN,   _______,   _______,   _______, \
        _______,   _______,   _______,   KC_INS,   KC_DEL,   KC_END,  KC_PGDN,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
        _______,   _______,   _______,                       INDENT,                                           _______,   _______,   _______,   _______
    ),
    [_FN2] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
        _______,    RANDOM,   _______,   EUNHAPK,    RINSPY,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
        _______,   _______,   _______,   _______,   _______,      GFYC,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
        _______,   _______,      YOUT,   _______,   _______,   PST_ENT,   _______,   _______,   _______,   _______,   _______,     HTTPS,     KC_UP,   _______, \
        _______,   _______,   _______,                         _______,                                               _______,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    [_WASD] = LAYOUT_all( /* 3: arrows */
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_UP,     _______,
        _______,   _______,   _______,                         _______,                                               _______,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

};

void matrix_scan_user(void) {

//Layer LED indicators
    layer_state_t layer = layer_state;

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

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

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


        case KC_BSPC:
            {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
            }
    }
    return true;
};
