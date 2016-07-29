#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
        {
            return -1;
        }
        else if(n == 1)
        {
            return nums[0] == target ? true : false;
        }

        int low = 0;
        int high = n - 1;
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

public:
    void testCase()
    {
        int array[] = {4,4,6,0,1,2,2,4};
        vector<int> arrayV(array, &array[8]); 
        cout <<search(arrayV, 2) << endl;
        cout <<search(arrayV, 4) << endl;
        cout <<search(arrayV, 0) << endl;
        cout <<search(arrayV, 7) << endl;

        vector<int> array1(5, 1);
        cout <<search(array1, 1) << endl;

        vector<int> array2(3, 1);
        array2[0] = 3;
        cout <<search(array2, 3) << endl;
        cout <<search(array2, 1) << endl;
        cout << findMin(array2, 0, 2) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
