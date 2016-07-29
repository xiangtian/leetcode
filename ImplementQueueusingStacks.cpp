#include<iostream>
#include<stack>
using namespace std;
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        mFirstStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if( !mSecondStack.empty()) {
            mSecondStack.pop();
            return;
        }

        while (!mFirstStack.empty()) {
            mSecondStack.push(mFirstStack.top());
            mFirstStack.pop();
        }
        mSecondStack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (!mSecondStack.empty()) {
            return mSecondStack.top();
        }

        while (!mFirstStack.empty()) {
            mSecondStack.push(mFirstStack.top());
            mFirstStack.pop();
        }
        return mSecondStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mFirstStack.empty() && mSecondStack.empty();
    }

    void testCase()
    {
        cout << empty()  << endl;
        push(1);
        push(2);
        push(3);
        cout << empty() << endl;
        cout << peek() << endl;
        pop();
        cout << peek() << endl;
        pop();
        cout << peek() << endl;
        pop();
        cout << empty() << endl;
    }

private:
    stack<int> mFirstStack;
    stack<int> mSecondStack;
};

int main(void)
{
    Queue queue;
    queue.testCase();
}
