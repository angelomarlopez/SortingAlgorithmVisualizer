#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "SortingAlgorithm.hpp"

namespace Sorting {
    class HeapSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Bubble Sort object
             * 
             * @param int Length of Data
             */
            HeapSort(int len) : SortingAlgorithm(len) {
                name = "Heap Sort";

                process = 0;
                currentIndex = length / 2 - 1;
            }

        private:
            int process;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();

            // Convert data between indexes to a Heap Structure
            void heapify(int, int);
    };
}

#endif