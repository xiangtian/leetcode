#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && !nums2.empty())
        {
            return getMedian(nums2);
        }

        if (nums2.empty() && !nums1.empty())
        {
            return getMedian(nums1);
        }

        double leftMedian = getMedian(nums1);
        double rightMedian = getMedian(nums2);
        if (leftMedian == rightMedian)
        {
            return leftMedian;
        }

    }

private:
    double getMedian(const vector<int>& nums)
    {
        int size = nums.size();
        if(nums.size() % 2 == 0) {
            return (static_cast<double>(nums[(size - 1 )) / 2]
                    + static_cast<double>(nums[size/2])) / 2;
        }
        else
        {
            return nums[(size - 1) / 2];
        }
    }
};
