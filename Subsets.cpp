#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > subset;
        //vector<int> v;
        subset.push_back(vector<int>());
        if(S.empty()) {
            return subset;
        }
        sort(S.begin(), S.end());
        int size = S.size();
        for(int i = 0; i < size; i++)
        {
            std::vector<int> iset;
            for(int j = i; j < size; j++)
            {
                iset.push_back(S[i+j]);
                subset.push_back(iset);
            }
            iset.clear();
        }
        return subset;

    }
private:
    void print(const vector<vector<int> > & matrix)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
                cout << matrix[i].size() << endl;
        }
    }

public:
    void testCase()
    {
        vector<int> v;
        v.push_back(3);
        v.push_back(2);
        v.push_back(1);
        vector<vector<int> > subset = subsets(v);
        cout << subset.size() << endl;
        print(subset);
    }
};

int main(void) 
{
    Solution s;
    s.testCase();
}
