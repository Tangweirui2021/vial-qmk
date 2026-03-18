VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes

# Disable optional Vial features to fit within the 2048-byte wear-leveling EEPROM.
# KEYCHRON_RGB_ENABLE adds per-key RGB storage (~434 bytes), leaving insufficient
# space for these additional features on this board.
# QMK_SETTINGS = no
# TAP_DANCE_ENABLE = no
# COMBO_ENABLE = no
# KEY_OVERRIDE_ENABLE = no
CAPS_WORD_ENABLE = no
LAYER_LOCK_ENABLE = no

# My
# Save space
LTO_ENABLE = yes
AVR_USE_MINIMAL_PRINTF = yes
MOUSEKEY_ENABLE = no # Disable mouse keys
CONSOLE_ENABLE = no

MAGIC_ENABLE = no	# Disable magic keycodes
COMMAND_ENABLE = no	# Disable command keycodes (similar to magic keycodes)
SPACE_CADET_ENABLE = no # Disable space cadet keycodes
MUSIC_ENABLE = no # Disable music keycodes
REPEAT_KEY_ENABLE = no # Disable repeat keycodes
ENCODER_MAP_ENABLE = no # Disable encoder map