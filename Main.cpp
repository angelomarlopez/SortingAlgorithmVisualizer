#include <SFML/Graphics.hpp>

#include "include/SortingAlgorithms.hpp"

int main() {
    // Creates style for window
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;

    // Creates Window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithm Visualizer", style);

    // Current Algorithm running
    Sorting::Algorithms current = Sorting::SELECTIONSORT;
    Sorting::SortingAlgorithm* currentAlgorithm = new Sorting::SelectionSort(LENGTH);

    // Game Loop
    while (window.isOpen()) {

        // Handle Events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    // Press Space to Restart Algorithm from beginning
                    if (event.key.code == sf::Keyboard::Space){
                        currentAlgorithm->restart();
                    }
                    // Press Tab to visualize the next algorithm
                    else if (event.key.code == sf::Keyboard::Tab){
                        current = static_cast<Sorting::Algorithms>((current + 1) % Sorting::NUM_OF_ALGORITHMS);
                        delete currentAlgorithm;
                        switch (current)
                        {
                            case Sorting::SELECTIONSORT:
                                currentAlgorithm = new Sorting::SelectionSort(LENGTH);
                                break;
                            case Sorting::BUBBLESORT:
                                currentAlgorithm = new Sorting::BubbleSort(LENGTH);
                                break;
                            case Sorting::INSERTIONSORT:
                                currentAlgorithm = new Sorting::InsertionSort(LENGTH);
                                break;
                            case Sorting::MERGESORT:
                                currentAlgorithm = new Sorting::MergeSort(LENGTH);
                                break;
                            case Sorting::HEAPSORT:
                                currentAlgorithm = new Sorting::HeapSort(LENGTH);
                                break;
                            case Sorting::QUICKSORT:
                                currentAlgorithm = new Sorting::QuickSort(LENGTH);
                                break;
                            default:
                                break;
                        }
                    }
                default:
                    break;
            }
        }
        
        // Update Scene
        currentAlgorithm->update();

        // Render Cycle
        currentAlgorithm->render(window);

        window.display();
    }

    return 0;
}