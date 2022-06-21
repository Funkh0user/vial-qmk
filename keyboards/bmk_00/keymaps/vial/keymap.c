#include "bmk_00.h"

enum encoder_names {
  DIAL,
};

enum layers {
    _WINDOWS,
    _LINUX,
    _NA,
};

enum my_keycodes {
    CMD_PROMPT = SAFE_RANGE
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WINDOWS] = KEYMAP(
        TO(_LINUX),           LGUI(KC_TAB),       LCTL(KC_EQUAL),   LCTL(KC_MINUS),
        LCTL(KC_A),           LCTL(KC_C),         LCTL(KC_V),
        LCTL(KC_Z),           LCTL(KC_S),         LCTL(KC_Y),       CMD_PROMPT,
        LSFT(LGUI(KC_S)),     LGUI(KC_PSCR),      LGUI(LALT(KC_R)),
        LGUI(KC_L),           LCTL(LSFT(KC_ESC)), LCTL(LALT(KC_DEL))),

	[_LINUX] = KEYMAP(
		TO(_WINDOWS),    KC_SLSH,    KC_ASTR,    KC_MINS,
		KC_HOME,    KC_NO,      KC_PGUP,
		KC_NO,      KC_5,       KC_NO,      KC_PLUS,
		KC_END,     KC_NO,      KC_PGDN,
		KC_INS,     KC_DEL,     KC_ENT),

	[_NA] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case CMD_PROMPT:
            if(record->event.pressed) {
                SEND_STRING(SS_TAP(X_LWIN) SS_DELAY(50) "cmd" SS_DELAY(50) SS_TAP(X_PENT));
            }
            break;
    }
	return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _WINDOWS:
            oled_write_P(PSTR("WINDOWS\n"), false);
            break;
        case _LINUX:
            oled_write_P(PSTR("LINUX\n"), false);
            break;
        case _NA:
            oled_write_P(PSTR("NA\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif


void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
