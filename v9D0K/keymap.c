#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "audio.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// Define the startup sound
float startup_sound[][2] = SONG(E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7));

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          TG(1),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TG(2),                                          TG(2),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_NUBS,                                                                        KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_LGUI, KC_QUOTE),
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT,
    MO(2),          KC_LEFT_GUI,    CW_TOGG,        KC_TRANSPARENT, MO(1),          KC_CAPS,                                                                                                        KC_ESCAPE,      MO(3),          KC_HYPR,        KC_LBRC,        KC_RBRC,        MO(1),
    KC_SPACE,       KC_LEFT_ALT,    KC_F13,                         KC_BSPC,        KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_GRAVE,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_NO,          LCTL(LSFT(KC_LEFT)),KC_NO,          LCTL(LSFT(KC_RIGHT)),KC_NUBS,        KC_NO,                                          KC_NO,          KC_HOME,        KC_7,           KC_8,           KC_9,           UK_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_NO,          LGUI(LCTL(KC_Y)),KC_NO,          LCTL(LSFT(KC_X)),KC_NO,          KC_TRANSPARENT,                                                                 KC_NO,          KC_END,         KC_4,           KC_5,           KC_6,           UK_PLUS,        KC_NO,
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          UK_SLSH,        KC_1,           KC_2,           KC_3,           UK_MINS,        KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,                                                                                                          KC_TRANSPARENT, KC_NO,          KC_0,           UK_DOT,         UK_EQL,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     KC_NO,          LCTL(KC_F),     KC_NO,          KC_NO,                                                                          KC_NO,          KC_END,         KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,                          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    QK_BOOT,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_NO,          KC_NO,          LSFT(KC_LEFT),  LCTL(LSFT(KC_X)),LSFT(KC_RIGHT), KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F12,
    KC_NO,          LCTL(KC_BSPC),  LCTL(KC_LEFT),  LGUI(LCTL(KC_Y)),LCTL(KC_RIGHT), KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          LCTL(RSFT(KC_BSPC)),LCTL(LSFT(KC_LEFT)),KC_NO,          LCTL(LSFT(KC_RIGHT)),KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {32,248,255}, {0,0,255}, {0,0,255}, {2,198,244}, {208,198,176}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {2,198,244}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {0,0,255}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {0,0,0}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {208,198,176}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {208,198,176}, {208,198,176}, {32,248,255}, {0,0,255}, {2,198,244}, {0,245,245}, {2,198,244}, {32,248,255}, {32,248,255}, {32,248,255}, {2,198,244}, {208,198,176}, {148,220,243}, {87,144,175}, {32,248,255}, {32,248,255}, {32,248,255}, {148,220,243}, {87,144,175}, {87,144,175}, {32,248,255}, {32,248,255}, {148,220,243}, {87,144,175}, {87,144,175}, {32,248,255}, {124,255,150}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {208,198,176}, {148,220,243}, {87,144,175}, {87,144,175}, {87,144,175}, {208,198,176}, {208,198,176}, {124,255,150}, {0,0,255}, {0,0,255}, {0,0,255}, {2,198,244} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {2,198,244}, {32,248,255}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {2,198,244}, {32,248,255}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {208,198,176}, {0,245,245}, {0,245,245}, {0,245,245}, {74,255,206}, {208,198,176}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {208,198,176}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {208,198,176}, {131,255,255}, {131,255,255}, {74,255,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,248,255}, {32,248,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,248,255}, {32,248,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,248,255}, {0,0,0}, {0,0,0}, {32,248,255}, {32,248,255}, {32,248,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,248,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {148,220,243}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {2,198,244}, {2,198,244}, {0,0,0}, {208,198,176}, {2,198,244}, {2,198,244}, {2,198,244}, {0,0,0}, {208,198,176}, {32,248,255}, {32,248,255}, {0,0,0}, {0,0,0}, {208,198,176}, {2,198,244}, {2,198,244}, {2,198,244}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,198,176}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }

  // Check if Caps Lock is on
  if (host_keyboard_led_state().caps_lock) {
    // Set all keys to red when Caps Lock is on
    rgb_matrix_set_color_all(255, 0, 0);
  } else {
    // Normal layer-based lighting when Caps Lock is off
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
     default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
    }
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CAPS:
        if (record->event.pressed) {
            // Play startup sound when Caps Lock is pressed
            PLAY_SONG(startup_sound);
        }
        return true; // Let QMK handle the actual Caps Lock toggling

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}








// Checkpoint CAPS LOCK
// +-----------------+
// | Custom QMK Code |
// +-----------------+
const key_override_t f13_to_f14_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_F13, KC_F14);

const key_override_t **key_overrides = (const key_override_t *[]){
	&f13_to_f14_override,
	NULL
};