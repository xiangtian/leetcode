#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1)
        {
            return 1;
        }

        int sum = 1;
        int lastMin = 1;
        int lastMax = 1;
        int lastMaxIdx = 0;
        for(int i = 1; i < ratings.size() ; i++)
        {
            if(ratings[i] > ratings[i-1]) {
                lastMin++;
                sum += lastMin;
                lastMax = lastMin;
                lastMaxIdx = i;
            }
            else if(ratings[i] == ratings[i-1])
            {
                lastMin = 1;
                lastMax = 1;
                lastMaxIdx = i;
                sum += lastMin;

            }
            else
            {
                lastMin = 1;
                // this condition is hard
                if(i < lastMax + lastMaxIdx)
                {
                    sum += i - lastMaxIdx;
                }
                else
                {
                    sum += i + 1 - lastMaxIdx;
                }
            }
        }
        return sum;
    }
public:
    void testCase()
    {
        int a[] = {1,2,5,3,1,2,3,4,5,3,1}; // 26
        vector<int> candies(&a[0],&a[11]);
        cout << candy(candies) << endl;

        int b[] = {5,1,2,3,4,5}; // 17
        vector<int> candies1(&b[0],&b[6]);
        cout << candy(candies1) << endl;

        int c[] = {5,4,3,2,1,2,6};// 20
        vector<int> candies2(&c[0],&c[7]);
        cout << candy(candies2) << endl;

        int d[] = {5,4,3,2,1}; // 15
        vector<int> candies4(&d[0],&d[5]);
        cout << candy(candies4) << endl;

        int e[] = {1,2,3,4,5};// 15
        vector<int> candies5(&e[0],&e[5]);
        cout << candy(candies5) << endl;

        int f[] = {1,2,3,4,5,5,3,2};// 20
        vector<int> candies6(&e[0],&e[9]);
        cout << candy(candies6) << endl;
        
        int g[] = {5,5};// 20
        vector<int> candies7(&g[0],&g[2]);
        cout << candy(candies7) << endl;
    }

};

int main(void)
{
    Solution s;
    s.testCase();
}
