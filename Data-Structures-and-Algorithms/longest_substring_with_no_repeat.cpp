#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


/*
************************************************
*   Description
*   
*   Given a string s, find the length of the longest substring without repeating characters.
*   
* 
*
*   Example 1:
*
*   Input: s = "abcabcbb"
*   Output: 3
*   Explanation: The answer is "abc", with the length of 3.
*   
*   Example 2:
*   
*   Input: s = "bbbbb"
*   Output: 1
*   Explanation: The answer is "b", with the length of 1.
*   
*   Example 3:
*   
*   Input: s = "pwwkew"
*   Output: 3
*   Explanation: The answer is "wke", with the length of 3.
*   Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*   
*   Example 4:
*   
*   Input: s = ""
*   Output: 0
*   
*    
*   
*   Constraints:
*   
*   0 <= s.length <= 5 * 104
*   s consists of English letters, digits, symbols and spaces.
*
*   Strategy
*   1. Brute force
*   2. Sliding Window:
*
*
*
*/

//Write your code here
class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {      
         std::string buf;
         for(auto i:s)
         {
              for(auto j:buf)
              {
                  if (i == j)
                  {
                      buf="";
                      buf += j;
                  }
                  else
                  {
                       buf += i;
    
                  }
              }
      
         }

         return buf.size();
         
         

        
    }

    //Brute force approach
    int lengthOfLongestSubstring2(std::string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = std::max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(std::string& s, int start, int end) {
        std::vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
    }
    
    //Sliding Window Solution
    int lengthOfLongestSubstringSW(std::string s) {
        std::vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = std::max(res, right - left + 1);

            right++;
        }

        return res;
    }

};


//Interface to test code
int main()
{
    std::fstream testFile("test_for_longest_substring_with_no_repeat.txt", std::ios::in); 

    std::cout << "Length of Longest substring with no repeating Characters:\n"; 

    //check if it opens
    if (!testFile.is_open()) 
    {
        std::cout << "failed to open " << "test_for_longest_substring_with_no_repeat.txt" << '\n';
    } 
    else  //program loop
    {        
        for( std::string lineBuffer ;std::getline(testFile, lineBuffer);) //keep reading the file
        {

            std::cout << "In the following string: (\"" << lineBuffer << "\") Length = ";

            //Answers using different strategies

            Solution sol = Solution() ;

            //Strategy 1
            std::cout << sol.lengthOfLongestSubstringSW(lineBuffer);   

            //Strategy 2
            std::cout << "\nAlternative method:   Length = ";
            std::cout << sol.lengthOfLongestSubstring2(lineBuffer); 
            std::cout << "\n";   

            //Strategy 3
            std::cout << "\nAnother Alternative method:   Length = ";
            std::cout << sol.lengthOfLongestSubstring(lineBuffer); 
            std::cout << "\n";     
        }
    }
    return 0;
}
