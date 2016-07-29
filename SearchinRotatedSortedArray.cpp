#include<iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n == 0)
        {
            return -1;
        }
        else if(n == 1)
        {
            return A[0] == target ? 0 : -1;
        }

        int mid = 0;
        int low = mid = 0;
        int high = n-1;
        while(mid < high && A[mid] < A[mid+1])
        {
            if(A[mid] == target)
            {
                return mid;
            }
            mid++;
        }

        if(A[mid] == target)
        {
            return mid;
        }
        mid = mid + 1;

        return binarySearchInRow(A, mid, high, target);
    }
private:
    int binarySearchInRow(int row[], int low, int high, int target)
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
        int array[] = {4,5,6,0,1,2,3};
        cout <<search(array, 7, 4) << endl;
        cout <<search(array, 7, 0) << endl;
        cout <<search(array, 7, 7) << endl;

        int array1[] = {1};
        cout <<search(array1, 1, 1) << endl;
        int array2[] = {1,3};
        cout <<search(array2, 2, 3) << endl;

    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
