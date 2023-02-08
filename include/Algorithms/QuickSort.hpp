#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "SortingAlgorithm.hpp"

namespace Sorting {
    class QuickSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Bubble Sort object
             * 
             * @param int Length of Data
             */
            QuickSort(int len) : SortingAlgorithm(len) {
                name = "Quick Sort";

                process = 0;
                process2 = 0;
                innerProcess = 0;

                low = 0;
                high = length - 1;
            }

        private:
            int process;
            int process2;
            int innerProcess;
            int low, pi, high, pivot, i;
            int *stack;
            int top;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();

            // Main sorting function
            void quicksort();

            // Sets partition point for iteration
            void partition();
    };
}

#endif