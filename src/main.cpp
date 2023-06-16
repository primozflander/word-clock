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
    updatePixelColors();
    delay(1000);
    printFrame();
    ArduinoOTA.handle();

    // addCustomFrame(weilingFrame);
    // delay(5000);
    // Serial.println("running");
}
