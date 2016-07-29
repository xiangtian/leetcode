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
    bool isBalanced(TreeNode *root) {
        bool isBalance = true;
        int depth = getDepth(root, isBalance);
        return isBalance;

    }
private:
    int getDepth(TreeNode* root, bool& isBalance)
    {
        if(!isBalance || root == NULL)
        {
            return 0;
        }
        else
        {
            int leftChildDepth = getDepth(root->left, isBalance);
            int rightChildDepth = getDepth(root->right, isBalance);
            if (leftChildDepth < rightChildDepth) {
                if ((rightChildDepth - leftChildDepth) > 1)
                {
                    isBalance = false;
                }
                return  rightChildDepth + 1;
            }
            else
            {
                if ((leftChildDepth -rightChildDepth) > 1)
                {
                    isBalance = false;
                }
                return leftChildDepth + 1;
            }
        }
    }

public:
    void testCase() {
        TreeNode* root = new TreeNode(0);
        TreeNode* left = new TreeNode(1);
        TreeNode* right = new TreeNode(2);
        root->left = left;
        root->right = right;
        cout << isBalanced(root) << endl;
        left->left = new TreeNode(3); 
        cout << isBalanced(root) << endl;
        left->left->left = new TreeNode(4); 
        cout << isBalanced(root) << endl;
    }

};

int main(void)
{
    Solution s;
    s.testCase();
}
