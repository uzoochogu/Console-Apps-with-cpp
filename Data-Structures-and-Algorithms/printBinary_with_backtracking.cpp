/*
This program print the binary equivalent of a supplied Decimal using Backtracking
*/

#include <iostream>
#include <string>

 
/**
 * @brief Prints every binary number that has exactly the given number of digits
 * 
 */
void printBinary(int digits, std::string prefix = "")
{
    if(digits == 0)
    {
        std::cout << prefix << std::endl;         //base case
    }
    else                                          //recursive case: multiple digits
    {
        printBinary( digits - 1, prefix + "0");    
        printBinary( digits - 1, prefix + "1");
    }
}


int main()
{


    return 0;
}