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
            left = nullptr;
            right = nullptr;
        }
        TreeNode(int v)
        {
            value = v;
            left = nullptr;
            right = nullptr;
        }

};


class BST
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


        //Inserts a node in the binary search tree. Iterative Approach. Space Complexity O(n)
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
                    else if ((new_node->value < temp->value) && (temp -> left == nullptr))  
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
                    else if ((new_node->value > temp->value) && (temp->right == nullptr)) 
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
            if(r==nullptr)
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
            if (r == nullptr) // Base case  1
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
            if(r == nullptr)
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
            if(r == nullptr)
            {
                return;
            }

            //Access the Left Node 
            printInorder(r->left);

            //Access the Node
            cout << r->value << " ";            

            //Access the Right Node
            printInorder(r->right);
        }



        //Prints the content of the Binary Search Tree in a PostOrder DFS (Left, Right, Node)
        void printPostorder(TreeNode* r)
        {
            if(r == nullptr)
            {
                return;
            }

            //Access the Left Node 
            printPostorder(r->left);

            //Access the Right Node
            printPostorder(r->right);

            //Access the Node
            cout << r->value << " ";         
        }


        //Searches the Binary Search tree iteratively.
        TreeNode* iterativeSearch(int v) 
        {
            if (root == nullptr)  //The Tree is empty 
            {
                return root;
            }
            else    
            {
                TreeNode * temp = root; //our investigator pointer
                while (temp != nullptr) 
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
                return nullptr; //nullptr will indicate that it wasn't found
            }
        }

        //Searches the Binary Search tree  recursively. Arg: (r)Pointer to Node, (v) search term 
        TreeNode* recursiveSearch(TreeNode* r, int val)
        {
            if (r == nullptr || r -> value == val) //r will point to the found search term or nullptr 
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
            if (r == nullptr)
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
            if (r == nullptr) //Base Case
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



        TreeNode* minValueNode(TreeNode* node)
        {
            TreeNode* current = node;

            //Loop to get leftmost leaf
            while(current->left != nullptr)
            {
                current = current->left;
            }
            return current;
        }


        //Delete a node if it exists. Returns deleted node or nullptr if not found.
        TreeNode* deleteNode(TreeNode* r, int v)
        {
            //base case
            if(r == nullptr)
            {
                return r;
            }
            else if(v < r->value) //search term smaller, go left
            {
                r->left = deleteNode(r->left , v); //We basically disconnect the deleted node
            }
            else if(v > r->value) //search term larger, go right
            {
                r->right = deleteNode(r->right, v); //We basically disconnect the deleted node
            }
            else //When a Match is found
            {
                TreeNode* temp = nullptr;
                if(r->left == nullptr) //Node only has a right child OR no child
                {
                    temp = r->right;
                    delete r;
                    return temp;
                }
                else if(r->right == nullptr) //Node with only left child
                {
                    temp = r->left ;
                    delete r;
                    return temp;
                }
                else //node with TWO children
                {
                    temp = minValueNode(r->right);
                    r->value = temp->value;
                    r->right = deleteNode(r->right, temp->value);

                }
            }

            return r; //We return this to relink the nodes the recursive stack
            

        }


};
