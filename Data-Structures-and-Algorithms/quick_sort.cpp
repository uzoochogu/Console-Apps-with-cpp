#include <iostream>


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


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


//The partition function
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    //Finding the correct position of the pivot
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    //Give pivot element the correct position
    int pivotIndex = start + count;
    swap(&arr[pivotIndex], &arr[start]);

    /* Sorting the left and right parts of the pivot elements
    it swaps once it meets an element on the left greater than pivot
    and on the right less than pivot
    */
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j++;
        }
        if(i < pivotIndex && j > pivotIndex)
        {
            swap(&arr[i++], &arr[j--]);
        }
    }
    return pivotIndex;
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

    //Print out the array
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}