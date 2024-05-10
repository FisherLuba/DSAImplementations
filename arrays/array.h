#ifndef DSI_ARRAY_H
#define DSI_ARRAY_H

#include <array>

template <typename T>
class Array
{
private:
    unsigned int length;
    T *data;

public:
    Array(unsigned int length) : length(length), data(new T[length]) {}

    T &operator[](unsigned int index)
    {
        return data[index];
    }

    ~Array() {
        delete[] data;
    }
};


#endif