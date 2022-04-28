//Testing modules and std::format
import <iostream>;
import <format>;


int main()
{
    const int fish_count {100};
    const float pond_diameter {15.5f};

    std::cout << std::format("Pond diameter required for {} fish is {} feet.\n", fish_count, pond_diameter);  

    return 0;
}