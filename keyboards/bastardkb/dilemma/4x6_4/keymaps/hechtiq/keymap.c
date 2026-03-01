/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_POINTER,
    LAYER_INTELIJ,
    LAYER_INTELIJ2,
    LAYER_GAMING,
    LAYER_GNOME,
};



// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

// Homerow mods
#define MOD_S GUI_T(KC_S)
#define MOD_D CTL_T(KC_D)
#define MOD_F SFT_T(KC_F)

#define MOD_J SFT_T(KC_J)
#define MOD_K CTL_T(KC_K)
#define MOD_L GUI_T(KC_L)

// SYM keys
enum custom_keycodes {
    KC_LEQ = SAFE_RANGE,
    KC_GEQ,
    KC_NEQ,
    KC_ARR,
    KC_PAE,
};

//Intellij shortcuts
#define BMRK_O  KC_F11
#define BMRK_T  LSFT(KC_F11)
#define BMRK_P  LCS(KC_F11)
#define BMRK_N  LSA(KC_F11)
#define FIND    LCS(KC_F)
#define OPEN    LCS(KC_N)
#define CMD_P   HYPR(KC_F)
#define FND_USG LSA(KC_7)
#define RFCT_MN HYPR(KC_T)
#define RCNT_FI  LC(KC_E)
#define GO_DCL  LC(KC_B)
#define GO_IMP  LCA(KC_B)
#define GO_BCK  LSA(KC_LEFT)
#define GO_FWD  LSA(KC_RIGHT)
#define BLAME   HYPR(KC_B)
#define REOPN   HYPR(KC_R)

#define QCK_DEF LCS(KC_I)
#define QCK_DOC LC(KC_Q)

// GNOME shortcuts
#define ACTY    KC_LGUI
#define WS_L    LCA(KC_LEFT)
#define WS_R    LCA(KC_RIGHT)
#define S_1     LGUI(KC_1)
#define S_2     LGUI(KC_2)
#define S_3     LGUI(KC_3)
#define S_4     LGUI(KC_4)
#define SS_1    LSFT(LGUI(KC_1))
#define SS_2    LSFT(LGUI(KC_2))
#define SS_3    LSFT(LGUI(KC_3))
#define SS_4    LSFT(LGUI(KC_4))
#define S_UP    LGUI(KC_UP)
#define S_DWN   LGUI(KC_DOWN)
#define S_LFT   LGUI(KC_LEFT)
#define S_RGT   LGUI(KC_RIGHT)
#define A_TAB   LALT(KC_TAB)
#define AS_TAB  LALT(LSFT(KC_TAB))
#define AT_GRV  LALT(KC_GRV)

