#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        innerMajority2(nums);
    }
private:
    // mid is the element
    int innerMajority(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         int mid = nums.size() /2;
         return nums[mid];
    }
    
    // each time delete two different nums
    // the last one is majority
    int innerMajority2(vector<int>& nums) {
        int majority = 0;
        int nTimes = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if(nTimes == 0) {
                majority = nums[i];
                ++nTimes;
            }
            else
            {
                if (nums[i] != majority) {
                    --nTimes;
                }
                else
                {
                    ++nTimes;
                }
            }
        }
        return majority;
    }

public:
    void testCase()
    {
        int a[] = {2, 2, 1, 1, 1};
        vector<int> v(a, &a[5]);
        cout << v.size() << endl;
        cout << majorityElement(v) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
