# mcp4822_linux
A user space linux driver for Microchip MCP4822 Digital-to-Analog Converter.

The code in the test.c file uses the driver functions to generate a sawtooth wave for DAC Channel A, and a sine wave for Channel B.

Tested using Raspberry Pi 3 Model B.

Wiring:

| MCP4822 pin              | Raspberry Pi pin |
| ------------------------ | ---------------- |
| 1 V<sub>DD</sub>         | 2 5V Power       |
| 2 CS                     | 24 SPI0 CE0      |
| 3 SCK                    | 23 SPI0 SCLK     |
| 4 SDI                    | 19 SPI0 MOSI     |
| 5 LDAC                   | 39 Ground        |
| 6 V<sub>OUTB</sub>       | to oscilloscope  |
| 7 V<sub>SS</sub>         | 29 Ground        |
| 8 V<sub>OUTB</sub>       | to oscilloscope  |

Test result:

![](output_test_waveform.gif)
