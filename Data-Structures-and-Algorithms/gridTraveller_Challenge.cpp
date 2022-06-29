
#include <iostream>
#include <unordered_map>
#include <string>

long gridTraveller(long row, long column, std::unordered_map<std::string, long>& memo)
{
    //constructing the memo object
    std::string key = row + "," + column; 
    std::string alt_key = column + "," + row;
    
    //searching
    auto search = memo.find(key);
    auto alt_search = memo.find(alt_key);
    if(search != memo.end())
        return memo[key];
    else if (alt_search != memo.end())
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
    std::unordered_map<std::string, long> memo;
    std::cout << gridTraveller(2,3, memo) << std::endl;
    std::cout << gridTraveller(4,8, memo)<< std::endl;
    std::cout << gridTraveller(18,18, memo)<< std::endl;
    std::cout <<gridTraveller(28,28, memo) << std::endl;

    return 0;
}