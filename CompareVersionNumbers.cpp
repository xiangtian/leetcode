#include<iostream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t v1begin = 0, v1end = 0;
        size_t v2begin = 0, v2end = 0;
        bool isFirst = true;
        v1end = version1.find_first_of(".", v1begin);
        v2end = version2.find_first_of(".", v2begin);
        while(v1end != string::npos && v2end != string::npos)
        {
            isFirst = false;
            string sub1 = version1.substr(v1begin, v1end - v1begin);
            string sub2 = version2.substr(v2begin, v2end - v2begin);
            int int1 = atoi(sub1.c_str());
            int int2 = atoi(sub2.c_str());
            if(int1 < int2)
            {
                return -1;
            }else if(int1 > int2)
            {
                return 1;
            }
            v1begin = v1end + 1;
            v2begin = v2end + 1;
            v1end = version1.find_first_of(".", v1begin);
            v2end = version2.find_first_of(".", v2begin);
        }

        if(!isFirst && v1end != string::npos &&
           atoi(version1.substr(v1begin, v1end - v1begin).c_str()) != 0)
        {
            return 1;
        }

        if(!isFirst && v2end != string::npos &&
           atoi(version2.substr(v2begin, v2end - v2begin).c_str()) != 0)
        {
            return -1;
        }

        if(v1begin < string::npos && v2begin < string::npos)
        {
            int v1size = v1end == string::npos ? (version1.size() -v1begin) :(v1end -v1begin);
            int v2size = v2end == string::npos ? (version2.size() - v2begin) : (v2end - v2begin);
            int v1int = atoi(version1.substr(v1begin, v1size).c_str());
            int v2int = atoi(version2.substr(v2begin, v2size).c_str());
            if(v1int < v2int)
            {
                return -1;
            }
            else if (v1int > v2int)
            {
                return 1;
            }

            if(v1end != string::npos &&
                    atoi(version1.substr(v1end+1, version1.size() - v1end - 1).c_str()) != 0)
            {
                return 1;
            }
            if(v2end != string::npos &&
                    atoi(version2.substr(v2end+1, version2.size() - v2end - 1).c_str()) != 0)
            {
                return -1;
            }
        }

        return 0;
    }
    void testCase()
    {
        string v1 = "001.0";
        string v2 = "1.0";
        cout << compareVersion(v1, v2) << endl;
        v2 = "1.1";
        cout << compareVersion(v1, v2) << endl;
        v1 = "12.1";
        cout << compareVersion(v1, v2) << endl;
        v1 = "000";
        v2 = "00000";
        cout << compareVersion(v1, v2) << endl;
        v1 = "1.0";
        v2 = "1";
        cout << compareVersion(v1, v2) << endl;
        cout << compareVersion(v2, v1) << endl;
        v1 = "1.1";
        cout << compareVersion(v1, v2) << endl;
        cout << compareVersion(v2, v1) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
