#include <iostream>
using namespace std;

void Merge(int left[], int leftSize, int right[], int rightSize, int numbers[]) {
    int i = 0, l = 0, r = 0;

    // Merge the two subarrays back into numbers
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            numbers[i++] = left[l++];
        } else {
            numbers[i++] = right[r++];
        }
    }
    // Copy the remaining elements of left[], if there are any
    while (l < leftSize) {
        numbers[i++] = left[l++];
    }
    // Copy the remaining elements of right[], if there are any
    while (r < rightSize) {
        numbers[i++] = right[r++];
    }
}

void mergeSort(int numbers[], int length) {
    if (length <= 1) {
        return;
    }

    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < mid; i++) {
        left[i] = numbers[i];
    }
    for (int i = mid; i < length; i++) {
        right[i - mid] = numbers[i];
    }

    // Recursively sort the two halves
    mergeSort(left, mid);
    mergeSort(right, length - mid);

    // Merge the sorted halves
    Merge(left, mid, right, length - mid, numbers);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {12, 2, 34, 2, 1, 67, 8, 9};
    int arr_size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Unsorted array: ";
    printArray(numbers, arr_size);

    mergeSort(numbers, arr_size);

    cout << "Sorted array: ";
    printArray(numbers, arr_size);

    return 0;
}
