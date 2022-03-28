#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

/*
Description

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.


Testing the Code:
We would use a text file to test the code. 
Each line will contain two numbers separated by a white space.

The driver code will run through each line until EOF is reached calling the
addTwoNumbers method from the solution class.




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




//Put your solution here
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newDigit; //Node to keep track of next digit ListNode
        
        //For the first digit
        ListNode* sum = new ListNode((l1->val + l2->val) % 10); //head node for the sum
        
        int carry = (l1->val + l2->val) / 10; //we'll keep track of the carry between digits
        int intermediateSum;  //Stores sum per digit

        sum->next = newDigit; 
        ListNode* travelerNode1 = l1->next;
        ListNode* travelerNode2 = l2->next; 
        
        //TODO: Add functionality to add varying length LinkedList
        while(travelerNode1 != nullptr && travelerNode2 != nullptr)
        {

            intermediateSum = 0;

            //Create new Node
            //ListNode* newDigit = new ListNode();
            
            //Base case: One is longer than the other
            if(travelerNode1 == nullptr && travelerNode2 != nullptr ) //l1 is longer
            {
                intermediateSum = travelerNode1->val + carry;

                if(intermediateSum > 9)
                {
                    newDigit->val = intermediateSum % 10;
                    newDigit->next = new ListNode(intermediateSum/10);
                }
                return sum;
            }
            else if (travelerNode1->next != nullptr && travelerNode2->next== nullptr) //l2 is longer
            {
                intermediateSum = travelerNode2->val + carry;

                if(intermediateSum > 9)
                {
                    newDigit->val = intermediateSum % 10;
                    newDigit->next = new ListNode(intermediateSum/10);
                }
                return sum;
            }

            //sum->val = l1->val + l2->val;
            //sum->next = addTwoNumbers(l1->next, l2->next);

            else
            {
                intermediateSum = (travelerNode1->val + travelerNode2->val + carry) % 10;
                newDigit->val = intermediateSum;
                carry = intermediateSum/10;

                //Move to the next node
                travelerNode1 = travelerNode1->next;
                travelerNode2 = travelerNode2->next;  

                //we move to the next Digit ListNode
                newDigit->next = new ListNode();
                newDigit = newDigit->next;   

            }

        }

        return sum;
    }
   
};

//Driver Code to test Solution.

/*This function will convert a number to a linkedList of digit.
It returns the head of the list
*/
ListNode* toLinkedList(int val)
{
    ListNode* head = new ListNode(val%10);
    ListNode* traverse = head;
    std::cout << "We converted "<< val << " to Linked List!\n";

    //TODO: Fix algorithm to extract digits
    for(int i=1;  val/int(std::pow(10.0, i)) != 0; i++ )
    {
        traverse->next =  new ListNode(val/int(std::pow(10.0, i)));
        traverse = traverse->next;    
    }
    return head;
}

/*Prints the linked list in the correct order */
void printLinkedList(ListNode* head)
{
    std::cout << "Printing Works\n";     
    ListNode* traverse = head;
    std::cout << "( ";
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

            printLinkedList(sol.addTwoNumbers(number1, number2));           
             

        }

    }

    return 0;
}