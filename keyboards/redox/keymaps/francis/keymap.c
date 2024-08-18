#include QMK_KEYBOARD_H

// ----------------------------------------------------------------------------------------------------
// KEYCODES

// UK shifted symbols
#define UK_DQUOT  LSFT(KC_2)    // "
#define UK_GBP    LSFT(KC_3)    // £
#define UK_AT     LSFT(KC_QUOT) // @
#define UK_HASH   KC_NUHS       // #
#define UK_TILDE  LSFT(KC_NUHS) // ~
#define UK_BSLS   KC_NUBS       // backslash
#define UK_PIPE   LSFT(KC_NUBS) // |

// Special characters
#define EMOJI LGUI(KC_DOT) // windows emoji

// Layer shortcuts
#define TG_QWRTY  TG(_QWERTY) // Toggle qwerty layer
#define TG_MOUSE  TG(_MOUSE)  // Mouse layer on hold (momentary) or double tap (toggle)
#define TT_FUN  TT(_FUN)      // Function layer on hold (momentary) or double tap (toggle)

// Layer tap keys
#define BSPC_SYMA LT(_SYM_A, KC_BSPC) // Symbol A on hold, backspace on tap
#define ESC_SYMB  LT(_SYM_B, KC_ESC)  // Symbol B on hold, escape on tap
#define ENT_NAV LT(_NAV, KC_ENT)    // Navigation layer on hold, enter on tap
#define SPC_NUM LT(_NUM, KC_SPC)    // Number layer on hold, space on tap

// Mod tap keys
// Left hand
#define GUI_A GUI_T(KC_A)   // A on tap, GUI on hold
#define ALT_R ALT_T(KC_R)   // R on tap, ALT on hold
#define CTRL_S CTL_T(KC_S)  // S on tap, CTRL on hold
#define SHIFT_T SFT_T(KC_T) // T on tap, SHIFT on hold
// Right hand
#define SHIFT_N SFT_T(KC_N) // N on tap, SHIFT on hold
#define CTRL_E CTL_T(KC_E)  // E on tap, CTRL on hold
#define ALT_I  ALT_T(KC_I)  // I on tap, ALT on hold
#define GUI_O GUI_T(KC_O)   // O on tap, GUI on hold

enum custom_keycodes {
    RGB_TOGG = SAFE_RANGE,  // Ensure this doesn't overlap with existing keycodes
};

enum layers {
   _COLMK,
   _QWERTY,
   _SYM_A,
   _SYM_B,
   _NAV,
   _NUM,
   _MOUSE,
};


// ----------------------------------------------------------------------------------------------------
// KEY OVERRIDES

// on all layers
const key_override_t volume_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_BRID); // Shift + volume down = brightness down
const key_override_t volume_up_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_BRIU);   // Shift + volume up = brightness up

// on colemak layer only
const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, 1 << 1);         // Shift + , = ;
const key_override_t dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, 1 << 1);            // Shift + . = :
const key_override_t quote_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOTE, UK_DQUOT, 1 << 1);        // Shift + ' = "
const key_override_t question_mark_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_QUES, 1 << 1); // Shift +  ! = ?

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &volume_down_override,
    &volume_up_override,
    &comma_override,
    &dot_override,
    &quote_override,
    &question_mark_override,
    NULL // Null terminate the array of overrides!
};

