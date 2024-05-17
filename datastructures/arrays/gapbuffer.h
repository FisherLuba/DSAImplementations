#ifndef DSA_GAP_BUFFER_H
#define DSA_GAP_BUFFER_H

#include <stdexcept>

// TODO
template <typename T>
class GapBuffer {

private:
    int length;
    T emptyValue;
    T* data = nullptr;
    int startSection;
    int gapStart;
    int current;
    int gapEnd;
    int endSection;
    int gapSize;

public:
    GapBuffer(int initialSize, int gapSize, T emptyValue) : emptyValue(emptyValue), length(initialSize), gapSize(gapSize) {
        data = new T[initialSize];
        startSection = 0;
        current = startSection;
        gapStart = startSection;
        gapEnd = gapStart + gapSize;
        endSection = gapEnd + 1;
    }

    void moveCursor(int index) {
        if (index > length) throw std::invalid_argument("index is out of bounds");
        if (index == current) return;
        const int shiftDistance = std::abs(index - gapStart);
        if (index < gapStart) {
            checkResize(endSection + shiftDistance);
            for (int i = endSection + shiftDistance; i >= endSection; i--) {
                data[i] = data[i - shiftDistance];
                data[i - shiftDistance] = nullptr;
            }
            for (int i = gapSize; i <= gapEnd; i++) {

            }
        }
    }

    void checkResize(int index) {
        if (index < length) return;
        T* newData = new T[length * 2];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }


};

#endif