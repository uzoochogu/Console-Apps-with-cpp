#include <iostream>


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
        ListNode* sum = new ListNode(); //head node for the sum
        ListNode* travelerNode1 = l1;
        ListNode* travelerNode2 = l2; 
        ListNode* newDigit = new ListNode(); //keeps track of next digit ListNode
        
        
        
        int carry = 0; //we'll keep track of the carry between digits
        int intermediateSum = 0;
        
        while(travelerNode1->next == nullptr && travelerNode2->next == nullptr)
        {

            intermediateSum = 0;

            //Create new Node
            ListNode* newDigit = new ListNode();
            
            //Base case: One is longer than the other
            if(travelerNode1->next == nullptr && travelerNode2->next != nullptr ) //l1 is longer
            {
                intermediateSum = travelerNode1->val + carry;

                if(intermediateSum > 9)
                {
                    newDigit->val = intermediateSum % 10;
                    newDigit->next = new ListNode(intermediateSum/10);
                }

            }
            else if (travelerNode1->next != nullptr && travelerNode2->next== nullptr) //l2 is longer
            {
                intermediateSum = travelerNode2->val + carry;

                if(intermediateSum > 9)
                {
                    newDigit->val = intermediateSum % 10;
                    newDigit->next = new ListNode(intermediateSum/10);
                }
            }

            //sum->val = l1->val + l2->val;
            //sum->next = addTwoNumbers(l1->next, l2->next);

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

        return sum;
        
    }
};



int main()
{


    return 0;
}