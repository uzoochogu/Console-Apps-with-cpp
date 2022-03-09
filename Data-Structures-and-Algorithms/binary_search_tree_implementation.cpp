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
        TreeNode* insertRecursive(TreeNode* r, TreeNode *new_node)
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
        void print2D(TreeNode* r, int space) 
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


        //Prints the content of the Binary Search Tree in a Preorder DFS (Node, Left, Right)
        void printPreorder(TreeNode* r)
        {
            if(r == NULL)
            {
                return;
            }

            //Access the Node First
            cout << r->value << " ";

            //Access the Left Node 
            printPreorder(r->left);

            //Access the Right Node
            printPreorder(r->right);
        }



        //Prints the content of the Binary Search Tree in a InOrder DFS (Left, Node, Right)
        void printInorder(TreeNode* r)
        {
            if(r == NULL)
            {
                return;
            }

            //Access the Left Node 
            printInorder(r->left);

            //Access the Node First
            cout << r->value << " ";            

            //Access the Right Node
            printInorder(r->right);
        }



        //Prints the content of the Binary Search Tree in a PostOrder DFS (Left, Right, Node)
        void printPostorder(TreeNode* r)
        {
            if(r == NULL)
            {
                return;
            }

            //Access the Left Node 
            printPostorder(r->left);

            //Access the Right Node
            printPostorder(r->right);

            //Access the Node First
            cout << r->value << " ";         
        }


        //Searches the Binary Search tree iteratively.
        TreeNode* iterativeSearch(int v) 
        {
            if (root == NULL)  //The Tree is empty 
            {
                return root;
            }
            else    
            {
                TreeNode * temp = root; //our investigator pointer
                while (temp != NULL) 
                {
                    if (v == temp -> value) 
                    {
                        return temp;
                    } 
                    else if (v < temp -> value)  //Go left if search term is less than current node value
                    {
                        temp = temp -> left;
                    } 
                    else //else go right
                    {
                        temp = temp -> right;
                    }
                }
                return NULL; //NULL will indicate that it wasn't found
            }
        }

        //Searches the Binary Search tree  recursively. Arg: (r)Pointer to Node, (v) search term 
        TreeNode* recursiveSearch(TreeNode* r, int val)
        {
            if (r == NULL || r -> value == val) //r will point to the found search term or NULL 
            {
                return r;
            }              

            else if (val < r -> value)
            {
                return recursiveSearch(r -> left, val);
            }

            else
            {
                return recursiveSearch(r -> right, val);
            }
        }



        /*Height is the number of Edges between tree's root and its furthest leaf. 
        This function computes the height of a node in a BST.*/
        int height(TreeNode* r) 
        {
            if (r == NULL)
            {
                return -1; //Height of an empty tree is designated with -1.
            }
            else 
            {
                /* compute the height of each subtree */
                int lheight = height(r -> left);
                int rheight = height(r -> right);

                /* use the larger one */
                if (lheight > rheight)
                {
                    return (lheight + 1);
                }
                else 
                {
                    return (rheight + 1);
                }
            }
        }

        /* Print nodes at a given level. Utility function for printLevelOrderBFS(TreeNode* r)*/
        void printGivenLevel(TreeNode* r, int level) 
        {
            if (r == NULL) //Base Case
            {
                return;
            }
            else if (level == 0) //Only print when you get to the level (i.e level=0)
            {
                cout << r -> value << " ";
            }
            else // level > 0  
            {
                printGivenLevel(r -> left, level - 1);
                printGivenLevel(r -> right, level - 1);
            }
        }


        /*Prints the nodes of a tree using a Breadth First Search Approach*/
        void printLevelOrderBFS(TreeNode* r) 
        {
            int h = height(r);
            for (int i = 0; i <= h; i++) //Prints level by level
            {   
                printGivenLevel(r, i);
            }
        }



        //Delete a node if it exists. Returns deleted node or NULL if not found.
        TreeNode* deleteNode(TreeNode* r, int v)
        {
            //base case
            

        }


};


//Driver code
int main()
{
    int option;
    int data, val;

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
                cout << "Please input the value to be stored: " ;
                cin >> data;
                new_node->value = data; 
                bst.insertNode(new_node);
                break;

            case 2:
                cout << "SEARCH" << endl;
                cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
                cin >> val;

                //Iterative Search
                cout << "ITERATIVE SEARCH: "; 
                new_node = bst.iterativeSearch(val);
                if (new_node != NULL) 
                {
                    cout << "Value found" << endl;
                } 
                else    
                {
                    cout << "Value NOT found" << endl;
                }
                
                //Recursive Search
                cout << "RECURSIVE SEARCH: "; 
                new_node = bst.recursiveSearch(bst.root, val);
                if (new_node != NULL) 
                {
                    cout << "Value found" << endl;
                } 
                else 
                {
                    cout << "Value NOT found" << endl;
                }

                break;

            case 3:
                cout << "DELETE" << endl;
                //Deletion code


                break;
            
            case 4:
                //Printing code

                cout << "Binary Search Tree 2D print:" << endl;
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
                cout << "HEIGHT of Binary Search Tree:\n Height:  " << bst.height(bst.root) << endl;
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