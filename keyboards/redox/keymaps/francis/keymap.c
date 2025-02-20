#include QMK_KEYBOARD_H

// ----------------------------------------------------------------------------------------------------
// KEYCODES

// Layer shortcuts
#define DF_ALPHA DF(_ALPHABET)
#define DF_GAME1 DF(_GAME1)
#define MO_GAME2 MO(_GAME2)

// Layer tap keys
// #define R_MACRO LT(_MACROS, KC_R)        // Macros layer on hold, r on tap
#define BSPC_SYM LT(_SYMBOLS, KC_BACKSPACE) // Symbols layer on hold, backspace on tap
#define ESC_NUM LT(_NUMBERS, KC_ESCAPE)     // Numbers on hold, escape on tap
#define ENT_NAV LT(_NAVIGATION, KC_ENTER)   // Navigation on hold, enter on tap
#define SPC_SYM LT(_SYMBOLS, KC_SPACE)      // Symbols layer on hold, space on tap
#define TAB_MOUS LT(_MOUSE, KC_TAB)         // Mouse layer on hold, tab on tap

// Mod tap keys
// Left hand
#define GUI_S GUI_T(KC_S)   // S on tap, GUI on hold
#define ALT_N ALT_T(KC_N)   // N on tap, ALT on hold
#define CTRL_T CTL_T(KC_T)  // T on tap, CTRL on hold
#define SHIFT_H LSFT_T(KC_H) // H on tap, SHIFT on hold
// Right hand
#define SHIFT_A RSFT_T(KC_A) // A on tap, SHIFT on hold
#define CTRL_E CTL_T(KC_E)  // E on tap, CTRL on hold
#define ALT_I  ALT_T(KC_I)  // I on tap, ALT on hold
#define GUI_C GUI_T(KC_C)   // C on tap, GUI on hold

enum custom_keycodes {
    RGB_TOGG = SAFE_RANGE,  // Ensure this doesn't overlap with existing keycodes
};

enum layers {
    _ALPHABET,
    _SYMBOLS,
    _NUMBERS,
    _NAVIGATION,
    _MOUSE,
    _FUNCTION,
    _GAME1,
    _GAME2,
};


// ----------------------------------------------------------------------------------------------------
// KEY OVERRIDES

// on all layers
const key_override_t volume_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_BRID); // Shift + volume down = brightness down
const key_override_t volume_up_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_BRIU);   // Shift + volume up = brightness up

// on alphabet layer only
const key_override_t alpha_comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, 1 << 0);         // Shift , is ;
const key_override_t alpha_dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, 1 << 0);            // Shift . is :
const key_override_t alpha_question_mark_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, 1 << 0); // Shift ? is !

// on number layer only
const key_override_t num_equals_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQUAL, KC_DLR, 1 << 2); // Shift = is $
const key_override_t num_minus_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINUS, KC_BSLS, 1 << 2); // Shift - is /
const key_override_t num_plus_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_ASTR, 1 << 2);   // Shift + is *

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &volume_down_override,
    &volume_up_override,
    &alpha_comma_override,
    &alpha_dot_override,
    &alpha_question_mark_override,
    &num_equals_override,
    &num_minus_override,
    &num_plus_override,
};

