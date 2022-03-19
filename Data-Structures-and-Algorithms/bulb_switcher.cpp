/*
*   Bulb Switcher
*   Description
*
*   There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. 
*   Initially, all the bulbs are turned off.
*
*   At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. 
*   A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.
*
*   Return the number of moments in which all turned on bulbs are blue.
*
*   Constraints:
*
*   n == light.length
*   1 <= n <= 5 * 10^4
*   light is a permutation of  [1, 2, ..., n]
*
*
*   Pseudocode
*   Take in the light array
*   Iterate through it (used to track moments), looking for the maximum number between previous iterations
*       Check if the current iteration + 1 (moment + 1) = max 
    (Reason: if it is equal then it is in the right position, since light consists of permutation of n)
*           If yes the increment the valid moments
*
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <cstdlib>


//Computes number of times (moments) all the available bulbs are blue 
int numTimesAllBlue(std::vector <int> light)
{
    int moment = 0;
    int max = -1;
    for(int i= 0 ; i < light.size(); ++i)
    {
        max = std::max(light[i], max);

        if(i + 1 == max)
        {
            moment++;
        }
    }
    return moment;
}


//driver
int main()
{
    int option, permutations;

    //Custom Random Number Generator
    auto roll = [](int n) { return rand() % n + 1; };

    std::vector <int> light;
    std::unordered_set <int> container; //Used to help generate permutations
 
    do
    {
        std::cout << "Select an Option: " << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Input the Light array" << std::endl;

        std::cin >> option;     

        switch(option)

        {
            case 0:
                break;
            
            case 1:
                std::cout << "For the Light Array, input the number of Lights: ";
                std::cin >> permutations;

                std::cout << "You selected " << permutations << " permutations\n\n";
                std::cout << "Randomly Generated Permutation: [";               

                //Generate Permutations
                while(container.size() != permutations)
                {
                    container.insert(roll(permutations));
                }

                //Copy and Print Permutations
                for( auto c : container )
                {
                    light.push_back(c);
                    std::cout << c << ", ";

                }

                std::cout << "]\n\n";

                //Used Function here        
                std::cout << "The Number of times all the lights are blue is " << numTimesAllBlue(light);
                std::cout << "\n";
                break;

            default:
                std::cout << "Please select a Valid option\n\a"; 
                break;

        }

    } while(option != 0);

    return 0;
}