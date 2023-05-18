#pragma once
#include <GlobalVariables.h>
#include <Adafruit_NeoPixel.h>

void testPixels();
void initPixels();
void modifyPixel(uint16_t x, uint16_t y, uint32_t color);
void resetPixel(uint16_t x, uint16_t y);
void addWordToFrame(const int theword[3], uint32_t frame[16][16], uint32_t color);
// void updateDisplay(uint32_t prevFrame[16][16], uint32_t frame[16][16]);
void updateDisplay();
void printFrame();
void resetFrame();

Adafruit_NeoPixel pixels(NUMPIXELS, PIXELS_PIN, NEO_GRB + NEO_KHZ800);

uint32_t frame[16][16];
uint32_t prevFrame[16][16];
uint32_t defaultColor = pixels.Color(0, 150, 0);

// void updateDisplay(uint32_t prevFrame[16][16], uint32_t frame[16][16])
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
    for (int row = 0; row < 16; ++row)
    {
        for (int column = 0; column < 16; ++column)
        {
            frame[15 - column][15 - row] > 0 ? Serial.print(String(wordMapping[row][column]) + "  ") : Serial.print("-  ");
        }
        Serial.println();
    }
    Serial.println();
}

void updateDisplay()
{
    for (int row = 0; row < 16; ++row)
    {
        for (int column = 0; column < 16; ++column)
        {
            // if (prevFrame[row][column] && !frame[row][column])
            // {
            //     resetPixel(row, column);
            // }
            // else if (!prevFrame[row][column] && frame[row][column])
            // {
            //     modifyPixel(row, column, defaultColor);
            // }
            // modifyPixel(1,1,4566);
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

    // Copy current frame to prevFrame
    // for (int i = 0; i < 16; i++)
    // {
    //     for (int j = 0; j < 16; j++)
    //     {
    //         prevFrame[i][j] = frame[i][j];
    //     }
    // }
    pixels.show();
}

void addWordToFrame(const int theword[3], uint32_t frame[16][16], uint32_t color)
{
    for (int i = 0; i < theword[2]; ++i)
    {
        frame[theword[0] + i][theword[1]] = color;
    }
}

void initPixels()
{
    pixels.begin();
    pixels.clear();
    pixels.setBrightness(25);
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