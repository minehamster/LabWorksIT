#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

class SmartArray
{
private:
    int* data;
    int size;

public:
    SmartArray(int sizeValue);
    ~SmartArray();

    void setElement(int index, int value);
    int getElement(int index);
};

#endif
