/*
This program prints all binary numbers or decimal numbers that has exactly the given number of digits using backtracking
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

/**
 * @brief Prints every Decimal number that has exactly the given number of digits
 * 
 */
void printDecimal(int digits, std::string prefix = "")
{
    if(digits == 0)
    {
        std::cout << prefix << std::endl;         //base case
    }
    else                                          //recursive case: multiple digits
    {
        for(int i = 0; i < 10; i++)
        {
            printDecimal( digits - 1, prefix + std::to_string(i)); 
        }
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
        std:: cout << "\n\nThe Decimal numbers with " << digit  << " digits are: \n";
        printDecimal(digit);
        std:: cout << "\n\n\nDo you want to enter another digit? (y/n): ";
        std::cin >> option;
    } while (option == 'y');

    return 0;
}