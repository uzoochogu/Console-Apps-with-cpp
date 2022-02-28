#include <iostream>
using namespace std;


/*
***************************************
Counting sort
This is not a comparision sort. It creates a map containing 
the count of all elements in an array/container. This map 
has a length of the range of possible values.
***
It has a time complexity of O(n+k) and a 
Space complexity of O(k)
***************************************
*/

void countingSort(int input_array[], int s, int r)
{
    int* output_array= new int[s];
    int* count_array= new int[r] {0}; //create array dynamically and fill with 0
    
    //we count occurences for each value in the input array
    for(int i=0; i<s; i++) //iterate within size of input array
    {
        ++count_array[input_array[i]]; 
    }

    //Get cummulative count array to store positional values for output array
    for(int i=1; i<r; i++) //start from the second element
    {
        count_array[i] += count_array[i-1];
    }

    //Extract using cumulative count array values from input array to output array
    for(int i=0; i<s; i++) //iterate within the size of the input/output
    {
        output_array[--count_array[input_array[i]]]= input_array[i]; //--because position = index+1
    }

    //copy output array elements to input_array
    for(int i=0; i<s; i++)
    {
        input_array[i]=output_array[i]; //we count occurences for each value
    }

    //free up memory
    delete [] output_array;
    delete [] count_array;
}



//driver
int main()
{
    int size =0;
    int range = 10; 

    cout << "Enter Size of the array: "<<endl;
    cin>>size;
    int* myarray = new int[size]; 

    cout << "Enter Range of the array (0-range): "<<endl;
    cin>>range;

    cout << "Enter " << size << " integers in any order in the range of 0-" << range <<": "
    <<endl;
    for(int i=0; i<size; i++)
    {
        cin>>myarray[i];
    }

    cout << endl << "Before Sorting" << endl;
    for(int i=0; i<size; i++)
    {
        cout << myarray[i];
    }

    countingSort(myarray, size, range); //function call

    cout <<endl << "After Sorting" << endl;
    for(int i=0; i<size; i++)
    {
        cout << myarray[i] << " ";
    }


    delete [] myarray;
    return 0;
}
