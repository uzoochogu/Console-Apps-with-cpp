/*
This program prints all binary numbers that has exactly the given number of digits using backtracking
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
    int digit{0};
    char option;

    do
    {
        std::cout << "Enter a number: ";
        std::cin >> digit;
        std:: cout << "\nThe Binary numbers with " << digit  << " digits are: \n";
        printBinary(digit);
        std:: cout << "\n\n\nDo you want to enter another digit? (y/n): ";
        std::cin >> option;
    } while (option == 'y');

    return 0;
}