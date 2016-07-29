#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
        {
            return false;
        }
        map<int, int> valIdx;
        for(int i = 0; i < nums.size(); i++)
        {
            map<int, int>::iterator it = valIdx.find(nums[i]);
            if(it != valIdx.end()) {
                if((i - it->second) <= k){
                    return true;
                }
                else
                {
                    it->second = i;
                }
            }
            else
            {
                valIdx.insert(std::make_pair<int, int>(nums[i], i));
            }
        }
        return false;
    }
public:
    void testCase()
    {
        int a[] = {1,2,1,4,5,7};
        vector<int> v(a, &a[6]);
        cout << containsNearbyDuplicate(v, 1) << endl;
        cout << containsNearbyDuplicate(v, 2) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
