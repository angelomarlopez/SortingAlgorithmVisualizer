#include "../../include/Algorithms/QuickSort.hpp"

namespace Sorting {
    /**
     * @brief Resets values back to default
     * 
     */
    void QuickSort::set_default() {
        sorted = false;
        process = process2 = innerProcess = currentIndex = 0;

        low = 0;
        high = length - 1;
        delete[] stack;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void QuickSort::sort() {
        quicksort();
        sf::sleep(sf::milliseconds(5));
    }

    /**
     * @brief Main function that implements quick sort
     * 
     */
    void QuickSort::quicksort() {
        if (process == 0) {
            stack = new int[high - low + 1];
            top = -1;
            stack[++top] = low;
            stack[++top] = high;
            
            process++;
        }
        if (process == 1) {
            if (process2 == 0) {
                high = stack[top--];
                low = stack[top--];

                process2++;
            }
            if (process2 == 1) {
                if (innerProcess != 3)
                    partition();
                else {
                    innerProcess = 0;
                    process2++;
                }
            }
            else if (process2 == 2) {
                if (pi - 1 > low) {
                    stack[++top] = low;
                    stack[++top] = pi - 1;
                }

                if (pi + 1 < high) {
                    stack[++top] = pi + 1;
                    stack[++top] = high;
                }

                if (top < 0) {
                    sorted = true;
                    currentIndex = length;
                }
                else
                    process2 = 0;
            }
        }
    }

    /**
     * @brief Selects the last element as pivot element, 
     *   places that pivo element correctly in the array 
     *   in such a way that all the elements to the left 
     *   of the pivot are lesser than the pivot and all 
     *   elements to the right of pivot are greater than it.
     * 
     */
    void QuickSort::partition() {
        if (innerProcess == 0) {
            pivot = data[high].getSize().y;

            dataAccess++;

            i = (low - 1);
            currentIndex = low;

            innerProcess++;
        }
        if (innerProcess == 1) {
            if (currentIndex <= high - 1) {
                int current = data[currentIndex].getSize().y;

                dataAccess++;
                comparisons++;

                if (current <= pivot) {
                    i++;
                    swap(data[i], data[currentIndex]);

                    exchanges++;
                }
                currentIndex++;
            }
            else
                innerProcess++;
        }
        if (innerProcess == 2) {
            swap(data[i + 1], data[high]);

            exchanges++;

            pi = (i+1);

            innerProcess++;
        }
    }
}