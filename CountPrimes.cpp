#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }
        vector<bool> primes;
        primes.assign(n, true);
        for(int i = 2; i < n; i++)
        {
            if(primes[i-1])
            {
                for(int j = 2; i * j < n; j++)
                {
                    primes[i*j-1] = false;
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(primes[i])
            {
                ++sum;
            }
        }
        // first one and last one
        return sum - 2;
    }
public:
    void testCase()
    {
        cout << countPrimes(5) << endl;
        cout << countPrimes(6) << endl;
        cout << countPrimes(7) << endl;
        cout << countPrimes(8) << endl;
        cout << countPrimes(120) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
