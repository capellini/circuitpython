#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_global_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_board_id), MP_ROM_PTR(&board_module_id_obj) },

    { MP_ROM_QSTR(MP_QSTR_NEOPIXEL), MP_ROM_PTR(&pin_PA04) },

    { MP_ROM_QSTR(MP_QSTR_POTENTIOMETER), MP_ROM_PTR(&pin_PA02) },
    { MP_ROM_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_PA02) },

    { MP_ROM_QSTR(MP_QSTR_TOUCH), MP_ROM_PTR(&pin_PA07) },
};
MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
