/*
**************Dice Rolls************************
When passed a number n, the function displays all possible combinations of outcomes if n dice are rolled


**************Dice Sum**********************
When passed a number n and a target, the function displays all possible combinations of n dice that can give that target
*/

#include <iostream>
#include <vector>

/**
 * @brief Prints content of a vector formatted as a set of numbers
 * @param v vector to be printed
 */
void print_vec(std::vector<int> &v)
{
    std::cout << "{";
    for (unsigned int i = 0; i < v.size() - 1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1] << "}\n";
}

/**
 * @brief Utility function for printDiceRolls
 */
void printDiceRollsUtil(int number, std::vector<int> &eyes)
{
    if (number == 0)
    {
        print_vec(eyes);
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            // choose
            eyes.push_back(i);

            // explore
            printDiceRollsUtil(number - 1, eyes);

            // unchoose
            eyes.pop_back();
        }
    }
}

/**
 * @brief Displays all possible combinations of outcomes if {number} number of dice are rolled
 * @param number number of dice rolls
 */
void printDiceRolls(int number)
{
    std::vector<int> eyes;
    printDiceRollsUtil(number, eyes);
}


/**
 * @brief Utility function for printDiceSum
 */
void printDiceSumUtil(int number, int target, int runningSum, std::vector<int> &eyes)
{
    if (number == 0) // base case
    {
        print_vec(eyes);
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            // Discard too big and too small rolls
            if (runningSum + i + 1 * (number - 1) <= target &&
                runningSum + i + 6 * (number - 1) >= target)
            {
                // choose
                eyes.push_back(i);

                // explore
                printDiceSumUtil(number - 1, target, runningSum + i, eyes);

                // unchoose
                eyes.pop_back();
            }
        }
    }
}

/**
 * @brief Displays all possible combinations of outcomes that meet a target if {number} number of dice are rolled
 * @param number number of dice rolls
 * @param target target number to be reached by dice roll
 */
void printDiceSum(int number, int target)
{
    std::vector<int> eyes;
    printDiceSumUtil(number, target, 0, eyes);
}

int main()
{
    int n{0}, target{1};
    std::cout << "How many Dice rolls do you want to display? ";
    std::cin >> n;
    std::cout << "What target do you want? ";
    std::cin >> target;

    std::cout << "\nCombinations of " << n << " dice that sum up to " << target << " are: \n";
    printDiceSum(n, target);

    std::cout << "\nCombinations of " << n << " dice are: \n";
    printDiceRolls(n);    
    return 0;
}