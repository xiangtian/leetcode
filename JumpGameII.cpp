#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return 0;
        }

        int minStep = 1;
        int curMaxReach = nums[0];
        int nextMaxReach = nums[0];
        int lastIdx = nums.size() - 1;
        // care this end condition must <=  (e.g:2,3,1,1,4)
        for(int i = 1; i <= lastIdx; i++)
        {
            // cout << i << ": curret:" << curMaxReach <<
            //    " next:" << nextMaxReach << " min:" << minStep << endl;
            if(curMaxReach >= lastIdx)
            {
                return minStep;
            }

            int tmp = i + nums[i];
            if (nextMaxReach < tmp)
            {
                nextMaxReach = tmp;
            }

            if(i == curMaxReach)
            {
                minStep++;
                curMaxReach = nextMaxReach;
            }
        }
    }

public:
    void testCase()
    {
        int a[] = {2,1,3,1,4};
        vector<int> values1(&a[0], &a[5]);
        cout << jump(values1) << endl;

        int b[] = {2,1,1,1,4};
        vector<int> values2(&b[0], &b[5]);
        cout << jump(values2) << endl;

        int c[] = {2,4};
        vector<int> values3(&c[0], &c[2]);
        cout << jump(values3) << endl;

        int d[] = {2,1,4};
        vector<int> values4(&d[0], &d[3]);
        cout << jump(values4) << endl;

        int e[] = {1,1,4};
        vector<int> values5(&e[0], &e[3]);
        cout << jump(values5) << endl;

    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