// ----------------------------------------------------------------------------------------------------
// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLMK] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B   ,TG_QWRTY,                          RGB_TOGG,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_EXLM ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,GUI_A   ,ALT_R   ,CTRL_S  ,SHIFT_T ,KC_G   ,KC_VOLD ,                          KC_VOLU ,KC_M    ,SHIFT_N ,CTRL_E  ,ALT_I   ,GUI_O   ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V   ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_QUOTE,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    KC_DEL      ,BSPC_SYMA,ESC_SYMB,       ENT_NAV ,SPC_NUM,     KC_TAB       ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5   ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T   ,TG_QWRTY,                          RGB_TOGG,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G   ,KC_VOLD ,                          KC_VOLU ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B   ,XXXXXXX ,XXXXXXX ,        XXXXXXX, XXXXXXX ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     KC_LCTL ,KC_LGUI ,KC_LALT ,KC_ESC  ,    KC_DEL      ,BSPC_SYMA,ESC_SYMB,       ENT_NAV ,SPC_NUM,     KC_TAB       ,XXXXXXX ,KC_RALT ,KC_RGUI ,KC_RCTL
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

  [_SYM_A] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LCBR ,KC_DLR  ,KC_GRAVE,UK_TILDE,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,XXXXXXX,XXXXXXX ,                          XXXXXXX ,KC_LABK ,KC_LPRN ,KC_UNDS ,KC_MINUS,KC_SLASH,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LBRC ,KC_AMPR ,UK_HASH ,KC_PERC ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

   [_SYM_B] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_RCBR ,UK_GBP  ,KC_ASTR ,KC_CIRC ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,XXXXXXX,XXXXXXX ,                          XXXXXXX ,KC_RABK ,KC_RPRN ,KC_EQUAL,KC_PLUS ,UK_BSLS ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RBRC ,UK_PIPE ,UK_AT   ,EMOJI   ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

  [_NAV] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_END  ,KC_UP   ,KC_HOME,KC_PGUP ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT,KC_PGDN ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LSFT ,KC_LCTL ,KC_LALT ,KC_LGUI ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    _______     ,TG_MOUSE,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

  [_NUM] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_1    ,KC_2    ,KC_3   ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6   ,KC_0    ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LSFT ,KC_LCTL ,KC_LALT ,KC_LGUI ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

[_MOUSE] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_WH_U,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX ,XXXXXXX ,        TG_MOUSE,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    _______     ,TG_MOUSE,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  ),

//   [_FUN] = LAYOUT(
//   //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
//   //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//      RGB_HUD ,RGB_HUI ,RGB_SPD ,RGB_SPI ,RGB_RMOD,RGB_MOD,XXXXXXX ,                          TT_FUN,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10 ,QK_BOOT,
//   //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//      RGB_SAD ,RGB_SAI ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX,                          XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11 ,EE_CLR ,
//   //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//      RGB_VAD ,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,XXXXXXX,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12 ,DB_TOGG,
//   //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    RGB_M_P     ,RGB_TOG ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
//   //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
//   )
};

// ----------------------------------------------------------------------------------------------------
// LIGHTING
void keyboard_post_init_user(void) {
    // Ensure the RGB light matches the current layer on startup
    rgblight_setrgb(RGB_WHITE);
}

// Set the RGB underglow color based on the active layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COLMK:
            rgblight_setrgb(RGB_GOLDENROD);
            break;
        case _QWERTY:
            rgblight_setrgb(RGB_TEAL);
            break;
        case _SYM_A:
            rgblight_setrgb(RGB_PINK);
            break;
        case _SYM_B:
            rgblight_setrgb(RGB_PINK);
            break;
        case _NAV:
            rgblight_setrgb(RGB_CYAN);
            break;
        case _NUM:
            rgblight_setrgb(RGB_CYAN);
            break;
        case _MOUSE:
            rgblight_setrgb(RGB_MAGENTA);
            break;
        default:
            rgblight_setrgb(RGB_WHITE); // White for any other undefined layers
            break;
    }
    return state;
}

// Change the color of the RGB underglow when mod-tap keys are pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOGG:
            if (record->event.pressed) {
                rgblight_toggle();
            }
            break;
        case SHIFT_T:
        case SHIFT_N:
        case CTRL_S:
        case CTRL_E:
        case ALT_R:
        case ALT_I:
        case GUI_A:
        case GUI_O:
            if (record->event.pressed) {
                rgblight_setrgb(RGB_GOLD); // Set to gold when mod-tap key is pressed
            } else {
                layer_state_set_user(layer_state); // Reset to current layer color
            }
            break;
    }
    return true;
}
