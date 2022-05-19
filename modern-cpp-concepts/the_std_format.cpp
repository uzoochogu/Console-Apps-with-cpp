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
    std::cout << std::format("\n\n{:^50}\n","Using the std::format:");

    std::cout << std::format("Pond diameter required for {} fish is {:.3} feet.\n", fish_count, pond_diameter);   //15.5

    
    
    //[[fill]align][sign][#][0][width][.precision][type]

    // The width, alignment, fill, and 0 formatting options of std::format()
    // Default alignment: right for numbers, left otherwise
    std::cout << std::format("{:7}|{:7}|{:7}|{:7}|{:7}\n", 1, -.2, "str", 'c', true);
    // Left and right alignment + custom fill character
    std::cout << std::format("{:*<7}|{:*<7}|{:*>7}|{:*>7}|{:*>7}\n", 1,-.2,"str",'c',true);
    // Centered alignment + 0 formatting option for numbers
    std::cout << std::format("{:^07}|{:^07}|{:^7}|{:^7}|{:^7}\n", 1, -.2, "str", 'c', true);

    
    //Formatting numbers
    std::cout << std::format("\n\n{:^50}\n","Formatting numbers:");

    const double pi = std::numbers::pi;
    std::cout << std::format("Default: {:.2}, fixed: {:.2f}, scientific: {:.2e}, "
                 "general: {:.2g}\n", pi, pi, pi, pi);
    std::cout << std::format("Default: {}, binary: {:b}, hex.: {:x}\n", 314, 314, 314);
    std::cout << std::format("Default: {}, decimal: {:d}, hex.: {:x}\n", 'c', 'c', 'c');
    std::cout << std::format("Alternative hex.: {:#x}, binary: {:#b}, HEX.: {:#X}\n",
                            314, 314, 314);
    std::cout << std::format("Forced sign: {:+}, space sign: {: }\n", 314, 314);
    std::cout << std::format("All together: {:*<+10.4f}, {:+#09x}\n", pi, 314);

    //Argument Indexing the std::format function
    std::cout << std::format("\n\n{:<50}\n","Argument Indexing the std::format function:");
    std::cout << std::format("Default: {0}, binary: {0:b}, hex.: {0:x}\n", 314);

    //to catch std::format exceptions
    /* try
    {
        std::cout << std::format("Pond diameter required for {:.2} fish is {:.2} feet.\n",
        fish_count, pond_diameter);
    }
    catch (const std::format_error& error)
    {
        std::cout << error.what(); // Outputs "precision not allowed for this argument type"
    } */



    //Now we would use it to display the limit of some fundamental types
    //Include the <limits> module

    std::cout << std::format("The range for type short is from {} to {}\n", 
                              std::numeric_limits<short>::min(), 
                              std::numeric_limits<short>::max())
              << std::format("The range for type unsigned int is from {} to {}\n",
                              std::numeric_limits<unsigned int>::min(),
                              std::numeric_limits<unsigned int>::max())
              << std::format("The range for type long is from {} to {}\n",
                              std::numeric_limits<long>::min(), 
                              std::numeric_limits<long>::max())
              << std::format("The positive range for type float is from {} to {}\n",
                              std::numeric_limits<float>::min(), 
                              std::numeric_limits<float>::max())
              << std::format("The full range for type float is from {} to {}\n",
                              std::numeric_limits<float>::lowest(),
                              std::numeric_limits<float>::max())
              << std::format("The positive range for type double is from {} to {}\n",
                              std::numeric_limits<double>::min(),
                              std::numeric_limits<double>::max())
              << std::format("The positive range for type long double is from {} to {}\n",
                              std::numeric_limits<long double>::min(),
                              std::numeric_limits<long double>::max());

    return 0;
}