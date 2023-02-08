#include "../../include/Algorithms/SelectionSort.hpp"

namespace Sorting {

    /**
     * @brief Resets values back to default
     * 
     */
    void SelectionSort::set_default() {
        sorted = false;
        currentIndex = 0;

        elapsed = currentIndex + 1;
        minIndex = currentIndex;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void SelectionSort::sort() {
        if (currentIndex == length)
            sorted = true;
        else
            if (elapsed < length) {
                // Set currentIndex (current minimim index) to fillColor Blue
                data[currentIndex].setFillColor(sf::Color::Blue);

                // Set elapsed index fillColor Yellow to indicate compared to currentIndex  
                data[elapsed].setFillColor(sf::Color::Yellow);

                // Read height values at minIndex and elapsed index
                int height = data[elapsed].getSize().y;
                int min = data[minIndex].getSize().y;

                dataAccess += 2;
                comparisons++;

                if (height < min) {
                    // Reset fillColor(s) to White
                    for (int i = currentIndex; i < length; i++)
                        data[i].setFillColor(sf::Color::White);
                    
                    // Reset minimumIndex fillColor to White
                    data[minIndex].setFillColor(sf::Color::White);

                    // Change elapsed index to fillColor Red (indicates new minimum index found)
                    data[elapsed].setFillColor(sf::Color::Red);

                    // Update current Minimum index
                    minIndex = elapsed;
                }
                
                // Increment elapsed index to move to next iteration (step)
                elapsed++;
            }
            else {

                // Swap currentIndex and minimum index heights
                swap(data[currentIndex], data[minIndex]);

                exchanges++;

                // Set currentIndex fillColor back to White as it is sorted
                data[currentIndex].setFillColor(sf::Color::White);

                // Increment currentIndex to proceed to next iteration
                currentIndex++;

                // Reset elapsed to next iteration
                elapsed = currentIndex + 1;
            }
    }
}