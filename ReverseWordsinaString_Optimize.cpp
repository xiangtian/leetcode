#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return;
        }
        string::iterator it = s.begin();
        // delete head blank
        while (it < s.end()&&((*it) == 32))
        {
            it++;
        }
        s.erase(s.begin(), it--);
       
        // just for leet Code Judge,no using
        if(s.empty()) {
            return;
        }
        // delete tail blank
        it = s.end();
        while(it != s.begin() && ((*(--it))== 32))
        {
        }
        s.erase(++it, s.end());

        size_t i = 0;
        size_t j = 0;
        bool isBlank = false;
        size_t start = 0;
        while(i < s.size())
        {
            if(s[i] != ' ')
            {
                isBlank = false;
                s[j++] = s[i++];
            }
            else if(isBlank)
            {
                i++;
            }
            else
            {
                reverse(s, start,j-1);
                isBlank = true;
                s[j++] = s[i++];
                // the last world
                if (i < s.size())
                {
                    start = j;
                }
            }
        }
        reverse(s, start, j-1);
        // delete tail from j
        s.erase(j);
        reverse(s, 0, s.size()-1);
    }

private:
    void reverse(string &s, int start, int end)
    {
        if(end <= start)
        {
            return;
        }
        int mid = (start + end + 1) / 2;
        for(int i= 0; i < (mid-start); i++)
        {
            char tmp = s[start+i];
            s[start+i] = s[end-i];
            s[end-i] = tmp;
        }
    }

public:
    void testCase()
    {
        string s0 = "abcd";
        reverse(s0, 0, s0.size()-1);
        cout << s0 << endl;
        string s1 = " abc ";
        reverse(s1, 0, s1.size()-1);
        cout << s1 << endl;
        reverse(s1, 0, s1.size()-1);
        cout << s1 << endl;
        reverseWords(s1);
        cout << s1 << endl;

        string s2 = "abc   def          hig";
        cout << s2 << endl;
        reverseWords(s2);
        cout << s2 << endl;
        cout << s2.length() << endl;

        string s3 = "a ";
        reverseWords(s3);
        cout << s3 << endl;
        cout << s3.length() << endl;

        string s4 = "a";
        reverseWords(s4);
        cout << s4 << endl;
        cout << s4.length() << endl;

        string s5 = "";
        reverseWords(s5);

        string s6 = "hello world!";
        cout << s6 << endl;
        cout << s6.find_last_of(" ") << endl;
        reverseWords(s6);
        cout << s6 << endl;
        cout << s6 << endl;

        string s7= " ";
        reverseWords(s7);
        cout << s7 << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}

