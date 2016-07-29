#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        processThousand(num, ss);
        processHundred(num, ss);
        processTens(num, ss);
        processUnit(num, ss);
        return ss.str();
    }
private:
    void processThousand(int num, stringstream& ss) {
        int nTimes = num / 1000;
        for(int i = 0; i < nTimes; i++)
        {
            ss << "M";
        }
    }

    void processHundred(int num, stringstream& ss)
    {
        int nTimes = (num % 1000) / 100;
        processDigit(nTimes,"C", "D", "M", ss);
    }

    void processTens(int num, stringstream& ss) {
        int nTimes = (num % 100) / 10;
        processDigit(nTimes, "X", "L", "C", ss);
    }

    void processUnit(int num, stringstream& ss) {
        int nTimes = num % 10;
        processDigit(nTimes, "I", "V", "X", ss);
    }

    void processDigit(int nTimes,
                      const std::string& one,
                      const std::string& five,
                      const std::string& ten,
                      stringstream& ss)
    {
        if(nTimes <= 3) {
            for(int i = 0; i < nTimes; i++) {
                ss << one;
            }
        }
        else if(nTimes == 4) {
            ss << one << five;
        }
        else if(nTimes < 9) {
            ss << five;
            for(int i = 5; i < nTimes; i++) {
                ss << one;
            }
        }
        else {
            ss << one << ten;
        }
    }
public:
    void testCase()
    {
        int num = 3999;
        cout << intToRoman(num) << endl;
        num = 3333;
        cout << intToRoman(num) << endl;
        num = 3444;
        cout << intToRoman(num) << endl;
        num = 3555;
        cout << intToRoman(num) << endl;
        num = 3666;
        cout << intToRoman(num) << endl;
        num = 3888;
        cout << intToRoman(num) << endl;
        num = 1976;
        cout << intToRoman(num) << endl;
        num = 1984;
        cout << intToRoman(num) << endl;
        num = 1990;
        cout << intToRoman(num) << endl;
        num = 2000;
        cout << intToRoman(num) << endl;
        num = 1899;
        cout << intToRoman(num) << endl;
        num = 1400;
        cout << intToRoman(num) << endl;
        num = 1500;
        cout << intToRoman(num) << endl;
        num = 1600;
        cout << intToRoman(num) << endl;
        num = 1100;
        cout << intToRoman(num) << endl;
        num = 1001;
        cout << intToRoman(num) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
