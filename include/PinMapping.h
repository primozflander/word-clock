#pragma once

#ifdef ESP32C3
#define I2C_SDA_PIN 4
#define I2C_SCL_PIN 5
#define PIXELS_PIN 8
#define DEBUG_LED_PIN 12
#define DEBUG_LED2_PIN 13
#define BOOT_BUTTON_PIN 9
#define USB_D_P_PIN 19 // green
#define USB_D_N_PIN 18 // white
#endif

#ifdef ESP32DEV
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22
#define PIXELS_PIN 19
#define DEBUG_LED_PIN 2
#define BOOT_BUTTON_PIN 0
#endif