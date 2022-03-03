#include <iostream>
using namespace std;


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
        TreeNode *root;


        //Checks if the BST is empty or not
        bool isEmpty()
        {
            if(root==NULL)
                return true;
            else
                return false;
        }


        //Inserts a node in the binary search tree
        void insertNode(TreeNode * new_node) 
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
                    if (new_node -> value == temp -> value) 
                    {
                        cout << "Value Already exist," <<
                        "Insert another value!" << endl;
                        return;
                    } 
                    else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) 
                    {
                        temp -> left = new_node;
                        cout << "Value Inserted to the left!" << endl;
                        break;
                    } 
                    else if (new_node -> value < temp -> value) 
                    {
                        temp = temp -> left;
                    } 
                    else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) 
                    {
                        temp -> right = new_node;
                        cout << "Value Inserted to the right!" << endl;
                        break;
                    }
                    else
                    {
                        temp = temp -> right;
                    }
                }
            }
    
        }


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


};


//Driver code
int main()
{
    int option;

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

        cin >> option;

        switch(option)
        {
            case 0: 
                break;
            case 1:
                cout << "INSERT" << endl;
                //Insertion code
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