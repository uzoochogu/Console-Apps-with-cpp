//Testing modules and std::format
import <iostream>;
import <format>;


int main()
{
    int fish_count {100};
    float pond_diameter {15.5f};

    std::cout << std::format("Pond diameter required for {} fish is {} feet.\n", fish_count, pond_diameter);  

    return 0;
}