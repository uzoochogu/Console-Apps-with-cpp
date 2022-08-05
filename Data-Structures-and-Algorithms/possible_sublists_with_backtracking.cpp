/**
 * @file possible_sublists_with_backtracking.cpp
 * @author Uzo Ochogu (uzoochogu@yahoo.com)
 * @brief This program prints out all the possible sublists of a given input list
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief prints the contents of a vector of strings in a nice format
 * 
 * @param v vector of strings to be printed
 */
void print_strvec(std::vector<std::string>& v)
{
    std::cout << "{" ;
    for (unsigned int i = 0; i < v.size() - 1; i++)
    {
        std::cout << "\""<< v[i] << "\""<< ", ";
    }
    std::cout << "\"" <<  v[v.size() - 1]  << "\""<<  "}\n";
}

/**
 * @brief Utilty function for sublists
 * 
 * @param words vector of strings to be combined into sublists
 * @param chosen vector of strings that tracks chosen words(strings) within the vector.
 */
void sublistsHelper(std::vector<std::string>& words, std::vector<std::string>& chosen)
{
    if(words.empty() && !chosen.empty())
    {
        print_strvec(chosen);
    }
    else
    {
        //There are two choices to explore: The subset with an element and without an element
        //choose
        std::string last = words[words.size()-1];           //choosing last is more elegant
        words.pop_back();

        //explore - With the removed word
        chosen.push_back(last);
        sublistsHelper(words, chosen);

        //explore 2 - without the removed word
        chosen.pop_back();
        sublistsHelper(words, chosen);

        //unchoose
        words.push_back(last);
    }
}

/**
 * @brief prints the combination of possible sublists of a vector of strings
 * 
 * @param words vector of strings
 */
void sublists(std::vector<std::string> &words)
{
    std::vector<std::string> chosen;
    sublistsHelper(words, chosen);
}

int main()
{
    std::cout << "Enter the elements of the list(Enter Q! to stop): \n";
    std::string elements;
    std::vector<std::string> word_list;
    do         
    {
        std::cin >> elements;
        if(elements != "Q!")
            word_list.push_back(elements);
    }
    while(elements != "Q!");
   
    std::cout << "Your input elements: "; print_strvec(word_list);

    std::cout << "\n\nSublists: \n"; sublists(word_list);
    return 0;
}