#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int rotate = n - (k % n);
        if (rotate == 0)
        {
            return;
        }

        reverseArray(nums,0, rotate-1);
        reverseArray(nums,rotate, n-1);
        reverseArray(nums,0, n-1);
    }
private:
    void reverseArray(int nums[], int start, int end)
    {
        int mid = (start + end + 1) / 2;
        for(int i = 0; i < mid - start; i++) {
            int tmp = nums[start+i];
            nums[start+i] = nums[end-i];
            nums[end-i] = tmp;
        }
    }

    void printArray(int nums[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
public:
    void testCase()
    {
        int a1[] = {1,2,3,4,5,6,7};
        rotate(a1,7,1);
        printArray(a1, 7);
        rotate(a1,7,2);
        printArray(a1, 7);
        rotate(a1,7,4);
        printArray(a1, 7);
        rotate(a1,7,15);
        printArray(a1, 7);
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
