#include <iostream>
#include <cstdlib>

#include <unordered_map>
#include <algorithm>
#include <chrono>

/*
Maps implements key value pairs, correlations and uses 
hashes to implement uniqueness
*/

int main()
{
   
   std::unordered_map<std::string, int> container;

   container["one"] = 1;
   container["two"] = 2;
   container["three"] = 3;
   container["four"] = 4;
   container["five"] = 5;
   container["six"] = 6;


   //Iterate through the unordered map
   for (auto& i : container)
   {
       std::cout << i.first << " = " << i.second << "\n";
   }


}