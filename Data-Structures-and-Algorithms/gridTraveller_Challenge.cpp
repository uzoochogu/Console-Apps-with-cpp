
#include <iostream>
#include <unordered_map>
#include <string>

/*
You can only move right and downwards. 
How many possible ways to move from point A to B given a particular grid dimension.
 _ _ _ _ _
|A|_|_|_|_|
|_|_|_|_|_|
|_|_|_|_|B|

Solution
This was solved using a recursive function visualized as a tree.
An optimal solution was obtained by memoization using C++ unordered_map.
*/

//Computes the number of possible ways to move down the grid from top left to bottom right
long long gridTraveller(long long row, long long column, std::unordered_map<std::string, long long>& memo)
{
    //constructing the memo object
    std::string key = std::to_string(row) + "," + std::to_string(column); 
    std::string alt_key = std::to_string(column) + "," + std::to_string(row);
    
    //searching
    if(memo.find(key) != memo.end())
        return memo[key];
    else if (memo.find(alt_key) != memo.end())
        return memo[alt_key];

    //other base case
    if ( row == 1 && column == 1)
        return 1;
    if (row  == 0 || column == 0)
        return 0;

    memo[key] = gridTraveller(row-1, column, memo) + gridTraveller(row, column-1, memo);
    return memo[key];
}

int main()
{
    std::unordered_map<std::string, long long> memo;
    std::cout << gridTraveller(2,3, memo) << std::endl;
    std::cout << gridTraveller(3,2, memo) << std::endl;
    std::cout << gridTraveller(3,3, memo)<< std::endl;
    std::cout << gridTraveller(18,18, memo)<< std::endl;
    std::cout <<gridTraveller(28,28, memo) << std::endl;

    return 0;
}