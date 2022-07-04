/*
Checks if the numbers in the array can be summed to a given target sum. 
The numbers can be repeated and combined in any way possible.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

bool canSum(int targetSum, std::vector<int> numbers, std::unordered_map<int,bool>& memo)
{
  int remainder{0};
  if(memo.find(targetSum) != memo.end()) return memo[targetSum];
  if(targetSum == 0) return true;
  if(targetSum < 0) return false;
  
  for(auto i: numbers)
  {
    remainder = targetSum - i;
    if (canSum(remainder, numbers, memo))
    {
      memo[targetSum]= true;
      return true;
    }    
  }
  
  memo[targetSum]= false;
  return false;
 }

int main()
{
  std::unordered_map <int, bool> memo;
  std::cout << "canSum:\n";
  std::cout << "7 from {2, 3}: " << canSum(7, {2,3}, memo) << "\n";              //true
  std::cout << "7 from {5, 3, 4, 7}: " << canSum(7, {5, 3, 4, 7}, memo) << "\n"; //true
  std::cout << "7 from {2, 4}: " << canSum(7, {2, 4}, memo) << "\n";             //false
  std::cout << "8 from {2, 3, 5}: " << canSum(8, {2, 3, 5}, memo) << "\n";       //true
  std::cout << "300 from {7, 14}: " << canSum(300, {7, 14}, memo) << "\n";       //false
  
  return 0;
}
