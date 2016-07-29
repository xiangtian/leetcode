#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return innerCount2(n);
    }
private:

    //bit manipulation
    int innerCount(uint32_t n) {
        int nums = 0;
        while(n != 0) {
            n &= (n-1);
            nums++;
        }
    }

    int innerCount2(uint32_t n) {
        int nums = 0;
        while(n != 0)
        {
            if (n % 2 == 1) {
                nums++;
            }
            n = n >> 1;
        }
        return nums;
    }
public:
    void testCase()
    {
        uint32_t n = 7;
        cout << innerCount(n) << endl;
        cout << hammingWeight(n) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
