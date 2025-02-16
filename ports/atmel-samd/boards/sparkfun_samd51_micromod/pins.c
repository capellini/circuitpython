/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 * Copyright (c) 2021 Chris Wilson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_global_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_board_id), MP_ROM_PTR(&board_module_id_obj) },
    // The SparkFun MicroMod spec uses a zero-based peripheral numbering scheme.
    // The 0th peripheral is the default and the "0" is omitted from the
    // peripheral name (e.g. "I2C" instead of "I2C0").
    //
    // For more details, see https://www.sparkfun.com/micromod#tech-specs

    // MicroMod built-in status LED pin
    // Requirement from the "Designing with MicroMod" SparkFun article:
    // "... every Processor Board shall include one status LED connected to a
    // pin that is not connected to the board edge."
    { MP_ROM_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_PA23) },         // MicroMod LED (PA23)

    // MicroMod USB bus input voltage (+5V) pin
    // { MP_ROM_QSTR(MP_QSTR_USB_VIN), MP_ROM_PTR() },           // MicroMod USB_VIN (not connected)

    // MicroMod +3.3V enable pin
    { MP_ROM_QSTR(MP_QSTR_P3V3_EN), MP_ROM_PTR(&pin_PA19) },     // MicroMod 3.3V_EN (PA19)

    // MicroMod battery voltage sense pin
    { MP_ROM_QSTR(MP_QSTR_BATT_VIN3), MP_ROM_PTR(&pin_PB03) },   // MicroMod BATT_VIN/3 (PB03)

    // MicroMod reset pin
    // { MP_ROM_QSTR(MP_QSTR_RESET), MP_ROM_PTR() },             // MicroMod RESET# (SAMD51 has a dedicated HW RESETN pin)

    // MicroMod boot pin
    // { MP_ROM_QSTR(MP_QSTR_BOOT), MP_ROM_PTR() },              // MicroMod BOOT (not connected)

    // MicroMod USB device pins
    // USB device is always used internally by CircuitPython, so skip creating
    // the pin objects for it. See explicit ignores in mpconfigboard.h.
    // { MP_ROM_QSTR(MP_QSTR_USB_DM), MP_ROM_PTR(&pin_PA24) },   // MicroMod USB_D- (PA24)
    // { MP_ROM_QSTR(MP_QSTR_USB_DP), MP_ROM_PTR(&pin_PA25) },   // MicroMod USB_D+ (PA25)

    // MicroMod USB host pins
    // { MP_ROM_QSTR(MP_QSTR_USBHOST_DM), MP_ROM_PTR() },        // MicroMod USBHOST_D- (not connected)
    // { MP_ROM_QSTR(MP_QSTR_USBHOST_DP), MP_ROM_PTR() },        // MicroMod USBHOST_D+ (not connected)

    // MicroMod CAN pins
    { MP_ROM_QSTR(MP_QSTR_CAN_RX), MP_ROM_PTR(&pin_PB15) },       // MicroMod CAN_RX (PB15)
    { MP_ROM_QSTR(MP_QSTR_CAN_TX), MP_ROM_PTR(&pin_PB14) },       // MicroMod CAN_TX (PB14)

    // Note: MicroMod UART (UART0) is not present in the edge connector pinout
    // because the primary debug serial port is exposed as a virtual serial port
    // over USB.

    // MicroMod UART1 pins
    { MP_ROM_QSTR(MP_QSTR_UART_TX1), MP_ROM_PTR(&pin_PB31) },     // MicroMod UART_TX1 | CircuitPython TX (PB31)
    { MP_ROM_QSTR(MP_QSTR_UART_RX1), MP_ROM_PTR(&pin_PB30) },     // MicroMod UART_RX1 | CircuitPython RX (PB30)
    // { MP_ROM_QSTR(MP_QSTR_UART_RTS1), MP_ROM_PTR() },          // MicroMod RTS1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_UART_CTS1), MP_ROM_PTR() },          // MicroMod CTS1 (not connected)

    // CircuitPython default UART pins
    { MP_ROM_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_PB31) },           // CircuitPython TX | MicroMod UART_TX1 (PB31)
    { MP_ROM_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_PB30) },           // CircuitPython RX | MicroMod UART_RX1 (PB30)

    // MicroMod UART2 pins
    { MP_ROM_QSTR(MP_QSTR_UART_TX2), MP_ROM_PTR(&pin_PA12) },     // MicroMod UART_TX2 (PA12)
    { MP_ROM_QSTR(MP_QSTR_UART_RX2), MP_ROM_PTR(&pin_PA13) },     // MicroMod UART_RX2 (PA13)

    // MicroMod I2C pins
    { MP_ROM_QSTR(MP_QSTR_I2C_SDA), MP_ROM_PTR(&pin_PA17) },      // MicroMod I2C_SDA | CircuitPython SDA (PA17)
    { MP_ROM_QSTR(MP_QSTR_I2C_SCL), MP_ROM_PTR(&pin_PA16) },      // MicroMod I2C_SCL | CircuitPython SCL (PA16)

    // CircuitPython default I2C pins
    { MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_PA17) },          // CircuitPython SDA | MicroMod I2C_SDA (PA17)
    { MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_PA16) },          // CircuitPython SCL | MicroMod I2C_SCL (PA16)

    // MicroMod I2C interrupt pin
    { MP_ROM_QSTR(MP_QSTR_I2C_INT), MP_ROM_PTR(&pin_PA18) },      // MicroMod I2C_INT (PA18)

    // MicroMod I2C1 pins
    { MP_ROM_QSTR(MP_QSTR_I2C_SDA1), MP_ROM_PTR(&pin_PA13) },     // MicroMod I2C_SDA1 (PA13)
    { MP_ROM_QSTR(MP_QSTR_I2C_SCL1), MP_ROM_PTR(&pin_PA12) },     // MicroMod I2C_SCL1 (PA12)

    // MicroMod SPI pins
    { MP_ROM_QSTR(MP_QSTR_SPI_CIPO), MP_ROM_PTR(&pin_PA06) },     // MicroMod SPI_CIPO | CircuitPython CIPO (PA06)
    { MP_ROM_QSTR(MP_QSTR_SPI_MISO), MP_ROM_PTR(&pin_PA06) },     // MicroMod SPI_MISO | CircuitPython MISO (PA06)
    { MP_ROM_QSTR(MP_QSTR_SPI_COPI), MP_ROM_PTR(&pin_PA04) },     // MicroMod SPI_COPI | CircuitPython COPI | LED_DAT (PA04)
    { MP_ROM_QSTR(MP_QSTR_SPI_MOSI), MP_ROM_PTR(&pin_PA04) },     // MicroMod SPI_MOSI | CircuitPython MOSI (PA04)
    { MP_ROM_QSTR(MP_QSTR_SPI_SCK), MP_ROM_PTR(&pin_PA05) },      // MicroMod SPI_SCK | CircuitPython SCK | LED_CLK (PA05)
    { MP_ROM_QSTR(MP_QSTR_SPI_CS), MP_ROM_PTR(&pin_PA07) },       // MicroMod SPI_CS | CircuitPython CS (PA07)

    // CircuitPython default SPI pins
    { MP_ROM_QSTR(MP_QSTR_CIPO), MP_ROM_PTR(&pin_PA06) },         // CircuitPython CIPO | MicroMod SPI_CIPO (PA06)
    { MP_ROM_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_PA06) },         // CircuitPython MISO | MicroMod SPI_MISO (PA06)
    { MP_ROM_QSTR(MP_QSTR_COPI), MP_ROM_PTR(&pin_PA04) },         // CircuitPython COPI | MicroMod SPI_COPI | LED_DAT (PA04)
    { MP_ROM_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_PA04) },         // CircuitPython MOSI | MicroMod SPI_MOSI (PA04)
    { MP_ROM_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_PA05) },          // CircuitPython SCK | MicroMod SPI_SCK | LED_CLK (PA05)
    { MP_ROM_QSTR(MP_QSTR_CS), MP_ROM_PTR(&pin_PA07) },           // CircuitPython CS | MicroMod SPI_CS (PA07)

    // MicroMod 2-wire serial LED pins
    { MP_ROM_QSTR(MP_QSTR_LED_DAT), MP_ROM_PTR(&pin_PA04) },      // MicroMod LED_DAT | SPI_COPI (PA04)
    { MP_ROM_QSTR(MP_QSTR_LED_CLK), MP_ROM_PTR(&pin_PA05) },      // MicroMod LED_CLK | SPI_SCK (PA05)

    // MicroMod SDIO pins
    // { MP_ROM_QSTR(MP_QSTR_SDIO_CLK), MP_ROM_PTR() },           // MicroMod SDIO_SCK | SPI_SCK1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SDIO_CMD), MP_ROM_PTR() },           // MicroMod SDIO_CMD | SPI_COPI1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SDIO_DATA0), MP_ROM_PTR() },         // MicroMod SDIO_DATA0 | SPI_CIPO1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SDIO_DATA1), MP_ROM_PTR() },         // MicroMod SDIO_DATA1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SDIO_DATA2), MP_ROM_PTR() },         // MicroMod SDIO_DATA2 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SDIO_DATA3), MP_ROM_PTR() },         // MicroMod SDIO_DATA3 | SPI_CS1 (not connected)

    // MicroMod SPI1 pins
    // { MP_ROM_QSTR(MP_QSTR_SPI_CIPO1), MP_ROM_PTR() },          // MicroMod SPI_CIPO1 | SDIO_DATA0 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SPI_MISO1), MP_ROM_PTR() },          // MicroMod SPI_MISO1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SPI_COPI1), MP_ROM_PTR() },          // MicroMod SPI_COPI1 | SDIO_CMD (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SPI_MOSI1), MP_ROM_PTR() },          // MicroMod SPI_MOSI1 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SPI_SCK1), MP_ROM_PTR() },           // MicroMod SPI_SCK1 | SDIO_SCK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_SPI_CS1), MP_ROM_PTR() },            // MicroMod SPI_CS1 | SDIO_DATA3 (not connected)

    // MicroMod audio pins
    { MP_ROM_QSTR(MP_QSTR_AUD_MCLK), MP_ROM_PTR(&pin_PB17) },     // MicroMod AUD_MCLK (PB17)
    { MP_ROM_QSTR(MP_QSTR_AUD_OUT), MP_ROM_PTR(&pin_PA21) },      // MicroMod AUD_OUT | I2S_OUT | PCM_OUT | CAM_MCLK (PA21)
    { MP_ROM_QSTR(MP_QSTR_AUD_IN), MP_ROM_PTR(&pin_PA22) },       // MicroMod AUD_IN | I2S_IN | PCM_IN | CAM_PCLK (PA22)
    { MP_ROM_QSTR(MP_QSTR_AUD_LRCLK), MP_ROM_PTR(&pin_PA20) },    // MicroMod AUD_LRCLK | I2S_WS | PCM_SYNC | PDM_DATA (PA20)
    { MP_ROM_QSTR(MP_QSTR_AUD_BCLK), MP_ROM_PTR(&pin_PB16) },     // MicroMod AUD_BCLK | I2S_SCK | PCM_CLK | PDM_CLK (PB16)

    // MicroMod I2S pins
    { MP_ROM_QSTR(MP_QSTR_I2S_OUT), MP_ROM_PTR(&pin_PA21) },      // MicroMod I2S_OUT | AUD_OUT | PCM_OUT | CAM_MCLK (PA21)
    { MP_ROM_QSTR(MP_QSTR_I2S_IN), MP_ROM_PTR(&pin_PA22) },       // MicroMod I2S_IN | AUD_IN | PCM_IN | CAM_PCLK (PA22)
    { MP_ROM_QSTR(MP_QSTR_I2S_WS), MP_ROM_PTR(&pin_PA20) },       // MicroMod I2S_WS | AUD_LRCLK | PCM_SYNC | PDM_DATA (PA20)
    { MP_ROM_QSTR(MP_QSTR_I2S_SCK), MP_ROM_PTR(&pin_PB16) },      // MicroMod I2S_SCK | AUD_BCLK | PCM_CLK | PDM_CLK (PB16)

    // MicroMod PCM pins
    { MP_ROM_QSTR(MP_QSTR_PCM_OUT), MP_ROM_PTR(&pin_PA21) },      // MicroMod PCM_OUT | AUD_OUT | I2S_OUT | CAM_MCLK (PA21)
    { MP_ROM_QSTR(MP_QSTR_PCM_IN), MP_ROM_PTR(&pin_PA22) },       // MicroMod PCM_IN | AUD_IN | I2S_IN | CAM_PCLK (PA22)
    { MP_ROM_QSTR(MP_QSTR_PCM_SYNC), MP_ROM_PTR(&pin_PA20) },     // MicroMod PCM_SYNC | AUD_LRCLK | I2S_WS | PDM_DATA (PA20)
    { MP_ROM_QSTR(MP_QSTR_PCM_CLK), MP_ROM_PTR(&pin_PB16) },      // MicroMod PCM_CLK | AUD_BCLK | I2S_SCK | PDM_CLK (PB16)

    // MicroMod PDM pins
    { MP_ROM_QSTR(MP_QSTR_PDM_DATA), MP_ROM_PTR(&pin_PA20) },     // MicroMod PDM_DATA | AUD_LRCLK | I2S_WS | PCM_SYNC (PA20)
    { MP_ROM_QSTR(MP_QSTR_PDM_CLK), MP_ROM_PTR(&pin_PB16) },      // MicroMod PDM_CLK | AUD_BCLK | I2S_SCK | PCM_CLK (PB16)

    // MicroMod SWD pins
    { MP_ROM_QSTR(MP_QSTR_SWDIO), MP_ROM_PTR(&pin_PA31) },        // MicroMod SWDIO (PA31)
    { MP_ROM_QSTR(MP_QSTR_SWCLK), MP_ROM_PTR(&pin_PA30) },        // MicroMod SWDCK (PA30)
    // { MP_ROM_QSTR(MP_QSTR_SWO), MP_ROM_PTR() },                // MicroMod SWO | G11 (not connected)

    // MicroMod ADC pins
    { MP_ROM_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_PA02) },           // MicroMod A0 (PA02)
    { MP_ROM_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_PB00) },           // MicroMod A1 (PB00)

    // MicroMod PWM pins
    { MP_ROM_QSTR(MP_QSTR_PWM0), MP_ROM_PTR(&pin_PB01) },         // MicroMod PWM0 (PB01)
    { MP_ROM_QSTR(MP_QSTR_PWM1), MP_ROM_PTR(&pin_PB02) },         // MicroMod PWM1 (PB02)

    // MicroMod digital pins
    { MP_ROM_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_PB04) },           // MicroMod D0 (PB04)
    { MP_ROM_QSTR(MP_QSTR_D1), MP_ROM_PTR(&pin_PB05) },           // MicroMod D1 | CAM_TRIG (PB05)

    // MicroMod general purpose pins
    { MP_ROM_QSTR(MP_QSTR_G0), MP_ROM_PTR(&pin_PB06) },           // MicroMod G0 | BUS0 (PB06)
    { MP_ROM_QSTR(MP_QSTR_G1), MP_ROM_PTR(&pin_PB07) },           // MicroMod G1 | BUS1 (PB07)
    { MP_ROM_QSTR(MP_QSTR_G2), MP_ROM_PTR(&pin_PB08) },           // MicroMod G2 | BUS2 (PB08)
    { MP_ROM_QSTR(MP_QSTR_G3), MP_ROM_PTR(&pin_PB09) },           // MicroMod G3 | BUS3 (PB09)
    { MP_ROM_QSTR(MP_QSTR_G4), MP_ROM_PTR(&pin_PB10) },           // MicroMod G4 | BUS4 (PB10)
    { MP_ROM_QSTR(MP_QSTR_G5), MP_ROM_PTR(&pin_PB11) },           // MicroMod G5 | BUS5 (PB11)
    { MP_ROM_QSTR(MP_QSTR_G6), MP_ROM_PTR(&pin_PB12) },           // MicroMod G6 | BUS6 (PB12)
    { MP_ROM_QSTR(MP_QSTR_G7), MP_ROM_PTR(&pin_PB13) },           // MicroMod G7 | BUS7 (PB13)
    { MP_ROM_QSTR(MP_QSTR_G8), MP_ROM_PTR(&pin_PA14) },           // MicroMod G8 (PA14)
    { MP_ROM_QSTR(MP_QSTR_G9), MP_ROM_PTR(&pin_PA15) },           // MicroMod G9 | ADC_D- | CAM_HSYNC (PA15)
    // { MP_ROM_QSTR(MP_QSTR_G10), MP_ROM_PTR() },                // MicroMod G10 | ADC_D+ | CAM_VSYNC (not connected)
    { MP_ROM_QSTR(MP_QSTR_G11), MP_ROM_PTR(&pin_PA27) },          // MicroMod G11 | SWO (PA27)

    // MicroMod 8-bit bus pins
    { MP_ROM_QSTR(MP_QSTR_BUS0), MP_ROM_PTR(&pin_PB06) },         // MicroMod BUS0 | G0 (PB06)
    { MP_ROM_QSTR(MP_QSTR_BUS1), MP_ROM_PTR(&pin_PB07) },         // MicroMod BUS1 | G1 (PB07)
    { MP_ROM_QSTR(MP_QSTR_BUS2), MP_ROM_PTR(&pin_PB08) },         // MicroMod BUS2 | G2 (PB08)
    { MP_ROM_QSTR(MP_QSTR_BUS3), MP_ROM_PTR(&pin_PB09) },         // MicroMod BUS3 | G3 (PB09)
    { MP_ROM_QSTR(MP_QSTR_BUS4), MP_ROM_PTR(&pin_PB10) },         // MicroMod BUS4 | G4 (PB10)
    { MP_ROM_QSTR(MP_QSTR_BUS5), MP_ROM_PTR(&pin_PB11) },         // MicroMod BUS5 | G5 (PB11)
    { MP_ROM_QSTR(MP_QSTR_BUS6), MP_ROM_PTR(&pin_PB12) },         // MicroMod BUS6 | G6 (PB12)
    { MP_ROM_QSTR(MP_QSTR_BUS7), MP_ROM_PTR(&pin_PB13) },         // MicroMod BUS7 | G7 (PB13)

    // MicroMod differential ADC input pins
    // { MP_ROM_QSTR(MP_QSTR_ADC_DM), MP_ROM_PTR(&pin_PA15) },    // MicroMod ADC_D- | G9 | CAM_HSYNC (PA15)
    // { MP_ROM_QSTR(MP_QSTR_ADC_DP), MP_ROM_PTR() },             // MicroMod ADC_D+ | G10 | CAM_VSYNC (not connected)

    // MicroMod camera pins
    // { MP_ROM_QSTR(MP_QSTR_CAM_MCLK), MP_ROM_PTR(&pin_PA21) },  // MicroMod CAM_MCLK | AUD_OUT | I2S_OUT | PCM_OUT (PA21)
    // { MP_ROM_QSTR(MP_QSTR_CAM_PCLK), MP_ROM_PTR(&pin_PA22) },  // MicroMod CAM_PCLK | AUD_IN | I2S_IN | PCM_IN (PA22)
    // { MP_ROM_QSTR(MP_QSTR_CAM_TRIG), MP_ROM_PTR(&pin_PB05) },  // MicroMod CAM_TRIG | D1 (PB05)
    // { MP_ROM_QSTR(MP_QSTR_CAM_HSYNC), MP_ROM_PTR(&pin_PA15 },  // MicroMod CAM_HSYNC | ADC_D- | G9 (PA15)
    // { MP_ROM_QSTR(MP_QSTR_CAM_VSYNC), MP_ROM_PTR() },          // MicroMod CAM_VSYNC | ADC_D+ | G10 (not connected)

    // Module-specific aliases (not part of the MicroMod spec)
    { MP_ROM_QSTR(MP_QSTR_HOST_ENABLE), MP_ROM_PTR(&pin_PA27) },  // HOST_ENABLE | G11 | SWO (PA27)

    // CircuitPython board objects
    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },     // CircuitPython I2C
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },     // CircuitPython SPI
    { MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&board_uart_obj) },   // CircuitPython UART
};
MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
