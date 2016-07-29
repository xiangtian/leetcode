#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        folderByDiag(matrix);
        folderByMiddle(matrix);
    }

private:
    void folderByDiag(vector<vector<int> > & matrix)
    {
        for(int i = 0; i < matrix.size(); i++) 
        {
            for(int j = i; j < matrix.size(); j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp; 
            }
        }
    }

    void folderByMiddle(vector<vector<int> > & matrix)
    {
        int size = matrix.size();
        int halfSize = size / 2;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < halfSize; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][size-j-1];
                matrix[i][size-j-1] = tmp;
            }
        }
    }

public:
    void print(const vector<vector<int> > & matrix)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void makeMatrix(vector<vector<int> > & matrix)
    {
        int num = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                 matrix[i].push_back(num++);
            }
        }
    }
};

int main(void)
{
    Solution solution;
    vector<vector<int> > matrix(4);
    solution.makeMatrix(matrix);
    solution.print(matrix);
    for(int i= 0; i < 4; i++)
    {
        cout << i+1 << " rotate:" << endl;
        solution.rotate(matrix);
        solution.print(matrix);
    }
    return 0;
}

