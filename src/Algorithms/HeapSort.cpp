#include "../../include/Algorithms/HeapSort.hpp"

namespace Sorting {
    /**
     * @brief Resets values back to default
     * 
     */
    void HeapSort::set_default() {
        sorted = false;
        process = 0;

        currentIndex = length / 2 - 1;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void HeapSort::sort() {
        if (process == 2) {
            sorted = true;
        }
        else if (process == 0) {
            if (currentIndex >= 0) {
                heapify(length, currentIndex);
                currentIndex--;
            } 
            else {
                process++;
                currentIndex = length - 1;
            }
        }
        else if (process == 1) {
            if (currentIndex >= 0) {
                swap(data[0], data[currentIndex]);

                exchanges++;

                heapify(currentIndex, 0);
                currentIndex--;
            }
            else {
                process++;
                currentIndex = length;
            }
        }
        sf::sleep(sf::milliseconds(10));
    }

    /**
     * @brief  Convert data between indexes to a Heap Structure
     * 
     * @param int Length of Sub-Tree
     * @param int Index of root element
     */
    void HeapSort::heapify(int n, int i) {
        // Find largest among root, left child and right child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left].getSize().y > data[largest].getSize().y){
            largest = left;

            dataAccess += 2;
            comparisons++;
        }

        if (right < n && data[right].getSize().y > data[largest].getSize().y) {
            largest = right;

            dataAccess += 2;    
            comparisons++;
        }
        
        // Swap and continue heapifying if root is not largest
        if (largest != i) {
            swap(data[i], data[largest]);

            exchanges++;

            heapify(n, largest);
        }
    }
}