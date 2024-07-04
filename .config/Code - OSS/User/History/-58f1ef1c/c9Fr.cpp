#include <iostream>
#include <random>
#include <string>
#include <array>
#include <algorithm>
using namespace std;




//-------------------------------------- MERGE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

void Merge(int left[],int right[],int(&numbers)[]){
    float leftSize = numbers[].length() / 2;
    int rightSize = numbers.length() - leftSize;

    int l,r,i = 0;

    while (l < leftSize && r < rightSize){
        if (left[l] < right[r]){
            numbers[i] = left[l];
            l++;
            i++;
        }
        else{
            numbers[i] = right[r];
            i++;
            r++;
        }
    }
    while(l < leftSize){
        numbers[i] = leftSize[l];
        l++;
        i++;
    }
        while(r < rightSize){
        numbers[i] = rightSize[r];
        r++;
        i++;
    }
}

void mergeSort(int(&numbers)[]) {
    int length = numbers[].length();
    if (length <= 1){
        return;
    }
    
    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    int i = 0;
    int j = 0;

    for (; i < length;i++){
        if (i<mid){
            left[i] = numbers[i];
        }
        else{
            right[j] = numbers[i];
            j++;
        }
    }

    mergeSort(left);
    mergeSort(right);
    Merge(left,right,numbers);

}



//-----------------------------------------------------------------------------------------//
//---------------------------------------- M A I N ----------------------------------------//
//-----------------------------------------------------------------------------------------//

//this is the main function where we create our list of numbers and call functions to sort it 

int main() {

    int numbers[] = {12,2,34,2,1,67,8,9};

    mergeSort(numbers);
    print(numbers);

}