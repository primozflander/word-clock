
#pragma once
#include <StateMachine.h>
#include <SystemFunctions.h>
#include <TempHumDisplay.h>

void initStates();
void initState();
void wordState();
void analogState();
void digitalState();
void tempHumState();
bool init2WordTransition();
bool word2AnalogTransition();
bool analog2DigitalTransition();
bool digital2TemphumTransition();
bool temphum2WordTransition();
bool word2tempHumTransition();

StateMachine stateMachine = StateMachine();
State *INIT_STATE = stateMachine.addState(&initState);
State *WORD_STATE = stateMachine.addState(&wordState);
State *ANALOG_STATE = stateMachine.addState(&analogState);
State *DIGITAL_STATE = stateMachine.addState(&digitalState);
State *TEMPHUM_STATE = stateMachine.addState(&tempHumState);

unsigned long previousStateMillis = 0;

void initStates()
{
    INIT_STATE->addTransition(&init2WordTransition, WORD_STATE);
    WORD_STATE->addTransition(&word2tempHumTransition, TEMPHUM_STATE);
    // WORD_STATE->addTransition(&word2AnalogTransition, ANALOG_STATE);
    // ANALOG_STATE->addTransition(&analog2DigitalTransition, DIGITAL_STATE);
    // DIGITAL_STATE->addTransition(&digital2TemphumTransition, TEMPHUM_STATE);
    TEMPHUM_STATE->addTransition(&temphum2WordTransition, WORD_STATE);
}

void initState()
{
    Serial.println("--INIT STATE--");
    if (stateMachine.executeOnce)
    {
        init();
        previousStateMillis = millis();
    }
}

void wordState()
{
    Serial.println("--WORD STATE--");
    if (stateMachine.executeOnce)
    {
        previousStateMillis = millis();
    }
    displayWordClock();
}

void analogState()
{
    Serial.println("--ANALOG STATE--");
    if (stateMachine.executeOnce)
    {
        previousStateMillis = millis();
    }
}

void digitalState()
{
    Serial.println("--DIGITAL STATE--");
    if (stateMachine.executeOnce)
    {
        previousStateMillis = millis();
    }
}

void tempHumState()
{
    Serial.println("--TEMPHUM STATE--");
    if (stateMachine.executeOnce)
    {
        previousStateMillis = millis();
    }
    displayTempHum();
}

bool word2tempHumTransition()
{
    Serial.println("TRANSITION CHECK: word2tempHum");
    if ((millis() - previousStateMillis) > 10000)
    {
        return true;
    }
    return false;
}

bool init2WordTransition()
{
    // Serial.println("TRANSITION CHECK: init2Word");
    // if ((millis() - previousStateMillis) > TRANSITION_DELAY)
    // {
    //     return true;
    // }
    // return false;
    return true;
}

bool word2AnalogTransition()
{
    Serial.println("TRANSITION CHECK: init2Word");
    if ((millis() - previousStateMillis) > 10000)
    {
        return true;
    }
    return false;
}

bool analog2DigitalTransition()
{
    // Serial.println("TRANSITION CHECK: init2Word");
    // if ((millis() - previousStateMillis) > TRANSITION_DELAY)
    // {
    //     return true;
    // }
    // return false;
    return true;
}

bool digital2TemphumTransition()
{
    // Serial.println("TRANSITION CHECK: init2Word");
    // if ((millis() - previousStateMillis) > TRANSITION_DELAY)
    // {
    //     return true;
    // }
    // return false;
    return true;
}

bool temphum2WordTransition()
{
    Serial.println("TRANSITION CHECK: init2Word");
    if ((millis() - previousStateMillis) > 2000)
    {
        return true;
    }
    return false;
}