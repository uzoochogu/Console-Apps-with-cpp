#include <iostream>
using namespace std;

/*
***************************************
Radix Sort
It is useful because in counting sort, the range of values can get 
very large quickly because of the elements the array contains.
For small arrays with wide range of values, the counting sort is not
very space inefficient.Radix sort solves this. It applies this counting sort 
strategy per digit starting from the least significant digit.

Time Complexity: O d(n+K)
Space Complexity: O(n+k) 

where:
k=range of values
d = number of digits of largest member
***************************************
*/


//countingSort Utility Function  (modified to work with radixSort) 
void countingSort(int arr[], int size, int div)
{
    int* output_array= new int[size];
    int count_array[10] {0}; //we know decimal has 10 digits and fill with 0
    
    //count occurences in array
    for(int i=0; i<size; i++) //iterate within size of input array
    {
        ++count_array[(arr[i]/div)%10];  //pick only the digit in question
    }

    //cummulative count array 
    for(int i=1; i<10; i++) //start from the second element
    {
        count_array[i] += count_array[i-1];
    }

    //Extract using cumulative count array values from input array to output array
    for(int i= size - 1; i >= 0; i--) //iterate within the size of the input/output
    {
        output_array[count_array[ (arr[i]/div)%10 ] - 1]= arr[i];
        count_array[ (arr[i]/div)%10 ]--; //reduce count of particular digit
    }

    //copy output array elements to input_array
    for(int i=0; i < size; i++)
    {
        arr[i]=output_array[i]; //we count occurences for each value
    }

    //free up memory
    delete [] output_array;
}


//Utility Function to get max element
int getMax(int arr[], int size)
{
    int max = arr[0]; //Start from the first element

    //compare with other elements
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void radixSort(int arr[], int size)
{
    int m = getMax(arr, size);

    //call counting sort as many times as the number of the digits in Max number 
    for(int div=1; m/div > 0; div*=10) //To access individual digits starting from lsd
    {
         countingSort(arr, size, div);   
    }
}



//driver
int main()
{
    int size =0;
    cout << "Enter Size of the array: "<<endl;
    cin>>size;
    
    int* myarray = new int[size]; 

    cout << "Enter " << size << " integers in any order: "
    <<endl;
    for(int i=0; i<size; i++)
    {
        cin>>myarray[i];
    }

    cout << endl << "Before Sorting: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << myarray[i] << " ";
    }

    radixSort(myarray, size); //function call

    cout <<endl << "After Sorting: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << myarray[i] << " ";
    }


    delete [] myarray;
    return 0;
}