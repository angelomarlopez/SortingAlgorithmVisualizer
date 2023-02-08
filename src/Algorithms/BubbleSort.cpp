#include "../../include/Algorithms/BubbleSort.hpp"

namespace Sorting {
    /**
     * @brief Resets values back to default
     * 
     */
    void BubbleSort::set_default() {
        sorted = false;
        currentIndex = 0;

        elapsed = 0;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void BubbleSort::sort() {
        if (currentIndex == length) {
            sorted = true;
        }
        else {
            if (elapsed < (length - currentIndex - 1)) {
                // Set elapsed index to Yellow to indicate compared index
                data[elapsed].setFillColor(sf::Color::Yellow);

                // Set next elapsed index to Red to indicate current largest value
                data[elapsed + 1].setFillColor(sf::Color::Red);

                // Read height values at current elapsed index and next elapsed index
                int dataA = data[elapsed].getSize().y;
                int dataB = data[elapsed + 1].getSize().y;

                dataAccess += 2;
                comparisons++;

                if (dataA > dataB) {
                    exchanges++;
                    
                    // Swap current elapsed index and next elapsed index heights
                    swap(data[elapsed], data[elapsed + 1]);
                    
                }

                // Increment elapsed index for next iteration
                elapsed++;
            }
            else {
                // Reset fillColor to White
                for (int i = 0; i < elapsed + 1; i++)
                    data[i].setFillColor(sf::Color::White);

                // Increment currentIndex to proceed to next iteration
                currentIndex++;

                // Reset elapsed for next iteration
                elapsed = 0;
            }
        }
    }
}