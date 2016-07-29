#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return false;
        }
        set<int>valIdx;
        for(int i = 0; i < nums.size(); i++)
        {
            set<int>::iterator it = valIdx.find(nums[i]);
            if(it != valIdx.end()) {
                return true;
            }
            else
            {
                valIdx.insert(nums[i]);
            }
        }
        return false;
    }
public:
    void testCase()
    {
        int a[] = {1,2,1,4,5,7};
        vector<int> v(a, &a[6]);
        cout << containsDuplicate(v) << endl;
        vector<int> v2(&a[2], &a[6]);
        cout << containsDuplicate(v2) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
