#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++)
        {
           map<int, int>::iterator it = numMap.find(target - nums[i]);
           if(it != numMap.end())
           {
               result.push_back(it->second);
               result.push_back(i+1);
               break;
           }
           else
           {
               numMap[nums[i]] = i+1;
           }
        }
        return result;
    }
    
public:
    void testCase() 
    {
        int a[4] = {2, 7, 11, 5};
        vector<int> v(a, &a[4]);
        v = twoSum(v, 16);
        for (int i = 0; i < v.size(); i++) 
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
















