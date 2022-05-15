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

    std::cout << std::format("Pond diameter required for {} fish is {:.3} feet.\n", fish_count, pond_diameter);   //15.5


    // Default alignment: right for numbers, left otherwise
    std::cout << std::format("{:7}|{:7}|{:7}|{:7}|{:7}\n", 1, -.2, "str", 'c', true);
    // Left and right alignment + custom fill character
    std::cout << std::format("{:*<7}|{:*<7}|{:*>7}|{:*>7}|{:*>7}\n", 1,-.2,"str",'c',true);
    // Centered alignment + 0 formatting option for numbers
    std::cout << std::format("{:^07}|{:^07}|{:^7}|{:^7}|{:^7}\n", 1, -.2, "str", 'c', true);



    //to catch std::format exceptions
    try
    {
        std::cout << std::format("Pond diameter required for {:.2} fish is {:.2} feet.\n",
        fish_count, pond_diameter);
    }
    catch (const std::format_error& error)
    {
        std::cout << error.what(); // Outputs "precision not allowed for this argument type"
    }



    return 0;
}