#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char *p = s;
        const char *q = s;
        bool hasBlank = false;
        int len = 0;
        while(*p)
        {
            if(*p == 32) {
                if(p != q && *(p-1) != 32)
                {
                    len = p - q;
                    if (hasBlank) {
                        len = len - 1;
                    }
                }

                q = p;
                hasBlank = true;
            }
            p++;
        }

        if(p != q &&  *(p -1) != 32) 
        {
            int tmpLen = p - q;
            if (hasBlank) {
                tmpLen = tmpLen - 1;
            }
            return tmpLen;
        }
        else
        {
            return len;
        }
    }
public:
    void testCase()
    {
        char *s = " Hello  world   ";
        cout << (lengthOfLastWord(s) == 5) << endl;
        char *a = "hello";
        cout << (lengthOfLastWord(a) == 5) << endl;
        char *b = " hello";
        cout << (lengthOfLastWord(b) == 5) << endl;
        char *c = "";
        cout << (lengthOfLastWord(c) == 0) << endl;
        char *d = "a";
        cout << (lengthOfLastWord(d) == 1) << endl;
        char *e = "a ";
        cout << (lengthOfLastWord(e) == 1) << endl;
    }

};


int main(void)
{
    Solution t;
    t.testCase();
}
