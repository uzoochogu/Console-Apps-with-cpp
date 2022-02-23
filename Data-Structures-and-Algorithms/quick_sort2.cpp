#include <iostream>
//using namespace std;

/*
**********************************************
 The Quick Sort algorithm is a Divide and Conquer algorithm.
 It initially selects an element as a pivot element and partitions the given array 
 around the picked pivot. Here we always pick the first element as the pivot.

 The partition() process is the key process. It's aim is to receive 
 an array, and a pivot element eg x.
 x is put in the correct position in the sorted array and all elements smaller are 
 put before x, all elements greater are put after x. 


**********************************************
*/


/* // A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
} */


//The partition function
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}


//Recursive function to Divide and Conquer
void quickSort(int arr[], int start, int end)
{
    //base case
    if(start >= end)
        return;

    //partitioning the array
    int p = partition(arr, start, end);

    //sorting the left part
    quickSort(arr, start, p - 1);

    //sorting the right part
    quickSort(arr, p + 1, end);
    
}


int main()
{
    //Testing the algorithm

    int arr[] = {74, 49, 32, 100, 45, 75, 68, 29, 90, 40, 36, 229};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    //print out the array
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}