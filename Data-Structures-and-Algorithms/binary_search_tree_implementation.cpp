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