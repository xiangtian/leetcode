#include<iostream>
#include<cctype>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        int flag = 1;
        long sum = 0; // using long to process out of range

        // process blank
        while(idx < str.length() && str[idx] == 32)
        {
            ++idx;
        }

        // process plus or minus
        if (idx < str.length())
        {
            if(str[idx] == '-')
            {
                flag = -1;
                ++idx;
            }
            else if(str[idx] == '+')
            {
                flag = 1;
                ++idx;
            }
        }

        // process digit
        while(idx < str.length() && isdigit(str[idx]))
        {
            sum = sum * 10 + (str[idx++] - '0');
            if (sum * flag >= std::numeric_limits<int>::max())
            {
                return std::numeric_limits<int>::max();
            }
            else if(sum * flag <= std::numeric_limits<int>::min() ) {
                return std::numeric_limits<int>::min();
            }
        }

        return sum * flag;
    }


    void testCase()
    {
        string s = "-1234abc";
        cout << myAtoi(s) << endl;
        s = "1234abc";
        cout << myAtoi(s) << endl;
        s = "+1234abc";
        cout << myAtoi(s) << endl;
        s = "    1234.";
        cout << myAtoi(s) << endl;
        s = "    123456789111111.";
        cout << myAtoi(s) << endl;
        s = "    -123456789111111.";
        cout << myAtoi(s) << endl;
        s = "    -abc";
        cout << myAtoi(s) << endl;
        s = " 10522545459";
        cout << myAtoi(s) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
