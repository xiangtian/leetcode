#include<iostream>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int firstArea = getRectangeArea(A, B, C, D);
        int secondArea = getRectangeArea(E, F, G, H);
        int total = firstArea + secondArea;
        int interArea = 0;
        if (A > G || B > H || F > D || E > C) 
        {
            return total;
        }
        
        int a = A > E ? A : E;
        int b = B > F ? B : F;
        int c = C > G ? G : C;
        int d = D > H ? H : D;
        interArea = getRectangeArea(a, b, c, d);
        return total - interArea;
    }

private:
    int getRectangeArea(int a, int b, int c, int d) 
    {
        return (c - a) * ( d - b);
    }
public:
    void testCase() 
    {
        cout << getRectangeArea(0, 0, 4, 4) << endl;
        cout << getRectangeArea(-4, -4, 0, 0) << endl;
        int A = 0, B = 0, C = 4, D = 4;
        int E = -4, F= -4, G= 0, H = 0;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 32
        G = 1, H = 1;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 40
        G = 1, H = 5;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 57 
        G = 5, H = 0;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 52  
        G = 5, H = 1;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 57
        G = 5, H = 5;
        cout << computeArea(A,B,C,D,E,F,G,H) << endl; // 81
    }

};

int main(void) 
{
    Solution s;
    s.testCase();
    
}



