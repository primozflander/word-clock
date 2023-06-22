#pragma once
#include <GlobalVariables.h>
#include <LedFunctions.h>
#include <RTClib.h>
#include <BH1750.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <WiFiManager.h>
#include <Credentials.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ArduinoOTA.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "at.pool.ntp.org", 7200, 60000);
RTC_DS3231 rtc;
BH1750 lightSensor;
Adafruit_BME280 bme;
int colorValue;

void initRtc();
void initLightSensor();
void init();
void initWifi();
void simulateRTC();
void initAP();
void initBme();
void getWebTime();
void updatePixelColors();
void initOTA();
void adaptBrightness();

void initBme()
{
    // status = bme.begin(0x76, &Wire2)
    if (bme.begin(0x76))
    {
        isBmeDetected = true;
    }
    else
    {
        Serial.println("ERROR: BME280 init failed");
        isBmeDetected = false;
    }
}

void initAP()
{
    Serial.println("INFO: AP init");
    WiFi.mode(WIFI_STA);
    WiFiManager wm;
    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    // wm.resetSettings();
    bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("WordClockAP"); // password protected ap
    if (!res)
    {
        Serial.println("FAIL: Failed to connect");
        // ESP.restart();
    }
    else
    {
        Serial.println("INFO: Connected");
        if (!MDNS.begin(DEVICE_MDNS_NAME))
        {
            Serial.println("FAIL: Error setting up MDNS responder!");
        }
        Serial.println("INFO: mDNS responder started");
    }
}

void initOTA()
{
    // Hostname defaults to esp3232-[MAC]
    ArduinoOTA.setHostname(DEVICE_MDNS_NAME);
    ArduinoOTA
        .onStart([]()
                 {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type); })
        .onEnd([]()
               { Serial.println("\nEnd"); })
        .onProgress([](unsigned int progress, unsigned int total)
                    { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); })
        .onError([](ota_error_t error)
                 {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed"); });

    ArduinoOTA.begin();

    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void updatePixelColors()
{
    static unsigned long previousColorUpdate = 0;
    if ((millis() - previousColorUpdate) > 1000)
    {
        colorValue < 65530 ? colorValue += 100 : colorValue = 0;
        defaultColor = pixels.ColorHSV(colorValue);
        previousColorUpdate = millis();
    }
}

void getWebTime()
{
    // static unsigned long previousTimeUpdate = 0;
    // if ((millis() - previousTimeUpdate) > 1000)
    // {
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
    seconds = timeClient.getSeconds();
    minutes = timeClient.getMinutes();
    hours = timeClient.getHours();
    // previousTimeUpdate = millis();
    // Serial.println("s");
    // }
}

void simulateRTC()
{
    seconds < 59 ? seconds++ : seconds = 0;
    minutes < 59 ? minutes++ : minutes = 0;
    hours < 23 ? hours++ : hours = 0;
    Serial.println("s: " + String(seconds) + " min: " + String(minutes) + " hours: " + String(hours));
}

void init()
{
#ifdef ESP32C3
    pinMode(DEBUG_LED2_PIN, OUTPUT);
#endif
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    pinMode(BOOT_BUTTON_PIN, INPUT);
    pinMode(DEBUG_LED_PIN, OUTPUT);
    initBme();
    initRtc();
    initLightSensor();
    initPixels();
#ifdef DEBUG
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    if (!MDNS.begin(DEVICE_MDNS_NAME))
    {
        Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
    initOTA();
#else
    initWifi();
    timeClient.begin();
    // timeClient.update();
    // WiFi.disconnect(true);
    // WiFi.mode(WIFI_OFF);
#endif
}

void initWifi()
{
    // WiFi.mode(WIFI_STA);
    // WiFi.begin(ssid, password);
    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(500);
    //     Serial.print(".");
    // }
    // if (!MDNS.begin("esp32"))
    // {
    //     Serial.println("Error setting up MDNS responder!");
    // }
    // Serial.println("mDNS responder started");
    initAP();
    initOTA();
}

void initLightSensor()
{
    if (!lightSensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE))
    {
        Serial.println("FAIL: Couldn't find DH1750");
        isLightSensorDetected = false;
    }
    else
    {
        Serial.println("INFO: Connected to DH1750");
        isLightSensorDetected = true;
    }
}

void initRtc()
{
    if (!rtc.begin())
    {
        Serial.println("FAIL: Couldn't find DS3231");
        isRtcDetected = false;
    }
    else
    {
        Serial.println("INFO: Connected to DS3231");
        if (rtc.lostPower())
        {
            Serial.println("INFO: RTC lost power, setting time");
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        }
        isRtcDetected = true;
    }
}

void adaptBrightness()
{
    if (isLightSensorDetected)
    {
        float lux = lightSensor.readLightLevel();
        Serial.println("Light: " + String(lux) + " lx");
        pixels.setBrightness(map(lux, 0, 1500, 0, 255));
    }
}