#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low <= high) 
        {
            int mid = (low + high) / 2;
            // mySqrt(std::limit<int>::max) = 46340
            // why 46340 not 46341? the last low will be 46341
            while(mid > 46340) {
                high = 46340;
                mid = (low + high) / 2;
            }
            int mid2 = mid * mid;
            if ( mid2 < x) {
                low = mid + 1;
            }
            else if (mid2 > x)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return low - 1;
    }

    void testCase() 
    {
        cout << std::numeric_limits<int>::min() << endl;
        cout << std::numeric_limits<int>::max() << endl;
        cout << mySqrt(2147483647) << endl;
        cout << mySqrt(2147483646) << endl;
        cout << mySqrt(2147395600) << endl;
        cout << mySqrt(16) << endl;
        cout << mySqrt(25) << endl;
        cout << mySqrt(24) << endl;
        cout << mySqrt(1) << endl;
        cout << mySqrt(0) << endl;
        cout << mySqrt(36) << endl;
        cout << mySqrt(37) << endl;
        cout << mySqrt(49) << endl;
        cout << mySqrt(50) << endl;
    }
};

int main(void) 
{
    Solution s;
    s.testCase();
}
