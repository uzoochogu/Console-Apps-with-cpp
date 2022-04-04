#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

/*
*   Description
* 
*   You are given two non-empty linked lists representing two non-negative integers. 
*   The digits are stored in reverse order and each of their nodes contain a single digit. 
*   Add the two numbers and return it as a linked list.
*
*   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
*   Example:
*
*   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*   Output: (7 -> 0 -> 8)
*   Explanation: 342 + 465 = 807.
*
*
*   Example 2:
*
*   Input: l1 = [0], l2 = [0]
*   Output: [0]
*   
*   Example 3:
*
*   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
*   Output: [8,9,9,9,0,0,0,1]
*
*
*   Constraints:
*   The number of nodes in each linked list is in the range [1, 100] ->(Ignored for storage overflow consideration and over)
*   0 <= Node.val <= 9
*   It is guaranteed that the list represents a number that does not have leading zeros.
*
*   Testing the Code:
*   (The test interface only works with 32bit Int because of the method of streaming)
*   (Your Functions should work on test cases higher than 32bit Int)
*   We would use a text file to test the code. 
*   Each line will contain two numbers separated by a white space.
*
*   The driver code will run through each line until EOF is reached calling the
*   addTwoNumbers() method from the solution class and prints the result.
*
*   Strategies: (Both were implemented here, Strategy B is limited by size of Int)
*   A. Traverse through each Digit node, add and keep track of the carry between digits -> addTwoNumbers()
*   B. Create two functions. ToLinkedList() and ToNumber(). Convert two linkedList to number 
*      perform addition and then convert back to LinkedLList. (More Straight forward and Efficient). ->addTwoNumbersUsingInt()
*/

//Definition for a singly-linked list node. (Given)
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Utility Functions

/*Prints the linked list in the correct order */
void printLinkedList(ListNode* head)
{
    std::cout << "Printing Works\n";     
    ListNode* traverse = head;
    std::cout << "(";
    while(traverse != nullptr)
    {
        std::cout << traverse->val;

        if(traverse->next != nullptr)
        {
            std::cout << " => ";
        }
        traverse = traverse->next;
    }
    std::cout << ") \n";
}

/*This function will convert a number to a linkedList of digit.
It returns the head of the list
*/
ListNode* toLinkedList(int val)
{
    ListNode* head = new ListNode(val%10);
    ListNode* traverse = head;
    std::cout << "We converted "<< val << " to Linked List!\n";
    
    for(int i=1;  val/int(std::pow(10.0, i)) > 0; i++ )
    {
        traverse->next =  new ListNode( (val/int(std::pow(10.0, i))) % 10 );  // (val/10^i ) % 10
        traverse = traverse->next;    
    }
    return head;
}


//Converts a given LinkedList to an integer
int toInt(ListNode* list)
{
    ListNode* travelerNode = list;
    int counter = 0;
    int value = 0;
    //Traverse the LinkedList
    while(travelerNode != nullptr)
    {
        value += travelerNode->val * int(std::pow(10, counter)); //Keep adding the place values.         
        counter++;
        travelerNode = travelerNode->next;
    }
    return value;
}

//Put your solution here
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newDigit = new ListNode(0); //Node to keep track of next digit's ListNode
        
        //For the first digit
        ListNode* sum = new ListNode((l1->val + l2->val) % 10, newDigit); //head node for the sum
        
        int carry = (l1->val + l2->val) / 10; //to keep track of the carry between digits
        int intermediateSum;  //Stores sum per digit

        ListNode* travelerNode1 = l1->next; //Node pointers for traversals
        ListNode* travelerNode2 = l2->next; 
        
        //iterates until both lists have been exhausted
        while(travelerNode1 != nullptr || travelerNode2 != nullptr)
        {
            intermediateSum = 0;

            //Base case: One is longer than the other
            if(travelerNode1 == nullptr) //l2 is longer
            {
                intermediateSum = travelerNode2->val + carry; //Add only l2
                newDigit->val = intermediateSum % 10;
                
                //Move to the next node
                travelerNode2 = travelerNode2->next;      
            }
            else if (travelerNode2 == nullptr) //l1 is longer
            {
                intermediateSum = travelerNode1->val + carry; //Add only l1
                newDigit->val = intermediateSum % 10;
  
                //Move to the next node
                travelerNode1 = travelerNode1->next;  
            }
            else
            {
                intermediateSum = travelerNode1->val + travelerNode2->val + carry;
                newDigit->val = intermediateSum % 10;
                
                //Move to the next node
                travelerNode1 = travelerNode1->next;
                travelerNode2 = travelerNode2->next;  
            }
            
            //compute new carry
            carry = intermediateSum/10;

            // only move to the next Digit if digits still exists
            if(travelerNode1 != nullptr || travelerNode2 != nullptr) 
            {
                newDigit->next = new ListNode();
                newDigit = newDigit->next;
            }
            else if(carry > 0) //no next digit, append final carry
            {
                newDigit->next = new ListNode(carry);
            }              
        }
        return sum;
    } 

    ListNode* addTwoNumbersUsingInt(ListNode* l1, ListNode* l2) 
    {
        int sum = toInt(l1) + toInt(l2);

        //Convert back to LinkedList
        return toLinkedList(sum);
    }  
};

//Interface 
int main()
{
    std::fstream testFile("test_for_add_two_numbers_leetcode.txt", std::ios::in); 

    std::stringstream stringBuffer;
    int num1,num2;
    std::string numberBuffer;
    ListNode *number1, *number2;
    //ListNode *test = new ListNode();

    //check if it opens
    if (!testFile.is_open()) 
    {
        std::cout << "failed to open " << "test_for_add_two_numbers_leetcode.txt" << '\n';
    } 
    else  //program loop
    {        
        for( std::string lineBuffer ;std::getline(testFile, lineBuffer);) //keep reading the file
        {
            //stringBuffer << lineBuffer << lineBuffer;
            stringBuffer.str(lineBuffer);
            stringBuffer >> numberBuffer;
            num1 = std::stoi(numberBuffer);
            stringBuffer >> numberBuffer;
            num2 = std::stoi(numberBuffer);

            stringBuffer.clear();

            //convert to linkedlist
            number1 = toLinkedList(num1);
            number2 = toLinkedList(num2);

            Solution sol = Solution();

            //Strategy 1
            printLinkedList(sol.addTwoNumbers(number1, number2));  

            //Strategy 2
            std::cout << "\nAlternative method\n";
            printLinkedList(sol.addTwoNumbersUsingInt(number1, number2));
            std::cout << "\n\n";        
        }
    }
    return 0;
}