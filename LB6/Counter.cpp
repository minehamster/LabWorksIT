#include "Counter.h"

Counter::Counter(int minValue, int maxValue)
{
    minLimit = minValue;
    maxLimit = maxValue;
    count = minLimit;
}

void Counter::increment()
{
    if (count < maxLimit)
    {
        count++;
    }
}

void Counter::decrement()
{
    if (count > minLimit)
    {
        count--;
    }
}

int Counter::getCurrent()
{
    return count;
}
