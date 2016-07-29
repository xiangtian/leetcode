#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN;
        getWeight(root, max);
        return max;
        
    }
private:
    int getWeight(TreeNode* node, int& max) {
        if (node == NULL) {
            return 0;
        }

        int leftWeight = getWeight(node->left, max);
        int rightWeight = getWeight(node->right, max);
        int tmpMax = leftWeight + rightWeight + node->val;
        if (tmpMax > max) {
            max = tmpMax;
        }
        
        int value = node->val + std::max(leftWeight, rightWeight);
        return std::max(value, 0); 
    }

public:
    void testCase() 
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->right = new TreeNode(2);
        root->left->left = new TreeNode(2);
        root->left->left->right = new TreeNode(3);
        root->right = new TreeNode(3);
        cout << maxPathSum(root) << endl;
        cout << maxPathSum(root->left) << endl;
        TreeNode* root1 = new TreeNode(-3);
        cout << maxPathSum(root1) << endl;
        TreeNode* root2 = new TreeNode(-3);
        root2->left = new TreeNode(1);
        root2->left->right = new TreeNode(-4);
        cout << maxPathSum(root2) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
