#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        mQueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int qSize = mQueue.size();
        for(int i= 1; i < qSize; i++)
        {
            mQueue.push(mQueue.front());
            mQueue.pop();
        }

        mQueue.pop();
    }

    // Get the top element.
    int top() {
        int qSize = mQueue.size();
        for(int i = 1; i< qSize; i++)
        {
            mQueue.push(mQueue.front());
            mQueue.pop();
        }
        int top = mQueue.front();
        mQueue.push(mQueue.front());
        mQueue.pop();
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return mQueue.empty();
    }
private:
    queue<int> mQueue;
};

int main(void)
{
    Stack s;
    for(int i = 0; i < 4; i++)
    {
        s.push(i);
    }

    for(int i = 0; i< 4; i++)
    {
        cout << s.top() << endl;
        s.pop();
        cout << "isempty: "<< s.empty() << endl;
    }
}
