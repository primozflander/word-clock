#pragma once
#include <GlobalVariables.h>
#include <LedFunctions.h>

void addSecondsToFrame();
void addMinutesToFrame();
void addHoursToFrame();
void addStaticToFrame();
void displayWordClock();

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
    {1, 13, 3},  // one
    {3, 13, 3},  // two
    {0, 9, 5},   // three
    {12, 10, 4}, // four
    {4, 12, 4},  // five
    {10, 13, 3}, // six
    {11, 11, 5}, // seven
    {11, 12, 5}, // eight
    {4, 11, 4},  // nine
    {13, 13, 3}, // ten
    {5, 9, 6},   // eleven
    {10, 9, 6},  // twelve
    {0, 10, 8},  // thirteen
    {8, 10, 8},  // fourteen
    {9, 14, 7},  // quarter
    {6, 13, 7},  // sixteen
    {7, 11, 9},  // seventeen
    {8, 12, 8},  // eighteen
    {0, 11, 8},  // nineteen
    {3, 14, 6}   // twenty
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

uint32_t weilingFrame[16][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void displayWordClock()
{
#ifdef DEBUG
    simulateRTC();
#else
    getWebTime();
#endif
    resetFrame();
    addSecondsToFrame();
    if (hours == 9 && minutes == 16)
    {
        addCustomFrame(weilingFrame);
    }
    else
    {
        addHoursToFrame();
        addMinutesToFrame();
    }
    addStaticToFrame();
    updateDisplay();
}

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
        addWordToFrame(w_seconds_dec[int(seconds / 10)], frame, defaultColor);
    }
}