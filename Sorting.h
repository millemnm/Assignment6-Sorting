#ifndef SORTING
#define SORTING

class Sorting
{
public:
	Sorting();
	~Sorting();

	void readFile();
	void randStart(int n);

	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void quickSort();
	void mergeSort();

	void printArray(int u);
	bool sorted(int u);

private:
	int size;
	double *bubble;
	double *selection;
	double *insertion;
	double *quick;
	double *merge;

	//part of quick sort (unsorted4):
	void quickSort(int start, int end);
	int partition(int start, int end);

	//part of merge sort (unsorted5):
	void mergeSort(int start, int end);
	void merger(int start, int middle, int end);
};

#endif
