#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        int min = prices[0];
        int max = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min)
            {
                min = prices[i];
            }
            int tmp = prices[i] - min;
            if(max < tmp) {
                max = tmp;
            }
        }
        return max;
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
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
