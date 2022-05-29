/*
Lonely Integer

Given an array of integers, where all elements but one occur twice, find the unique element.
Example: a = [1,2,3,4,3,2,1]

The unique element is 4.

Function Description:
Complete the lonelyinteger function in the editor below.

lonelyinteger has the following parameter(s):
int a[n]: an array of integers

Returns
int: the element that occurs only once

Input Format: (Check test_for_lonely_integer_Challenge.txt)
The first line contains a single integer i.e. the number of integers in the array.
The second line contains  space-separated integers that describe the values in vector a

Constraints
1 <= n < 100
it is guaranteed that n is an odd number and that there is one unique element
0 <= a[i] <= 100, where 0 <= i < n

Analysis solution
Time Complexity: O(2n) -> O(n) 
Space Complexity: O(n)
*/


#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>   
#include <string>   
#include <sstream>             


/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(std::vector<int> a) 
{
    const int range = 100;
    std::bitset<range> bit_map; //initialized to all zeros
    int solution{0};
    for(unsigned int i= 0; i < a.size(); i++) //Duplicates will be set then reset
    {        
        bit_map.flip(a[i]);        
    }
    
    for(unsigned int i= 0; i < a.size(); i++)
    {
        if(bit_map[a[i]])       //Non Duplicate is the only set bit
            solution = a[i];
    }
    
    return solution;
}

//Driver Code
int main()
{
    /*
    The first line contains a single integer i.e. the number of integers in the array.
    The second line contains  space-separated integers that describe the values in vector a
    */

    std::vector<int> input;
    std::fstream testFile("test_for_lonely_integer_Challenge.txt", std::ios::in); 
    int array_size{};
    std::stringstream stringBuffer;
    std::string buf;

    //check if it opens
    if (!testFile.is_open()) 
    {
        std::cout << "failed to open " << "test_for_lonely_integer_Challenge.txt" << '\n';
    } 
    else
    {
        for( std::string lineBuffer ;std::getline(testFile, lineBuffer);) //keep reading the file (Reads odd number lines)
        {
            array_size = std::stoi(lineBuffer);  //number of elements

            std::getline(testFile, lineBuffer);  //2nd line always contains data 
            stringBuffer.str(lineBuffer);

            for(int i=0; i < array_size; i++)  //inputs elements
            {
                stringBuffer >> buf;
                input.push_back(std::stoi(buf));            
            }

            //Display the input vector
            for(auto i: input)
            {
                std::cout << i << " ";
            }

            std::cout << "\n";
            stringBuffer.clear();

            //Answer 
            std::cout << "The lonely integer is: " << lonelyinteger(input)  << "\n\n";

            input.clear();  //Clears content for new batch    
        }

    }

}
