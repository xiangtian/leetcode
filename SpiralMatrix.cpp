#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> values;
        int m = matrix.size(); 
        if(m == 0) {
            return values;
        }

        int n = matrix[0].size();

        int i = 0;
        int j = 0;
        int c = 0;
        int totalValues = m * n;
        // read one set one -1
        values.push_back(matrix[0][0]);
        // use totalValues to control loop time
        while(values.size() < totalValues)
        {
            while((j+1) < (n-c) && values.size() < totalValues)
            {
                values.push_back(matrix[i][++j]);
            }

            while((i+1) < (m-c) && values.size() < totalValues)
            {
                values.push_back(matrix[++i][j]);
            }

            while((j-1) >= c && values.size() < totalValues)
            {
                values.push_back(matrix[i][--j]);
            }
            while((i-1) > c && values.size() < totalValues)
            {
                values.push_back(matrix[--i][j]);
            }
            c++;
        }
        return values;
    }
private:
    void initMatrix(vector<vector<int> >& matrix,int m, int n)
    {
        int num = 0;
        for(int i = 0; i < m; i++)
        {
            vector<int> v;
            for(int j = 0; j < n; j++)
            {
                v.push_back(num++);
            }
            matrix.push_back(v);

        }
    }

    void printMatrix(const vector<vector<int> >& matrix)
    {
        for(int i = 0; i< matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printValues(const vector<int> values)
    {
        for(int i = 0; i < values.size(); i++)
        {
            cout << values[i] << " " ;
        }
        cout << endl;
    }

public:
    void testCase()
    {
        vector<vector<int> > matrix;
        initMatrix(matrix, 3, 4);
        printMatrix(matrix);
        vector<int> values = spiralOrder(matrix);
        printValues(values);

        matrix.clear();
        values.clear();
        initMatrix(matrix, 1, 4);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);

        matrix.clear();
        values.clear();
        initMatrix(matrix, 4, 1);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);
        
        matrix.clear();
        values.clear();
        initMatrix(matrix, 2, 4);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);
        
        matrix.clear();
        values.clear();
        initMatrix(matrix, 3, 3);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);
        
        matrix.clear();
        values.clear();
        initMatrix(matrix, 4, 4);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);
        
        matrix.clear();
        values.clear();
        initMatrix(matrix, 4, 3);
        printMatrix(matrix);
        values = spiralOrder(matrix);
        printValues(values);
    }

};

int main(void)
{
    Solution s;
    s.testCase();
}
