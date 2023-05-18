#include <Arduino.h>
#include <SystemFunctions.h>
#include <LedFunctions.h>

int colorValue;

void setup()
{
    Serial.begin(115200);
    init();
    Serial.println("INFO: Setup complete");
}

// the loop function runs over and over again forever
void loop()
{
    colorValue < 65530 ? colorValue += 100 : colorValue = 0;
    defaultColor = pixels.ColorHSV(colorValue);
    // Serial.println("Hello");
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
    seconds = timeClient.getSeconds();
    minutes = timeClient.getMinutes();
    hours = timeClient.getHours();

    resetFrame();
    addSecondsToFrame();
    addHoursToFrame();
    addMinutesToFrame();
    addStaticToFrame();
    printFrame();
    updateDisplay();
    delay(1000);
    // simulateRTC();
}
