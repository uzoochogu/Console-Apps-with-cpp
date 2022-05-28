//Testing the <format> and <limit> modules
//import <iostream>;  //I'll use these when they are fully supported
//import <format>;

import std.core;     //We're using this temporarily



/*
The above header file gives me experimental support for <iostream> and <format> modules
I needed to use the following flags and the msvc 14.31
'cl /std:c++20 /experimental:module /EHsc /MD the_std_format.cpp'
*/

//A Template check for signed and unsigned types
template <typename T> struct test {
    test(const char* name) {
        std::cout << std::format("{:<15} : {}signed\n", (std::numeric_limits<T>::is_specialized ? name : "non-specialized"),
                                                        (std::numeric_limits<T>::is_signed ? "" : "un"));
    }
};

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


    //Retrieving other properties of fundamental types
    std::cout << std::format("\n\nThe number of bits in the mantissa of a float is {} \n",std::numeric_limits<float>::digits);
    std::cout << std::format("The number of bits in the value of a signed int(excluding sign bit) is {} \n",std::numeric_limits<int>::digits);

    //Range of the exponent component of floating-point values 
    std::cout << std::format("\n\nMaximum Float exponent:  {}\n",std::numeric_limits<float>:: max_exponent);
    std::cout << std::format("Minimum Float exponent:  {}\n\n",std::numeric_limits<float>:: min_exponent);

    //Signed or Not -> See Struct Template Constructor
    test<bool>{"bool"};
    test<char>{"char"};
    test<wchar_t>{"wchar_t"};
    test<char16_t>{"char16_t"};
    test<char32_t>{"char32_t"};
    test<float>{"float"};
    struct delusion{};              //User Defined type 
    test<delusion>{"delusion"};     //Non-specialized type
    test<decltype(42)>{"decltype(42)"};



    //For the maximum float exponent
    std::cout << std::format("\n\nMaximum Float exponent:  {}\n",std::numeric_limits<float>:: max_exponent);
    std::cout << std::format("\nMinimum Flaot exponent:  {}\n",std::numeric_limits<float>:: min_exponent);


    //To obtain the special floating-point values for infinity and not-a-number (NaN)
    std::cout << std::format("\n\nPositive Infinity:  {}\n",std::numeric_limits<float>::infinity());
    std::cout << std::format("Negative Infinity:  {}\n", -std::numeric_limits<double>::infinity());
    std::cout << std::format("Not-A-Number (NaN):  {}\n", std::numeric_limits<long double>::quiet_NaN());


    //Processing Unicode: Use char8_t, char16_t etc rather than char and wchar_t for Unicode. 
/*  char8_t yen {u8'\x0A5'};           // or char8_t yen {u8'¥'};         Initialized with UTF-8 code for the yen sign (¥)
    auto delta {u'\x0394'};            // or char16_t delta {u16'Δ'};     Initialized with UTF-16 code for Greek Delta (Δ)
    char32_t ya {U'\x44f'};            // or char32_t ya {U'я'};          Initialized with UTF-32 code for cyrillic letter ya (я)
    wchar_t cc {L'ç'};                 //or L'\x00E7'
    

    std::cout << std::vformat("\n\nSome Unicode characters are printed below: \n{}\n{}\n{}\n{}", 
                                yen, delta, ya, cc);
//Not currently supported*/



    return 0;
}