#include "../../include/Algorithms/InsertionSort.hpp"

namespace Sorting {
    
    /**
     * @brief Resets values back to default
     * 
     */
    void InsertionSort::set_default() {
        sorted = false;
        currentIndex = 1;

        process = 0;

        comparisons = dataAccess = exchanges = 0;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void InsertionSort::sort() {
        if (currentIndex == length){
            sorted = true;
        }
        else {
            // Sets  currentIndex to fillColor Blue to indicate anythgin before it is sorted
            data[currentIndex].setFillColor(sf::Color::Blue);

            // Initial Algorithm set up
            if (process == 0) {
                // Read height of currentIndex to set as key value
                key = data[currentIndex].getSize().y;

                dataAccess++;

                // Set elapsed to the previous index of currentIndex
                elapsed = currentIndex - 1;

                // Increment process to move to the next step
                process++;
            }

            comparisons++;
            dataAccess++;

            if (key < data[elapsed].getSize().y && elapsed >= 0) {
                // Set elapsed index to fillColor Red to indicate compared
                data[elapsed].setFillColor(sf::Color::Red);

                // Set next elapsed index to elapsed index height
                data[elapsed + 1].setSize(sf::Vector2f(
                    dataWidth,
                    data[elapsed].getSize().y
                ));

                exchanges++;

                // Decrement elapsed to continue to next iteration
                elapsed--;
            } else {
                // Reset fillColor to White
                for (int i = currentIndex; i > elapsed; i--)
                    data[i].setFillColor(sf::Color::White);
                
                // Set next elapsed index height to the key value
                data[elapsed + 1].setSize(sf::Vector2f(
                    dataWidth,
                    key
                ));

                exchanges++;

                // Increment currentIndex to continue to next iteration
                currentIndex++;

                // Reset process to run initial step
                process = 0;
            }
        }
    }
}