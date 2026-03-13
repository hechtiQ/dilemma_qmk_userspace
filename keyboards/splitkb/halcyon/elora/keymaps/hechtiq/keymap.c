#include QMK_KEYBOARD_H

// ============================================================
// Layers
// ============================================================

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_SETTINGS,
    LAYER_INTELIJ,
    LAYER_INTELIJ2,
    LAYER_GAMING,
    LAYER_GNOME,
};

// ============================================================
// Custom keycodes
// ============================================================

enum custom_keycodes {
    KC_ARR = SAFE_RANGE, // ->
    RGB_THEME,
};

// ============================================================
// Persistent user config (EEPROM)
// ============================================================

typedef union {
    uint32_t raw;
    struct {
        bool rgb_theme_matcha : 1;
        // future settings can go here, up to 32 bits total
    };
} user_config_t;

static user_config_t user_config;

// ============================================================
// Homerow mods
// ============================================================

#define MOD_A    GUI_T(KC_A)
#define MOD_S    ALT_T(KC_S)
#define MOD_D    CTL_T(KC_D)
#define MOD_F    SFT_T(KC_F)

#define MOD_J    SFT_T(KC_J)
#define MOD_K    CTL_T(KC_K)
#define MOD_L    ALT_T(KC_L)
#define MOD_SCLN GUI_T(KC_SCLN)

// ============================================================
// Layer taps
// ============================================================

#define NAV     LT(LAYER_NAV, KC_SPC)
#define SYM     LT(LAYER_SYM, KC_SPC)
#define INTJ    LT(LAYER_INTELIJ, KC_ENT)
#define INTJ2   MO(LAYER_INTELIJ2)
#define GNME    LT(LAYER_GNOME, KC_ENT)
#define SETT    MO(LAYER_SETTINGS)

// ============================================================
// IntelliJ shortcuts
// ============================================================

#define BMRK_O  KC_F11
#define BMRK_T  LSFT(KC_F11)
#define BMRK_P  LCTL(LSFT(KC_F11))
#define BMRK_N  LSA(KC_F11)
#define FIND    LCTL(LSFT(KC_F))
#define OPEN    LCTL(LSFT(KC_N))
#define CMD_P   HYPR(KC_F)
#define FND_USG LSA(KC_7)
#define RFCT_MN HYPR(KC_T)
#define RCNT_FI LCTL(KC_E)
#define GO_DCL  LCTL(KC_B)
#define GO_IMP  LCA(KC_B)
#define GO_BCK  LSA(KC_LEFT)
#define GO_FWD  LSA(KC_RIGHT)
#define BLAME   HYPR(KC_B)
#define REOPN   HYPR(KC_R)
#define QCK_DEF LCTL(LSFT(KC_I))
#define QCK_DOC LCTL(KC_Q)

// ============================================================
// GNOME shortcuts
// ============================================================

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

