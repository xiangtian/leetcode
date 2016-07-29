#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return true;
        }

        int lastIdx = nums.size() - 1;
        int reachMax = nums[0];

        for(int i = 1; i < lastIdx; i++)
        {
            int tmp = nums[i] + i;
            if(reachMax >= i)
            {
                if(reachMax < tmp)
                {
                    reachMax = tmp;
                }
            }
            else
            {
                return false;
            }
        }
        return reachMax >= lastIdx;
    }

public:
    void testCase()
    {
        int a[] = {2,3,1,1,4};
        vector<int> jumps(&a[0], &a[5]);
        cout << canJump(jumps)<< endl;
        int b[] = {3,2,1,0,4};
        vector<int> jumps1(&b[0], &b[5]);
        cout << canJump(jumps1)<< endl;
        int c[] = {3,2,1,5,4};
        vector<int> jumps2(&c[0], &c[5]);
        cout << canJump(jumps2)<< endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
