#pragma once
#include <GlobalVariables.h>
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 256

void testPixels();
void initPixels();
void modifyPixel(uint16_t x, uint16_t y, uint32_t color);
void resetPixel(uint16_t x, uint16_t y);
void addWordToFrame(const int theword[3], uint32_t frame[16][16], uint32_t color);
void updateDisplay();
void printFrame();
void printFrameColors();
void resetFrame();
void addCustomFrame(uint32_t customFrame[16][16]);

Adafruit_NeoPixel pixels(NUMPIXELS, PIXELS_PIN, NEO_GRB + NEO_KHZ800);

uint32_t frame[16][16];
uint32_t prevFrame[16][16];
uint32_t defaultColor = pixels.Color(0, 150, 0);

String wordMapping[16][16] =
    {
        {"T", "H", "E", "B", "T", "I", "M", "E", "R", "I", "S", "E", "H", "A", "L", "F"},
        {"Q", "U", "A", "R", "T", "E", "R", "T", "W", "E", "N", "T", "Y", "T", "T", "X"},
        {"T", "E", "N", "S", "I", "X", "T", "E", "E", "N", "T", "W", "O", "N", "E", "L"},
        {"E", "I", "G", "H", "T", "E", "E", "N", "F", "I", "V", "E", "R", "X", "X", "X"},
        {"S", "E", "V", "E", "N", "T", "E", "E", "N", "I", "N", "E", "T", "E", "E", "N"},
        {"F", "O", "U", "R", "T", "E", "E", "N", "T", "H", "I", "R", "T", "E", "E", "N"},
        {"T", "W", "E", "L", "V", "E", "L", "E", "V", "E", "N", "T", "H", "R", "E", "E"},
        {"M", "I", "N", "U", "T", "E", "S", "X", "P", "A", "S", "T", "O", "W", "O", "R"},
        {"T", "W", "O", "N", "E", "L", "E", "V", "E", "N", "I", "N", "E", "S", "I", "X"},
        {"S", "E", "V", "E", "N", "T", "H", "R", "E", "E", "T", "W", "E", "L", "V", "E"},
        {"F", "O", "U", "R", "X", "F", "I", "V", "E", "I", "G", "H", "T", "E", "N", "D"},
        {"O", "C", "L", "O", "C", "K", "X", "I", "N", "A", "T", "X", "2", "0", "2", "3"},
        {"N", "I", "G", "H", "T", "H", "E", "X", "M", "O", "R", "N", "I", "N", "G", "X"},
        {"E", "V", "E", "N", "I", "N", "G", "A", "F", "T", "E", "R", "N", "O", "O", "N"},
        {"P", "I", "R", "X", "O", "N", "X", "O", "F", "F", "X", "X", "S", "Y", "N", "C"},
        {"0", "1", "2", "3", "4", "5", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}};

// uint32_t customFrame[16][16] =
//     {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, c, c, c, c, 0, 0, 0, 0, c, c, c, c, 0, 0},
//         {0, c, 0, 0, 0, 0, c, 0, 0, c, 0, 0, 0, 0, c, 0},
//         {c, 0, 0, 0, 0, 0, 0, c, c, 0, 0, 0, 0, 0, 0, c},
//         {c, 0, 0, 0, 0, 0, 0, c, c, 0, 0, 0, 0, 0, 0, c},
//         {c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, c},
//         {0, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, c, 0},
//         {0, 0, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, c, 0, 0},
//         {0, 0, 0, c, 0, 0, 0, 0, 0, 0, 0, 0, c, 0, 0, 0},
//         {0, 0, 0, 0, c, 0, 0, 0, 0, 0, 0, c, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, c, 0, 0, 0, 0, c, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, c, 0, 0, c, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, c, c, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, c, c, c, c, c, c, c, 0, c, c, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// uint32_t c = pixels.Color(0, 150, 0);
// uint32_t weilingFrame[16][16] =
//     {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, c, c, c, c, 0, 0, 0, 0, c, c, c, c, 0, 0},
//         {0, c, c, c, c, c, c, 0, 0, c, c, c, c, c, c, 0},
//         {0, c, c, c, c, c, c, c, c, c, c, c, c, c, c, 0},
//         {0, c, c, c, c, c, c, c, c, c, c, c, c, c, c, 0},
//         {0, c, c, c, c, c, c, c, c, c, c, c, c, c, c, 0},
//         {0, 0, c, c, c, c, c, c, c, c, c, c, c, c, 0, 0},
//         {0, 0, c, c, c, c, c, c, c, c, c, c, c, c, 0, 0},
//         {0, 0, 0, c, c, c, c, c, c, c, c, c, c, 0, 0, 0},
//         {0, 0, 0, 0, c, c, c, c, c, c, c, c, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, c, c, c, c, c, c, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, c, c, c, c, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, c, c, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, c, c, c, c, c, c, c, 0, c, c, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};



void addCustomFrame(uint32_t customFrame[16][16])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            frame[i][j] = customFrame[15 - j][15 - i];
        }
    }
    // updateDisplay();
}

void resetFrame()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            frame[i][j] = 0;
        }
    }
}

void printFrame()
{
    for (int row = 0; row < 16; row++)
    {
        for (int column = 0; column < 16; column++)
        {
            frame[15 - column][15 - row] > 0 ? Serial.print(String(wordMapping[row][column]) + "  ") : Serial.print("-  ");
        }
        Serial.println();
    }
    Serial.println();
}

void printFrameColors()
{
    for (int row = 0; row < 16; row++)
    {
        for (int column = 0; column < 16; column++)
        {
            Serial.print(String(frame[row][column]) + "  ");
        }
        Serial.println();
    }
    Serial.println();
}

void updateDisplay()
{
    for (int row = 0; row < 16; row++)
    {
        for (int column = 0; column < 16; column++)
        {
            if (frame[row][column] > 0)
            {
                modifyPixel(row, column, defaultColor);
            }
            else
            {
                modifyPixel(row, column, 0);
            }
        }
    }
    pixels.show();
}

void addWordToFrame(const int theword[3], uint32_t frame[16][16], uint32_t color)
{
    for (int i = 0; i < theword[2]; i++)
    {
        frame[theword[0] + i][theword[1]] = color;
    }
}

void initPixels()
{
    pixels.begin();
    pixels.clear();
    pixels.setBrightness(BRIGHTNESS);
}

void testPixels()
{
    pixels.clear();
    for (int i = 0; i < NUMPIXELS; i++)
    {
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
        if (i > 0)
        {
            pixels.setPixelColor(i - 1, pixels.Color(0, 0, 0));
        }
        pixels.show();
        delay(10);
    }
}

void modifyPixel(uint16_t x, uint16_t y, uint32_t color)
{
    uint16_t pixelIndex;
    y % 2 != 0 ? pixelIndex = (15 - x) + y * 16 : pixelIndex = x + y * 16;
    pixels.setPixelColor(pixelIndex, color);
}

void resetPixel(uint16_t x, uint16_t y)
{
    uint16_t pixelIndex;
    y % 1 == 0 ? pixelIndex = (15 - x) + y * 16 : pixelIndex = x + y * 16;
    pixels.setPixelColor(pixelIndex, 0);
}