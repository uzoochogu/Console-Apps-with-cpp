#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <numeric>
using namespace std;


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


//adjacent_count algorithm
template <typename FwdIt>
auto adjacent_count(FwdIt first, FwdIt last)
{
    auto c = 0;
    while (true)
    {
        first = std::adjacent_find(first, last);
        if (first == last) return c;
        ++c, ++first;
    }
    return c;
}


//Implementing count using std::reduce
namespace my
{
    template<class InIt, class T>
    auto count(InIt first, InIt last, const T& val)
    {
        return std::reduce(first, last, 0, [val](auto i, auto e) { return i + (e == val); });
    }
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
    std::cout << "\nstd::upper_bound:\n";

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


    //std::all_of, std::any_of and std::none_of in  <algorithm>
    std::cout << "\nstd::all_of, std::any_of and std::none_of:\n";

    std::vector<std::string> words{ "Cat", "Dog", "123" };

    for (const auto& word : words)
    {
        std::cout << word << " is "
                  << (std::all_of(word.begin(), word.end(), std::isdigit) ? "" : "NOT ")
                  << "a number.\n";
    }

    //using a user defined unary predicate
    std::cout << "\nUsing a user defined unary predicate:\n";

    v = { 1, 2, 3 };
    print(v);
    std::cout << "Are they all odd numbers? ";

    auto is_even = [](auto n) { return n % 2 == 0; };
    std::cout << (std::none_of(v.begin(), v.end(), is_even) ? "YES\n" : "NO\n");


    //std::iota in <numeric>  O(n)
    std::cout << "\nstd::iota:\n"
              << "Generated range from 1 is: ";
    
    std::vector<int> a(5), b(5), c(5);             //used in below
    
    std::iota(a.begin(), a.end(), 1);
    print(a);

    
    //std::partial_sum in <numeric>  O(n)
    std::cout << "\nstd::partial_sum:\n"
              << "Generated partial sum for range: ";
    print(a);
    std::cout << "is: ";
    std::partial_sum(a.begin(), a.end(), b.begin());    //by default plus<> ()
    print(b);

    //Specifying the operator as "Multiplication"
    std::cout << "Specifying the operator as <multiplies> ():\n ";    
    std::partial_sum(a.begin(), a.end(), c.begin(), std::multiplies<>());
    print(c);

    //std::set_union, std::set_intersection, std::set_difference, std::set_symmetric_difference
    //in <algorithm> O(n) and can work with any containers
    std::cout << "\nstd::set_union, std::set_intersection, std::set_difference, std::set_symmetric_difference:\n";
    std::set<int> s1 = { 0, 1, 2, 3, 4, 5};
    std::set<int> s2 = {             4, 5, 6, 7, 8, 9};
    std::cout << "Given these sets:\n";
    print(s1); print(s2);
    
    std::set<int> s3, s4, s5, s6;

    std::set_union               (s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.end()));
    std::set_intersection        (s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s4, s4.end()));
    std::set_difference          (s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s5, s5.end()));
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s6, s6.end()));

    std::cout << "set_union:                "; print(s3);
    std::cout << "set_intersection:         "; print(s4);
    std::cout << "set_difference:           "; print(s5);
    std::cout << "set_symmetric_difference: "; print(s6);


    //std::adjacent_find in <algorithm> 
    std::cout << "\nstd::adjacent_find:\nGiven:\n";

    v = { 0, 5, 2, 2, 3, 1, 4 , 4 };
    print(v);

    it = std::adjacent_find(v.begin(), v.end());
    std::cout << "Value: " << *it << std::endl;
    std::cout << "Index: " << distance(v.begin(), it) << std::endl;

    //using a user specified binary predicate
    std::cout << "\nUsing a user specified binary predicate (Greater) :\n";
    it = std::adjacent_find(v.begin(), v.end(), std::greater<>());
    std::cout << "Value: " << *it << std::endl;
    std::cout << "Index: " << distance(v.begin(), it) << std::endl;

    //adjacent_count - a user defined wrapper around adjacent_find()
    std::cout << "\nadjacent_count - a user defined wrapper around adjacent_find():\n"
              << "Returns number of adjacent numbers equal to each other\n";
    std::cout << "Count: " << adjacent_count(v.begin(), v.end()) << std::endl;

    //std::count and std::count_if in <algorithm>
    std::cout << "\nstd::count and std::count_if:\nGiven: ";
    v = { 1, 2, 3, 1, 2};
    print(v);

    std::cout << "1 appears " << std::count(v.begin(), v.end(), 1) << " time(s)\n";  //2
    std::cout << "3 appears " << std::count(v.begin(), v.end(), 3) << " time(s)\n";  //1

    auto is_odd = [](auto e) { return e % 2 == 1; };
    std::cout << "There are " << std::count_if(v.begin(), v.end(), is_odd) << " odd numbers in the vector\n";


    //std::partition and std::stable_partition in <algortihm>
    std::cout << "\nstd::partition and std::stable_partition:\nGiven: ";
    v.resize(10);
    std::iota(std::begin(v), std::end(v), 1);
    print(v);

    std::partition(std::begin(v), std::end(v), is_even);      //is_even was previously defined
    std::cout << "std::partition: "; print(v);

    std::iota(std::begin(v), std::end(v), 1);
    std::stable_partition(std::begin(v), std::end(v), is_even);
    std::cout << "std::stable_partition: "; print(v);


    //std::remove_if in <algortihm> and idiomatic erase-remove 
    std::cout << "\nstd::remove_if and idiomatic erase-remove\nGiven: ";
    std::iota(std::begin(v), std::end(v), 1);
    print(v);

    std::remove_if(std::begin(v), std::end(v), is_odd);      //is_odd was previously defined
    std::cout << "std::remove_if: "; print(v);

    //idiomatic erase-remove
    std::iota(std::begin(v), std::end(v), 1);
    v.erase(std::remove_if(std::begin(v), std::end(v), is_odd), std::end(v));
    std::cout << "idiomatic erase-remove: "; print(v);


    //std::generate and std::generate_n in <algorithm>
    std::cout << "\nstd::generate and std::generate_n\nGenerated vector: ";
    std::vector<std::string> letters(10);
    std::generate(std::begin(letters), std::end(letters), [s = ""s, c = '`']() mutable {++c; s += c; return s; });
    print(letters);

    //std:min, std::max  and std::minmax in <algorithm>
    std::cout << "\nstd::max and std::min: \nGiven: ";
    auto i = { 1, 2, 3 };
    print(i);
    std::cout << "Min: " << std::min(i) << std::endl;
    std::cout << "Max: " << std::max(i) << "\n\nGiven: 1 , 2:\n";

    //using c++17 structured bindings
    {
        auto [min_, max_] = std::minmax(2, 1);
        std::cout << "Min: " << min_ << "\n";
        std::cout << "Max: " << max_ << "\n\n";
    }

    //std::min_element, std::max_element and std::minmax_element
    std::cout << "\nstd::min_element, std::max_element and std::minmax_element\nGiven: ";
    print(v);

    {
        auto[min_, max_] = std::minmax_element(std::begin(v), std::end(v) );
        std::cout << "Min: " << *min_ << "\n";
        std::cout << "Max: " << *max_ << "\n\n";
    }








    

    std::cin.get();

    return 0;
}




