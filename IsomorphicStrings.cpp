#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty() && t.empty())
        {
            return true;
        }

        if (s.size() != t.size())
        {
            return false;
        }

        map<char, char> pairs1;
        map<char, char> pairs2;
        for (int i = 0; i < s.size(); i++)
        {
            if (pairs1.find(s[i]) == pairs1.end())
            {
                pairs1[s[i]] = t[i];
            }
            else
            {
                if(pairs1[s[i]] != t[i])
                {
                    return false;
                }
            }

            if(pairs2.find(t[i]) == pairs2.end()) 
            {
                pairs2[t[i]] = s[i];
            }
            else
            {
                if (pairs2[t[i]] != s[i]) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    void testCase()
    {
        string s = "egg";
        string t = "add";
        cout <<isIsomorphic(s, t) << endl;
        s = "foo";
        t = "bar";
        cout <<isIsomorphic(s, t) << endl;
        s = "paper";
        t = "title";
        cout <<isIsomorphic(s, t) << endl;
        s = "ab";
        t = "aa";
        cout <<isIsomorphic(s, t) << endl;
    }
};
int main(void)
{
    Solution s;
    s.testCase();
}
