/*
This program checks if given Binary Tree is a BST
*/

#include "binary_search_tree.hpp"
#include <string>
#include <vector>

class BinaryTree : public BST
{
    public:
        TreeNode *root = nullptr;


        //Checks if the BST is empty or not
        bool isEmpty()
        {
            if(root==nullptr)
                return true;
            else
                return false;
        }

        //Inserts a node in the binary tree. Iterative Approach. Space Complexity O(n)
        void insertNode(TreeNode* new_node) 
        {
            if (root == nullptr) 
            {
                root = new_node;
                cout << "Value Inserted as root node!" << endl;
            } 
            else
            {
                TreeNode * temp = root;
                while (temp != nullptr) //we traverse 
                {
                    if (new_node -> value == temp -> value)  //value already exists
                    {
                        cout << "Value Already exist," <<
                        "Insert another value!" << endl;
                        return;
                    } 
                    // insert at left node if empty and the value is less than current node's value
                    else if ((temp -> left == nullptr))  
                    {
                        temp -> left = new_node;
                        cout << "Value Inserted to the left!" << endl;
                        break;
                    } 
                    // left node is not empty, keep traversing 
                    else if (new_node->value < temp->value) 
                    {
                        temp = temp -> left;
                    } 
                    // insert at right node if empty
                    else if ((temp->right == nullptr)) 
                    {
                        temp -> right = new_node;
                        cout << "Value Inserted to the right!" << endl;
                        break;
                    }
                    else //keep traversing (right node is not empty)
                    {
                        temp = temp -> right;
                    }
                }
            }
    
        }

        
};

void storeInorder(TreeNode* r, std::vector<int> &out)
{
    if(r == nullptr)
    {
        return;
    }

    //Access the Left Node 
    storeInorder(r->left, out);

    //Access and store node content
    out.push_back(r->value);         

    //Access the Right Node
    storeInorder(r->right, out);
}

bool isBinaryTreeBST(TreeNode* tree_root)
{
    std::vector<int> tree_values;
    storeInorder(tree_root, tree_values);

    for(unsigned int i = 1; i < tree_values.size(); i++)
    {
        if(tree_values[i-1] > tree_values[i])
        {
            return false;
        }

    }
    return true;
}

int main()
{
    //Prompt to enter a Binary Tree
    int option;
    int data, val;

    BinaryTree bst;
    


    do
    {
        cout << "What operation do you want to perform? "
        << " Select Option number. Enter 0 to exit." <<endl;
        cout << "0. Exit Program" <<endl;
        cout << "1. Insert Node" <<endl;
        cout << "2. Test for BST" <<endl;
        cout << "3. Delete Node" <<endl;
        cout << "4. Print BST value" <<endl;
        cout << "5. HEIGHT of Binary Search Tree " <<endl;
        cout << "6. Clear Screen" <<endl; 

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
                cout << "(Note that the Left branch is filled first before the Right): \n" ;
                cout << "Please input the value to be stored: " ;
                cin >> data;
                new_node->value = data; 
                bst.insertNode(new_node);
                break;

            case 2:
                cout << "Test for BST" << endl;
                bst.print2D(bst.root, 5);

                if(isBinaryTreeBST(bst.root))
                    cout << "\nYES it is a Binary Search Tree\n";
                else
                    cout << "\nNo it not a Binary Search Tree\n";              

                break;

            case 3:
                cout << "DELETE" << endl;
                //Deletion code

                cout << "Enter VALUE of Tree Node you want to DELETE in BST: ";
                cin >> val;

                //Check if Node exists
                new_node = bst.iterativeSearch(val);
                if(new_node != nullptr)
                {
                    bst.deleteNode(bst.root, val);
                    cout << "Value Deleted" << endl;
                }
                else
                {
                    cout << "Value NOT found" << endl;
                }              
                break;
            
            case 4:
                //Printing code

                cout << "Binary Tree 2D print:" << endl;
                bst.print2D(bst.root, 5);

                cout << "\n\n\n";

                //DFS Printing Techniques
                cout << "DFS Printing Techniques:\n";
                cout << "PreOrder Printing: ";
                bst.printPreorder(bst.root);
                cout << "\nInOrder Printing: "; 
                bst.printInorder(bst.root);
                cout << "\nPostOrder Printing: ";
                bst.printPostorder(bst.root);

                //BFS Printing Techniques
                cout << "\n\nBFS Printing Techniques: \n";
                bst.printLevelOrderBFS(bst.root);

                break;

            case 5:
                cout << "HEIGHT of Binary Tree:\n Height:  " << bst.height(bst.root) << endl;
                break;  


            case 6:
                system("cls"); //For GCC, for Turbo cpp use "clrscr"
                break;

            default:
                cout << "Enter proper option number" << endl;
                break;

            

                
        }
    } while (option != 0);
    







    return 0;
}
