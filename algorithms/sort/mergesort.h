#ifndef DSA_MERGESORT_H
#define DSA_MERGESORT_H

#include <iostream>

#include "../../datastructures/arrays/array.h"

template <typename T>
struct MergeSort
{

    static Array<T> mergeSortRecursive(const Array<T> array)
    {
        if (array.length == 1)
        {
            return array;
        }
        Array<T> left(array.length / 2);
        Array<T> right(array.length - left.length);
        unsigned int i = 0;
        while (i < left.length)
        {
            left[i] = array[i];
            i++;
        }
        i = 0;
        while (i < right.length)
        {
            right[i] = array[left.length + i];
            i++;
        }

        return merge(mergeSortRecursive(left), mergeSortRecursive(right));
    }

private:
    static Array<T> merge(const Array<T> left, const Array<T> right)
    {
        Array<T> newArray(left.length + right.length);
        unsigned int l = 0;
        unsigned int r = 0;
        unsigned int i = 0;
        while (l < left.length)
        {
            if (r >= right.length || left[l] < right[r])
            {
                newArray[i++] = left[l++];
                continue;
            }
            newArray[i++] = right[r++];
        }
        while (r < right.length)
        {
            newArray[i++] = right[r++];
        }
        return newArray;
    }
};

namespace MergeSortTesting
{

    void test()
    {
        std::cout << "----------MergeSort Testing Start----------\n";
        Array<int> test = {1, 5, 34, 5, 7, 8, 4, 1, 9};
        Array<int> array2 = MergeSort<int>::mergeSortRecursive(test);
        for (unsigned int i = 0; i < array2.length; i++)
        {
            std::cout << array2[i] << " ";
        }
        std::cout << "\n----------MergeSort Testing End----------\n";
    }

};

#endif