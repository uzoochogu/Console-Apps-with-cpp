#include <iostream>
#include <cstdlib>

#include <array>
#include <algorithm>


int something()
{
    std::cout << "Action \n";
    return rand();
}

int main()
{
    std::array<int, 10> b; //Creating a int array container on the stack

    for (int i=0; i < 10; i++)
    {
        b[i] = something();
    }

    for (std::array<int, 10>::iterator i=b.begin(); i != b.end(); ++i)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl << std::endl;

    //Efficient way of filling the array
    std::fill(b.begin(), b.end(), something());

    std::cout << std::endl;

    // Not yet supoorted by ompiler before C++11
    for (auto& i : b)
    {
        std::cout << i << " ";
    }

    return 0;
}