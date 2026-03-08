#include QMK_KEYBOARD_H

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

// Homerow mods
#define MOD_S GUI_T(KC_S)
#define MOD_D CTL_T(KC_D)
#define MOD_F SFT_T(KC_F)

#define MOD_J SFT_T(KC_J)
#define MOD_K CTL_T(KC_K)
#define MOD_L GUI_T(KC_L)

// SYM layer macro keycodes
enum custom_keycodes {
    KC_ARR = SAFE_RANGE, // ->
    RGB_THEME,
};

// Persistent user config stored in EEPROM
typedef union {
    uint32_t raw;
    struct {
        bool rgb_theme_matcha : 1;
        // future settings can go here, up to 32 bits total
    };
} user_config_t;

static user_config_t user_config;

// Intellij shortcuts
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

// Layer taps
#define NAV     LT(LAYER_NAV, KC_SPC)
#define SYM     LT(LAYER_SYM, KC_SPC)
#define INTJ    LT(LAYER_INTELIJ, KC_TAB)
#define INTJ2   MO(LAYER_INTELIJ2)
#define GNME    LT(LAYER_GNOME, KC_ENT)
#define SETT    OSL(LAYER_SETTINGS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY with homerow mods (GUI/CTL/SFT on S/D/F and J/K/L)
 * Combos: QW=Esc, FJ=CapsWord, QP=Gaming toggle, 0+PScr=Sleep
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  | PScr   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  | GUI/S| CTL/D| SFT/F|   G  |                              |   H  | SFT/J| CTL/K| GUI/L|  ; : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      | SETT |  |      |      |   N  |   M  |  , < |  . > |  / ? | LEAD   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | BrDn| BrUp| Bksp | TAB/ | SPC/ |  |  SPC/| ENT/ | DEL  | Prev | Next |
 *                        |      |      |      | INTJ | NAV  |  |  SYM | GNME |      | Track| Track|
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              | MUTE |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_BASE] = LAYOUT_elora_hlc(
      KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
      KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_NO,   KC_A,    MOD_S,   MOD_D,   MOD_F,   KC_G,                                         KC_H,    MOD_J,   MOD_K,   MOD_L,   KC_SCLN, KC_QUOT,
      KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   SETT,        KC_NO,  KC_NO, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, QK_LEAD,
                                 KC_BRID, KC_BRIU, KC_BSPC, INTJ,    NAV,         SYM,    GNME,    KC_DEL,  KC_MPRV, KC_MNXT,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Sym Layer: Symbols
 * Combos (SYM layer only): > + = → <=    = + ( → =>    = + ` → !=    = + _ → +=
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   \  |   *  |   &  |   ~  |  ->  |                              |   ^  |   `  |   {  |   }  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   #  |   :  |   +  |   @  |   <  |                              |   >  |   =  |   (  |   )  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   |  |   \  |   !  |   %  |      |      |      |  |      |      |      |   _  |   [  |   ]  |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |LLLCK |      | SYM  |  |  SYM |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_SYM] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_BSLS, KC_ASTR, KC_AMPR, KC_TILD, KC_ARR,                                       KC_CIRC, KC_GRV,  KC_LCBR, KC_RCBR, KC_NO,   KC_NO,
      KC_NO,   KC_HASH, KC_COLN, KC_PLUS, KC_AT,   KC_LT,                                        KC_GT,   KC_EQL,  KC_LPRN, KC_RPRN, KC_NO,   KC_NO,
      KC_NO,   KC_PIPE, KC_BSLS, KC_EXLM, KC_PERC, KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_UNDS, KC_LBRC, KC_RBRC, KC_SLSH, KC_NO,
                                 _______, _______, QK_LLCK, KC_NO,   _______,     _______, KC_NO,   KC_NO,   _______, _______,
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
 * |        |      | PgUp |      | PgDn |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |LLLCK |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_NAV] = LAYOUT_elora_hlc(
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                                        KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      KC_NO,   KC_NO,   KC_PGUP, KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   KC_NO,   _______,     _______, KC_NO,   QK_LLCK, _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * Settings Layer: RGB theme toggle, Boot/EE_CLR, one-shot mods.
 * Access: hold SETT key (bottom row inner right on BASE).
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LGUI | LAlt | LCtl | LSft |      |                              |      | RSft | RCtl | RAlt | RGUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |EE_CLR| BOOT |      |      | SETT |  |      |      | BOOT |EE_CLR|      |THEME |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_SETTINGS] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                        KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      KC_NO,   KC_NO,   KC_NO,   EE_CLR,  QK_BOOT, KC_NO,   KC_NO,   _______,     KC_NO,  KC_NO, KC_NO,   QK_BOOT, EE_CLR,  KC_NO,   RGB_THEME, KC_NO,
                                 _______, _______, KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * IntelliJ Layer: IDE navigation and actions
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | QkDoc| Open |GoImp | GoBk | GoFw |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | QkDef| BmkT |GoDcl | CmdP |RcntF |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |RfctMn| Find |FndUsg| BmkP | BmkN |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | INTJ2|      |      |  |      |      |LLLCK |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_INTELIJ] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   QCK_DOC, OPEN,    GO_IMP,  GO_BCK,  GO_FWD,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   QCK_DEF, BMRK_T,  GO_DCL,  CMD_P,   RCNT_FI,                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   RFCT_MN, FIND,    FND_USG, BMRK_P,  BMRK_N,  KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   _______,  INTJ2,       _______, KC_NO,   QK_LLCK, _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

