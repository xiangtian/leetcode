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
    int minDepth(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }

        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);
        // has no left child
        if (lDepth == 0) {
            return rDepth + 1;
        }

        // has no right child
        if (rDepth == 0) {
            return lDepth + 1;
        }
        return lDepth < rDepth ? (lDepth + 1) : (rDepth + 1);
    }
public:
    void testCase()
    {
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        cout << minDepth(root) << endl;
        root->right = new TreeNode(2);
        cout << minDepth(root) << endl;
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        cout << minDepth(root) << endl;
        root->right->left->left = new TreeNode(5);
        cout << minDepth(root) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
