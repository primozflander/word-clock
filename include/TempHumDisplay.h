#pragma once
#include <GlobalVariables.h>
#include <LedFunctions.h>

void testTempHum();
void printNumber(const int number[7][3]);
void displayTempHum();
void addTempHumUnitsToFrame();
void addNumberToFrame(const int number[7][3], int index);

const int frame_num[10][7][3] = {
    {{1, 1, 1}, // 0
     {1, 0, 1},
     {1, 0, 1},
     {1, 0, 1},
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1}},
    {{0, 0, 1}, // 1
     {0, 1, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1}},
    {{1, 1, 1}, // 2
     {0, 0, 1},
     {0, 0, 1},
     {1, 1, 1},
     {1, 0, 0},
     {1, 0, 0},
     {1, 1, 1}},
    {{1, 1, 1}, // 3
     {0, 0, 1},
     {0, 0, 1},
     {1, 1, 1},
     {0, 0, 1},
     {0, 0, 1},
     {1, 1, 1}},
    {{1, 0, 1}, // 4
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1}},
    {{1, 1, 1}, // 5
     {1, 0, 0},
     {1, 0, 0},
     {1, 1, 1},
     {0, 0, 1},
     {0, 0, 1},
     {1, 1, 1}},
    {{1, 1, 1}, // 6
     {1, 0, 0},
     {1, 0, 0},
     {1, 1, 1},
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1}},
    {{1, 1, 1}, // 7
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1},
     {0, 0, 1}},
    {{1, 1, 1}, // 8
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1},
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1}},
    {{1, 1, 1}, // 9
     {1, 0, 1},
     {1, 0, 1},
     {1, 1, 1},
     {0, 0, 1},
     {0, 0, 1},
     {1, 1, 1}}};

const int frame_percentage[7][7] = {
    {1, 0, 0, 0, 1, 1, 1}, // %
    {0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 1}};

const int frame_celsius[7][7] = {
    {1, 1, 1, 0, 0, 1, 0}, // %
    {1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0}};

void displayTempHum()
{
    int temp = (int)bme.readTemperature() % 10;
    int tempDec = bme.readTemperature() / 10;
    int hum = (int)bme.readHumidity() % 10;
    int humDec = bme.readHumidity() / 10;
    resetFrame();
    addNumberToFrame(frame_num[tempDec], 0);
    addNumberToFrame(frame_num[temp], 1);
    addNumberToFrame(frame_num[humDec], 2);
    addNumberToFrame(frame_num[hum], 3);
    addTempHumUnitsToFrame();
    updateDisplay();
    // Serial.println(bme.readTemperature());
    // Serial.println(bme.readHumidity());
    // Serial.println(temp);
    // Serial.println(tempDec);
    // Serial.println(hum);
    // Serial.println(humDec);
}

void addTempHumUnitsToFrame()
{
    for (int row = 9; row < 16; row++)
    {
        for (int column = 0; column < 7; column++)
        {
            frame[15 - row][15 - column] = frame_celsius[column][row - 9] > 0 ? defaultColor : 0;
            // printFrame();
            // delay(500);
        }
        // printFrame();
    }
    for (int row = 9; row < 16; row++)
    {
        for (int column = 9; column < 16; column++)
        {
            frame[15 - row][15 - column] = frame_percentage[column - 9][row - 9] > 0 ? defaultColor : 0;
            // printFrame();
            // delay(500);
        }
        // printFrame();
    }
}

void addNumberToFrame(const int number[7][3], int index)
{
    // temp
    // Serial.println("here");
    if (index == 0) // first number
    {
        // Serial.println("here2");
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 7; column++)
            {
                frame[15 - row][15 - column] = number[column][row] > 0 ? defaultColor : 0;
                // printFrame();
                // delay(500);
            }
            // printFrame();
        }
    }
    else if (index == 1) // second number
    {
        for (int row = 4; row < 7; row++)
        {
            for (int column = 0; column < 7; column++)
            {
                frame[15 - row][15 - column] = number[column][row - 4] > 0 ? defaultColor : 0;
            }
        }
    }
    // hum
    else if (index == 2) // first number
    {
        for (int row = 0; row < 3; row++)
        {
            for (int column = 9; column < 16; column++)
            {
                frame[15 - row][15 - column] = number[column - 9][row] > 0 ? defaultColor : 0;
            }
        }
    }
    else if (index == 3) // second number
    {
        for (int row = 4; row < 7; row++)
        {
            for (int column = 9; column < 16; column++)
            {
                frame[15 - row][15 - column] = number[column - 9][row - 4] > 0 ? defaultColor : 0;
            }
        }
    }
}

void testTempHum()
{
    for (int i = 0; i < 9; i++)
    {
        resetFrame();
        addNumberToFrame(frame_num[i], 0);
        addNumberToFrame(frame_num[9 - i], 1);
        addNumberToFrame(frame_num[i], 2);
        addNumberToFrame(frame_num[9 - i], 3);
        // printNumber(frame_num[0]);
        // printFrame();
        addTempHumUnitsToFrame();
        updateDisplay();
        delay(1000);
    }
}

void printNumber(const int number[7][3])
{
    for (int row = 0; row < 7; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            Serial.print(String(number[row][column]) + "  ");
        }
        Serial.println();
    }
    Serial.println();
}
