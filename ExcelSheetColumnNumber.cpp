#include<iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            sum *= 26;
            sum += (s[i] - 'A' + 1) ;
        }
        return sum;
    }

    void testCase()
    {
        string str("AA");
        cout << titleToNumber(str) << endl;
        str = "AAA";
        cout << titleToNumber(str) << endl;
        str = "Z";
        cout << titleToNumber(str) << endl;
        str = "YZ";
        cout << titleToNumber(str) << endl;
        str = "ZZ";
        cout << titleToNumber(str) << endl;
        str = "BA";
        cout << titleToNumber(str) << endl;
        str = "A";
        cout << titleToNumber(str) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
