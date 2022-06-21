#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x424D
#define PRODUCT_ID      0x4B00
#define DEVICE_VER      0x0000
#define MANUFACTURER    Brad Arnett
#define PRODUCT         BMK00 Numpad

#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, B4, B5, B2, B6 }
#define MATRIX_COL_PINS { F6, F5, D4, C6 }
#define UNUSED_PINS

#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B1 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#endif
