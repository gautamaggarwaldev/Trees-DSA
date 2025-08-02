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
    TreeNode *solve(vector<int> &pre, long long min, long long max, int &i)
    {
        if (i >= pre.size())
            return NULL;
        if (pre[i] < min || pre[i] > max)
            return NULL;
        TreeNode *temp = new TreeNode(pre[i++]);
        temp->left = solve(pre, min, temp->val, i);
        temp->right = solve(pre, temp->val, max, i);
        return temp;
    }
    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        int i = 0;
        return solve(pre, LLONG_MIN, LLONG_MAX, i);
    }
};
int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode *root = sol.bstFromPreorder(preorder);
}