#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }

        int sum = 0;
        for(int i = 0; i < prices.size()-1; i++)
        {
            if(prices[i] < prices[i+1])
            {
                sum += prices[i+1] - prices[i];
            }
        }
        return sum;
    }
public:
    void testCase()
    {
        int a[] = {1, 2, 3, 4, 5};
        vector<int> v(&a[0],&a[5]);
        cout << maxProfit(v) << endl;
        int b[] = {6, 2, 3, 4, 5};
        vector<int> v1(&b[0],&b[5]);
        cout << maxProfit(v1) << endl;
        
        int c[] = {5, 4, 3, 2, 1};
        vector<int> v2(&c[0],&c[5]);
        cout << maxProfit(v2) << endl;
        
        int d[] = {5, 5, 5, 6, 5};
        vector<int> v3(&d[0],&d[5]);
        cout << maxProfit(v3) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
