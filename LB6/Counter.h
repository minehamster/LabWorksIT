#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int count;
    int minLimit;
    int maxLimit;

public:
    Counter(int minValue, int maxValue);

    void increment();
    void decrement();
    int getCurrent();
};

#endif
