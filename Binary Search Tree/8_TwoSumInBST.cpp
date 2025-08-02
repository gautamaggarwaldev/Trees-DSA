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

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> in;
        inorder(root, in);

        int n = in.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            int sum = in[i] + in[j];
            if (sum == k)
            {
                return true;
            }
            if (sum < k)
            {
                i++;
            }
            else
                j--;
        }
        return false;
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

    int k;
    cout << "Enter the target sum k: ";
    cin >> k;

    Solution sol;
    if (sol.findTarget(root, k))
        cout << "There are two elements in the BST that add up to " << k << "." << endl;
    else
        cout << "No two elements in the BST add up to " << k << "." << endl;

    return 0;
}