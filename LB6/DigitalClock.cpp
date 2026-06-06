#include <iostream>
#include <iomanip>
#include "DigitalClock.h"

DigitalClock::DigitalClock(int hoursValue, int minutesValue, int secondsValue)
{
    if (hoursValue >= 0 && hoursValue <= 23)
    {
        hours = hoursValue;
    }
    else
    {
        hours = 0;
    }

    if (minutesValue >= 0 && minutesValue <= 59)
    {
        minutes = minutesValue;
    }
    else
    {
        minutes = 0;
    }

    if (secondsValue >= 0 && secondsValue <= 59)
    {
        seconds = secondsValue;
    }
    else
    {
        seconds = 0;
    }
}

DigitalClock::~DigitalClock()
{
    std::cout << "Clock was deleted" << std::endl;
}

void DigitalClock::setHours(int hoursValue)
{
    if (hoursValue >= 0 && hoursValue <= 23)
    {
        hours = hoursValue;
    }
    else
    {
        hours = 0;
    }
}

void DigitalClock::setMinutes(int minutesValue)
{
    if (minutesValue >= 0 && minutesValue <= 59)
    {
        minutes = minutesValue;
    }
    else
    {
        minutes = 0;
    }
}

void DigitalClock::setSeconds(int secondsValue)
{
    if (secondsValue >= 0 && secondsValue <= 59)
    {
        seconds = secondsValue;
    }
    else
    {
        seconds = 0;
    }
}

int DigitalClock::getHours()
{
    return hours;
}

int DigitalClock::getMinutes()
{
    return minutes;
}

int DigitalClock::getSeconds()
{
    return seconds;
}

void DigitalClock::display()
{
    std::cout << std::setw(2) << std::setfill('0') << hours << ":";
    std::cout << std::setw(2) << std::setfill('0') << minutes << ":";
    std::cout << std::setw(2) << std::setfill('0') << seconds << std::endl;
}

void DigitalClock::tick()
{
    seconds++;

    if (seconds > 59)
    {
        seconds = 0;
        minutes++;
    }

    if (minutes > 59)
    {
        minutes = 0;
        hours++;
    }

    if (hours > 23)
    {
        hours = 0;
    }
}
