#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        mDataStack.push(x);
        if(mMinStack.empty() || x <= mMinStack.top())
        {
            mMinStack.push(x);
        }
    }

    void pop() {
        if (!mMinStack.empty())
        {
            if (mMinStack.top() == mDataStack.top())
            {
                mMinStack.pop();
            }
        }
        mDataStack.pop();
    }

    int top() {
        return mDataStack.top();
    }

    int getMin() {
        return mMinStack.top();
    }

private:
    stack<int> mDataStack;
    stack<int> mMinStack;

public:
    void testCase()
    {
        push(0);
        push(1);
        push(0);
        cout << getMin() << endl;
        pop();
        cout << getMin() << endl;
    }
};

int main(void)
{
    MinStack ms;
    ms.testCase();
}
