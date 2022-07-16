// Using the bitwise operators
import std.core;     //We're using this temporarily

/*
* The above header file gives me experimental support for <iostream> and <memory> modules
* It is not needed here but is used for consistency
* I needed to use the following flags and the msvc 14.31
* 'cl /std:c++20 /experimental:module /EHsc /MD modern_memory_mgmt.cpp'
*/

//Templated Print Function
template<typename T>
void print(T t)
{
    for (const auto& e : t)
        std::cout << e << " ";
    
    std::cout << std::endl;
}

int main()
{

    //std::sort in  <algorithm>
    std::cout << "std::sort:\n";
    std::vector<std::string> animals = { "mouse", "dog", "cat", "ant", "moth", "elephant" };
    std::cout << "unsorted:\n";
    print(animals); //outputs: mouse, dog, cat, ant, moth, elephant

    std::cout << "\nsorted:\n";
    std::sort(animals.begin(), animals.end());
    print(animals); //outputs: ant, cat, dog, elephant, moth, mouse

    //using a Lambda to specify sorting criterion
    std::cout << "\nsorted using length\n";
    auto sortByLength = [](const auto& a, const auto& b) { return a.size() < b.size(); };
    std::sort(animals.begin(), animals.end(), sortByLength);
    print(animals); // may output: dog, cat, ant, moth, mouse, elephant
                    //         or: ant, cat, dog, moth, mouse, elephant    depending on implementation


    //std::stable_sort in <algorithm>
    std::cout << "\nstd::stable_sort:\n";
    std::stable_sort(animals.begin(), animals.end(), sortByLength);
    print(animals); //outputs: ant, cat, dog, moth, mouse, elephant


    //std::binary_search
    std::binary_search(animal.begin(), animal.end(), "ant");   //true

    //std::lower_bound

    //std::upper_bound

    

    std::cin.get();

    return 0;
}


