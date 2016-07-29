#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        map<char, char> brackets;
        brackets['('] = ')';
        brackets['['] = ']';
        brackets['{'] = '}';
        stack<char> bracketStack;
        for(int i = 0; i< s.length(); i++)
        {
            map<char,char>::iterator it = brackets.find(s[i]);
            if (it == brackets.end())
            {
                if(!bracketStack.empty()) {
                    char top = bracketStack.top();
                    bracketStack.pop();
                    if( brackets[top] == s[i])
                    {
                        continue;
                    }
                }
                return false;
            }
            else
            {
                bracketStack.push(s[i]);
            }
        }

        if(!bracketStack.empty())
        {
            return false;
        }

        return true;
    }

    void testCase()
    {
        string s = "{{}}";
        cout << isValid(s) << endl;
        s = "{{()";
        cout << isValid(s) << endl;
        s = "{{()[]}}";
        cout << isValid(s) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
