#include <iostream>
#include <vector>
using namespace std;


/*
*******************************
Merge sort Algorithm
This is another Divide and Conquer Algorithm, it breaks the 
data in two halves and keeps on breaking until it arrives at 
two pairs of values which it sorts, then it merges the halves
back sorting at each step until it arrives at the full array.

We would use two functions to implement this:
1. A merge function that does the merging
2. The merge sort function that calls itself recursively 
   and also calls the merge each time.
*******************************
*/


void merge(int arr[], int l, int m, int r)
{
    //We are using the 2 pointer approach
    int i=l; //starting index for left subarray
    int j=m+1; //starting index for right subarray
    int k=l;  //starting index for result temporary vector (not needed in a vector)

    //int* temp = new int[(l-r) + 1]; //we create a temp array that'll fit the element size 
    std::vector <int> temp; //temp vector;

    while(i<=m && j <=r) //Bounds the iteration
    {
        if(arr[i] <= arr[j]) //arr[i] is smaller
        {
            //temp[k] = arr[i];
            temp.push_back(arr[i]);  
            i++; //we can't compare the left value again  
        }
        else //arr[j] is smaller
        {
            //temp[k] = arr[j];
            temp.push_back(arr[j]); 
            j++;
        } 
        //k++; //we move to next position in array/vector   
    }

    //When split arrays are not equal, and the arrays have unaccessed elements
    while(i<=m)
    {
        //copying all remaining elements in left array
        //temp[k] = arr[i]; 
        temp.push_back(arr[i]); 
        i++;
        //k++;
    }

    while(j<=r)
    {
        //copying all remaining elements in right array
        //temp[k] = arr[j]; 
        temp.push_back(arr[j]); 
        j++;
        //k++;
    }

    //copy elements from temp vector to original array
    for(int s=l; s <= r; s++) 
    {
        arr[s] = temp[s-l]; //s-l gives the index for the function stack local vector
    }
}


//merge sort function
void mergeSort(int arr[], int begin, int end)
{
    if(begin < end) //This is False if the array has one element (Splitting is complete)
    {
        int m = (begin + end)/2; //midpoint

        mergeSort(arr,begin,m); //sort the left side of each split

        mergeSort(arr,m+1, end); //sort the right side of each split

        merge(arr,begin,m,end);
    }

}



int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin>>size;

    cout << "Enter "<<size<< " no of elements of the array: " << endl;

    int * myarr = new int(size);
    //cout << "Please enter 5 values to be sorted: " <<endl;
    for(int i=0; i<size; i++)
    {
        cin >> myarr[i];

    }
    cout << "Before Merge Sort: ";
    for(int i=0; i<size; i++)
    {
        cout << myarr[i] << " " ;
    }

    //mergesort function
    mergeSort(myarr, 0, (size-1));

    cout << endl << "After Merge Sort: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout << myarr[i] << " ";
    }



    delete [] myarr;
    return 0;
}