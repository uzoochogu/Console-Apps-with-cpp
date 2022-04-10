#include <iostream>
#include <string>
#include <unordered_map>     //for hash map


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
                  if (*i == *j)
                  {
                      buf=0;
                      buf += *j;
                  }
                  else
                  {
                       buf += *i;
    
                  }
              }
      
         }

         return buf.size();
         
         

        
    }

    //Brute force approach
    int lengthOfLongestSubstring2(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        vector<int> chars(128);

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
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);

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

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }

};


//Interface
int main()
{

    return 0;
}