// ============================================================
// Keymaps
// ============================================================

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY with homerow mods (GUI/ALT/CTL/SFT on A/S/D/F and J/K/L/;)
 * Combos: FJ=CapsWord, QP=Gaming toggle, 0+PScr=Sleep
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  | PScr   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | SETT   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc   | GUI/A| ALT/S| CTL/D| SFT/F|   G  |                              |   H  | SFT/J| CTL/K| ALT/L|GUI/; |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  | TAB  |      |  |      |      |   N  |   M  |  , < |  . > |  / ? | LEAD   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | BrDn | BrUp | Bksp | SPC/ | ENT/ |  | ENT/ |  SPC/| DEL  | Prev | Next |
 *                        |      |      |      | NAV  | INTJ |  | GNME |  SYM |      | Track| Track|
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              | MUTE |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_BASE] = LAYOUT_elora_hlc(
      KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
      SETT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_ESC,  MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,                                         KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN,KC_QUOT,
      KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,  KC_NO,       KC_NO,  KC_NO, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, QK_LEAD,
                                 KC_BRID, KC_BRIU, KC_BSPC, NAV,     INTJ,        GNME,    SYM,     KC_DEL,  KC_MPRV, KC_MNXT,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Sym Layer: Symbols
 * Combos (SYM layer only): > + = → <=    = + ( → =>    = + ` → !=    = + _ → +=
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   *  |   !  |   &  |   ~  |  ->  |                              |   ^  |   `  |   {  |   }  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   #  |   :  |   +  |   @  |   <  |                              |   >  |   =  |   (  |   )  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   |  |   \  |   -  |   %  |      |      |      |  |LLLCK |      |   _  |   [  |   ]  |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  SYM |      |  |  SYM |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_SYM] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_ASTR, KC_EXLM, KC_AMPR, KC_TILD, KC_ARR,                                       KC_CIRC, KC_GRV,  KC_LCBR, KC_RCBR, KC_NO,   KC_NO,
      KC_NO,   KC_HASH, KC_COLN, KC_PLUS, KC_AT,   KC_LT,                                        KC_GT,   KC_EQL,  KC_LPRN, KC_RPRN, KC_NO,   KC_NO,
      KC_NO,   KC_PIPE, KC_BSLS, KC_MINS, KC_PERC, KC_NO,   KC_NO,   KC_NO,       QK_LLCK,KC_NO,   KC_NO,   KC_UNDS, KC_LBRC, KC_RBRC, KC_SLSH, KC_NO,
                                 _______, _______, _______,  _______,  KC_NO,       _______, KC_NO,   KC_NO,   _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * Nav Layer: Navigation, F-keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  F12   |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Home |  Up  |  End |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |                              |      | RSft | RCtl | RAlt | RGUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | PgUp |      | PgDn |      |      |LLLCK |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_NAV] = LAYOUT_elora_hlc(
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                                        KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      KC_NO,   KC_NO,   KC_PGUP, KC_NO,   KC_PGDN, KC_NO,   KC_NO,   QK_LLCK,     KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   KC_NO,   _______,     _______, KC_NO,   _______,   _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * Settings Layer: RGB theme toggle, Boot/EE_CLR, one-shot mods.
 * Access: hold SETT key (top alpha row col 0 on BASE).
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RGBTOG  |      |      |      |      |      |                              |      |      |      |      |      | RGBTOG |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LGUI | LAlt | LCtl | LSft |      |                              |      | RSft | RCtl | RAlt | RGUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |THEME   |      |      |EE_CLR| BOOT |      |      | SETT |  |      |      | BOOT |EE_CLR|      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_SETTINGS] = LAYOUT_elora_hlc(
      RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                        KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      RGB_THEME, KC_NO, KC_NO,   EE_CLR,  QK_BOOT, KC_NO,   KC_NO,   _______,     KC_NO,  KC_NO, KC_NO,   QK_BOOT, EE_CLR,  KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * IntelliJ Layer: IDE navigation and actions
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | GoBk | GoFw | CmdP |RcntF |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |QkDef |QkDoc |GoDcl |GoImp |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |RfctMn|FndUsg| Find | Open |      |      |LLLCK |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | INTJ2|      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAYER_INTELIJ] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   GO_BCK,  GO_FWD,  CMD_P,   RCNT_FI, KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   QCK_DEF, QCK_DOC, GO_DCL,  GO_IMP,  KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   RFCT_MN, FND_USG, FIND,    OPEN,    KC_NO,   KC_NO,   QK_LLCK,     KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, _______,  INTJ2,   _______,     _______, _______, _______, _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * IntelliJ2 Layer: Bookmarks, blame, reopen
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | BmkO | BmkT | Reop | Blme |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | BmkP | BmkN | GoBk | GoFw |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |LLLCK |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAYER_INTELIJ2] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   BMRK_O,  BMRK_T,  REOPN,   BLAME,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   BMRK_P,  BMRK_N,  GO_BCK,  GO_FWD,  KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_LLCK,     KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   _______,  _______,     _______, KC_NO,   _______, _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * Gaming Layer: No homerow mods, standard WASD. Toggle off with right thumb.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Esc    |  1   |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   | PScr   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  T   |  Q   |  W   |  E   |  R   |                              |   Y  |  U   |  I   |  O   |  P   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LSft |  A   |  S   |  D   |  F   |                              |   H  |  J   |  K   |  L   |  ; : |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | LCtl |  Z   |  X   |  C   |  V   | C(F) |      |  |      |      |   N  |  M   |  , < |  . > |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  M   |  I   |  H   | Spc  |      |  |      |      |TG(GM)|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_GAMING] = LAYOUT_elora_hlc(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
      KC_NO,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
      KC_NO,   KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    LCTL(KC_F), KC_NO,   KC_NO,  KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                 KC_M,    KC_I,    KC_H,    KC_SPC,  KC_NO,       KC_NO,   KC_NO,   TG(LAYER_GAMING), _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * GNOME Layer: Desktop and window management
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | WinUp|WinLft|WinRgt|WinDwn|      |                              |      | SS_1 | SS_2 | SS_3 | SS_4 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Super|      | WS_L | WS_R |      |                              |      | S_1  | S_2  | S_3  | S_4  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |LLLCK |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |AT_GRV| A_TAB|AS_TAB|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_GNOME] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   S_UP,    S_LFT,   S_RGT,   S_DWN,   KC_NO,                                        KC_NO,   SS_1,    SS_2,    SS_3,    SS_4,    KC_NO,
      KC_NO,   ACTY,    KC_NO,   WS_L,    WS_R,    KC_NO,                                        KC_NO,   S_1,     S_2,     S_3,     S_4,     KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       QK_LLCK,KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, AT_GRV,  A_TAB,   AS_TAB,      _______, KC_NO,   _______,  _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

};
// clang-format on

