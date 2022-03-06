#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLMK 1
#define _SYMB 2
#define _NAV_NUM 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLMK,
  SYMB,
  NAV_NUM,
  ADJUST,
};

// Shortcut to make keymap more readable
// Layer shortcuts
#define DF_COLMK  DF(_COLMK)
#define DF_QWRTY  DF(_QWERTY)
#define MO_SYM    MO(_SYMB)
#define MO_NVNM   MO(_NAV_NUM)
#define TT_ADJST  TT(_ADJUST)

// UK shortcuts
#define UK_AT     LSFT(KC_QUOT)
#define UK_GBP    LSFT(KC_3)
#define UK_HASH   KC_NUHS
#define UK_TILD   LSFT(KC_NUHS)
#define UK_BSLS   KC_NUBS
#define UK_PIPE   LSFT(KC_NUBS)
#define UK_DQUO   LSFT(KC_2)

// Key Overrides

// on all layers
// Shift + volume down = brightness down
const key_override_t volume_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_BRID);
// Shift + volume up = brightness up
const key_override_t volume_up_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_BRIU);

// on colemak layer only
// Shift + comma = semicolon
const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, _COLMK);
// Shift + dot = colon
const key_override_t dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, _COLMK);
// Shift + quote = double quote
const key_override_t quote_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOTE, UK_DQUO, _COLMK);
// Shift + question mark = exclamation mark
const key_override_t question_mark_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, _COLMK);

const key_override_t **key_overrides = (const key_override_t *[]){
    &volume_down_override,
    &volume_up_override,
    &comma_override,
    &dot_override,
    &quote_override,
    &question_mark_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,DF_COLMK,                          TT_ADJST,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_VOLD ,                          KC_VOLU ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL  ,XXXXXXX ,        XXXXXXX ,KC_BSPC ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_LALT ,KC_ESC  ,     KC_SPC  ,    KC_ENT  ,MO_NVNM ,        MO_SYM  ,KC_SPC  ,    KC_RSFT ,     MO_MACFN ,KC_RALT ,KC_RGUI ,KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_COLMK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,DF_QWRTY,                          TT_ADJST,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUES ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_VOLD ,                          KC_VOLU ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_RALT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_DEL  ,XXXXXXX ,        XXXXXXX ,KC_BSPC ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_QUOTE,KC_RCTL ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_LCTL ,    KC_ENT  ,MO_NVNM ,        MO_SYM  ,KC_SPC  ,    KC_RSFT ,     MO_MACFN,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,UK_AT   ,KC_MINS ,KC_LBRC ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_RBRC ,KC_PLUS ,KC_DLR  ,UK_GBP  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,UK_HASH ,KC_SLASH,KC_UNDS ,KC_LPRN ,KC_LT   ,XXXXXXX ,                          XXXXXXX ,KC_GT   ,KC_RPRN ,KC_EQL  ,UK_BSLS ,KC_ASTR ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,UK_TILD ,KC_PERC ,UK_PIPE ,KC_LCBR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RCBR ,KC_AMPR ,KC_CIRC ,KC_GRV  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_PGDN ,KC_UP   ,KC_PGUP ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_7   ,KC_8    ,KC_9    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_END  ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,KC_0    ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,RESET   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUD ,RGB_HUI ,RGB_SPD ,RGB_SPI ,RGB_RMOD,RGB_MOD ,XXXXXXX ,                          TT_ADJST,XXXXXXX ,KC_F7   ,KC_F8    ,KC_F9  ,XXXXXXX ,EEP_RST ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SAD ,RGB_SAI ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,XXXXXXX ,DEBUG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAD ,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     RGB_M_P ,    RGB_TOG ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
