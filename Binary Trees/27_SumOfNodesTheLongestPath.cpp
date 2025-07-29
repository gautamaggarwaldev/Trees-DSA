#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void solve(Node *root, int sum, int len, int &maxLen, int &maxSum)
    {
        if (root == NULL)
        {
            if (len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            if (len == maxLen)
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        sum += root->data;
        solve(root->left, sum, len + 1, maxLen, maxSum);
        solve(root->right, sum, len + 1, maxLen, maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int sum = 0;
        int maxLen = 0;
        int maxSum = INT_MIN;
        solve(root, sum, len, maxLen, maxSum);
        return maxSum;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);
    cout << "Sum of nodes in the longest path: " << result << endl;

    return 0;
}