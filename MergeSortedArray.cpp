#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastIdx = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0)
        {
            while(j >= 0 && nums1[i] <= nums2[j])
            {
                nums1[lastIdx--] = nums2[j--];
            }
            nums1[lastIdx--] = nums1[i--];
        }
        
        while(j >= 0)
        {
            nums1[lastIdx--] = nums2[j--];
        }
    }
public:
    void testCase()
    {
        int a[] = {1,2,3,4,5,7,8,9,3,4,5};
        vector<int> v1(a,&a[5]);
        printVector(v1);
        vector<int> v2(&a[5],&a[8]);
        printVector(v2);
        merge(v1, 3, v2, 2);
        printVector(v1);

        vector<int> v3(&a[5], &a[11]);
        printVector(v3);
        vector<int> v4;
        v4.push_back(3);
        v4.push_back(9);
        merge(v3,3, v4,2);
        printVector(v3);


    }
private:    
    void printVector(const vector<int>& v)
    {
        for(int i = 0; i < v.size(); i++)
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
