#include<iostream>
#include<vector>
#include<tr1/unordered_set>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return true;
        }

        int cur = 0;
        int next = 0;
        int lastIdx = nums.size() - 1;

        unordered_set<int> reachedIdxSet;
        reachedIdxSet.insert(0);
        for(int i = 0; i < lastIdx; i++)
        {
            if(reachedIdxSet.find(i) == reachedIdxSet.end())
            {
                continue;
            }
            // nodes which cur could reach
            for(int j = 1; j <=nums[i]&&j < lastIdx; j++)
            {
                reachedIdxSet.insert(i+j);
            }
            // calculate could reach?
            if(reachedIdxSet.find(lastIdx) != reachedIdxSet.end())
            {
                return true;
            }
        }
        return false;
    }

public:
    void testCase()
    {
        int a[] = {2,3,1,1,4};
        vector<int> jumps(&a[0], &a[5]);
        cout << canJump(jumps)<< endl;
        int b[] = {3,2,1,0,4};
        vector<int> jumps1(&b[0], &b[5]);
        cout << canJump(jumps1)<< endl;
        int c[] = {3,2,1,5,4};
        vector<int> jumps2(&c[0], &c[5]);
        cout << canJump(jumps2)<< endl;
    }
private:
    void printSet(const unordered_set<int>& nums)
    {
        unordered_set<int>::const_iterator it = nums.begin();
        while(it != nums.end())
        {
            cout << *it <<" ";
            it++;
        }
        cout << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
