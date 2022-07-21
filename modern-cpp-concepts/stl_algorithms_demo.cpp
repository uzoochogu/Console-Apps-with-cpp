#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>


//import std.core;     //We're using this temporarily
/*
* The above header file gives me experimental support for <iostream> and <memory> modules
* It is not needed here but is used for consistency
* I needed to use the following flags and the msvc 14.31
* 'cl /std:c++20 /experimental:module /EHsc /MD modern_memory_mgmt.cpp'
*/

//Templated Print Function
template<typename T>
void print(T t)
{
    for (const auto& e : t)
        std::cout << e << " ";
    
    std::cout << std::endl;
}

//first_less_than algorithm
template<typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value)
{
    auto it = std::lower_bound(first, last, value);
    return (it == first ? last : --it);                 //return end() iterator if no less than value
}

int main()
{

    //std::sort in  <algorithm>
    std::cout << "std::sort:\n";
    std::vector<std::string> animals = { "mouse", "dog", "cat", "ant", "moth", "elephant" };
    std::cout << "unsorted:\n";
    print(animals); //outputs: mouse, dog, cat, ant, moth, elephant

    std::cout << "\nsorted:\n";
    std::sort(animals.begin(), animals.end());
    print(animals); //outputs: ant, cat, dog, elephant, moth, mouse

    //using a Lambda to specify sorting criterion
    std::cout << "\nsorted using length\n";
    auto sortByLength = [](const auto& a, const auto& b) { return a.size() < b.size(); };
    std::sort(animals.begin(), animals.end(), sortByLength);
    print(animals); // may output: dog, cat, ant, moth, mouse, elephant
                    //         or: ant, cat, dog, moth, mouse, elephant    depending on implementation


    //std::stable_sort in <algorithm>
    std::cout << "\nstd::stable_sort:\n";
    std::stable_sort(animals.begin(), animals.end(), sortByLength);
    print(animals); //outputs: ant, cat, dog, moth, mouse, elephant


    //std::binary_search in <algorithm>
    std::cout << "\nstd::binary_search:\n";

    std::vector<int> v = {1, 3, 5, 7};
    print(v); std::cout << std::endl;

    std::cout << (binary_search(v.begin(), v.end(), 3) ? "3 Found" : "3 Not Found ") << std::endl; //output Found
    std::cout << (binary_search(v.begin(), v.end(), 4) ? "4 Found" : "4 Not Found ") << std::endl; //outputs Not Found

    //using a defined binary predicate
    v = { 7, 5, 3, 1 };

    std::cout << "\nUsing a defined binary predicate: \n"; 
    print(v); std::cout << std::endl;

    std::cout << (binary_search(v.begin(), v.end(), 3, std::greater<int>()) ? "3 Found" : "3 Not Found ") << std::endl; //output Found
    std::cout << (binary_search(v.begin(), v.end(), 4, std::greater<int>()) ? "4 Found" : "4 Not Found ") << std::endl; //outputs Not Found


    //std::lower_bound in <algorithm>    ->std::first_greater_or_equal_to
    std::cout << "\nstd::lower_bound:\n";

    v ={ 1, 3, 3, 5, 7};              // used in std::lower_bound, std::upper_bound and our implemented first_lower_than()
    print(v); std::cout << std::endl;

    auto it  = lower_bound (v.begin (), v.end (), 3);
    auto it2 = lower_bound (v.begin (), v.end (), 4);
    auto it3 = lower_bound (v.begin (), v.end (), 8);

    std::cout << "Lower bound for 3: " << (it != v.end() ? std::to_string(*it) : "Not Found") << std::endl;        //outputs 3
    std::cout << "Lower bound for 4: " << (it2 != v.end () ? std::to_string (*it2) : "Not Found") << std::endl;    //outputs 5
    std::cout << "Lower bound for 8: " << (it3 != v.end () ? std::to_string (*it3) : "Not Found") << std::endl;    //outputs Not Found

    std::cout << "To verify that only the first equal value is printed, this is the distance: " 
              << distance(v.begin(), it) << std::endl;  //outputs 1

    

    //std::upper_bound in <algorithm>    ->std::first_greater_than
    std::cout << "\nstd::lower_bound:\n";

    it  = upper_bound (v.begin (), v.end (), 3);
    it2 = upper_bound (v.begin (), v.end (), 4);
    it3 = upper_bound (v.begin (), v.end (), 8);

    std::cout << "Upper bound for 3: " << (it != v.end () ? std::to_string (*it) : "Not Found") << std::endl;      //outputs 5
    std::cout << "Upper bound for 4: " << (it2 != v.end () ? std::to_string (*it2) : "Not Found") << std::endl;    //outputs 5
    std::cout << "Upper bound for 8: " << (it3 != v.end () ? std::to_string (*it3) : "Not Found") << std::endl;    //outputs Not Found


    //using Implemented first_less_than
    std::cout << "\nUsing Implemented first_less_than: \n";
    it = first_less_than(v.begin(), v.end(), 3);
    it2 = first_less_than(v.begin(), v.end(), 4);
    it3 = first_less_than(v.begin(), v.end(), 8);

    std::cout << "First less than bound for 3: " << (it != v.end() ? std::to_string(*it)   : "Not Found") << std::endl;    //outputs 1
    std::cout << "First less than bound for 4: " << (it2 != v.end() ? std::to_string(*it2) : "Not Found") << std::endl;    //outputs 3
    std::cout << "First less than bound for 8: " << (it3 != v.end() ? std::to_string(*it3) : "Not Found") << std::endl;    //outputs 7

    //std::next_permutation and std::prev_permutation in <algorithm>
    std::cout << "\nstd::next_permutation and std::prev_permutation:\n"
              << "Valid Anagrams of \"Stop\": \n";

    std::unordered_set<std::string> dictionary = { "stop", "pots", "tops", "opts", "post", "spot" };
    std::string word{ "stop" };

    std::sort(word.begin(), word.end());

    do
    {
        std::cout << word << (dictionary.count(word) ? ": IS A WORD\n" : "\n");

    } while (std::next_permutation(word.begin(), word.end()));   


    

    std::cin.get();

    return 0;
}




