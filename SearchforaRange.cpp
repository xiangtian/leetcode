#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        range.push_back(-1);
        range.push_back(-1);
        // nums's empty
        if (nums.empty())
        {
            return range;
        }
        std::pair<bool, int> result = binarySearch(nums, 0, nums.size() - 1, target);
        // not found
        if(!result.first) 
        {
            return range;
        }
        else
        {
            //caution this
            double pre = static_cast<double>(target) - 0.1;
            result = binarySearch(nums, 0, nums.size() - 1, pre);
            range[0] = result.second;

            double next = static_cast<double>(target) + 0.1;
            result = binarySearch(nums, 0, nums.size() - 1, next);
            range[1] = result.second - 1;
        }
        return range;
    }

    std::pair<bool, int> binarySearch(const vector<int>& nums, int low, int high, double target)
    {
        while(low <= high) 
        {
            int mid = (low + high) / 2;
            if (target == nums[mid]) {
                return std::make_pair(true, mid);
            }
            else if (target > nums[mid]) 
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return std::make_pair(false, low);
    }


    void testCase()
    {
        int a[] = {1, 1, 2, 3, 4, 5};
        vector<int> v(a, &a[6]);
        std::pair<bool, int> result = binarySearch(v, 0, 4, 3);
        cout << result.first << " "<< result.second << endl;
        result = binarySearch(v, 0, 4, 6);
        cout << result.first << " "<< result.second << endl;
        vector<int> range = searchRange(v, 7);
        for(int i = 0; i < range.size(); i++) 
        {
            cout << range[i] << " ";
        }
        cout << endl;
    }
};

int main(void) 
{
    Solution s;
    s.testCase();
}
