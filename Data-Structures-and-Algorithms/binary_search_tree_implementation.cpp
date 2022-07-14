#include "binary_search_tree.hpp"

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
                if (new_node != nullptr) 
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
                if (new_node != nullptr) 
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