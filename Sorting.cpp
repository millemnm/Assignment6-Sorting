#include "Sorting.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

Sorting::Sorting(){
	size = 0;
}
Sorting::~Sorting(){
	delete[] bubble;
	delete[] selection;
	delete[] insertion;
	delete[] quick;
	delete[] merge;
}

void Sorting::readFile(){
	std::ifstream file;
	std::string fileName;
	std::cout << "What is the name of the text file? " << '\n';
	while(true){
		file.close();
    	file.clear();
		getline(std::cin, fileName); //get the file name from terminal
		file.open(fileName.c_str()); //open the file
		if(file){
			break;
		}
		std::cout << "Invalid file name, please enter a valid file name: " << '\n';
	}

	if (file.is_open()) {
	    std::string line;
		int i = 0;
	    while (getline(file, line)) {
			if(size == 0){
				size = stoi(line);
				bubble = new double[size];
				selection = new double[size];
				insertion = new double[size];
				quick = new double[size];
				merge = new double[size];
			}else{
				double temp = stod(line);
				bubble[i] = temp;
				selection[i] = temp;
				insertion[i] = temp;
				quick[i] = temp;
				merge[i] = temp;
				i++;
			}
	    }
	    file.close();
	}
}

void Sorting::randStart(int n){
	size = n;
	bubble = new double[size];
	selection = new double[size];
	insertion = new double[size];
	quick = new double[size];
	merge = new double[size];

	for(int i = 0; i < size; ++i){
		bubble[i] = rand() % 100000;
		selection[i] = rand() % 100000;
		insertion[i] = rand() % 100000;
		quick[i] = rand() % 100000;
		merge[i] = rand() % 100000;
	}
	// std::cout << "UNSORTED:" << '\n';
	// printArray(1);
}

void Sorting::bubbleSort(){ // bubble
	for(int i = 0; i<size-1; ++i){
		double temp = 0.0;
		for(int j = 0; j < size-i-1; ++j){
			if(bubble[j] > bubble[j+1]){
				temp = bubble[j+1];
				bubble[j+1] = bubble[j];
				bubble[j] = temp;
			}
		}
	}
	// std::cout << "BUBBLE SORT:" << '\n';
	// printArray(1);
}

void Sorting::selectionSort(){ // selection
	int i, j, minindex;
	double tmp;

	for(i = 0; i < size-1; i++){
		minindex = i;

		for(j = i+1; j < size; j++){
			if(selection[j] < selection[minindex]){
				minindex = j;
			}
		}

		if(minindex != i){
			tmp = selection[i];
			selection[i] = selection[minindex];
			selection[minindex] = tmp;
		}
	}
	// std::cout << "SELECTION SORT:" << '\n';
	// printArray(2);
}

void Sorting::insertionSort(){ // insertion
	for(int j = 1; j < size; ++j){
		double temp = insertion[j];
		int k = j;
		while(k>0 && insertion[k-1]>=temp){
			insertion[k] = insertion[k-1];
			--k;
		}
		insertion[k] = temp;
	}
	// std::cout << "INSERTION SORT:" << '\n';
	// printArray(3);
}

void Sorting::quickSort(){
	quickSort(0, size-1);
	// std::cout << "QUICK SORT:" << '\n';
	// printArray(4);
}

void Sorting::quickSort(int start, int end){ // quick
	if(start < end){
		int piv = partition(start, end);

		quickSort(start, piv-1);
		quickSort(piv+1, end);
	}
}

int Sorting::partition(int start, int end){
	double piv = quick[end]; // pivot
	int x = (start - 1); // index of smaller element

	for(int y = start; y <= end-1; y++){
		if(quick[y] <= piv){
			x++;
			double temp = quick[x];
			quick[x] = quick[y];
			quick[y] = temp;
		}
	}

	double temp = quick[x+1];
	quick[x+1] = quick[end];
	quick[end] = temp;

	return (x+1);
}

void Sorting::mergeSort(){
	mergeSort(0, size-1);
	// std::cout << "MERGE SORT:" << '\n';
	// printArray(5);
}

void Sorting::mergeSort(int start, int end){
	if(start < end){
		int middle = start + ((end - start) / 2);

		mergeSort(start, middle);
		mergeSort(middle+1, end);

		merger(start, middle, end);
	}
}

void Sorting::merger(int start, int middle, int end){ // merge
	int frontSize = middle - start + 1; // find the size of the first half
	int backSize = end - middle; // find the size of the second half

	// temporary arrays:
	double front[frontSize];
	double back[backSize];

	//split data from large array into the temp arrays
	for(int x = 0; x < frontSize; ++x){
		front[x] = merge[start + x];
	}
	for(int y = 0; y < backSize; ++y){
		back[y] = merge[middle + y + 1];
	}


	int i = 0; // index to keep within the bounds of front
	int j = 0; // index to keep within the bounds of back
	int k = start; // index to keep within the larger subarray
	while(i < frontSize && j < backSize){
		if(front[i] <= back[j]){
			merge[k] = front[i];
			i++;
		}else{
			merge[k] = back[j];
			j++;
		}
		k++;
	}

	//insert remaining data from the front into merge
	while(i < frontSize){
		merge[k] = front[i];
		++i;
		++k;
	}
	//insert remaining data from the back into merge
	while(j < backSize){
		merge[k] = back[j];
		++j;
		++k;
	}

}

void Sorting::printArray(int u){
	double *arr;
	if(u == 1){
		arr = bubble;
	}else if(u == 2){
		arr = selection;
	}else if(u == 3){
		arr = insertion;
	}else if(u == 4){
		arr = quick;
	}else{
		arr = merge;
	}


	for(int i = 0; i < size; ++i){
		if(i != 0){
			std::cout << ", ";
		}
		std::cout << arr[i];
	}
	std::cout << '\n' << '\n';
}

bool Sorting::sorted(int u){
	double *arr;
	if(u == 1){
		arr = bubble;
	}else if(u == 2){
		arr = selection;
	}else if(u == 3){
		arr = insertion;
	}else if(u == 4){
		arr = quick;
	}else{
		arr = merge;
	}

	for(int i = 0; i < size-1; ++i){
		if(arr[i] > arr[i+1]){
			return false;
		}
	}
	return true;
}
