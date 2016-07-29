#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
class Solution {
public:
    // like: hex conversion: 10 -> 26
    // a little different
    string convertToTitle(int n) {
        stack<int> remainders;
        while (n != 0)
        {
            int remainder = n % 26;
            n = n / 26;
            //caution this, e.g: 26-> Z
            if (remainder == 0)
            {
                remainder = 26;
                n = n - 1;
            }
            remainders.push(remainder);
        }

        return constructStr(remainders);
    }
private:
    string constructStr(stack<int>& remainders)
    {
        stringstream ss;
        while(!remainders.empty()) {
            int top = remainders.top();
            remainders.pop();
            char c = 'A' + top - 1;
            ss << c;
        }
        return ss.str();
    }
public:
    void testCase()
    {
        int n = 27;
        cout << convertToTitle(n) << endl;
        n = 26;
        cout << convertToTitle(n) << endl;
        n = 53;
        cout << convertToTitle(n) << endl;
        n = 676;
        cout << convertToTitle(n) << endl;
        n = 702;
        cout << convertToTitle(n) << endl;
        n = 703;
        cout << convertToTitle(n) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
