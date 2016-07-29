#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int start = 0;
        int next = 1;
        while(next < nums.size())
        {
            if(nums[next] != nums[start]) {
                ++start;
                ++next;
                if(start != (next -1)) {
                    nums[start] = nums[next-1];
                }

            }
            else
            {
                ++next;
            }
        }
        return start+1;

    }

public:
    void testCase()
    {
        int a[] = {1,1,1,2,3,4};
        vector<int> v(a,&a[6]);
        printVector(v,v.size());
        printVector(v, removeDuplicates(v));
        int b[] = {1,1,1};
        vector<int> v1(b,&b[3]);
        printVector(v1,v1.size());
        printVector(v1, removeDuplicates(v1));
        
        int c[] = {1};
        vector<int> v2(c,&c[1]);
        printVector(v2,v2.size());
        printVector(v2, removeDuplicates(v2));

        vector<int> v3;
        printVector(v3, v3.size());

        int d[] = {1,2,3,4};
        vector<int> v4(d,&d[4]);
        printVector(v4,v4.size());
        printVector(v4, removeDuplicates(v4));

    }
private:
    void printVector(const vector<int>& v, int num)
    {
        for(int i = 0; i < num; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
