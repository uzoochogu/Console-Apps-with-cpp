#include <iostream>
using namespace std;

#define SPACE 10


class TreeNode
{
    public:
        int value;  //key or data
        TreeNode* left;
        TreeNode* right;

        TreeNode()
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
        TreeNode(int v)
        {
            value = v;
            left = NULL;
            right = NULL;
        }

};


class BST
{
    public:
        TreeNode *root = NULL;


        //Checks if the BST is empty or not
        bool isEmpty()
        {
            if(root==NULL)
                return true;
            else
                return false;
        }


        //Inserts a node in the binary search tree. Iterative Approach. Space Complexity O(n)
        void insertNode(TreeNode* new_node) 
        {
            if (root == NULL) 
            {
                root = new_node;
                cout << "Value Inserted as root node!" << endl;
            } 
            else
            {
                TreeNode * temp = root;
                while (temp != NULL) //we traverse 
                {
                    if (new_node -> value == temp -> value)  //value already exists
                    {
                        cout << "Value Already exist," <<
                        "Insert another value!" << endl;
                        return;
                    } 
                    // insert at left node if empty and the value is less than current node's value
                    else if ((new_node->value < temp->value) && (temp -> left == NULL))  
                    {
                        temp -> left = new_node;
                        cout << "Value Inserted to the left!" << endl;
                        break;
                    } 
                    // left node is not empty, but still less than current node's value, keep traversing 
                    else if (new_node->value < temp->value) 
                    {
                        temp = temp -> left;
                    } 
                    // insert at right node if empty and the value is less than current node's value
                    else if ((new_node->value > temp->value) && (temp->right == NULL)) 
                    {
                        temp -> right = new_node;
                        cout << "Value Inserted to the right!" << endl;
                        break;
                    }
                    else //keep traversing (right node is not empty, but still less than current node's value)
                    {
                        temp = temp -> right;
                    }
                }
            }
    
        }

        //Inserts a node in the binary search tree. Recursive Approach.Space complexity O(H) i.e proportional to Height
        TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
        {
            if(r==NULL)
            {
                r=new_node;
                cout <<"Insertion successful"<<endl;
                return r;
            }
        
            if(new_node->value < r->value)
            {
                r->left = insertRecursive(r->left,new_node);
            }
            else if (new_node->value > r->value)  
            {
                r->right = insertRecursive(r->right,new_node);
            }
            else
            {
                cout << "No duplicate values allowed!" << endl;
                return r; 
            }
            return r;
        }

        //Prints the content of the tree in a strucured way. Recursive Approach
        void print2D(TreeNode * r, int space) 
        {
            if (r == NULL) // Base case  1
            {
                return;
            }
                
            space += SPACE; // Increase distance between levels   2
            print2D(r -> right, space); // Process right child first 3 
            cout << endl;
            for (int i = SPACE; i < space; i++) // 5 
            {
                cout << " "; // 5.1 
            }
                 
            cout << r -> value << "\n"; // 6
            print2D(r -> left, space); // Process left child  7
        }


};


//Driver code
int main()
{
    int option;
    int data;

    BST bst;
    


    do
    {
        cout << "What operation do you want to perform? "
        << " Select Option number. Enter 0 to exit." <<endl;
        cout << "0. Exit Program" <<endl;
        cout << "1. Insert Node" <<endl;
        cout << "2. Search Node" <<endl;
        cout << "3. Delete Node" <<endl;
        cout << "4. Print BST value" <<endl;
        cout << "5. Clear Screen" <<endl; 

        cout << "\n\nOption: ";

        cin >> option;

        TreeNode* new_node = new TreeNode();

        switch(option)
        {
            case 0: 
                break;
            case 1:
                cout << "INSERT" << endl;
                //Insertion code
                cout << "Please input the value to be stored: " ;
                cin >> data;
                new_node->value = data; 
                bst.insertNode(new_node);
                break;

            case 2:
                cout << "Search" << endl;
                //Search code
                break;

            case 3:
                cout << "DELETE" << endl;
                //Deletion code
                break;
            
            case 4:
                //Printing code

                cout << "Binary Search Tree 2D print:" << endl;
                bst.print2D(bst.root, 5);

                break;

            case 5:
                system("cls"); //For GCC, for Turbo cpp use "clrscr"
                break;

            default:
                cout << "Enter proper option number" << endl;
                break;

            

                
        }
    } while (option != 0);
    




    return 0;
}