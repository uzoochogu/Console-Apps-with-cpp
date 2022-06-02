import std.core;     //We're using this temporarily



/*
The above header file gives me experimental support for <iostream> and <format> modules
I needed to use the following flags and the msvc 14.31
'cl /std:c++20 /experimental:module /EHsc /MD constexpr_keyword.cpp'
*/

//constexpr variables must be initialized

/*
* constexpr (and constexpr functions) are computed at compile time. The are used when you want
* to pass a constant expression to somewhere exprecting a const. Modern C++ makes this possible 
* with constexpr.
*
* volatile keyword removes all optimizations including constexpr
*/

class Widget
{
public:
//constexpr constructors - coming soon

};

//constexpr function
constexpr int factorial(int n)
{
    auto result {1};
    for(auto i = 1; i <= n; i++)\
    {
        result *= i;
    }
    return result;
}

//variable template - new feature too
template<int N>
constexpr int value = N;

int main()
{
    int a[factorial(2)] = {};                   //This runs because factorial(2) is a constexpr

    return value<factorial(3)>;                 //returns 6         
}