/*
 * IntelliJ2 Layer: Debug, blame, bookmarks
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Reop |  F2  | GoBk | GoFw |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | BmkO |S(F2) |  F7  |S(F7) |      |                              |      |      |      |      |      |        |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Blme |C(F4) | BmkP | BmkN |      |      |      |  |      |      |      |      |      |      |      |        |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |LLLCK |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_INTELIJ2] = LAYOUT_elora_hlc(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   REOPN,   KC_F2,   GO_BCK,  GO_FWD,  KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   BMRK_O,  LSFT(KC_F2), KC_F7, LSFT(KC_F7), KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   BLAME,   LCTL(KC_F4), BMRK_P, BMRK_N, KC_NO, KC_NO,  KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_NO,   _______,  _______,     _______, KC_NO,   QK_LLCK, _______, _______,
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
 * |        | LCtl |  Z   |  X   |  C   |  V   |      | C(F) |  |      |      |   N  |  M   |  , < |  . > |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  M   |  I   |  H   |      | Spc  |  |      |      |TG(GM)|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [LAYER_GAMING] = LAYOUT_elora_hlc(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
      KC_NO,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
      KC_NO,   KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,   LCTL(KC_F),  KC_NO,  KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                 KC_M,    KC_I,    KC_H,    KC_NO,   KC_SPC,      KC_NO,   KC_NO,   TG(LAYER_GAMING), _______, _______,
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
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
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
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, AT_GRV,  A_TAB,   AS_TAB,      _______, KC_NO,   KC_NO,   _______, _______,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_elora_hlc(
//       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//                                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,   KC_NO,
//       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
//     ),
};
// clang-format on

// Theme state: false = lavender, true = matcha. Persisted via eeconfig_user.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_ARR: send_string("->"); return false;
            case KC_SPC:
                if (is_caps_word_on()) {
                    tap_code16(KC_UNDS);
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
            // Allow these without shifting, continue CapsWord
            // (space is intercepted in process_record_user and converted to _)
            return true;
        default:
            // Everything else (including Enter) exits CapsWord
            return false;
    }
}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    static const uint8_t colors_lavender[][3] = {
        [LAYER_BASE]     = { 80,  60, 180}, // soft lavender
        [LAYER_SYM]      = {112,  80, 204}, // deeper purple
        [LAYER_NAV]      = { 40,  80, 200}, // periwinkle blue
        [LAYER_SETTINGS] = {200,  20,  20}, // danger red
        [LAYER_INTELIJ]  = {100,  60, 200}, // medium lavender
        [LAYER_INTELIJ2] = { 80,  40, 160}, // darker lavender
        [LAYER_GAMING]   = {160,  20, 120}, // deep magenta
        [LAYER_GNOME]    = { 40, 160, 160}, // cyan-lavender
    };

    static const uint8_t colors_matcha[][3] = {
        [LAYER_BASE]     = { 60, 140,  60}, // soft moss
        [LAYER_SYM]      = { 40, 160,  80}, // richer green
        [LAYER_NAV]      = { 30, 130, 100}, // fern
        [LAYER_SETTINGS] = {200,  20,  20}, // danger red
        [LAYER_INTELIJ]  = { 50, 145,  70}, // sage
        [LAYER_INTELIJ2] = { 30, 110,  50}, // dark moss
        [LAYER_GAMING]   = {120, 200,  20}, // poison frog
        [LAYER_GNOME]    = { 80, 180, 120}, // frog belly
    };

    const uint8_t (*colors)[3] = user_config.rgb_theme_matcha ? colors_matcha : colors_lavender;

    // Handle underglow for all layers
    for (uint8_t i = led_min; i < led_max; i++) {
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

    // All other layers: per-key, only light active keys
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index < led_min || index >= led_max || index == NO_LED) continue;
            if (!(g_led_config.flags[index] & (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER))) continue;

            uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (keycode == KC_NO || keycode == QK_LEAD) {
                rgb_matrix_set_color(index, 0, 0, 0);
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
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
}
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
// Single encoder on the right Halcyon module (index 0).
// CCW = vol down / prev track, CW = vol up / next track.
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_SYM]      = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NAV]      = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_SETTINGS]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_INTELIJ]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_INTELIJ2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_GAMING]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_GNOME]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

#ifdef COMBO_ENABLE
    enum combos {
        QW_ESC,
        ZR_PRS,
        FJ_CAPS,
        QP_GAMING,
        MEDIA_PLAY,
        SYM_LEQ,
        SYM_FAT,
        SYM_NEQ,
        SYM_PAE,
    };
    const uint16_t PROGMEM qw_combo[]          = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM lck_combo[]         = {KC_0, KC_PSCR, COMBO_END};
    const uint16_t PROGMEM caps_combo[]        = {MOD_F, MOD_J, COMBO_END};
    const uint16_t PROGMEM gaming_combo[]      = {KC_Q, KC_P, COMBO_END};
    const uint16_t PROGMEM media_play_combo[]  = {KC_MPRV, KC_MNXT, COMBO_END};
    const uint16_t PROGMEM sym_leq_combo[]     = {KC_GT,  KC_EQL,  COMBO_END}; // > + = → <=
    const uint16_t PROGMEM sym_fat_combo[]     = {KC_EQL, KC_LPRN, COMBO_END}; // = + ( → =>
    const uint16_t PROGMEM sym_neq_combo[]     = {KC_EQL, KC_GRV,  COMBO_END}; // = + ` → !=
    const uint16_t PROGMEM sym_pae_combo[]     = {KC_EQL, KC_UNDS, COMBO_END}; // = + _ → +=

    combo_t key_combos[] = {
        [QW_ESC]    = COMBO(qw_combo,        KC_ESC),
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
            case QW_ESC:
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

#ifdef LEADER_ENABLE
void leader_start_user(void) {}

void leader_end_user(void) {
    if (leader_sequence_four_keys(KC_M, KC_COMM, KC_DOT, KC_SLSH)) {
        tap_code(KC_SLEP);
    }
}
#endif // LEADER_ENABLE