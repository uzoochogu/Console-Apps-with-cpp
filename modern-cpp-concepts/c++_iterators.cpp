#include <iostream>
#include <algorithm>
#include <numeric>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;


//import std.core;     //We're using this temporarily
/*
* The above header file gives me experimental support for <iostream> and <memory> modules
* It is not needed here but is used for consistency
* I needed to use the following flags and the msvc 14.31
* 'cl /std:c++20 /experimental:module /EHsc /MD modern_memory_mgmt.cpp'
*/


template <typename T>
std::string get_iterator_type(T it)
{
    if      (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::input_iterator_tag))         return "Input";
    else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        return "Output";
    else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       return "Forward";
    else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) return "Bidirectional";
    else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) return "Random Access";
    //else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::contiguous_iterator_tag))    return "Contiguous";

    return "missing";
}

int main()
{
    
    //Test for different containers
    std::cout << "Sequence Containers:\n\n";

    std::array<int, 1> a{0};
    auto it = a.begin();
    std::cout << "array::begin         () returns a " << get_iterator_type(it) << " Iterator.\n";

    std::vector<int> v;
    auto it2 = v.begin();
    std::cout << "vector::begin        () returns a " << get_iterator_type(it2) << " Iterator.\n";

    std::deque<int> dq;
    auto it3 = dq.begin();
    std::cout << "deque::begin         () returns a " << get_iterator_type(it3) << " Iterator.\n";

    std::forward_list<int> fl;
    auto it4 = fl.begin();
    std::cout << "forward_list::begin  () returns a " << get_iterator_type(it4) << " Iterator.\n";

    std::list<int> l;
    auto it5 = l.begin();
    std::cout << "list::begin          () returns a " << get_iterator_type(it5) << " Iterator.\n";

    //Associative Containers
    std::cout << "\nAssociative Containers:\n\n";

    std::set<int> s;
    auto it6 = s.begin();
    std::cout << "set::begin           () returns a " << get_iterator_type(it6) << " Iterator.\n";

    std::map<int, int> m;
    auto it7 = m.begin();
    std::cout << "map::begin           () returns a " << get_iterator_type(it7) << " Iterator.\n";

    //Unordered Associative Containers
    std::cout << "\nUnordered Associative Containers:\n\n";

    std::unordered_set<int> us;
    auto it8 = s.begin();
    std::cout << "unordered_set::begin () returns a " << get_iterator_type(it8) << " Iterator.\n";

    std::unordered_map<int, int> um;
    auto it9 = m.begin();
    std::cout << "unordered_map::begin () returns a " << get_iterator_type(it9) << " Iterator.\n";;


    std::cin.get();
    return 0;
}