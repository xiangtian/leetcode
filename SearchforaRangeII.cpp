#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2, -1);
        // nums's empty
        if (nums.empty())
        {
            return range;
        }

        int low = 0;
        int high = nums.size() - 1;
        std::pair<bool, int> result = searchFirst(nums, low, high, target);
        if (!result.first)
        {
            return range;
        }
        else
        {
            range[0] = result.second;
            result = searchLast(nums, low, high, target);
            range[1] = result.second; 
        }
        return range;
    }

    std::pair<bool, int> searchFirst(const vector<int>& nums, 
            int low, int high, int target) 
    {
        int localHigh = high;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (target <= nums[mid]) {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        if (low > localHigh || nums[low] != target)
        {
            return std::make_pair(false, low);
        }

        return std::make_pair(true, low);
    }

    std::pair<bool, int> searchLast(const vector<int>& nums, 
            int low, int high, int target)
    {
        int localLow = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if((low -1)  < localLow || nums[low - 1] != target) {
            return std::make_pair(false, low - 1);
        }
        return std::make_pair(true, low - 1);
    }


    void testCase()
    {
        int a[] = {1, 1, 2, 3, 3, 4, 5};
        vector<int> v(a, &a[7]);
        printPair(searchFirst(v, 0, v.size() - 1, 0));
        printPair(searchFirst(v, 0, v.size() - 1, 3));
        printPair(searchFirst(v, 0, v.size() - 1, 5));
        printPair(searchFirst(v, 0, v.size() - 1, 6));

        printPair(searchLast(v, 0, v.size() - 1, 0)); 
        printPair(searchLast(v, 0, v.size() - 1, 3)); 
        printPair(searchLast(v, 0, v.size() - 1, 5)); 
        printPair(searchLast(v, 0, v.size() - 1, 6)); 
        vector<int> range = searchRange(v, 7);
        printRange(range);
        range = searchRange(v, 3);
        printRange(range);
        range = searchRange(v, 1);
        printRange(range);
        range = searchRange(v, 0);
        printRange(range);
        range = searchRange(v, 5);
        printRange(range);
    }

private:
    void printPair(const std::pair<bool, int>& pair)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    void printRange(const vector<int>& range)
    {
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
