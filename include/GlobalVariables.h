#pragma once
#include <PinMapping.h>

#define NUMPIXELS 256

// Format: { line index, start position index, length }

const int w_on[3] = {11, 1, 2};
const int w_off[3] = {6, 1, 3};
const int w_sync[3] = {0, 1, 4};

const int w_the[3] = {13, 15, 3};
const int w_the_2[3] = {9, 3, 3};
const int w_time[3] = {8, 15, 4};
const int w_is[3] = {5, 15, 2};
const int w_half[3] = {0, 15, 4};
const int w_past[3] = {4, 8, 4};
const int w_to[3] = {3, 8, 2};
const int w_oclock[3] = {10, 4, 6};
const int w_in[3] = {7, 4, 2};
const int w_at[3] = {5, 4, 2};
const int w_minutes_2[3] = {9, 8, 7};
const int w_minute[3] = {10, 8, 6};
const int w_a[3] = {2, 15, 1};
const int w_quarter[3] = {9, 14, 7};

const int w_night[3] = {11, 3, 5};
const int w_morning[3] = {1, 3, 7};
const int w_evening[3] = {9, 2, 7};
const int w_afternoon[3] = {0, 2, 9};
const int w_noon[3] = {0, 2, 4};

// const int w_and[3] = {14, 8, 3};
// const int w_cold[3] = {14, 12, 4};
// const int w_cool[3] = {15, 0, 4};
// const int w_warm[3] = {15, 6, 4};
// const int w_hot[3] = {15, 12, 3};
// const int w_el[3] = {9, 2, 2};

// const byte              w_the[3] PROGMEM = { 0,  0, 3 };
// const byte             w_time[3] PROGMEM = { 0,  4, 4 };
// const byte               w_is[3] PROGMEM = { 0,  9, 2 };
// const byte             w_half[3] PROGMEM = { 0, 12, 4 };
// const byte                w_a[3] PROGMEM = { 0, 13, 1 };
// const byte           w_minute[3] PROGMEM = { 7, 0, 6 };
// const byte                w_s[3] PROGMEM = { 7, 6, 1 };
// const byte             w_past[3] PROGMEM = { 7, 8, 4 };
// const byte               w_to[3] PROGMEM = { 7,11, 2 };
// const byte           w_oclock[3] PROGMEM = { 11, 0, 6 };
// const byte               w_in[3] PROGMEM = { 11, 7, 2 };
// const byte               w_at[3] PROGMEM = { 11, 9, 2 };
// const byte           w_night_ampm[3] PROGMEM = { 12, 0, 5 };
// const byte             w_the_ampm[3] PROGMEM = { 12, 4, 3 };
// const byte         w_morning_ampm[3] PROGMEM = { 12, 8, 7 };
// const byte         w_evening_ampm[3] PROGMEM = { 13, 0, 7 };
// const byte       w_afternoon_ampm[3] PROGMEM = { 13, 7, 9 };
// const byte            w_noon_ampm[3] PROGMEM = { 13,12, 4 };
// const byte              w_and[3] PROGMEM = { 14,0, 1 };
// const byte                    w_deg[3] PROGMEM = { 14,15, 1 };

const int w_seconds[10][3] = {
    {9, 0, 1}, // 0
    {8, 0, 1}, // 1
    {7, 0, 1}, // 2
    {6, 0, 1}, // 3
    {5, 0, 1}, // 4
    {4, 0, 1}, // 5
    {3, 0, 1}, // 6
    {2, 0, 1}, // 7
    {1, 0, 1}, // 8
    {0, 0, 1}, // 9
};

const int w_seconds_dec[6][3] = {
    {15, 0, 1}, // 0
    {14, 0, 1}, // 10
    {13, 0, 1}, // 20
    {12, 0, 1}, // 30
    {11, 0, 1}, // 40
    {10, 0, 1}, // 50
};

const int w_minutes[20][3] = {
    {1, 13, 3},  // one ok
    {3, 13, 3},  // two ok
    {0, 9, 5},   // three ok
    {12, 10, 4}, // four ok
    {4, 12, 4},  // five ok
    {10, 13, 3}, // six ok
    {11, 11, 5}, // seven ok
    {11, 12, 5}, // eight ok
    {4, 11, 4},  // nine ok
    {13, 13, 3}, // ten ok
    {5, 9, 6},   // eleven ok
    {10, 9, 6},  // twelve ok
    {0, 10, 8},  // thirteen ok
    {8, 10, 8},  // fourteen ok
    {9, 14, 7},  // quarter
    {6, 13, 7},  // sixteen ok
    {7, 11, 9},  // seventeen ok
    {8, 12, 8},  // eighteen ok
    {0, 11, 8},  // nineteen ok
    {3, 14, 6}   // twenty ok
};

const int w_hours[12][3] = {
    {11, 7, 3}, // one
    {13, 7, 3}, // two
    {6, 6, 5},  // three
    {12, 5, 4}, // four
    {7, 5, 4},  // five
    {0, 7, 3},  // six
    {11, 6, 5}, // seven
    {3, 5, 5},  // eight
    {3, 7, 4},  // nine
    {1, 5, 3},  // ten
    {6, 7, 6},  // eleven
    {0, 6, 6}   // twelve
};

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
