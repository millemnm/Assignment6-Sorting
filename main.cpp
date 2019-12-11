#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[]) {
	Sorting sorter;
	sorter.readFile();

	//run the sorting algorithms
	//create timestamps in between each algorithm
	auto StartBub = high_resolution_clock::now();
	sorter.bubbleSort();
	auto BubSel = high_resolution_clock::now();
	sorter.selectionSort();
	auto SelIns = high_resolution_clock::now();
	sorter.insertionSort();
	auto InsQui = high_resolution_clock::now();
	sorter.quickSort();
	auto QuiMer = high_resolution_clock::now();
	sorter.mergeSort();
	auto MerEnd = high_resolution_clock::now();

	auto bubble = duration_cast<microseconds>(BubSel - StartBub);
	auto selection = duration_cast<microseconds>(SelIns - BubSel);
	auto insertion = duration_cast<microseconds>(InsQui - SelIns);
	auto quick = duration_cast<microseconds>(QuiMer - InsQui);
	auto merge = duration_cast<microseconds>(MerEnd - QuiMer);

	//check if each algorithm was sorted properly sorted before printing runtime:
	std::cout << "Sorting Algorithm Run Times:" << '\n';
	//BUBBLE SORT
	if(sorter.sorted(1)){
		std::cout << "Bubble Sort:      " << bubble.count() << " microseconds" << '\n';
	}else{
		std::cout << "Bubble Sort:      ERROR: Not properly sorted!" << '\n';
	}
	//SELECTION SORT
	if(sorter.sorted(2)){
		std::cout << "Selection Sort:   " << selection.count() << " microseconds" << '\n';
	}else{
		std::cout << "Selection Sort:   ERROR: Not properly sorted!" << '\n';
	}
	//INSERTION SORT
	if(sorter.sorted(3)){
		std::cout << "Insertion Sort:   " << insertion.count() << " microseconds" << '\n';
	}else{
		std::cout << "Insertion Sort:   ERROR: Not properly sorted!" << '\n';
	}
	//QUICK SORT
	if(sorter.sorted(4)){
		std::cout << "Quick Sort:       " << quick.count() << " microseconds" << '\n';
	}else{
		std::cout << "Quick Sort:       ERROR: Not properly sorted!" << '\n';
	}
	//MERGE SORT
	if(sorter.sorted(5)){
		std::cout << "Merge Sort:       " << merge.count() << " microseconds" << '\n';
	}else{
		std::cout << "Merge Sort:      ERROR: Not properly sorted!" << '\n';
	}
};
