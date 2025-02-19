#include QMK_KEYBOARD_H

// ----------------------------------------------------------------------------------------------------
// KEYCODES

// Layer shortcuts
#define TG_QWRTY  TG(_QWERTY) // Toggle qwerty layer
#define TG_MOUSE  TG(_MOUSE)  // Mouse layer on hold (momentary) or double tap (toggle)
#define TT_FUN  TT(_FUN)      // Function layer on hold (momentary) or double tap (toggle)
#define DF_ALPHA DF(_ALPHABET)
#define DF_GAME1 DF(_GAME1)
#define MO_GAME2 MO(_GAME2)
#define MO_FUN MO(_FUNCTION)

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
#define SHIFT_H SFT_T(KC_H) // H on tap, SHIFT on hold
// Right hand
#define SHIFT_A SFT_T(KC_A) // A on tap, SHIFT on hold
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

// on colemak layer only
const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, 1 << 0);         // Shift + , = ;
const key_override_t dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, 1 << 0);            // Shift + . = :
const key_override_t question_mark_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, 1 << 0); // Shift + ? = !

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &volume_down_override,
    &volume_up_override,
    &comma_override,
    &dot_override,
    &question_mark_override,
};

// ----------------------------------------------------------------------------------------------------
// KEYMAP

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHABET] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_VOLU ,KC_F    ,KC_P    ,KC_D    ,KC_L    ,KC_X    ,                          KC_Q    ,KC_U    ,KC_O    ,KC_Y    ,KC_B    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_VOLD ,GUI_S   ,ALT_N   ,CTRL_T  ,SHIFT_H ,KC_K    ,                          KC_Z    ,SHIFT_A ,CTRL_E  ,ALT_I   ,GUI_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE ,KC_V    ,KC_W    ,KC_G    ,KC_M    ,KC_J    ,                          KC_MINUS,KC_COMM ,KC_DOT  ,KC_QUES ,KC_QUOTE,RGB_TOGG,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         KC_R    ,BSPC_SYM,ESC_NUM ,        ENT_NAV ,SPC_SYM ,TAB_MOUS
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,KC_PIPE ,KC_AMPR ,KC_PLUS ,XXXXXXX ,                          XXXXXXX ,KC_RCBR ,KC_LCBR ,KC_DLR  ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_GT   ,KC_LT   ,KC_SLASH,KC_EQUAL,XXXXXXX ,                          XXXXXXX ,KC_RPRN ,KC_LPRN ,KC_HASH ,KC_GRAVE,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_CIRC ,KC_ASTR ,KC_PERC ,KC_TILDE,XXXXXXX ,                          XXXXXXX ,KC_RBRC ,KC_LBRC ,KC_AT   ,KC_BSLS ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,        _______ ,_______ ,_______
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,XXXXXXX ,                          KC_EQUAL,KC_0    ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_MINUS,KC_7    ,KC_8    ,KC_9    ,KC_SLASH,XXXXXXX ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,        MO_FUN  ,_______ ,_______
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,KC_END  ,KC_UP   ,KC_HOME ,KC_PGUP ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,                          XXXXXXX ,KC_LSFT ,KC_LCTL ,KC_LALT ,KC_LGUI ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,        _______ ,_______ ,_______
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

    [_MOUSE] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_WH_U ,                          XXXXXXX ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,                          XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,        _______ ,_______ ,_______
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,        _______ ,_______ ,_______
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

     [_GAME1] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LSFT ,KC_X    ,KC_C    ,KC_V    ,KC_T    ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         MO_GAME2,KC_SPC  ,KC_ESC  ,        XXXXXXX ,XXXXXXX ,XXXXXXX
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),

      [_GAME2] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_5    ,KC_4    ,KC_3    ,KC_2    ,KC_1    ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX
  //                                    └────────┴────────┴────────┘       └────────┴────────┴────────┘
  ),
};

// #include QMK_KEYBOARD_H
// #if __has_include("keymap.h")
// #    include "keymap.h"
// #endif
//
//
// /* THIS FILE WAS GENERATED!
//  *
//  * This file was generated by qmk json2c. You may or may not want to
//  * edit it directly.
//  */
//
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_RALT),
//     [1] = LAYOUT_split_3x6_3(_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
//     [2] = LAYOUT_split_3x6_3(QK_BOOT, _______, _______, _______, _______, _______, RM_VALU, RM_HUEU, RM_SATU, RM_NEXT, RM_TOGG, _______, EE_CLR, _______, _______, _______, _______, _______, RM_VALD, RM_HUED, RM_SATD, RM_PREV, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
// };
//
//
//
// #ifdef OTHER_KEYMAP_C
// #    include OTHER_KEYMAP_C
// #endif // OTHER_KEYMAP_C
//
