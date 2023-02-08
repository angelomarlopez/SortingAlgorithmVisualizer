#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "SortingAlgorithm.hpp"

namespace Sorting {
    class InsertionSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Insertion Sort object
             * 
             * @param int Length of Data
             */
            InsertionSort(int len) : SortingAlgorithm(len, 1) {
                name = "Insertion Sort";

                process = 0;
            }

        private:
            int elapsed;
            int process;
            int key;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();
    };
}

#endif