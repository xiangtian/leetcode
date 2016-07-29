#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) 
        {
            num = num ^ nums[i];
        }
        return num;
    }

public:
    void testCase()
    {
        int a[] = {1, 1, 2};
        vector<int> v(a, &a[3]);
        cout << singleNumber(v) << endl;
    }
};

int main(void) 
{
    Solution s;
    s.testCase();
}
