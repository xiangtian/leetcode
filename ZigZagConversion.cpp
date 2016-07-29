#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result(s);
        int gap = numRows-1;
        int j = 0;
        int i = 0;
        while(i < numRows) {
            int k = i;
            if(i == 0 || i == (numRows -1))
            {
                while(k < s.length())
                {
                    result[j++] = s[k];
                    k += 2 * gap;
                }
            }
            else
            {
                while(k < s.length())
                {
                    result[j++] = s[k];
                    k += 2 * (gap - i);
                    if (k < s.length())
                    {
                        result[j++] = s[k];
                        k += 2* i;
                    }
                }
            }
            i++;
        }
        return result;
    }
public:
    void testCase()
    {
        string s = convert("PAYPALISHIRING", 1);
        cout << s << endl;
        s = convert("A", 1);
        cout << s << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
