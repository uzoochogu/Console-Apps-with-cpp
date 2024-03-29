#include <iostream>
#include <cstdlib>

#include <deque>
#include <algorithm>
#include <chrono>

/*

Double ended queue has the insertion speed of a list and random access or indexable speed of a vector or array. 
It can be considered as a linked list of arrays

*/

int main()
{
    // Lambda function to roll a die
    auto roll = []() { return rand() % 6 + 1; };

    //Create Container - a vector
    std::deque<int> container;

    // Add 1 item
    container.push_back(roll());
    const int* pAddressOfOriginalItemZero = &(*container.begin());

    std::chrono::duration<double> durInsertTime(0);

    do
    {
        //Get Address of first item
        const int* pAddressOfItemZero = &(*container.begin());

        std::cout << "Contains " << container.size() << " elements, took "
            << std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << "us\n";

        for (const auto& i : container)
        {
            const int* pAddressOfItemX = &i;
            int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
            int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginalItemZero;
            std::cout << "Offset From Original: " << pItemOffsetOriginal 
                << "    Offset From Zero: " << pItemOffset << "  :  Content: "
                << *pAddressOfItemX << "\n" ;
        }

        auto tp1 = std::chrono::high_resolution_clock::now();
        container.push_back(roll());
        auto tp2 = std::chrono::high_resolution_clock::now();
        durInsertTime = (tp2 - tp1);


    } while (getc(stdin)); //Use Ctrl + C to breakout of loop
    


}