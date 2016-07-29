#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowLow = 0;
        int rowHigh = matrix.size() - 1;
        int rowMid = (rowLow + rowHigh) / 2;
        // find row
        while(rowLow < rowHigh)
        {
            if (target == matrix[rowMid][0])
            {
                return true;
            }

            if(target < matrix[rowMid][0])
            {
                rowHigh = rowMid - 1;
            }
            else
            {
                rowLow = rowMid + 1;
            }

            rowMid = (rowLow + rowHigh) / 2;
        }


        if (target == matrix[rowMid][0])
        {
            return true;
        }
        else if(target < matrix[rowMid][0])
        {
            if(rowMid > 0) {
                return binarySearchInRow(matrix[rowMid-1], target); // mid -1
            }
            else
            {
                return false;
            }
        }
        else
        {
            return binarySearchInRow(matrix[rowMid], target);
        }

    }

private:
    bool binarySearchInRow(const std::vector<int>& row, int target)
    {
        int low = 0;
        int high = row.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target == row[mid]) {
                return true;
            }
            else if(target < row[mid]) {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

public:
    void testCase()
    {
        vector<vector<int> > vvs;
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(6);

        cout << binarySearchInRow(v1, 1) << endl;
        cout << binarySearchInRow(v1, 3) << endl;
        cout << binarySearchInRow(v1, 6) << endl;
        cout << binarySearchInRow(v1, 7) << endl;

        vector<int> v2;
        v2.push_back(7);
        v2.push_back(8);
        v2.push_back(9);
        v2.push_back(10);
        v2.push_back(12);
        vector<int> v3;
        v3.push_back(13);
        v3.push_back(14);
        v3.push_back(15);
        v2.push_back(17);
        v3.push_back(18);
        vvs.push_back(v1);
        vvs.push_back(v2);
        vvs.push_back(v3);


        cout << searchMatrix(vvs, 0);
        cout << searchMatrix(vvs, 1);
        cout << searchMatrix(vvs, 2);
        cout << searchMatrix(vvs, 5);
        cout << searchMatrix(vvs, 6) << endl;
        cout << "---------------" << endl;

        cout << searchMatrix(vvs, 7);
        cout << searchMatrix(vvs, 8);
        cout << searchMatrix(vvs, 11);
        cout << searchMatrix(vvs, 12) << endl;
        cout << "---------------" << endl;

        cout << searchMatrix(vvs, 13);
        cout << searchMatrix(vvs, 14);
        cout << searchMatrix(vvs, 16);
        cout << searchMatrix(vvs, 18);
        cout << searchMatrix(vvs, 19);
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
