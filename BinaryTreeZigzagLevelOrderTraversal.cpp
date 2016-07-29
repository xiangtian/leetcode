#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > allNodes;
        if (root == NULL)
        {
            return allNodes;
        }

        vector<int> levelNodes;
        stack<int> stackNodes;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        bool level = true;
        while(!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if(node)
            {
                if(level)
                {
                    levelNodes.push_back(node->val);
                }
                else
                {
                    stackNodes.push(node->val);
                }
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
                // avoid dead loop
                if(!nodeQueue.empty()) {
                    nodeQueue.push(NULL); // put level end flag
                }

                if(!level) {

                    while(!stackNodes.empty())
                    {
                        levelNodes.push_back(stackNodes.top());
                        stackNodes.pop();
                    }
                }
                allNodes.push_back(levelNodes);
                levelNodes.clear();
                level = !level;
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
        root->right->right = new TreeNode(4);
        vector<vector<int> > allNodes = zigzagLevelOrder(root);
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
