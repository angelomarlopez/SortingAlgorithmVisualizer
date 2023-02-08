#ifndef SORTINGALGORITHMS_HPP
#define SORTINGALGORITHMS_HPP

// List of Algorithm Header files
#include "Algorithms/SelectionSort.hpp"
#include "Algorithms/BubbleSort.hpp"
#include "Algorithms/InsertionSort.hpp"
#include "Algorithms/MergeSort.hpp"
#include "Algorithms/HeapSort.hpp"
#include "Algorithms/QuickSort.hpp"

namespace Sorting {
    // List of Available Algorithms
    enum Algorithms {
        SELECTIONSORT,
        BUBBLESORT,
        INSERTIONSORT,
        MERGESORT,
        HEAPSORT,
        QUICKSORT,
        NUM_OF_ALGORITHMS
    };
}

#endif