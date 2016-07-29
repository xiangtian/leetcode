#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else
        {
            int step_2 = 1;  // last two
            int step_1= 2;   // last one
            for(int i = 3; i <= n; i++) 
            {
                int step = step_1 + step_2;
                step_2 = step_1;
                step_1 = step;
            }
            return step_1;
        }
    }
public:
    void testCase()
    {
        int methods = climbStairs(3);
        cout << methods << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
