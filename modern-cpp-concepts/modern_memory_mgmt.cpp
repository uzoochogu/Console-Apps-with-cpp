import std.core;     //We're using this temporarily
/*
* The above header file gives me experimental support for <iostream> and <memory> modules
* I needed to use the following flags and the msvc 14.31
* 'cl /std:c++20 /experimental:module /EHsc /MD modern_memory_mgmt.cpp'
*
*
* We will make use of:
* std::unique_ptr   -> Non-Copyable, just movable, has lifetime guarantee
* std::shared_ptr   -> Has Life time guarantee
* std::weak_ptr     -> No lifetime guarantee
*
* Note: Start reading from main() 
*/


//FreeWrapper, a custom deleter
struct FreeWrapper
{
    void operator() (int* p)
    {
        free(p);
    }
};

//Two Structs to demonstrate circular dependency

struct Gadget;
struct Widget
{
    std::shared_ptr<Gadget> mGadget;


};

struct Gadget
{
    std::weak_ptr<Widget> mWidget;    //most ideal here, prevents bad reference counting issue with circular dependency
};


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
    //Unique Pointers
    std::unique_ptr<int> up(new int(5));
    //std::unique_ptr<int> up2 = up;   //This doesn't run, You should use Unique pointers when owing resource without sharing it.
    auto up3 = std::make_unique<int>(5);       //Using this to make unique pointers is usually preferred.


    //Shared Pointer
    std::shared_ptr<int> sp(new int(5));
    std::shared_ptr<int> sp2 = sp;      //This runs because resources can be shared. It uses a reference counter
    auto sp3 = std::make_shared<int>(6);       //Using this is preferred 


    //Unique Pointer and Shared pointer in Practice
    *up = 7;           //Underlying object can be accessed just like raw pointers 
    *sp = 8;

    //To obtain the underlying raw pointer ( i.e a pointer to the underlying memory)
    int *rp = up.get();


    //You can convert a unique pointer to a shared pointer, not vice versa
    std::shared_ptr<int> sp_from_up (std::move(up));    //Shared pointers are thread safe (No data erases between threads)


    /*  
        Weak Pointer -> Can only be created from Shared Pointers.
        Used when you need to have a shared ownership but only for a limited time (Temporary shared ownership)
        To use the memory contained in a weak pointer, you must create a shared pointer from the
        weak pointer. This is because the shared pointer used to create the weak pointer might have been 
        deallocated, so calling lock() and creating another shared pointer helps ensure it is truly shared.
        Weak pointers helps against circular dependence

    */
    std::weak_ptr<int> wp(sp);
    {
        auto sp_from_wp = wp.lock();     //sp_from_wp is a share pointer
        // Do some work .....
        std::cout << wp.expired() << "\n";       //returns the state of the weak pointer
        //call lock() when next you want to use the memory
    }


    //Weak pointer used against Circular Dependency
    auto w = std::make_shared<Widget>();
    w->mGadget = std::make_shared<Gadget>();
    w->mGadget->mWidget =  w;   //back reference, if this wasn't a weak pointer, reference counting will not work well if w went out of scope.


    //Custom Deleters- delete operator is used by default but you can define yours
    std::unique_ptr<int, decltype(&free)> up_with_free(static_cast<int *>(malloc(sizeof(int))), &free);       //C deleter "free" specified with 2nd template arg
    std::unique_ptr<int, FreeWrapper> up_with_custom(static_cast<int *>(malloc(sizeof(int))), FreeWrapper());   //Custom deleter passed (There is no need to pass the constructor)

    std::shared_ptr<int> sp_with_custom(static_cast<int *>(malloc(sizeof(int))), FreeWrapper());  //in shared pointers, the deleter is not a part of the type and custom deleters
    std::shared_ptr<int> sp_with_free(static_cast<int *>(malloc(sizeof(int))), &free);          //must be passed as arg.

    
    //Test: Destructors are called when an exception is thrown
    f(OwningInt()); //Calls destructor after throwing an the exception
    return 0;
}