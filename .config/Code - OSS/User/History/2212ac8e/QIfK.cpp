#include <iostream>
#include <random>
#include <string>
#include <array>
#include <algorithm>
#include <memory>
#include <chrono>
using namespace std;

/*
notes
○ Bubble Sort       (functional)
○ Selection Sort    (functional)  
○ Insertion Sort    (functional)
○ Merge Sort        (functional)
○ Quick Sort        (functional) 
○ Heap Sort         (functional)  
○ Radix Sort 
○ Shell Sort        (functional)
*/

//------------------------------------- ARRAY-SIZE ----------------------------------------//

//this determines the length of our list of numbers
double range;
double latency = 0;

//--------------------------- GENERATION-PRINTING-CALCULATION -----------------------------//
//-----------------------------------------------------------------------------------------//

//this function generates random numbers in the specified range

double randomnum() {
    random_device rand;
    uniform_int_distribution<double> num(0,range);
    return num(rand);
}

//this is a simple function to print our numbers in order
void print(double(&numbers)[]) {    
    for(double i=0 ; i<range ; i++) {
        cout << numbers[i] << " ";
    }
}

//this class will calculate the latency of a certain code block
class Timer {
	public:
		Timer() {
			starttime = std::chrono::high_resolution_clock::now();
		}
		~Timer() {
			stop();
		}
		void stop() {
			auto stoptime = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(starttime).time_since_epoch().count();
			auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(stoptime).time_since_epoch().count();
			auto duration = stop - start;
			//cout << "latency of the selected sorting function was: " << duration << " microseconds";
            latency = duration;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> starttime;
};

//------------------------------------- BUBBLE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//first version of bubble sort function

void bubblesort(double(&numbers)[]) {

    while(1) {
        double counter = 1;
        for(double i=0 ; i<(range-1) ; i++) {
            if(numbers[i]>numbers[i+1]) {
                double temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                counter = 0;
            }
        }
        if (counter) break;
    }
}

//------------------------------------ SELECTION-SORT -------------------------------------//
//-----------------------------------------------------------------------------------------//

//first selection sort algorithm implementation

void selectionsort(double(&numbers)[]) {
    for(double i=0 ; i<(range-1) ; i++) {
        double min = i;
        for(double j=i ; j<(range) ; j++) {
            if(numbers[j]<numbers[min]) {
                min = j;
            }
        }
        double temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
}

//------------------------------------ INSERTION-SORT -------------------------------------//
//-----------------------------------------------------------------------------------------//

//insertion sort is functiolan

void insertionsort(double(&numbers)[]) {
    for(double i=1 ; i<range ; i++) {
        double index = i;
        while((index-1) >= 0 && numbers[index] < numbers[index-1]) {
            double temp = numbers[index];
            numbers[index] = numbers[index-1];
            numbers[index-1] = temp;
            index--;
        }
        i = index;
    }
}

//-------------------------------------- MERGE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

void Merge(double left[], double leftSize, double right[], double rightSize, double numbers[], double totalSize) {
    double l = 0, r = 0, i = 0;

    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            numbers[i++] = left[l++];
        } else {
            numbers[i++] = right[r++];
        }
    }

    while (l < leftSize) {
        numbers[i++] = left[l++];
    }

    while (r < rightSize) {
        numbers[i++] = right[r++];
    }
}

void mergeSort(double numbers[], double length) {
    if (length <= 1) {
        return;
    }

    double mid = length / 2;
    double left[mid];
    double right[length - mid];

    for (double i = 0; i < mid; i++) {
        left[i] = numbers[i];
    }
    for (double i = mid; i < length; i++) {
        right[i - mid] = numbers[i];
    }

    mergeSort(left, mid);
    mergeSort(right, length - mid);
    Merge(left, mid, right, length - mid, numbers, length);
}

//-------------------------------------- QUICK-SORT ----------------------------------------//
//-----------------------------------------------------------------------------------------//

double partition(double numbers[], double low, double high) {
    double pivot = numbers[high];
    double i = low - 1;

    for (double j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            double temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }
    double temp = numbers[i + 1];
    numbers[i + 1] = numbers[high];
    numbers[high] = temp;
    return (i + 1);
}

void quickSort(double numbers[], double low, double high) {
    if (low < high) {
        double pi = partition(numbers, low, high);

        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }
}

//--------------------------------------- HEAP-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//first version of heapsort

void heap(double numbers[], double n, double i) {
    double root = i;
    double l = 2 * i + 1;
    double r = 2 * i + 2;
    if (l < n && numbers[l] > numbers[root]){
        root = l;
    }
    if (r < n && numbers[r] > numbers[root]){
        root = r;
    }
    if (root != i) {
        swap(numbers[i], numbers[root]);
        heap(numbers, n, root);
    }
}
void heapSort(double(&numbers)[]) {
    for (double i = range / 2 - 1 ; i >= 0; i--) {
        heap(numbers, range, i);
    }
    for (double i = range - 1; i > 0; i--) {
        swap(numbers[0], numbers[i]);
        heap(numbers, i, 0);
    }
}

//-------------------------------------- SHELL-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//shell sort function done

void shellSort(double(&numbers)[]) {
	for (double n = range/2; n > 0; n /= 2) {
		for (double i = n; i < range; i += 1) {
			double temp = numbers[i];
			double j;		 
			for (j = i; j >= n && numbers[j - n] > temp; j -= n) {
				numbers[j] = numbers[j - n];
            }
			numbers[j] = temp;
		}
	}
}

//-----------------------------------------------------------------------------------------//
//---------------------------------------- M A I N ----------------------------------------//
//-----------------------------------------------------------------------------------------//

//this is the main function where we create our list of numbers and call functions to sort it 

double main() {

    

    cout << "welcome\nenter your preferred size for the dataset: ";
    double size;
    cin >> size;
    range = size;
    double numbers[range];
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }

    {
        Timer timer;
        bubblesort(numbers);     
    }
    cout << "the latency of bubble sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        selectionsort(numbers); 
    }
    cout << "the latency of selection sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        insertionsort(numbers);
    }
    cout << "the latency of insertion sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        heapSort(numbers);
    
    }
    cout << "the latency of heap sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        shellSort(numbers);
    
    }
    cout << "the latency of shell sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        mergeSort(numbers, range);  
    }
    cout << "the latency of merge sorting function was: "<<latency<<" microseconds" << endl;
    for(double i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    {
        Timer timer;
        quickSort(numbers, 0, range - 1);      
    }
    cout << "the latency of quick sorting function was: "<<latency<<" microseconds" << endl;
    return 0;
}

