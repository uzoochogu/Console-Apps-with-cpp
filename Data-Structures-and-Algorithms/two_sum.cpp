#include <iostream>
#include <vector>
#include <unordered_map>


/*
*
*   Description
*
*   Given an array of integers nums and an integer target, 
*   return indices of the two numbers such that they add up to target.
*   You may assume that each input would have exactly one solution,
*   and you may not use the same element twice.
*
*   You can return the answer in any order.


Constraints:

    2 <= nums.length <= 105
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.


*/

//O(n) Time complexity solution
std::vector<int> twoSumIndicesOptimized(const std::vector<int> nums, const int target) 
{
    int counter = 0; 
    //we create a hash map for an array of complements
    std::unordered_map<int, int> numsHash;
    std::vector<int> result;
    int complement;
    for(int i = 0; i != nums.size(); i++)
    {
        counter++;
        complement = target - nums[i];

        //use contains() in c++20, both are said to work in O(1) on average
        if(numsHash.find(complement) != numsHash.end()) //does complement exists in the Hashmap
        {
            result.push_back(numsHash[complement]);
            result.push_back(i);
        }
        numsHash.emplace(std::make_pair(nums[i], i)); //The value is equal to index in nums array
    }
    result.push_back(counter); 
    return result;
}

//O(n²) Time complexity solution
std::vector<int> twoSumIndices( const std::vector<int> nums, const int target) 
{
    int counter = 0; //For benchmarking purposes
    std::vector<int> result; //specifying that it contains 2 
    for(int i = 0; i != nums.size(); i++)
    {
        for(int j = i + 1; j != nums.size() ; j++) //We can't use same element twice
        {
            counter++;
            
            if(nums[i] + nums[j] == target)
            {
                
                result.push_back(i);
                result.push_back(j);           
            }
            
        }

    }
    result.push_back(counter);
    return result;

}

int main()
{

    //To test this function
    //Other tests include
    //{1,3,4,5,6,8} and target 13, answer 3, 5
    //{5,1,3,4,5,7,6} and target 11, answer 0, 6
    std::vector<int> sample{1,2,3,4,11,12,8,5,10};

    std::vector<int> output = twoSumIndices(sample, 23);
    

    std::cout << "Using the Unoptimized function, The output is at index: "  << output[0] << ", " << output[1]
                << "\nTotal number of iterations is " << output[2];

    output = twoSumIndicesOptimized(sample, 23);

    std::cout << "\nUsing the Optimized function, The output is at index: "  << output[0] << ", " << output[1]
                << "\nTotal number of iterations is " << output[2];   


    return 0;
}