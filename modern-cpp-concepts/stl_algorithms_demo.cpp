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
    std::cout << "\nstd::binary_search:\n";
    std::binary_search(animals.begin(), animals.end(), "ant");   //true

    std::vector<int> v = {1, 3, 5, 7};
    std::cout << (binary_search(v.begin(), v.end(), 3) ? "Found" : "Not Found ") << std::endl; //output Found
    std::cout << (binary_search(v.begin(), v.end(), 4) ? "Found" : "Not Found ") << std::endl; //outputs Not Found


    //std::lower_bound ->std::first_greater_or_equal_to
    std::cout << "\nstd::lower_bound:\n";

    std::vector<int> v ={ 1, 3, 3, 5, 7};

    auto it  = lower_bound (v.begin (), v.end (), 3);
    auto it2 = lower_bound (v.begin (), v.end (), 4);
    auto it3 = lower_bound (v.begin (), v.end (), 8);

    std::cout << (it != v.end () ? std::to_string (*it) : "Not Found") << std::endl;    //outputs 3
    std::cout << (it2 != v.end () ? std::to_string (*it2) : "Not Found") << std::endl;    //outputs 5
    std::cout << (it3 != v.end () ? std::to_string (*it3) : "Not Found") << std::endl;    //outputs Not Found

    std::cout <<"To verify that only the first equal value is printed, this is the distance: " <<distance(v.begin(), it) << endl;  //outputs 1

    

    //std::upper_bound->std::first_greater_than
    std::cout << "\nstd::lower_bound:\n";

    std::vector<int> v ={ 1, 3, 3, 5, 7};

    auto it  = upper_bound (v.begin (), v.end (), 3);
    auto it2 = upper_bound (v.begin (), v.end (), 4);
    auto it3 = upper_bound (v.begin (), v.end (), 8);

    std::cout << (it != v.end () ? std::to_string (*it) : "Not Found") << std::endl;    //outputs 5
    std::cout << (it2 != v.end () ? std::to_string (*it2) : "Not Found") << std::endl;    //outputs 5
    std::cout << (it3 != v.end () ? std::to_string (*it3) : "Not Found") << std::endl;    //outputs Not Found

   


    

    std::cin.get();

    return 0;
}