// ----------------------------------------------------------------------------------------------------
// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHABET] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_VOLU ,KC_F    ,KC_P    ,KC_D    ,KC_L    ,KC_X    ,XXXXXXX ,                          XXXXXXX ,KC_Q    ,KC_U    ,KC_O    ,KC_Y    ,KC_B    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_VOLD ,GUI_S   ,ALT_N   ,CTRL_T  ,SHIFT_H ,KC_K    ,XXXXXXX ,                          XXXXXXX ,KC_Z    ,SHIFT_A ,CTRL_E  ,ALT_I   ,GUI_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE ,KC_V    ,KC_W    ,KC_G    ,KC_M    ,KC_J    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_MINUS,KC_COMM ,KC_DOT  ,KC_QUES ,KC_QUOTE,RGB_TOGG,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_R        ,BSPC_SYM,ESC_NUM ,        ENT_NAV ,SPC_SYM ,    TAB_MOUS     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DF_GAME1
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_PIPE ,KC_AMPR ,KC_PLUS ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_RCBR ,KC_LCBR ,KC_DLR  ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_GT   ,KC_LT   ,KC_SLASH,KC_EQUAL,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_RPRN ,KC_LPRN ,KC_HASH ,KC_GRAVE,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_CIRC ,KC_ASTR ,KC_PERC ,KC_TILDE,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RBRC ,KC_LBRC ,KC_AT   ,KC_BSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_NUMBERS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_EQUAL,KC_0    ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_MINUS,KC_COMM ,KC_DOT  ,KC_8    ,KC_9    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_NAVIGATION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_END  ,KC_UP   ,KC_HOME ,KC_PGUP ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LSFT ,KC_LCTL ,KC_LALT ,KC_LGUI ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_WH_U ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_FUNCTION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F11  ,KC_F12  ,KC_F8   ,KC_F9   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

     [_GAME1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LSFT ,KC_X    ,KC_C    ,KC_V    ,KC_T    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     MO_GAME2     ,KC_SPC ,KC_ESC  ,        XXXXXXX ,XXXXXXX ,    XXXXXXX      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DF_ALPHA
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

      [_GAME2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_5    ,KC_4    ,KC_3    ,KC_2    ,KC_1    ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        XXXXXXX ,XXXXXXX ,    XXXXXXX      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  // select all, Copy, cut, paste, paste no styles
    // zoom in, out, 100%
    // screen shot, screen clip, screen recording
    // bold, italic, underline
    // clear terminal
    // save, undo, redo
    // power, sleep, lock, restart,
    // launcher, quit
    // find
// [_MACRO] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XZXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,ZOOM_IN ,VOL_UP  ,KC_PSCR ,XXXXXXX ,XXXXXXX ,XXXXXXX,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,ZOOM_100,TG_MUTE ,SCR_CLIP,XXXXXXX ,XXXXXXX ,XXXXXXX,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,ZOOM_OUT,VOL_DOWN,SCR_REC ,XXXXXXX ,XXXXXXX ,XXXXXXX,
//   //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______     ,_______ ,_______ ,        _______ ,_______ ,    _______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
//   //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//   ),

  // [_QWERTY] = LAYOUT(
  // //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
  //    KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5   ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX,
  // //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                         ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
  //    KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T   ,TG_QWRTY,                          RGB_TOGG,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX,
  // //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
  //    KC_CAPS XuC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G   ,KC_VOLD ,                          KC_VOLU ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,XXXXXXX,
  // //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
  //    KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B   ,XXXXXXX ,XXXXXXX ,        XXXXXXX, XXXXXXX ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT,
  // //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
  //    KC_LCTL ,KC_LGUI ,KC_LALT ,KC_ESC  ,    KC_DEL      ,BSPC_SYMA,ESC_SYMB,       ENT_NAV ,SPC_NUM,     KC_TAB       ,XXXXXXX ,KC_RALT ,KC_RGUI ,KC_RCTL
  // //└─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┘       └─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┘
  // ),

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

// Set the RGB underglow color based on the active layer
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUMBERS, _NAVIGATION, _FUNCTION);

    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    switch (get_highest_layer(state)) {
        case _ALPHABET:
            rgblight_setrgb(RGB_GOLDENROD);
            break;
        case _SYMBOLS:
            rgblight_setrgb(RGB_PINK);
            break;
        case _NAVIGATION:
            rgblight_setrgb(RGB_CYAN);
            break;
        case _NUMBERS:
            rgblight_setrgb(RGB_CYAN);
            break;
        case _MOUSE:
            rgblight_setrgb(RGB_MAGENTA);
            break;
        case _GAME1:
        case _GAME2:
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            break;
        default:
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_setrgb(RGB_WHITE); // White for any other undefined layers
            break;
    }
    return state;
}

void keyboard_post_init_user(void) {
    // Ensure RGB lighting corresponds to the current layer on startup
    layer_state_set_user(layer_state);
}

// Change the color of the RGB underglow when mod-tap keys are pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOGG:
            if (record->event.pressed) {
                rgblight_toggle();
                layer_state_set_user(layer_state);
            }
            break;
        case DF_GAME1:
            if(record->event.pressed) {
                rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            }
            break;
        case DF_ALPHA:
            if(record->event.pressed) {
                layer_state_set_user(layer_state);
            }
            break;
        case SHIFT_H:
        case SHIFT_A:
        case CTRL_T:
        case CTRL_E:
        case ALT_N:
        case ALT_I:
        case GUI_S:
        case GUI_C:
            if (record->event.pressed) {
                rgblight_setrgb(RGB_GOLD); // Set to gold when mod-tap key is pressed
            } else {
                layer_state_set_user(layer_state); // Reset to current layer color
            }
            break;
    }
    return true;
}
