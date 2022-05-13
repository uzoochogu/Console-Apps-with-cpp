import std.core;



int main()
{
    //Area of circle

    std::cout << "The area of a Circle with radius 7mm is: " 
    << std::numbers::pi * 7 * 7 << " squared mm\n";

    //Using Explicit Type conversions
    const unsigned feet_per_yard {3};      //Use constants rather than magic numbers.
    const unsigned inches_per_foot {12};
    const unsigned inches_per_yard {feet_per_yard * inches_per_foot };

    double length {}; //Length in decimal yards
    unsigned int yards{}; // Whole yards
    unsigned int feet {}; // Whole feet
    unsigned int inches {}; // Whole inches
    std::cout << "Enter a length in yards as a decimal: ";
    std::cin >> length;

    // Get the length as yards, feet, and inches
    yards = static_cast<unsigned int>(length);
    feet = static_cast<unsigned int>((length - yards) * feet_per_yard);
    inches = static_cast<unsigned int>(length * inches_per_yard) % inches_per_foot;

    std::cout << length << " yards converts to "
    << yards << " yards "
    << feet << " feet "
    << inches << " inches." << std::endl;

}