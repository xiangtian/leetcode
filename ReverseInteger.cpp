#include<iostream>
using namespace std;
class Solution {
public: 
    int reverse(int x) {
    long rev= 0;
    while( x != 0){
        rev= rev*10 + x % 10;
        x= x/10;
        if( rev > std::numeric_limits<int>::max()  || rev < std::numeric_limits<int>::min())
        {
            return 0;
        }
    }
    return (int) rev;
}

public:
    void testCase() 
    {
        cout << reverse(2)<< endl;
        cout << reverse(21)<< endl;
        cout << reverse(-3221)<< endl;
        cout << reverse(-32210)<< endl;
    }
};

int main(void) 
{
    Solution s;
    s.testCase();
}

