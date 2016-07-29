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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> >paths;
        if(root == NULL) {
            return paths;
        }

        int tmpSum = 0;
        TreeNode* lastNode = NULL;
        TreeNode* p = root;
        deque<TreeNode*> nodes;
        while(p != NULL || !nodes.empty()) {
            if(p)
            {
                tmpSum += p->val; // add when add to stack
                nodes.push_back(p);
                if (isLeaf(p) && tmpSum == sum) {
                    vector<int> v;
                    copyFromQueue(nodes, &v);
                    paths.push_back(v);
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
                        tmpSum -= p->val; // sub when pop from stack
                        p = NULL;
                    }
                }
            }
        }
        return paths;
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

    void copyFromQueue(const deque<TreeNode*>& nodes, vector<int>* v)
    {
        deque<TreeNode*>::const_iterator it = nodes.begin();
        for(; it != nodes.end(); it++) 
        {
            v->push_back((*it)->val); 
        }
    }

public:
    void testCase()
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);
        vector<vector<int> > v = pathSum(root, 22);
        for(int i = 0; i < v.size(); i++) 
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
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
