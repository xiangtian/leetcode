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

        int sum = 0;
        int lastMin = 0;
        int lastMax = 1;
        int lastMaxIdx = 0;
        int len = ratings.size() -1;
        bool isIncrease = true;
        bool isFirst = true;
        bool hasMax = false;
        for(int i = 1; i <= len; i++)
        {
            if(ratings[i-1] > ratings[i]) {
                if(i == len) {
                    lastMin = 0;
                    for(int j = i; j >=lastMaxIdx; j--)
                    {
                        sum+= (++lastMin);
                    }

                    if(hasMax)
                    {
                        if(lastMin < lastMax)
                        {
                            sum -= lastMin;
                        }
                        else
                        {
                            sum -= lastMax;
                        }
                    }
                }


                isIncrease = false;
                continue;
            }
            else
            {
                if(isIncrease)
                {
                    if(isFirst)
                    {
                        isFirst = false;
                        lastMin++;
                        sum+=lastMin;
                    }
                    lastMin++;
                    sum += lastMin;
                    lastMax = lastMin;
                    lastMaxIdx = i;
                }
                else
                {
                    isFirst = false;
                    isIncrease = true;
                    lastMin = 0;
                    for(int j = i-1; j >=lastMaxIdx; j--)
                    {
                        sum+= (++lastMin);
                    }

                    if(hasMax)
                    {
                        if(lastMin < lastMax)
                        {
                            sum -= lastMin;
                        }
                        else
                        {
                            sum -= lastMax;
                        }
                    }

                    lastMin = 2;
                    sum += lastMin; // add cur candy
                }
                hasMax = true;
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

        int f[] = {1,2,3,4,5,3};// 16
        vector<int> candies6(&e[0],&e[6]);
        cout << candy(candies6) << endl;
    }

};

int main(void)
{
    Solution s;
    s.testCase();
}
