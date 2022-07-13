/*
This program checks if given Binary Tree is a BST
*/

#include "binary_search_tree.hpp"

std::string storeInorder(TreeNode* r, std::string &out)
{
    if(r == NULL)
    {
        return out;
    }

    //Access the Left Node 
    storeInorder(r->left, out);

    //Access the Node First
    out.push_back(r->value);
    out.push_back(' ');         

    //Access the Right Node
    storeInorder(r->right, out);
}

bool isBinaryTreeBST(BST* tree)
{
    std::string tree_values;
    tree_values = storeInorder(tree->root, tree_values);

    for(unsigned int i = 1; i < tree_values.size(), i++)
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
    






    return 0;
}
