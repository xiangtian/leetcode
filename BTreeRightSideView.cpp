#include<iostream>
#include<vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSides;
        if(root == NULL)
        {
            return rightSides;
        }

        TreeNode* lastNode = NULL;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        nodesQueue.push(NULL);
        while(!nodesQueue.empty()) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            if(node) {
                if(node->left)
                {
                    nodesQueue.push(node->left);
                }

                if(node->right)
                {
                    nodesQueue.push(node->right);
                }
                lastNode = node;
            }
            else
            {
                rightSides.push_back(lastNode->val);
                if(!nodesQueue.empty()) {
                    nodesQueue.push(NULL);
                }
            }
        }
    }

public:
    void testCase() 
    {
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(4);
        root->left->left->left = new TreeNode(5);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);
        vector<int> v = rightSideView(root);
        printVector(v);
    }

private:
    void printVector(const vector<int>& v)
    {
        for(int i = 0; i < v.size(); i++) 
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
