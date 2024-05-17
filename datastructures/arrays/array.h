#ifndef DSA_ARRAY_H
#define DSA_ARRAY_H

#include <array>

template <typename T>
class Array
{
public:
    const unsigned int length;

    Array(std::initializer_list<T> list) : length(list.size()), data(new T[list.size()])
    {
        unsigned int i = 0;
        typename std::initializer_list<T>::const_iterator it = list.begin();
        while (it != list.end())
        {
            data[i++] = *it;
            it++;
        }
    }

    Array(unsigned int length) : length(length), data(new T[length]) {}

    T &operator[](unsigned int index)
    {
        return data[index];
    }

    const T &operator[](unsigned int index) const
    {
        return data[index];
    }

    ~Array()
    {
        delete[] data;
    }

    Array(const Array &other) : length(other.length), data(new T[other.length])
    {
        std::copy(other.data, other.data + other.length, data);
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] data;

            length = other.length;
            data = new T[other.length];
            std::copy(other.data, other.data + other.length, data);
        }

        return *this;
    }

private:
    T *data;
};

#endif