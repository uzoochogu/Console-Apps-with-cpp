import std.core;     //We're using this temporarily
/*
* The above header file gives me experimental support for <iostream> and <memory> modules
* I needed to use the following flags and the msvc 14.31
* 'cl /std:c++20 /experimental:module /EHsc /MD modern_memory_mgmt.cpp'
*
*
* We will make use of:
* std::unique_ptr   -> Non-Copyable, just movable
* std::shared_ptr
* std::weak_ptr 
*
*
*/

struct OwningInt
{
    OwningInt()
        : mPtr(new int)
    {

    }

    ~OwningInt()
    {
        std::cout << "dtor" << std::endl;
        delete mPtr;
    }

    int *mPtr;
};

void f(const OwningInt &arg)
{
    try
    {
        OwningInt someInt;
        throw std::exception("My Exception");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

int main()
{
    std::unique_ptr<int> pi(new int(5));

    f(OwningInt()); //Calls destructor after throwing an the exception
    return 0;
}