/*
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.

Example

The minimum sum is 1 + 3 + 5 + 7 = 16 and the maximum sum is 3 + 5 + 7 + 9 = 24.

The function prints 16 24
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {

    long max{0}, min, sum{0};
    for(auto i:arr)
    {
        sum +=i;
    }
    min = sum; //Since we keep updating for the minimum
    for(auto i:arr)
    {
        sum -= i;
        max = std::max(max, sum);
        min = std::min(min, sum);
        sum +=i;
    }
    std::cout << min << " " << max << "\n";

}

//driver
int main()
{
    /* We will parse a test file that is structured this way. 
    First line contains the 5 numbers delimited by a white space
    the next line contains the solution 
    */



}