#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(NULL);
        int nodeCount = 0;
        while(!nodes.empty())
        {
            TreeNode* top = nodes.front();
            nodes.pop();
            if (top)
            {
                nodeCount++;
                if (top->left) {
                    nodes.push(top->left);
                }

                if (top->right) {
                    nodes.push(top->right);
                }
            }
            else
            {
                if (!nodes.empty()) {
                    nodes.push(NULL);
                }
            }
        }
        return nodeCount;
    }

public:
    void testCase()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        cout << countNodes(root) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
