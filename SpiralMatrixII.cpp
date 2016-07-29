#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > a;
        if(n == 0) {
            return a;
        }

        initMatrix(a, n);

        int num = 1;
        int i = 0;
        int j = 0;

        a[0][0] = num++;
        while(num <= n*n)
        {
            while((j+1) < n  && a[i][j+1] == -1)
            {
                a[i][++j] = num++;
            }
            while((i+1) < n && a[i+1][j] == -1)
            {
                a[++i][j] = num++;
            }
            while((j-1) >=0 && a[i][j-1] == -1)
            {
                a[i][--j] = num++;
            }
            while((i-1) >=0 && a[i-1][j] == -1)
            {
                a[--i][j] = num++;
            }
        }
        return a; 
    }
private:
    void initMatrix(vector<vector<int> >& matrix, int n)
    {
        for(int i = 0; i < n; i++)
        {
            vector<int> v(n, -1);
            matrix.push_back(v);
        }
    }

    void printMatrix(const vector<vector<int> >& matrix)
    {
        for(int i = 0; i< matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
public:
    void testCase()
    {
        vector<vector<int> > v = generateMatrix(10);
        printMatrix(v);
    }

};

int main(void)
{
    Solution s;
    s.testCase();
}
