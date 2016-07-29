#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > allNodes;
        if (root == NULL)
        {
            return allNodes;
        }

        vector<int> levelNodes;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL); // level end flag
        while(!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if(node)
            {
                levelNodes.push_back(node->val);
                if(node->left) {
                    nodeQueue.push(node->left);
                }

                if(node->right) {
                    nodeQueue.push(node->right);
                }
            }
            else
            {
                // current QueueNode is null, but Queue is not null
                // means level end
                if(!nodeQueue.empty()) {
                    nodeQueue.push(NULL); // put level end flag
                }
                allNodes.push_back(levelNodes); // put levelNodes
                levelNodes.clear();
            }
        }
        return allNodes;
    }

public:
    void testCase()
    {
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(3);
        vector<vector<int> > allNodes = levelOrder(root);
        for(int i = 0; i < allNodes.size(); i++)
        {
            for(int j = 0; j < allNodes[i].size(); j++)
            {
                cout << allNodes[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
