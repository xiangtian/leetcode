#include<iostream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t v1begin = 0, v1end = 0;
        size_t v2begin = 0, v2end = 0;
        v1end = version1.find_first_of(".", v1begin);
        v2end = version2.find_first_of(".", v2begin);
        while(v1end != string::npos && v2end != string::npos)
        {
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

        if(v1end == string::npos && v2end == string::npos)
        {
            string sub1 = version1.substr(v1begin, version1.size() - v1begin);
            string sub2 = version2.substr(v2begin, version2.size() - v2begin);
            int int1 = atoi(sub1.c_str());
            int int2 = atoi(sub2.c_str());
            if(int1 < int2)
            {
                return -1;
            }else if(int1 > int2)
            {
                return 1;
            }
        }

        if(v1end != string::npos)
        {
            string sub1 = version1.substr(v1begin, v1end - v1begin);
            string sub2 = version2.substr(v2begin, version2.size());
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
            v1end = version1.find_first_of(".", v1begin);
            while(v1end != string::npos)
            {
                if(atoi(version1.substr(v1begin, v1end - v1begin).c_str())!= 0)
                {
                    return 1;
                }
                v1begin = v1end + 1;
                v1end = version1.find_first_of(".", v1begin);
            }

            if(atoi(version1.substr(v1begin, version1.size() - v1begin).c_str() ) != 0)
            {
                return 1;
            }
        }

        if(v2end != string::npos)
        {
            string sub1 = version1.substr(v1begin, version1.size());
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

            v2begin = v2end + 1;
            v2end = version2.find_first_of(".", v2begin);
            while(v2end != string::npos)
            {
                if(atoi(version2.substr(v2begin, v2end - v2begin).c_str())!= 0)
                {
                    return -1;
                }
                v2begin = v2end + 1;
                v2end = version2.find_first_of(".", v2begin);
            }

            if(atoi(version2.substr(v2begin, version2.size() - v2begin).c_str() ) != 0)
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
        cout << compareVersion(v1, v2) << endl; // 0
        v2 = "1.1";
        cout << compareVersion(v1, v2) << endl; // -1
        v1 = "12.1";
        cout << compareVersion(v1, v2) << endl; // 1
        v1 = "000";
        v2 = "00000";
        cout << compareVersion(v1, v2) << endl; // 0
        v1 = "1.0";
        v2 = "1";
        cout << compareVersion(v1, v2) << endl; // 0
        cout << compareVersion(v2, v1) << endl; // 0
        v1 = "1.1";
        cout << compareVersion(v1, v2) << endl; // 1
        cout << compareVersion(v2, v1) << endl; // -1
        v1 = "1.01.0.0";
        v2 = "1.1";
        cout << compareVersion(v1, v2) << endl; // 0
        cout << compareVersion(v2, v1) << endl; // 0
        v1 = "1.01.0.1";
        v2 = "1.1";
        cout << compareVersion(v1, v2) << endl; // 1
        cout << compareVersion(v2, v1) << endl; // -1
        v1 = "1";
        v2 = "0";
        cout << compareVersion(v1, v2) << endl; // 1
        cout << compareVersion(v2, v1) << endl; // -1
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
