# Arduino Nano ESP32

The **Arduino Nano ESP32** is a compact yet powerful development board based on the ESP32-S3 microcontroller, combining the familiar Nano form factor with modern wireless capabilities. Ideal for IoT and embedded projects requiring Wi-Fi, Bluetooth, and rich peripheral support.

## Features ⚡

- Dual-core Xtensa® 32-bit LX7 microprocessor @ up to 240 MHz
- 512 kB SRAM + 128 Mbit (16 MB) external flash + 8 MB external PSRAM
- Integrated Wi-Fi 802.11 b/g/n and Bluetooth LE 5.0
- USB-C programming and power port
- 14 digital I/O pins, 8 analog inputs, 5 PWM pins
- Communication interfaces: SPI, I2C, UART, CAN (TWAI)
- Compatible with Arduino IDE, Arduino Cloud, and MicroPython
- Operating voltage: 3.3 V; input voltage 6-21 V

## Specifications 📋

| Parameter         | Details                         |
|-------------------|--------------------------------|
| Microcontroller   | u-blox NORA-W106 (ESP32-S3)    |
| Processor Speed   | Up to 240 MHz                  |
| SRAM              | 512 kB Internal + 8 MB External |
| Flash Memory      | 128 Mbit (16 MB) External      |
| Operating Voltage | 3.3 V                         |
| Input Voltage     | 6 - 21 V                      |
| Digital I/O Pins  | 14                            |
| Analog Inputs     | 8                             |
| PWM Pins          | 5                             |
| Connectivity      | Wi-Fi 802.11 b/g/n, Bluetooth LE 5.0 |
| USB Connector     | USB-C                         |
| Dimensions        | 45 x 18 mm                   |

## Pinout

- 14x Digital GPIO pins (support interrupts)
- 8x Analog input pins (ADC)
- SPI: D11 (COPI), D12 (CIPO), D13 (SCK), Any GPIO for CS
- I2C: SDA (A4), SCL (A5)
- UART: 2 ports
- CAN (TWAI) supported

## Getting Started 🚀

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Add ESP32 board support by adding this URL to Board Manager:
3. Install the "Arduino Nano ESP32" board from the Board Manager.
4. Connect your Arduino Nano ESP32 via USB-C to your computer.
5. Select the board and port in the IDE.
6. Load and upload your sketch.

## Troubleshooting 🐞

- Ensure drivers for USB-C are installed if board is not detected.
- Verify correct COM port selection.
- Check 3.3V operating voltage limits on connected peripherals.
- Use compatible USB-C cables (some are power-only and lack data).

