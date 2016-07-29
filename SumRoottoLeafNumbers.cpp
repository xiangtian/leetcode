#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int tmpSum = 0;
        TreeNode* lastNode = NULL;
        TreeNode* p = root;
        deque<TreeNode*> nodes;
        while(p != NULL || !nodes.empty()) {
            if(p)
            {
                nodes.push_back(p);
                if (isLeaf(p)) {
                    vector<int> v;
                    tmpSum += getSumFromQueue(nodes);
                }

                p = p->left;
            }
            else
            {
                if(!nodes.empty())
                {
                    p = nodes.back();
                    if(p->right && p->right != lastNode)
                    {
                        p = p->right;
                    }
                    else
                    {
                        lastNode = p;
                        nodes.pop_back();
                        p = NULL;
                    }
                }
            }
        }
        return tmpSum;
    }

private:
    bool isLeaf(TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return true;
        }
        return false;
    }

    int getSumFromQueue(const deque<TreeNode*>& nodes)
    {
        int sum = 0;
        deque<TreeNode*>::const_iterator it = nodes.begin();
        for(; it != nodes.end(); it++)
        {
            sum *= 10;
            sum += (*it)->val;
        }
        return sum;
    }

public:
    void testCase()
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(1);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(4);
        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);
        cout << sumNumbers(root) << endl;

        TreeNode* newRoot = new TreeNode(1);
        newRoot->left = new TreeNode(2);
        newRoot->right = new TreeNode(3);
        cout << sumNumbers(newRoot) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
