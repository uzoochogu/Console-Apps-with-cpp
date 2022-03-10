
/**
********************
*	Windows Recent Files feature is an implementation of a Stack but with an added functionality
*	You push items to the stack (strings in this implementation) and it operates on a FILO or LIFO
*	basis for the pop operation
*	As an added feature, when an item that already exists is pushed into the stack,
*	it becomes the most recent item (last item) and the stack is rearranged accordingly. 
*	The stack has a size that can be manipulated by the user and it implements these functions
*
*	getMostRecentItem();
*	pushItem();
*
*	For this implementation, I will use std::deque 
**********************************
*/


#include <iostream>
#include <deque>
#include <string_view>

class RecentStack {
    int count;
    public:
        std::deque<std::string> recentStack;
        int size;
        
        
        //Default Constructor
        RecentStack() { 
            size = 5; 
            count = size;
        }

        //Parameterized constructor
        RecentStack(int size) : size(size), count(size) {} 


        //Returns the most recent element in the Recent Stack
        std::string getMostRecentItem() const {
            return recentStack.back();
        }


        //Adds element to the Recent Stack
        void pushItem( std::string item) {
            //search for match
            for( auto it = recentStack.begin(); it != recentStack.end(); ++it) {
                if(*it == item) {
                    std::cout << "Item Exists! It is added to the Front\n";
                    recentStack.push_back(item);
                    recentStack.erase(it);

                    return;
                }
            }

            //No match
            if(count == -1) { //RecentStack is full
                recentStack.push_back(item);
                std::cout << "Oops " << recentStack.front() << " fell off\n";
                recentStack.pop_front();

            } else {                            
				//push as normal and decrement counter
                recentStack.push_back(item);
                --count;
            }
            
            return;      
        }


        //Utility Function to print Recent Stack
        void printRecentList() {
            for(auto i = recentStack.rbegin(); i != recentStack.rend(); ++i ) {
                std::cout << *i << "\n";
            }
        }

};


int main() {
    int option;
    RecentStack rStack(5);
    
    do {
        std::cout << "What operation do you want to perform? \n";
        std::cout << "0. Exit \n";
        std::cout << "1. Add items to the stack \n";  
        std::cout << "2. View most Recent Item \n";
        std::cout << "3. Print Recent List \n";  
        std::cout << "4. Clear the Screen \n" <<std::endl;  


        std::cout << "Option: ";
        std::cin >> option;

        std::string str;

        switch (option){
            case 0:
                break;
            
            case 1:
                std::cout << "Input String to Add to stack: ";
                std::cin >> str;

                rStack.pushItem(str);
                std::cout << "ADDED!\n";

                break;

            case 2:
                std::cout << "The Most Recent Item is: " << rStack.getMostRecentItem();
                std::cout << std::endl;

                break;

            case 3:
                std::cout << "The Recent Stack is Composed of: " << std::endl;
                rStack.printRecentList();

                std::cout << "\n\n\n";

                break;

            case 4:
                system("cls"); 
                break;

            default:
                std::cout << "Enter proper option number" << std::endl;
                break;

        }  
  
    } while (option != 0);

    return 0;
}