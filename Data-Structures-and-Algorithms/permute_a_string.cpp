/**
 * @file permute_a_string.cpp
 * @author Uzo Ochogu (uzoochogu@yahoo.com)
 * @brief This program explores backtracking to display all the permutations of a string, corner cases like not repeating a string is taken care of
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <unordered_set>

/**
 * @brief Utility function of stringPermutationsUtil
 * 
 * @param word word to permute
 * @param chosen set keeping track of chosen words
 * @param letters current track of letter permuted per word
 */
void stringPermutationsUtil(std::string word, std::unordered_set<std::string>& chosen, std::string letters)
{
    //std::cout << "stringPermutationsUtil( \"" << word << "\" \"" << letters << "\") \n";
    if(word.empty() && chosen.find(letters + word) == chosen.end())
    {
        std::cout << letters << "\n";
        chosen.insert(letters);
    }
    else
    {
        for (int i = 0; i < word.length(); i++)
        {
                //choose
                char c = word[i];
                letters.append(1, c);
                word.erase(i, 1);

                //explore
                stringPermutationsUtil(word, chosen, letters);

                //unchoose
                word.insert(i, 1, c);
                letters.pop_back();
        }
    }    
}

/**
 * @brief displays all the permutations of a string, corner cases like not repeating a string is taken care of
 * 
 * @param word word to permute
 */
void stringPermutations(std::string word)
{
    std::unordered_set<std::string> chosen;
    stringPermutationsUtil(word, chosen, "");
}


int main()
{
    std::string word;
    std::cout << "Input the word you want to explore: ";
    std::cin >> word;

    stringPermutations(word);
    return 0;
}