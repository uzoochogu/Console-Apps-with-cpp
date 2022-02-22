#include <iostream>
using namespace std;

/*
This demonstrates Abstract Base Class:
Super Classes that don't implement their functions and contain pure
virtual functions. They let their derived classes overload implement the 
functions (method)

They can't be instantiated.
*/

//An ABC
class Animal
{
public:
    virtual void run()=0;
    virtual void speak() = 0;

};

//Still an ABC because it doesn't implement Animal::run()
class Dog: public Animal 
{
public:
    virtual void speak()
    {
        cout << "Woof" << endl;
    }

};

class Spaniel: public Dog  // Everything has been implemented
{
public:
    Spaniel() { cout << "new Spaniel" << endl; }
    virtual void run()
    {
        cout << "Spaniel running" << endl;
    }


};

void test(Animal &a) //This can accept object of subclasses
{
    a.run();
}

int main()
{
    //Animal animal; //Doesn't work because it is an ABC
    Spaniel span;
    span.run();
    span.speak();

    //Animal animals[5]; //Doesn't work
    Spaniel  spaniels[5]; //Constructor is called 5 times 

    //We can create an array of pointers to Animals and store subclass objects

    Animal *animals[5];

    animals[0] = &span;

    animals[0]->speak();

    test(span);


    return 0;
}