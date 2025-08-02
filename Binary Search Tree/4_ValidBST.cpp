#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool check(TreeNode *root, long long min, long long max)
    {
        if (root == NULL)
            return true;
        if (root->val > max || root->val < min)
        {
            return false;
        }
        bool leftAns = check(root->left, min, (long long)root->val - 1); // call for left subtree with updated max
        bool rightAns = check(root->right, (long long)root->val + 1, max); // call for right subtree with updated min

        if (rightAns && leftAns)
        {
            return true;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
int main()
{
    TreeNode *a = new TreeNode(7);
    TreeNode *b = new TreeNode(5);
    TreeNode *c = new TreeNode(10);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(6);
    TreeNode *f = new TreeNode(9);
    TreeNode *g = new TreeNode(12);

    a->right = c;
    a->left = b;
    b->right = e;
    b->left = d;
    c->right = g;
    c->left = f;

    Solution sol;
    if (sol.isValidBST(a))
    {
        cout << "The tree is a valid Binary Search Tree." << endl;
    }
    else
    {
        cout << "The tree is not a valid Binary Search Tree." << endl;
    }

    return 0;
}