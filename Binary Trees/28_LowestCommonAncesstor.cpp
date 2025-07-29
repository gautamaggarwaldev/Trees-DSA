#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns != NULL)
        {
            return leftAns;
        }
        else if (rightAns != NULL)
        {
            return rightAns;
        }
        else
            return NULL;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode *p = root->left; // Node with value 5
    TreeNode *q = root->right; // Node with value 1
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);
    
    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "No Common Ancestor found." << endl;

    return 0;   
}