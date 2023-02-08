#include "../../include/Algorithms/MergeSort.hpp"

namespace Sorting {
    /**
     * @brief Resets values back to default
     * 
     */
    void MergeSort::set_default() {
        sorted = false;
        currentIndex = 0;

        process = 0;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void MergeSort::sort() {
        if (!readyToMerge) {
            // Runs mergesort recursion
            mergesort(0, length - 1);

            // Algorithm is ready to merge
            readyToMerge = true;
        }
        else {
            if (currentIndex > pointsLength)
                sorted = true;
            else {
                if (process != 4) {
                    // Read current left, mid, and right indexes at currentIndex from Points Dynamic Array
                    int leftStart = points[currentIndex].left;
                    int mid = points[currentIndex].mid;
                    int rightEnd = points[currentIndex].right;

                    // Set leftStart index to fillColor Blue to indicate left
                    data[leftStart].setFillColor(sf::Color::Blue);

                    // Set mid index to fillColor Blue to indicate mid
                    data[mid].setFillColor(sf::Color::Magenta);

                    // Set rightEnd index to fillColor Blue to indicate right
                    data[rightEnd].setFillColor(sf::Color::Red);

                    // Run merge iteration with current left, mid, and right indexes
                    merge(leftStart, mid, rightEnd);
                }
                else {
                    // Reset fillColors to White
                    for (int i = 0; i < length; i++)
                        data[i].setFillColor(sf::Color::White);
                    
                    // Increment currentIndex to continue to next iteration
                    currentIndex++;

                    // Reset process to run initial step
                    process = 0;
                }
            }
        }
        sf::sleep(sf::microseconds(5000));
    }

    /**
     * @brief Adds an new Points instance to the points dynamic array
     * 
     * @param int left index 
     * @param int mid index
     * @param int right index
     */
    void MergeSort::add_point(int l, int m, int r) {
        if (pointsLength == pointsSize) {
            // Double current Dynamic Array size to allow more points
            pointsSize = pointsSize * 2;

            // Create temporary array with new size
            Points *temp = new Points[pointsSize];

            // Copy data from current Dynamic Array to temporary Dynamic Array
            for (int i = 0; i < pointsLength; i++)
                temp[i] = points[i];
            
            // Add new Points instance to data
            temp[pointsLength].left = l;
            temp[pointsLength].mid = m;
            temp[pointsLength].right = r;

            // Increment length of dynamic array
            pointsLength++;

            delete[] points;

            // Copy temp data to points data
            points = temp;
        }
        else {
            // Add new Points instance to data
            points[pointsLength].left = l;
            points[pointsLength].mid = m;
            points[pointsLength].right = r;

            // Increment length of dynamic array
            pointsLength++;
        }
    }

    /**
     * @brief Populates Points Dynamic Array with recursion results
     * 
     * @param int left index
     * @param int right index 
     */
    void MergeSort::mergesort(int left, int right) {
        if (left < right) {
            int midIndex = left + (right - left) / 2;
            mergesort(left, midIndex);
            mergesort(midIndex + 1, right);
            add_point(left, midIndex, right); 
        }
    }

    /**
     * @brief Merges data between indexes
     * 
     * @param int left Index 
     * @param int mid Index 
     * @param int right Index 
     */
    void MergeSort::merge(int leftIndex, int midIndex, int rightIndex) {
        // Lengths of temporary arrays
        int n1 = midIndex - leftIndex + 1;
        int n2  = rightIndex - midIndex;

        // Initial Process
        if (process == 0) {
            L = new int[n1];
            R = new int[n2];

            // Copy data to temporary arrays
            for (ii = 0; ii < n1; ii++) {
                L[ii] = data[leftIndex + ii].getSize().y;

                dataAccess++;    
            }
            for (jj = 0; jj < n2; jj++) {
                R[jj] = data[midIndex + 1 + jj].getSize().y;

                dataAccess++;    
            }

            ii = 0;
            jj = 0;
            kk = leftIndex;

            // Move on to next step
            process++;
        }
        else if (process == 1) {
            if (ii < n1 && jj < n2) {

                dataAccess += 2;
                comparisons++;
            
                if (L[ii] <= R[jj]) {
                    data[kk].setFillColor(sf::Color::Yellow);
                    data[kk].setSize(sf::Vector2f(dataWidth, L[ii]));

                    exchanges++;

                    ii++;
                }
                else {
                    data[kk].setFillColor(sf::Color::Yellow);
                    data[kk].setSize(sf::Vector2f(dataWidth, R[jj]));

                    exchanges++;

                    jj++;
                }
                kk++;
            }
            else {
                // Move on to next step
                process++;
            }
        }
        else if (process == 2) {
            if (ii < n1) {
                data[kk].setFillColor(sf::Color::Yellow);
                data[kk].setSize(sf::Vector2f(dataWidth, L[ii]));

                exchanges++;

                ii++;
                kk++;
            }
            else {
                // Move on to next step
                process++;
            }
        }
        else if (process == 3) {
            if (jj < n2) {
                data[kk].setFillColor(sf::Color::Yellow);
                data[kk].setSize(sf::Vector2f(dataWidth, R[jj]));

                exchanges++;

                jj++;
                kk++;
            }
            else {
                // Move on to next step
                process++;
            }
        }
    }

}