// ============================================================
// Tapping term
// ============================================================

// Longer tapping term for GUI on A and ; to avoid accidental Super triggers.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOD_A:
        case MOD_SCLN:
            return TAPPING_TERM + 80;
        default:
            return TAPPING_TERM;
    }
}

// ============================================================
// Key processing
// ============================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_ARR: send_string("->"); return false;
            case NAV:
            case SYM:
                if (record->tap.count > 0 && is_caps_word_on()) {
                    if (record->event.pressed) tap_code16(KC_UNDS);
                    return false;
                }
                break;
            case RGB_THEME:
                user_config.rgb_theme_matcha = !user_config.rgb_theme_matcha;
                eeconfig_update_user(user_config.raw);
                return false;
        }
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            // Shift letters and minus, continue CapsWord
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_SPC:
        case KC_SCLN:
        case MOD_A:
        case MOD_SCLN:
        case NAV:
        case SYM:
            // Allow these without shifting, continue CapsWord
            // (space is intercepted in process_record_user and converted to _)
            return true;
        default:
            // Everything else (including Enter) exits CapsWord
            return false;
    }
}

// ============================================================
// Combos
// ============================================================

#ifdef COMBO_ENABLE
    enum combos {
        ZR_PRS,
        FJ_CAPS,
        QP_GAMING,
        MEDIA_PLAY,
        SYM_LEQ,
        SYM_FAT,
        SYM_NEQ,
        SYM_PAE,
    };
    const uint16_t PROGMEM lck_combo[]         = {KC_0, KC_PSCR, COMBO_END};
    const uint16_t PROGMEM caps_combo[]        = {MOD_F, MOD_J, COMBO_END};
    const uint16_t PROGMEM gaming_combo[]      = {KC_Q, KC_P, COMBO_END};
    const uint16_t PROGMEM media_play_combo[]  = {KC_MPRV, KC_MNXT, COMBO_END};
    const uint16_t PROGMEM sym_leq_combo[]     = {KC_GT,  KC_EQL,  COMBO_END}; // > + = → <=
    const uint16_t PROGMEM sym_fat_combo[]     = {KC_EQL, KC_LPRN, COMBO_END}; // = + ( → =>
    const uint16_t PROGMEM sym_neq_combo[]     = {KC_EQL, KC_GRV,  COMBO_END}; // = + ` → !=
    const uint16_t PROGMEM sym_pae_combo[]     = {KC_EQL, KC_UNDS, COMBO_END}; // = + _ → +=

    combo_t key_combos[] = {
        [ZR_PRS]    = COMBO(lck_combo,        KC_SLEP),
        [FJ_CAPS]   = COMBO(caps_combo,       CW_TOGG),
        [QP_GAMING] = COMBO(gaming_combo,     TG(LAYER_GAMING)),
        [MEDIA_PLAY]= COMBO(media_play_combo, KC_MPLY),
        [SYM_LEQ]   = COMBO_ACTION(sym_leq_combo),
        [SYM_FAT]   = COMBO_ACTION(sym_fat_combo),
        [SYM_NEQ]   = COMBO_ACTION(sym_neq_combo),
        [SYM_PAE]   = COMBO_ACTION(sym_pae_combo),
    };

    bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
        switch (combo_index) {
            case FJ_CAPS:
            case ZR_PRS:
            case QP_GAMING:
                return layer_state_is(LAYER_BASE);
            case SYM_LEQ:
            case SYM_FAT:
            case SYM_NEQ:
            case SYM_PAE:
                return layer_state_is(LAYER_SYM);
            case MEDIA_PLAY:
                return true;
        }
        return false;
    }

    void process_combo_event(uint16_t combo_index, bool pressed) {
        if (!pressed) return;
        switch (combo_index) {
            case SYM_LEQ: send_string("<="); break;
            case SYM_FAT: send_string("=>"); break;
            case SYM_NEQ: send_string("!="); break;
            case SYM_PAE: send_string("+="); break;
        }
    }
