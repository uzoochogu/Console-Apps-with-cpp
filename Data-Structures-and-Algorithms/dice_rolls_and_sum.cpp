/*
**************Dice Rolls************************
When passed a number n, the function displays all possible combinations of outcomes if n dice are rolled


**************Dice Sum**********************
When passed a number n and a target, the function displays all possible combinations of n dice that can give that target
*/

#include <iostream>
#include <vector>

void print_vec(std::vector<int>& v)
{
    std::cout << "{";
    for(unsigned int i = 0; i < v.size()-1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1] << "}\n";
}

void printDiceRollsUtil(int number, std::vector<int>& eyes)
{
    if (number == 0)
    {
        print_vec(eyes);
    }
    else
    {
        for(int i = 1; i <= 6; i++)
        {
            //choose
            eyes.push_back(i);

            //explore
            printDiceRollsUtil(number - 1, eyes);

            //unchoose
            eyes.pop_back();
        }
    }
}

void printDiceRolls(int number)
{
    std::vector<int> eyes;
    printDiceRollsUtil(number, eyes);
}


int main()
{
    int n{0};
    std::cout << "How many Combination do you want to display? ";
    std::cin >> n;

    std::cout << "\nCombinations of " << n << " dice is: \n";
    printDiceRolls(n);


    return 0;
}