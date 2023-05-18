#pragma once
#include <GlobalVariables.h>
#include <LedFunctions.h>
#include <RTClib.h>
#include <BH1750.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "at.pool.ntp.org", 7200, 60000);
RTC_DS3231 rtc;
BH1750 lightMeter;

// const char *ssid = "viewpointsystemdev";
// const char *password = "!vps2017dev!";
const char *ssid = "WLAN14510355";
const char *password = "Mtm6nvcwtxtn";
int hours;
int minutes;
int seconds;

void initRtc();
void initLightMeter();
void init();
void initWifi();
void simulateRTC();
void addSecondsToFrame();
void addMinutesToFrame();
void addHoursToFrame();
void addStaticToFrame();

void addHoursToFrame()
{
    if (hours == 0)
    {
        addWordToFrame(w_hours[11], frame, defaultColor);
        addWordToFrame(w_at, frame, defaultColor);
        addWordToFrame(w_night, frame, defaultColor);
    }
    else if (hours <= 11)
    {
        addWordToFrame(w_hours[hours - 1], frame, defaultColor);
        addWordToFrame(w_in, frame, defaultColor);
        addWordToFrame(w_the_2, frame, defaultColor);
        addWordToFrame(w_morning, frame, defaultColor);
    }
    else if (hours == 12)
    {
        addWordToFrame(w_hours[11], frame, defaultColor);
        addWordToFrame(w_in, frame, defaultColor);
        addWordToFrame(w_the_2, frame, defaultColor);
        addWordToFrame(w_afternoon, frame, defaultColor);
    }
    else if (hours > 12 && hours < 18)
    {
        addWordToFrame(w_hours[hours - 13], frame, defaultColor);
        addWordToFrame(w_in, frame, defaultColor);
        addWordToFrame(w_the_2, frame, defaultColor);
        addWordToFrame(w_afternoon, frame, defaultColor);
    }
    else if (hours >= 18 && hours < 21)
    {
        addWordToFrame(w_hours[hours - 13], frame, defaultColor);
        addWordToFrame(w_in, frame, defaultColor);
        addWordToFrame(w_the_2, frame, defaultColor);
        addWordToFrame(w_evening, frame, defaultColor);
    }
    else
    {
        addWordToFrame(w_hours[hours - 13], frame, defaultColor);
        addWordToFrame(w_at, frame, defaultColor);
        addWordToFrame(w_night, frame, defaultColor);
    }
}

void addMinutesToFrame()
{
    if (minutes == 0)
    {
        addWordToFrame(w_oclock, frame, defaultColor);
    }
    else if (minutes == 1)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_minute, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 1 && minutes < 5)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 5)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 5 && minutes < 10)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 10)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 10 && minutes < 15)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 15)
    {
        addWordToFrame(w_a, frame, defaultColor);
        addWordToFrame(w_quarter, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 15 && minutes < 20)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 20)
    {
        addWordToFrame(w_minutes[minutes - 1], frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 20 && minutes < 25)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[minutes - 20], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 25)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[minutes - 20], frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 25 && minutes < 30)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[minutes - 20], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes == 30)
    {
        addWordToFrame(w_half, frame, defaultColor);
        addWordToFrame(w_past, frame, defaultColor);
    }
    else if (minutes > 30 && minutes < 35)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[39 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes == 35)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[39 - minutes], frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes > 35 && minutes < 40)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_minutes[39 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes == 40)
    {
        addWordToFrame(w_minutes[19], frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes > 40 && minutes < 45)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes == 45)
    {
        addWordToFrame(w_a, frame, defaultColor);
        addWordToFrame(w_quarter, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes > 45 && minutes < 50)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes == 50)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes > 50 && minutes < 55)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes == 55)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else if (minutes > 55 && minutes < 59)
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_minutes_2, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
    else
    {
        addWordToFrame(w_minutes[59 - minutes], frame, defaultColor);
        addWordToFrame(w_minute, frame, defaultColor);
        addWordToFrame(w_to, frame, defaultColor);
    }
}

void addStaticToFrame()
{
    addWordToFrame(w_the, frame, defaultColor);
    addWordToFrame(w_time, frame, defaultColor);
    addWordToFrame(w_is, frame, defaultColor);
}

void addSecondsToFrame()
{
    addWordToFrame(w_seconds[seconds % 10], frame, defaultColor);
    if (seconds > 9)
    {
        addWordToFrame(w_seconds_dec[int(seconds / pow(10, floor(log10(seconds))))], frame, defaultColor);
    }
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
    pinMode(DEBUG_LED_PIN, OUTPUT);
    pinMode(DEBUG_LED2_PIN, OUTPUT);
    pinMode(BOOT_BUTTON_PIN, INPUT);
    // Wire.setPins(I2C_SDA_PIN, I2C_SCL_PIN);
    // Wire.begin();
    // initRtc();
    // initLightMeter();
    initPixels();
    initWifi();
    timeClient.begin();
}

void initWifi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    if (!MDNS.begin("esp32"))
    {
        Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
}

void initLightMeter()
{
    if (!lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE))
    {
        Serial.println("FAIL: Couldn't find DH1750");
    }
    else
    {
        Serial.println("INFO: Connected to DH1750");
    }
}

void initRtc()
{
    if (!rtc.begin())
    {
        Serial.println("FAIL: Couldn't find DS3231");
    }
    else
    {
        Serial.println("INFO: Connected to DS3231");
        if (rtc.lostPower())
        {
            Serial.println("INFO: RTC lost power, setting time");
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        }
    }
}