#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int pos = binarySearch(nums, 0, nums.size() - 1);
        return nums[pos];
    }

private:
    int binarySearch(const vector<int>& nums, int low, int high)
    {
        int mid = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            // verify condition
            if (nums[mid] < nums[high])
            {
                high = mid - 1;
                if(nums[mid] < nums[high])
                {
                    break;
                }
            }
            else
            {
                low = mid + 1;
            }
        }
        return mid;
    }
public:
    void testCase()
    {
        vector<int> arrays;
        arrays.push_back(6);
        arrays.push_back(7);
        arrays.push_back(8);
        arrays.push_back(1);
        arrays.push_back(2);
        arrays.push_back(3);
        cout << findMin(arrays) << endl;

        vector<int> array2;
        array2.push_back(1);
        array2.push_back(2);
        array2.push_back(3);
        cout << findMin(array2) << endl;

        vector<int> array3;
        array3.push_back(3);
        array3.push_back(1);
        array3.push_back(2);
        cout << findMin(array3) << endl;

        vector<int> array4;
        array4.push_back(1);
        array4.push_back(2);
        cout << findMin(array4) << endl;
        
        vector<int> array5;
        array4.push_back(2);
        array4.push_back(1);
        cout << findMin(array4) << endl;

    }
};

int main()
{
    Solution s;
    s.testCase();
}
