/*
Program contains a function that checks if an expression has balanced parentheses
*/

#include <iostream>
#include <stack>
#include <string>


bool isParenthesesBalanced(std::string exp)
{
  std::stack<char> braces;
  for(unsigned int i = 0; i < exp.size(); i++)
  {
    if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
    {
      braces.push(exp[i]);
    }
    else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
    {
      if(braces.empty() || (braces.top() == '{') && (exp[i] != '}') || (braces.top() == '(') && (exp[i] != ')')|| (braces.top() == '[') && (exp[i] != ']'))  //check if they don't match
      {
        return false;
      }
      else braces.pop();
    }
  }
  return braces.empty()? true: false;      //empty stack means the parenthese are balanced
}


int main()
{
  std::cout << "Check for Balanced Parentheses:\n";
  std::cout << "(A+B):               " << isParenthesesBalanced("(A+B)") << std::endl;                                //true
  std::cout << "{(A + B) + (C + D)}: " << isParenthesesBalanced("{(A + B) + (C + D)}") << std::endl;                  //true
  std::cout << "{(X + Y) * (Z):      " << isParenthesesBalanced("{(X + Y) * (Z)") << std::endl;                       //false
  std::cout << "[2 * 3] + (A:        " << isParenthesesBalanced("[2 * 3] + (A") << std::endl;                         //false
  std::cout << "{A + Z):             " << isParenthesesBalanced("{A + Z)") << std::endl;                              //false
  
  return 0;  
}
