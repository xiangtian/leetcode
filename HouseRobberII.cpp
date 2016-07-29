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
        else if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        else
        {
            vector<int> maxV(nums.size(), 0);
            maxV[0] = nums[0];
            maxV[1] = max(nums[0], nums[1]);
            return maxV[nums.size()-1];
        }
    }
};

int main(void)
{
}