#define NAV     LT(LAYER_NAV, KC_SPC)
#define SYM     LT(LAYER_SYM, KC_SPC)
#define INTJ    LT(LAYER_INTELIJ, KC_TAB)
#define INTJ2   MO(LAYER_INTELIJ2)
#define GNME    LT(LAYER_GNOME, KC_ENT)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PSCR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_A,    MOD_S,   MOD_D,   MOD_F,   KC_G,       KC_H,    MOD_J  , MOD_K,   MOD_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, QK_LEAD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_MPLY, KC_BSPC,  INTJ,    NAV,      SYM,  GNME, KC_DEL,  KC_MUTE
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

    [LAYER_SYM] = LAYOUT(
// ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     XXXXXXX, XXXXXXX, KC_BSLS, KC_ASTR, KC_AMPR, KC_ARR,     KC_NEQ,  KC_GRV,  KC_LCBR, KC_RCBR, KC_PAE, XXXXXXX,
// ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     XXXXXXX, XXXXXXX,  KC_AT,  KC_COLN, KC_PLUS,  KC_LT,      KC_GT,  KC_EQL,  KC_LPRN, KC_RPRN, KC_SCLN, XXXXXXX,
// ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     XXXXXXX, XXXXXXX, KC_HASH, KC_PIPE, KC_EXLM, KC_LEQ,     KC_GEQ,  KC_UNDS, KC_LBRC, KC_RBRC, KC_SLSH, XXXXXXX,
// ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                        KC_MPLY, XXXXXXX, XXXXXXX, QK_LLCK,   _______, XXXXXXX, XXXXXXX, KC_MUTE
//                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_MPLY, XXXXXXX, XXXXXXX, _______,    QK_LLCK, XXXXXXX, XXXXXXX, KC_MUTE
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_MPLY, KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1, KC_BTN2, KC_MUTE
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

    [LAYER_INTELIJ] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, QCK_DOC,   OPEN,  GO_IMP,  GO_BCK,  GO_FWD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, QCK_DEF,  BMRK_T, GO_DCL,  CMD_P,   RCNT_FI,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, RFCT_MN,   FIND,  FND_USG, BMRK_P,  BMRK_N,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            KC_MPLY, XXXXXXX, _______, INTJ2,   QK_LLCK, XXXXXXX, XXXXXXX, KC_MUTE
    //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    ),

    [LAYER_INTELIJ2] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, REOPN,   KC_F2,   GO_BCK,  GO_FWD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, BMRK_O, LSFT(KC_F2), KC_F7, LSFT(KC_F7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, BLAME,  LCTL(KC_F4), BMRK_P, BMRK_N,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            KC_MPLY, XXXXXXX, _______, _______,   QK_LLCK, XXXXXXX, XXXXXXX, KC_MUTE
    //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    ),

    [LAYER_GAMING] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_ESC,  KC_5,    KC_1,    KC_2,    KC_3,    KC_4,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_P,    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_M,    KC_G,    KC_A,    KC_S,    KC_D,    KC_F,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_I,    KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            KC_MPLY, KC_LCTL, KC_SPC,  KC_LSFT,   XXXXXXX, XXXXXXX, TG(LAYER_GAMING),KC_MUTE
    //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    ),

    [LAYER_GNOME] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX,  S_UP,   S_LFT,   S_RGT,   S_DWN,  XXXXXXX,     SS_1,    SS_2,    SS_3,    SS_4,   XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX,  ACTY,   XXXXXXX,  WS_L,   WS_R,   XXXXXXX,     S_1,     S_2,     S_3,     S_4,   XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            KC_MPLY, AT_GRV,  A_TAB,  AS_TAB,     _______, XXXXXXX, XXXXXXX, KC_MUTE
    //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_LEQ: send_string("<="); return false;
            case KC_GEQ: send_string(">="); return false;
            case KC_NEQ: send_string("!="); return false;
            case KC_ARR: send_string("->"); return false;
            case KC_PAE: send_string("+="); return false;
        }
    }
    return true;
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef COMBO_ENABLE
    enum combos {
        QW_ESC,
        ZR_PRS,
        FJ_CAPS,
        QP_GAMING,
    };
    const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM lck_combo[] = {KC_0, KC_PSCR, COMBO_END};
    const uint16_t PROGMEM caps_combo[] = {MOD_F, MOD_J, COMBO_END};
    const uint16_t PROGMEM gaming_combo[] = {KC_Q, KC_P, COMBO_END};

    combo_t key_combos[] = {
        [QW_ESC]    = COMBO(qw_combo, KC_ESC),
        [ZR_PRS]    = COMBO(lck_combo, KC_SLEP),
        [FJ_CAPS]   = COMBO(caps_combo, CW_TOGG),
        [QP_GAMING] = COMBO(gaming_combo, TG(LAYER_GAMING)),
    };

    bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
        switch (combo_index) {
            case QW_ESC:
            case FJ_CAPS:
            case ZR_PRS:
            case QP_GAMING:
                return layer_state_is(LAYER_BASE);
        }
        return false;
    }
#endif

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
    #define ENCODER_DEFAULT {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}

    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [LAYER_BASE]        = ENCODER_DEFAULT,
        [LAYER_NAV]         = ENCODER_DEFAULT,
        [LAYER_SYM]         = ENCODER_DEFAULT,
        [LAYER_POINTER]     = ENCODER_DEFAULT,
        [LAYER_INTELIJ]     = ENCODER_DEFAULT,
        [LAYER_INTELIJ2]    = ENCODER_DEFAULT,
        [LAYER_GAMING]      = ENCODER_DEFAULT,
        [LAYER_GNOME]       = ENCODER_DEFAULT,
    };
// clang-format on
#endif // ENCODER_MAP_ENABLE

#ifdef LEADER_ENABLE
void leader_start_user(void) {
    // Do something when the leader key is pressed
}
void leader_end_user(void) {
    if (leader_sequence_four_keys(KC_M, KC_COMM,  KC_DOT, KC_SLSH)) {
        tap_code(KC_SLEP);
    }
}
#endif
