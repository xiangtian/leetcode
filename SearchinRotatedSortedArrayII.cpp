#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
        {
            return -1;
        }
        else if(n == 1)
        {
            return nums[0] == target ? 0 : -1;
        }

        int low = 0;
        int high = n - 1;
        int mid = findMin(nums, low, high);
        int findLeft = binarySearchInRow(nums, low, mid, target);
        if (findLeft != -1)
        {
            return findLeft;
        }
        else
        {
            return binarySearchInRow(nums, mid, high, target);
        }
    }

private:
    int binarySearchInRow(const vector<int>& row, int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target == row[mid]) {
                return mid;
            }
            else if(target < row[mid]) {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int findMin(const vector<int>& row, int low, int high)
    {
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if(row[mid] < row[high])
            {
                high = mid - 1;
                if(low <= high && row[high] > row[mid])
                {
                    return mid;
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
        int array[] = {4,5,6,0,1,2,3};
        vector<int> arrayV(array, &array[7]); 
        cout <<search(arrayV, 4) << endl;
        cout <<search(arrayV, 0) << endl;
        cout <<search(arrayV, 7) << endl;

        vector<int> array1(1, 1);
        cout <<search(array1, 1) << endl;

        vector<int> array2(2, 1);
        array2[0] = 3;
        cout <<search(array2, 3) << endl;
        cout <<search(array2, 1) << endl;
        cout << findMin(array2, 0, 1) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
