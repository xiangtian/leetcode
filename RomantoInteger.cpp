#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'M') {
                sum += 1000;
            }
            sum += processHundred(s, &i);
            sum += processTen(s, &i);
            sum += processOne(s, &i);
        }
        return sum;
    }
private:
    int processHundred(const std::string& s,int* i)
    {
        return innerProcess(s, 100, 'C', 'D', 'M', i);
    }

    int processTen(const std::string& s,int* i)
    {
        return innerProcess(s, 10, 'X', 'L', 'C', i);
    }

    int processOne(const std::string& s,int* i)
    {
        return innerProcess(s, 1, 'I', 'V', 'X', i);
    }

    int innerProcess(const std::string& s,int base,
                     char one, char five, char ten, int* i)
    {
            int sum = 0;
            int j = *i;
            if (s[j] == one)
            {
                if( (j+1) < s.length()) {
                    if (s[j+1] == ten)
                    {
                        sum += 9 * base;
                        (*i)++;
                    }
                    else if(s[j+1] == five)
                    {
                        sum+= 4 * base;
                        (*i)++;
                    }
                    else
                    {
                        sum += base;
                    }
                }
                else
                {
                    sum += base;
                }
            }
            else if (s[j] == five)
            {
                sum += 5 * base;
            }
            return sum;
    }
public:
    void testCase()
    {
        string s = "MMMCMXCIX";
        cout << romanToInt(s) << endl;
        s = "MMMCCCXXXIII";
        cout << romanToInt(s) << endl;
        s = "MMMCDXLIV";
        cout << romanToInt(s) << endl;
        s = "MMMDLV";
        cout << romanToInt(s) << endl;
        s = "MMMDCLXVI";
        cout << romanToInt(s) << endl;
        s = "MMMDCCCLXXXVIII";
        cout << romanToInt(s) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
