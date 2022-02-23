#include <iostream>
using namespace std;

/*
We would implement the following operations:
1. appendNode()
2. prependNode()
3. insertNodeAfter()
4. deleteNodeByKey()
5. updateNodeByKey()
6. print()
*/


//Node Class
class Node
{
    public:
        int key;
        int data;
        Node* next;

    Node()
    {
        key=0;
        data=0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }  

};


// Singly linked list class
class SinglyLinkedList
{
    public:
        Node* head;

        SinglyLinkedList()
        {
            head = NULL;;
        }

        SinglyLinkedList(Node *n)
        {
            head = n;
        }

        //Check if node exists using ley value
        Node * nodeExists(int k) 
        {
            Node* temp =NULL;

            Node* ptr = head;

            while(ptr != NULL)
            {
                if(ptr->key == k)
                {
                    temp = ptr; 
                }
                ptr = ptr->next;
            }
            return temp; 
        }

        //Appends a node to the list, we append at the end
        void appendNode(Node *n)
        {
            if(nodeExists(n->key) != NULL) //same key exists
            {
                cout << "Node already exists with key value: " << n->key  
                << ". Append another node with different Key value" << endl;
            }
            else
            {
                if(head==NULL) //No linked list
                {
                    head= n;
                    cout << "Node Appended" << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                    cout << "Node Appended" << endl;
                }
            }
        }


        //Prepend a node to the list - we attach a node to the start
        void appendNode(Node* n)
        {
            if(nodeExists(n->key) != NULL) //same key exists
            {
                cout << "Node already exists with key value: " << n->key  
                << ". Append another node with different Key value" << endl;
            }
            else
            {
                n->next=head;
                head = n;
                cout << "Node Prepended" << endl;
            }
        }


        //Insert a Node after a particular node in the list
        void insertNodeAfter (int k, Node *n)
        {
            Node* ptr = nodeExists(k); //store the location to insert after
            if(ptr==NULL)
            {
                cout <<"No node exists with key value: " << k << endl;
            }
            else
            {
                if(nodeExists(n->key) != NULL)  //same key exists
                {
                    cout << "Node already exists with key value: " << n->key  
                    << ". Append another node with different Key value" << endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next=n;
                    cout << "Node Inserted" << endl;
                }
            }
        }

        //Delete Node by unique key
        void deleteNodeByKey(int k)
        {
            if(head==NULL)
            {
                cout << "Singly Linked List already empty, Can't delete" << endl;                
            }
            else
            {
                if(head->key==k)
                {
                    head = head->next;
                    cout << "Node UNLINKED with key value: " <<k<<endl;
                }
                else
                {
                    Node* temp=NULL;
                    Node* prevptr=head;
                    Node*  currentptr = head->next;
                    while(currentptr != NULL) //while not the tail node or we have a match
                    {
                        if(currentptr->key==k) //check for match
                        {
                            temp = currentptr;
                            currentptr=NULL;
                        }

                        else //no match keep going
                        {
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }

                    if(temp !=NULL)
                    {
                        prevptr->next=temp->next;
                        cout << "Node UNLINKED with key value: " <<k<<endl;
                    }
                    else
                    {
                        cout << "Node Doesn't exist with key vlaue: "<<k<<endl;
                    }
                }
            }
        }


    //Update node by key
    void updateNodeByKey(int k, int d)
    {
        Node* ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout << "Node Data updated successfully"<<endl;
        }
        else
        {
            cout<<"Node Odesn't exist with key value: "<<k<<endl;
        }
    }

    //Printing of the SinglyLinkedList 
    void printList()
    {
        if(head==NULL)
        {
            cout << "No Nodes in singly Linked List";
        }
        else
        {
            cout << endl << "Singly Linked List calues:  ";
            Node* temp = head;

            while(temp!=NULL)
            {
                cout << "(" <<temp->key<<","<<temp->data<<") --> ";
                temp = temp->next;
            }
        }

        cout <<endl;
    }


};

int main()
{
     

    return 0;
}