#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return;
        }

        size_t start = 0;
        size_t end = 0;
        // delete head blank
        while(s.find_first_of(" ") == 0)
        {
            s.erase(0, 1);
        }
        
        if(s.empty()) {
            return;
        }

        // delete tail blank
        //
        while(s.find_last_of(" ") == (s.size()-1))
        {
            s.erase(s.size()-1, 1);
        }
        
        end = s.find_first_of(" ");
        // process first string
        if(end == std::string::npos) {
            return;
        }
        else
        {
            reverse(s, 0, end-1);
        }

        // reverse each word
        while(true)
        {
            size_t start = end + 1;
            end = s.find_first_of(" ", start);

            if(end == string::npos) {
                reverse(s, start, s.size()-1);
                break;
            }
            else
            {
                if(start == end)
                {
                    s.erase(start,1);
                    end = end -1;
                    continue;
                }
                reverse(s, start, end -1);
            }
        }

        reverse(s, 0, s.size()-1);
    }

private:
    void reverse(string &s, int start, int end)
    {
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

