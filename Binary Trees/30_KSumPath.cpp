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
    void solve(Node *root, vector<int> path, int k, int &count)
    {
        if (root == NULL)
            return;
        path.push_back(root->data);
        solve(root->left, path, k, count);
        solve(root->right, path, k, count);
        int sum = 0;
        int n = path.size();
        for (int i = n - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, path, k, count);
        return count;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    int k = 7;
    int result = sol.sumK(root, k);
    
    cout << "Number of paths with sum " << k << ": " << result << endl;
    
    return 0;
}