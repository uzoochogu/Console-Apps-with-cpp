#include <iostream>
using namespace std;


class Node
{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
            previous=NULL;
        }

        Node(int k, int d)
        {
            key=k;
            data=d;
        }

};

class DoublyLinkedList
{
    public:
        Node* head;

        DoublyLinkedList()
        {
            head=NULL;
        }

        DoublyLinkedList(Node *n)
        {
            head=n;
        }

        //1. Check if the Node Exists using Key value.
        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->next; 
            }

            return temp;
        }


        //2. Append a node to the list

        void appendNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout << "Node already exists with key value: " << n->key  
                << ". Append another node with different Key value" << endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout << "Node Appended as Head Node" << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next!=NULL) //iterate to the tail node
                    {
                        ptr = ptr->next;
                    }
                    ptr->next=n;
                    n->previous = ptr; //Doubly Linked List so we connect to previous node
                    cout << "Node Appended" <<endl;
                }
            }
        } 

        //3. Prepend Node - Attach a node at the start
        void prependNode(Node* n)
        {
            if(nodeExists(n->key) != NULL) //same key exists
            {
                cout << "Node already exists with key value: " << n->key  
                << ". Append another node with different Key value" << endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout << "Node Prepended as Head Node" << endl;
                }
                else
                {
                    head->previous=n;
                    n->next=head;

                    head = n;
                    cout << "Node Prepended" << endl;
                }
                
            }
        }

        //4. Insert a Node after a particular node in the list
        void insertNodeAfter(int k, Node *n)
        {
            Node* ptr = nodeExists(k); //store the location to insert after
            if(ptr==NULL) //Insert point does not exist
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(nodeExists(n->key) != NULL) //same key exists
                {
                    cout << "Node already exists with key value: " << n->key  
                    << ". Append another node with different Key value" << endl;
                }
                else
                {
                    cout << "INSERTING" <<endl;

                    Node* nextNode = ptr->next;

                    //Inserting at the end -> append
                    if(nextNode==NULL)
                    {
                        ptr->next=n;
                        n->previous=ptr;
                        cout<<"Node Inserted at the END"<<endl;
                    }

                    //inserting in between
                    else
                    {
                        n->next=nextNode;
                        nextNode->previous=n;

                        n->previous=ptr;
                        ptr->next=n;

                        cout<< "Node Inserted in Between" <<endl;
                    }
                }
            }
        }

        //5. Deleting a Node by unique key. Delinking (Not deleting)
        void deleteNodeByKey(int k)
        {
            if(head==NULL)
            {
                 cout << "Doubly Linked List already empty, Can't delete" << endl;
            }
            Node* ptr = nodeExists(k); //iterates and return the node with key or null
            if(ptr==NULL)
            {
                cout << "No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(head->key==k)
                {
                    head = head->next; //unlinked the previous head node not deleted
                    cout << "Node UNLINKED with keys value : "<<k<<endl;
                }
                else
                {
                    //Old implementation used extra pointers to store these. There are not needed
                    //Uncomment line with //* for old implementation
                    //* Node* nextNode = ptr->next;
                    //* Node* prevNode = ptr->previous;

                    //Deleting at the end
                    if(ptr->next == NULL) //We are at the tail node
                    {
                        //* prevNode->next= NULL; 
                        (ptr->previous)->next = NULL; 
                        cout<<"Node DELETED(UNLINKED) at the END"<<endl;
                    }
                    //deleting in between
                    else
                    {
                        //* prevNode->next=nextNode;
                        //* nextNode->previous=prevNode;

                        (ptr->previous)->next = ptr->next;   //we use the pointers to access the nodes directly                      
                        (ptr->next)->previous = ptr->previous;
                        cout<<"Node DELETED(UNLINKED) in-between" <<endl;
                    }
                }

            }
        }

        //6. Update Node
        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k); //iterates through the list
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data Updated Successfully"<<endl;
            }
            else
            {
                cout<<"Node Doesn't exist with key value : "<<k<<endl;
            }
        }

        //7. Printing
        void printList()
        {
            if(head==NULL)
            {
                cout << "No Node in Doubly Linked List";
            }
            else
            {
                cout << endl << "Doubly Linked List values:  ";
                Node* temp = head;

                while(temp!=NULL)
                {
                    cout << "(" <<temp->key<<", "<<temp->data<<") <==> ";
                    temp = temp->next;
                }

            }
            cout <<endl;
        }
        

};


int main()
{
    //We'll use this to test the DoublyLinkedList
     DoublyLinkedList dll;

     int option;
     int key1,k1,data1;
     do
     {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit."<<endl;
        cout << "1. appendNode()" <<endl;
        cout << "2. prependNode()" <<endl;
        cout << "3. insertNodeAfter()" <<endl;
        cout << "4. deleteNodeByKey()" <<endl;
        cout << "5. updateNodeByKey()" <<endl;
        cout << "6. print()" <<endl;
        cout << "7. Clear Screen" <<endl<<endl;

        cin >> option;
        Node* n1 = new Node(); //Create on Heap to prevent wastage of memory, this creation is global and is not deleted btw iterations

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Append Node Operation \nEnter key & data of the Node to be Appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
             dll.appendNode(n1);
                break;

            case 2:
                cout<<"Prepend Node Operation \nEnter key & data of the Node to be Prepended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
             dll.prependNode(n1);
                break;

            case 3:
                cout<< "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: "<<endl;
                cin>>k1;
                cout<<"Enter key of the New Node first: "<<endl;
                cin>>key1;
                n1->key=key1;
                cout<<"Enter data of the New Node : "<<endl;
                cin>>data1;
                n1->data=data1;

             dll.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout<<"Delete Node By Key Operation - \nEnter key of the Node to be deleted: "<<endl;
                cin>>k1;
             dll.deleteNodeByKey(k1);

                break;
            
            case 5:
                cout<<"Update Node By Key Operation - \nEnter key & New data to be Update.\nKey: ";
                cin >> key1;
                cout<<"Data: ";
                cin>> data1;
             dll.updateNodeByKey(key1,data1);

                break;

            case 6:
             dll.printList();

                break;
            case 7:
                system("cls");
                break;

            default:
                cout<<"Enter Proper Option number" << endl;




        }
     } while (option !=0);


    return 0;
}