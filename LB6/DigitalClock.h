#ifndef DIGITAL_CLOCK_H
#define DIGITAL_CLOCK_H

class DigitalClock
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    DigitalClock(int hoursValue, int minutesValue, int secondsValue);
    ~DigitalClock();

    void setHours(int hoursValue);
    void setMinutes(int minutesValue);
    void setSeconds(int secondsValue);

    int getHours();
    int getMinutes();
    int getSeconds();

    void display();
    void tick();
};

#endif
