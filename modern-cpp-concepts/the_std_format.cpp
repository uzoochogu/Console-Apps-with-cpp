//Testing modules and std::format
//import <iostream>;  //I'll use these when they are fully supported
//import <format>;

import std.core;  

/*
The above header file gives me experimental support for <iostream> and <format> modules
I needed to use the following flags and the msvc 14.31
'cl /std:c++20 /experimental:module /EHsc /MD the_std_format.cpp'
*/



int main()
{
    const int fish_count {100};
    const float pond_diameter {15.5342f};


    //Old style formatting
    std::cout << "Pond diameter required for " << fish_count << " fish is "
    << std::setprecision(2)                                                     // Use two significant digits
    << pond_diameter << " feet.\n";                                             // Output value is 16 (it is rounded).


    //using the std::format

    std::cout << std::format("Pond diameter required for {} fish is {} feet.\n", fish_count, pond_diameter);  

    return 0;
}