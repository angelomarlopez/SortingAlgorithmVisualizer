#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "../../include/Algorithms/SortingAlgorithm.hpp"

namespace Sorting {
    struct Points {
        int left;
        int mid;
        int right;

        /**
         * @brief Construct a new Points object
         * 
         * @param int left index
         * @param int mid index 
         * @param int right index 
         */
        Points(int l = 0, int m = 0, int r = 0) : left (l), mid(m), right(m) {}
    };

    class MergeSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Merge Sort object
             * 
             * @param int Length of Data
             */
            MergeSort(int len) : SortingAlgorithm(len) {
                name = "Merge Sort";

                process = 0;

                pointsLength = 0;
                pointsSize = 2;
                points = new Points[pointsSize];
            }
        private:
            int process;

            Points* points;
            int pointsSize;
            int pointsLength;
            bool readyToMerge;

            int ii, jj, kk;
            int *L, *R;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();

            // Adds an instance to the Points Dynamic Array
            void add_point(int, int, int);

            // Populates Points Dynamic Array with recursion end result
            void mergesort(int, int);

            // Merges data between given indexes
            void merge(int, int, int);
    };
}

#endif