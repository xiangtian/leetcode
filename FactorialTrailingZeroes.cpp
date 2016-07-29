#include<iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int zeroNum = 0;
        while(n != 0) {
            n = n / 5;
            zeroNum += n;
        }
        return zeroNum;
    }

public:
    void testCase()
    {
        cout << trailingZeroes(25) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
