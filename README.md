# Sorting Algorithm Visualizer
A C++ Application that visualizes a few Sorting Algorithms, using SFML:
> A Simple and Fast Multimedia Library ([SFML](https://www.sfml-dev.org/)) is a cross-platform software development library designed to provide a simple 
> application programming interface to various multimedia components in computers.

To Install visit: https://www.sfml-dev.org/download/sfml/2.5.1/

## Algorithms
### Selection Sort
**Description:** The algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n<sup>2</sup>)    |   O(n<sup>2</sup>)    |   O(n<sup>2</sup>)    |

### Bubble Sort
**Description:** The algorithm works by repeatedly swapping the adjacent elements if they are in wrong order.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n<sup>2</sup>)    |   O(n<sup>2</sup>)    |   O(n)                |

### Insertion Sort
**Description:** The algorithm works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n<sup>2</sup>)    |   O(n<sup>2</sup>)    |   O(n)                |

### Merge Sort
**Description:** The algorithm is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n log n)          |   O(n log n)          |   O(n log n)          |

### Heap Sort
**Description:** The algorithm is a comparison-based sorting techique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n log n)          |   O(n log n)          |   O(n log n)          |

### Quick Sort
**Description:** The algorithm is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
**Time Complexity:**
|   Worst-Case          |   Average-Case        |   Best-Case           |
|   :---:               |   :---:               |   :---:               |
|   O(n<sup>2</sup>)    |   O(n log n)          |   O(n log n)          |

## Controls
- <kbd>Space</kbd>: Restart Algorithm from beginning
- <kbd>Tab</kbd>: Switch to next Algorithm