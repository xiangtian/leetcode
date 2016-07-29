#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        bool isPalindrome = true;
        size_t begin = 0;
        size_t len = s.size() -1;
        size_t front = 0;
        size_t end = s.size() - 1;
        while(front < end)
        {
            while(front <= len && !isalpha(s[front])&& !isdigit(s[front])) {
                front++;
            }
            while(end > 0 && !isalpha(s[end]) && !isdigit(s[end])) {
                end--;
            }

            if (front >= end) {
                break;
            }

            if(tolower(s[front]) != tolower(s[end])) {
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
public:
    void testCase()
    {
        string a("A man, a plan, a canal: Panama");
        cout << isPalindrome(a) << endl;
        string b("");
        cout << isPalindrome(b) << endl;
        string c(".,");
        cout << isPalindrome(c) << endl;
        string d("aba");
        cout << isPalindrome(d) << endl;
        string e("race a car");
        cout << isPalindrome(e) << endl;
        string f("11");
        cout << isPalindrome(f) << endl;
        string g("1a1");
        cout << isPalindrome(g) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
