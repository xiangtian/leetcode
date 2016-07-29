#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0) {
            return false;
        }
        int result = n & (n - 1);
        return result == 0;
    }

    void testCase()
    {
        cout << isPowerOfTwo(1) << endl;
        cout << isPowerOfTwo(3) << endl;
        cout << isPowerOfTwo(8) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
