#include "shared-bindings/board/__init__.h"

// This mapping only includes functional names because pins broken
// out on connectors are labeled with their MCU name available from
// microcontroller.pin.
STATIC const mp_rom_map_elem_t board_global_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_board_id), MP_ROM_PTR(&board_module_id_obj) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_PA02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_PA05) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A2), MP_ROM_PTR(&pin_PA06) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A3), MP_ROM_PTR(&pin_PB00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A4), MP_ROM_PTR(&pin_PB08) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A5), MP_ROM_PTR(&pin_PB09) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_PA23) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_PA23) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D1), MP_ROM_PTR(&pin_PA22) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_PA22) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D2), MP_ROM_PTR(&pin_PB17) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D3), MP_ROM_PTR(&pin_PB16) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D4), MP_ROM_PTR(&pin_PB13) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D5), MP_ROM_PTR(&pin_PB14) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D6), MP_ROM_PTR(&pin_PB15) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D7), MP_ROM_PTR(&pin_PB12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D8), MP_ROM_PTR(&pin_PA21) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D9), MP_ROM_PTR(&pin_PA20) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D10), MP_ROM_PTR(&pin_PA18) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D11), MP_ROM_PTR(&pin_PA19) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D12), MP_ROM_PTR(&pin_PA17) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D13),MP_ROM_PTR(&pin_PA16) },

    // ESP control
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_CS), MP_ROM_PTR(&pin_PA15) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_GPIO0), MP_ROM_PTR(&pin_PB01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_BUSY), MP_ROM_PTR(&pin_PB04) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_RESET), MP_ROM_PTR(&pin_PB05) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_RTS), MP_ROM_PTR(&pin_PB23) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_TX), MP_ROM_PTR(&pin_PA04) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ESP_RX), MP_ROM_PTR(&pin_PA07) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_SDA),MP_ROM_PTR(&pin_PB02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCL),MP_ROM_PTR(&pin_PB03) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_NEOPIXEL),MP_ROM_PTR(&pin_PB22) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_SCK),MP_ROM_PTR(&pin_PA13) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MOSI),MP_ROM_PTR(&pin_PA12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MISO),MP_ROM_PTR(&pin_PA14) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_LED_RX),MP_ROM_PTR(&pin_PB06) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_LED_TX),MP_ROM_PTR(&pin_PB07) },
    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&board_uart_obj) },
};
MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
