#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else if(nums.size() == 1) {
            return nums[0];
        }
        else
        {
            vector<int> maxV(nums.size(), 0);
            maxV[0] = nums[0];
            maxV[1] = max(nums[0], nums[1]);
            for(int i = 2; i < nums.size(); i++)
            {
                maxV[i] = max((maxV[i-2] + nums[i]), maxV[i-1]);
            }
            return maxV[nums.size()-1];
        }
    }
    void testCase()
    {
        int a[] = {1,5,6,3};
        vector<int> v(a, &a[4]);
        cout << rob(v) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