#endif // COMBO_ENABLE

// ============================================================
// Leader
// ============================================================

#ifdef LEADER_ENABLE
void leader_start_user(void) {}

void leader_end_user(void) {
    if (leader_sequence_four_keys(KC_M, KC_COMM, KC_DOT, KC_SLSH)) {
        tap_code(KC_SLEP);
    }
}
#endif // LEADER_ENABLE

// ============================================================
// RGB
// ============================================================

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    static const uint8_t colors_lavender[][3] = {
        [LAYER_BASE]     = { 80,  60, 180}, // soft lavender
        [LAYER_SYM]      = {200,  40, 200}, // vivid magenta-purple
        [LAYER_NAV]      = { 20,  80, 220}, // strong blue
        [LAYER_SETTINGS] = {200,  20,  20}, // danger red
        [LAYER_INTELIJ]  = { 20, 180, 180}, // teal
        [LAYER_INTELIJ2] = { 20, 120, 120}, // darker teal
        [LAYER_GAMING]   = {220,  80,  20}, // orange
        [LAYER_GNOME]    = { 20, 200,  80}, // spring green
    };

    static const uint8_t colors_matcha[][3] = {
        [LAYER_BASE]     = { 60, 140,  60}, // soft moss
        [LAYER_SYM]      = {160, 200,  20}, // yellow-green
        [LAYER_NAV]      = { 20, 160, 100}, // jade
        [LAYER_SETTINGS] = {200,  20,  20}, // danger red
        [LAYER_INTELIJ]  = {100, 200,  60}, // lime
        [LAYER_INTELIJ2] = { 60, 140,  40}, // dark lime
        [LAYER_GAMING]   = {200, 160,  20}, // golden
        [LAYER_GNOME]    = { 20, 180, 140}, // aquamarine
    };

    const uint8_t (*colors)[3] = user_config.rgb_theme_matcha ? colors_matcha : colors_lavender;

    // Handle underglow — iterate full LED count to ensure no LEDs are missed
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            rgb_matrix_set_color(i, colors[layer][0], colors[layer][1], colors[layer][2]);
        }
    }

    // BASE: light all per-key LEDs uniformly
    if (layer == LAYER_BASE) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER)) {
                rgb_matrix_set_color(i, colors[LAYER_BASE][0], colors[LAYER_BASE][1], colors[LAYER_BASE][2]);
            }
        }
        return false;
    }

    static const uint8_t wasd_lavender[3] = { 20, 220, 220}; // cyan on orange
    static const uint8_t wasd_matcha[3]   = { 20,  80, 220}; // blue on golden
    const uint8_t *wasd_color = user_config.rgb_theme_matcha ? wasd_matcha : wasd_lavender;

    // All other layers: per-key, only light active keys
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index < led_min || index >= led_max || index == NO_LED) continue;
            if (!(g_led_config.flags[index] & (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER))) continue;

            uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (keycode == KC_NO || keycode == QK_LEAD) {
                rgb_matrix_set_color(index, 0, 0, 0);
            } else if (layer == LAYER_GAMING && (keycode == KC_W || keycode == KC_A || keycode == KC_S || keycode == KC_D)) {
                rgb_matrix_set_color(index, wasd_color[0], wasd_color[1], wasd_color[2]);
            } else {
                rgb_matrix_set_color(index, colors[layer][0], colors[layer][1], colors[layer][2]);
            }
        }
    }

    return false;
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_BLACK);
}
#endif // RGB_MATRIX_ENABLE

// ============================================================
// Encoders
// ============================================================

#ifdef ENCODER_MAP_ENABLE
// clang-format off
// The Halcyon Elora rev2 has 4 encoder slots (NUM_ENCODERS=4).
// Right module encoder rotation is on index 2+3, left would be 0+1.
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]     = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_SYM]      = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NAV]      = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_SETTINGS]  = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_INTELIJ]  = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_INTELIJ2] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_GAMING]   = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_GNOME]    = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
