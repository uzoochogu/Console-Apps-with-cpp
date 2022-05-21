/*
You are in charge of the cake for a child's birthday. 
You have decided the cake will have one candle for each year of their total age. 
They will only be able to blow out the tallest of the candles. 
Count how many candles are tallest.

Example
candles = [4, 4, 1, 3]

The maximum height candles are 4 units high. There are 2 of them, so return 2.

Function Description

Complete the function birthdayCakeCandles in the editor below.

birthdayCakeCandles has the following parameter(s):

int candles[n]: the candle heights

Returns:
int: the number of candles that are tallest

Input Format:
The first line contains a single integer,n , the size of candles[].
The second line contains n space-separated integers, where each integer i describes the height ofzdmz candles[i].

Constraints
1<= n <= 10E5
1<= candles[i] <= 10E7
Sample Input 0:
4
3 2 1 3

Sample Output 0:
2

Explanation 0:
Candle heights are [3, 2, 1, 3]. The tallest candles are  units, and there are  of them.

*/

#include <iostream>
#include <vector>


/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(std::vector<int> candles) {
    int max{0}, count{0};
    for(auto i:candles)
    {
        max = std::max(max, i);
    }
    for (auto i:candles)
    {
        if(max==i)
            count++;
    }
    return count;

}

//Driver code
int main()
{
    int number{0};
    std::vector<int> birthday_cakes;
    std::cout << "Input Test case (Input a letter to stop input): ";
    
    while (std::cin >> number)
    {
        birthday_cakes.push_back(number);
    }
    std::cout << "\nYour input is: ";

    for(auto i: birthday_cakes)
    {
        std::cout << i << " ";
    }
    std::cout << "\nThe number of blown candles are: " << birthdayCakeCandles(birthday_cakes);

    return 0;
}
