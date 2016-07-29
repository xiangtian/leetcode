#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        // find first not 0 from begin
        while(begin < nums.size() && nums[begin] == 0) {
            ++begin;
        }

        if (begin == nums.size()) {
            return;
        }
        // find firt not 2 from last
        while( end >= 0 && nums[end] == 2) {
            --end;
        }

        if (end < 0 ) {
            return;
        }

        for (int i = begin; i <= end; i++) {
            if (nums[i] == 1) {
                continue;
            }
            else if(nums[i] == 0) {
                if (begin == i) {
                    ++begin;
                    continue;
                }

                swap(&nums[begin], &nums[i]);
                ++begin;
                // current is 2, --end
                if (nums[i] == 2) {
                    swap(&nums[end], &nums[i]);
                    --end;
                }
            }
            else
            {
                // swap will cause 0 ,2, 1 ,1 , 2, 2, 0, 2
                // cause continous 2
                while(end >= i && nums[end] == 2) 
                {
                    --end;
                }
                // verify all is 2
                if (end < i) 
                {
                    break;
                }
                
                swap(&nums[end], &nums[i]);
                --end;
                // current is 0, ++begin
                if (nums[i] == 0) {
                    swap(&nums[begin], &nums[i]);
                    ++begin;
                }
            }
             // printVector(nums);
        }
    }

    void testCase() 
    {

        int a1[] = {2, 2, 0};
        vector<int> v9(a1, &a1[3]);
        runTest(v9);

        int h1[] = {0,2,2,2,0,2,1,1};
        vector<int> v8(h1, &h1[8]);
        runTest(v8);

        int a[] = {1, 2, 0, 1, 1, 0};
        vector<int> v(a, &a[6]);
        runTest(v);

        int b[] = {1, 0, 0, 1, 2, 1, 0};
        vector<int> v1(b, &b[7]);
        runTest(v1);

        int c[] = {1, 1, 0, 0, 2, 1};
        vector<int> v2(c, &c[6]);
        runTest(v2);

        int d[] = {0, 1, 2, 1, 0};
        vector<int> v3(d, &d[5]);
        runTest(v3);

        int e[] = {0, 0, 0, 0};
        vector<int> v4(e, &e[4]);
        runTest(v4);

        int f[] = {1, 1, 1, 1};
        vector<int> v5(f, &f[4]);
        runTest(v5);

        int g[] = {2, 2, 2, 2};
        vector<int> v6(g, &g[4]);
        runTest(v6);

        int h[] = {0, 2};
        vector<int> v7(h, &h[2]);
        runTest(v7);

    }

private:

    void runTest(vector<int>& v){
        printVector(v);
        sortColors(v);
        printVector(v);
    }

    void printVector(const vector<int>& v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void swap(int *p, int* q)
    {
        int tmp = *p;
        *p = *q;
        *q = tmp;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
