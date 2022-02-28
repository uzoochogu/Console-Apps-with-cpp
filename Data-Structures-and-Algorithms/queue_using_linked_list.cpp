#include <iostream>
using namespace std;


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

//Queue class
class Queue
{
    public:
        Node *front;
        Node *rear;

        //Default Constructor
        Queue()
        {
            front = NULL;
            rear = NULL;
        }

        //Parameterized Constructor
        Queue( Node* front, Node* rear) : front(front), rear(rear) {}


        //Checks if both the front and rear are pointing to null
        bool isEmpty()
        {
            if (front==NULL && rear==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool checkIfNodeExists(Node* n)
        {
            Node* temp = front;
            bool exist = false;

            while(temp != NULL)
            {
                if(temp->key == n->key)
                {
                    exist = true;
                    break;
                }
                temp = temp->next;
            }
            return exist;
        }

        //Add elements to the Queue
        void enqueue(Node* n)
        {
            if(isEmpty())
            {
                front = n;
                rear = n;
                cout << "Node ENQUEUED successfully" << endl;
            }
            else if(checkIfNodeExists(n))
            {
                cout << "Node already exist with this key value."
                <<"Enter different Key value" <<endl;
            }
            else
            {
                rear->next=n;
                rear=n; //because new rear

                cout << "Node ENQUEUED successfully" <<endl;
            }

        }

        //Dequeue operation happens at the front (FIFO)
        Node* dequeue()
        {
            Node* temp=NULL;
            if(isEmpty())
            {
                cout << "Queue is Empty" <<endl;
                return NULL;
            }
            else
            {
                if(front == rear) //has only one element
                {
                    temp=front;
                    front = NULL;
                    rear = NULL;
                    return temp;
                }
                else
                {
                    temp=front;
                    front = front->next;
                    return temp;
                }

                cout << "Node DEQUEUED successfully" <<endl;
            }
        }
        
        //Returns the count of elements in the array
        int count()
        {
            int count = 0;
            Node* temp = front;

            while(temp != NULL)
            {
                count++;
                temp= temp->next;
            }
            return count;
        }

        //Displays the Queue
        void display()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" <<endl;
            }
            else 
            {
                cout << "All values in the Queue are: " << endl;
                Node* temp = front;
                while(temp != NULL)
                {
                    cout <<"(" << temp->key <<", " << temp->data
                    << ")" << " -> ";
                    temp = temp->next;
                }
            }

        }

};

int main()
{


    Queue q;
    int option, key, data;

    do
    {
        cout << "What operation do you want to perform"
        <<" Select Option number. Enter 0 to exit." <<endl;

        cout << "1. Enqueue()" <<endl;
        cout << "2. Dequeue()" <<endl;
        cout << "3. isEmpty()" <<endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl << endl ;

        cin >> option;

        Node* new_node = new Node();


        switch (option) 
        {
            case 0:
                break;

            case 1:
                cout << "ENQUEUE Function Called -" <<endl;
                cout << "Enter KEY and VALUE of NODE to ENQUEUE "
                << "in the Queue" <<endl;
                cin >> key;
                cin >> data;
                new_node->key = key;
                new_node->data = data;
                q.enqueue(new_node);
                break;
                

            case 2:
                cout << "DEQUEUE Function Called - " << endl;
                new_node = q.dequeue();
                cout << "Dequeue Value is: (" << new_node->key
                << ", " << new_node->data <<")" <<endl;
                delete new_node;
                break;


            case 3:
                cout << "isEmpty Function Called - " << endl;
                if (q.isEmpty())
                {
                    cout << "Queue is Empty" <<endl;                    
                }
                else
                {
                    cout << "Queue is NOT Empty" << endl;
                }
                break;

            case 4:
                cout << "Count Function Called - " << endl;
                cout << "No of Nodes in the Queue: " << q.count() << endl;
                break;

            case 5:
                cout << "Display Function Called - " <<endl;
                q.display();
                cout << endl;
                break;

            case 6:
                system("cls");
                break;

            default:
                cout << "Enter Proper Option number " << endl;

        }



    }while(option !=0);


    return 0;
}