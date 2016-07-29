#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL )
        {
            return root;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    void testCase()
    {
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->left->right = new TreeNode(3);
        root = invertTree(root);
        cout << root->right->left->val << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
