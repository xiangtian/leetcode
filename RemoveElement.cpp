#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0)
        {
            return 0;
        }

        int* begin = &A[0];
        int* p = &A[0];
        int* q = &A[n-1];

        while(p <= q) {
            while(q > p && *q == elem)
            {
                q--;
            }

            if (*p == elem) {
                int tmp = *p;
                *p = *q;
                *q = tmp;
                q--;
            }
            p++;
        }
        return q - begin + 1;
    }
public:
    void testCase()
    {
        int array1[] = {1,1,2,3,1,1,4,5,1,1};
        printArray(array1, 10);
        int len = removeElement(array1, 10, 1);
        printArray(array1, len);
        len = removeElement(array1, len, 2);
        printArray(array1, len);
        len = removeElement(array1, len, 3);
        printArray(array1, len);
        len = removeElement(array1, len, 4);
        printArray(array1, len);
        len = removeElement(array1, len, 5);
        printArray(array1, len);
    }

private:
    void printArray(int a[], int len)
    {
        for(int i = 0; i < len; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}








