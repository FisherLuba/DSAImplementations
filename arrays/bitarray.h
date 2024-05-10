#ifndef DSI_BIT_ARRAY_H
#define DSI_BIT_ARRAY_H

#define BIT_ARRAY_BITS_PER_BYTE 8

#include <iostream>

class BitArray
{
private:
    unsigned int numBits;
    unsigned int bitsPerWord;
    unsigned int *words;

public:
    BitArray(unsigned int numBits) : numBits(numBits), bitsPerWord(sizeof(unsigned int) * BIT_ARRAY_BITS_PER_BYTE)
    {
        const unsigned int wordsSize = numBits / bitsPerWord + 1;
        words = new unsigned int[wordsSize];
        for (unsigned int i = 0; i < wordsSize; i++)
        {
            words[i] = 0;
        }
    }

    bool operator[](unsigned int index) const
    {
        const unsigned int word = words[index / bitsPerWord];
        unsigned int bitIndex = index % bitsPerWord;
        return (word >> bitIndex) & (unsigned int)1;
    }

    bool flip(unsigned int index)
    {
        unsigned int &word = words[index / bitsPerWord];
        word = word ^ ((unsigned int)1 << index);
        // std::cout << "new word: " << word << std::endl;
        return operator[](index);
    }

    unsigned int hammingWeight() const
    {
        unsigned int weight = 0;
        for (unsigned int i = 0; i < numBits; i++)
        {
            if (operator[](i)) {
                weight++;
            }
        }
        return weight;
    }

    unsigned int firstOne() const {
        for (unsigned int i = 0; i < numBits; i++) {
            if (operator[](i)) {
                return i;
            }
        }
        return -1;
    }

    void invertWords() {
        for (unsigned int i = 0; i < numBits; i++) {
            words[i] = ~words[i];
        }
    }

    unsigned int length() const
    {
        return numBits;
    }
};

namespace BitArrayTesting
{
    void test()
    {
        BitArray array(10);
        for (unsigned int i = 0; i < array.length(); i++)
        {
            bool value = array[i];
            bool newValue = array.flip(i);
            std::cout << i << ": " << value << " new: " << newValue << std::endl;
        }
        std::cout << "-----------" << std::endl;
        for (unsigned int i = 0; i < array.length(); i++)
        {
            bool value = array[i];
            bool newValue = array.flip(i);
            std::cout << i << ": " << value << " new: " << newValue << std::endl;
        }
    }

}

#endif