#include<iostream>
#include<bitset>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0) {
            return 0;
        }

        uint32_t rev = 0;
        int i = 0;
        while(n != 0)
        {
            rev = rev << 1;
            rev += n % 2;
            n = n >> 1;
            i++;
        }

        while(i < 32)
        {
            rev = rev << 1;
            i++;
        }

        return rev;
    }
public:
    void testCase() {
        uint32_t num = 2;
        bitset<32>input(num);
        cout << input << endl;
        uint32_t rev = reverseBits(num);
        bitset<32>output(rev);
        cout << output << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
