#include <Arduino.h>
#include <SystemFunctions.h>
#include <WordClockDisplay.h>
#include <AnalogClockDisplay.h>
#include <LedFunctions.h>
#include <StateMachineFunctions.h>
#include <TempHumDisplay.h>

void setup()
{
    Serial.begin(115200);
    initStates();
    Serial.println("INFO: Setup complete");
}

void loop()
{
    stateMachine.run();
    adaptBrightness();
    updatePixelColors();
    printFrame();
    // ArduinoOTA.handle();
    // delay(1000);

    // addCustomFrame(weilingFrame);
    // delay(5000);
    // Serial.println("running");
    // while(1);
    esp_sleep_enable_timer_wakeup(1000000);
    esp_light_sleep_start();
}
