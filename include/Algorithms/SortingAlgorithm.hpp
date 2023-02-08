#ifndef SORTINGALGORITHM_HPP
#define SORTINGALGORITHM_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#define WIDTH 1200
#define HEIGHT 700
#define LENGTH 400

namespace Sorting {
    /**
     * @brief Parent class for Sorting Algorithms
     * 
     */
    class SortingAlgorithm {
        public:
            // Default Constructor
            SortingAlgorithm() = default;

            /**
             * @brief Construct a new Sorting Algorithm object.
             * 
             * @param int Length of data 
             * @param int Beginning Index of algorithm 
             */
            SortingAlgorithm(int len, int i = 0) : length(len), dataWidth(WIDTH/len), currentIndex(i) {                
                comparisons = 0;
                exchanges = 0;
                dataAccess = 0;
                generate_data();
            }

            /**
             * @brief Destroy the Sorting Algorithm object.
             * 
             */
            ~SortingAlgorithm() {
                delete[] data;
            }

            // Updates Scene
            void update();

            // Render cycle
            void render(sf::RenderWindow&);

            // Restarts Algorithm from beginning
            void restart();

            // Returns if data is sorted
            bool is_sorted();

        protected:
            sf::RectangleShape* data;
            int length;                 // Length of data  
            int dataWidth;              // Width of each rectangle
            int currentIndex;           // Current Rectangle in iteration
            
            bool sorted;
            
            int comparisons;    // # of comparions made in algorithm
            int exchanges;      // # of exchanges made in algorithm
            int dataAccess;     // # of data access made in algorithm

            std::string name;   // Algorithm name

            virtual void sort() = 0;
            virtual void set_default() = 0;

            // Populates data with random (non-repetitive) values
            void generate_data();

            // Swap heights between data
            void swap(sf::RectangleShape&, sf::RectangleShape&);

            // Change all data fillColor to Green to show sorted
            void complete();

            // Draw Text onto Screen
            void draw_info(sf::RenderWindow&);
    };
}

#endif