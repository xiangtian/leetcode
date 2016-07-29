#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        while(q)
        {
            p = p->next;
            q = q->next;
            if (q)
            {
                q = q->next;
            }
            if(q == NULL)
            {
                return false;
            }

            if(p == q)
            {
                return true;
            }
        }
        return false;
    }
public:
    void testCase()
    {
        ListNode* head = new ListNode(0);
        ListNode* node1 = new ListNode(1);
        ListNode* node2 = new ListNode(2);
        ListNode* node3 = new ListNode(3);
        head->next = node1;
        node1->next = node2;
        node2->next = node3;
        printList(head);
        cout << hasCycle(head) << endl;
        node3->next = node2;
        cout << hasCycle(head) << endl;
    }

private:

    void printList(ListNode* head)
    {
        ListNode* p = head;
        while(p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
