CXX = g++
LIB_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = include/
SRC = src/
ALGO_SRC_DIR = $(SRC)Algorithms/
ALGO_INCLUDE_DIR = $(INCLUDE)Algorithms/
ALGO_FILES = $(ALGO_SRC_DIR)SortingAlgorithm.cpp $(ALGO_SRC_DIR)SelectionSort.cpp $(ALGO_SRC_DIR)BubbleSort.cpp $(ALGO_SRC_DIR)InsertionSort.cpp $(ALGO_SRC_DIR)MergeSort.cpp $(ALGO_SRC_DIR)HeapSort.cpp $(ALGO_SRC_DIR)QuickSort.cpp $(SRC)SortingAlgorithms.cpp
ALGO_OBJ = SortingAlgorithm.o SelectionSort.o BubbleSort.o InsertionSort.o MergeSort.o HeapSort.o QuickSort.o SortingAlgorithms.o

output: Main.o $(ALGO_OBJ)
	$(CXX) Main.o $(ALGO_OBJ) -o output $(LIB_FLAGS)

Main.o: Main.cpp
	$(CXX) -c Main.cpp

SortingAlgorithms.o: $(SRC)SortingAlgorithms.cpp $(INCLUDE)SortingAlgorithms.hpp
	$(CXX) -c $(SRC)SortingAlgorithms.cpp

QuickSort.o: $(ALGO_SRC_DIR)QuickSort.cpp $(ALGO_INCLUDE_DIR)QuickSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)QuickSort.cpp

HeapSort.o: $(ALGO_SRC_DIR)HeapSort.cpp $(ALGO_INCLUDE_DIR)HeapSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)HeapSort.cpp

MergeSort.o: $(ALGO_SRC_DIR)MergeSort.cpp $(ALGO_INCLUDE_DIR)MergeSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)MergeSort.cpp

InsertionSort.o: $(ALGO_SRC_DIR)InsertionSort.cpp $(ALGO_INCLUDE_DIR)InsertionSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)InsertionSort.cpp

BubbleSort.o: $(ALGO_SRC_DIR)BubbleSort.cpp $(ALGO_INCLUDE_DIR)BubbleSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)BubbleSort.cpp

SelectionSort.o: $(ALGO_SRC_DIR)SelectionSort.cpp $(ALGO_INCLUDE_DIR)SelectionSort.hpp
	$(CXX) -c $(ALGO_SRC_DIR)SelectionSort.cpp

SortingAlgorithm.o: $(ALGO_SRC_DIR)SortingAlgorithm.cpp $(ALGO_INCLUDE_DIR)SortingAlgorithm.hpp
	$(CXX) -c $(ALGO_SRC_DIR)SortingAlgorithm.cpp

clean:
	rm *.o output