#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &in)
    {
        if (root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode *makeBST(int s, int e, vector<int> &in)
    {
        if (s > e)
            return NULL;
        int mid = (s + e) / 2;
        TreeNode *temp = new TreeNode(in[mid]);
        temp->left = makeBST(s, mid - 1, in); // Recursively build left subtree
        temp->right = makeBST(mid + 1, e, in); // Recursively build right subtree
        // The inorder traversal ensures that the tree remains balanced
        return temp;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> in;
        inorder(root, in);
        return makeBST(0, in.size() - 1, in);
    }
};
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;
    TreeNode *balancedRoot = sol.balanceBST(root);

    cout << "Inorder traversal of the balanced BST: ";
    vector<int> in;
    sol.inorder(balancedRoot, in);
    for (int val : in)
        cout << val << " ";
    cout << endl;

    return 0;
}