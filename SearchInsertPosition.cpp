#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
private:
    int binarySearch(const vector<int>& nums, int target, int low, int high)
    {
        while ( low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
public:
    void testCase()
    {
        int a[] = {0, 1, 2, 3, 6};
        vector<int> v(a, &a[5]);
        cout << searchInsert(v, 2) << endl;
        cout << searchInsert(v, -1) << endl;
        cout << searchInsert(v, 5) << endl;
        cout << searchInsert(v, 8) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
