#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
     ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

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
                return NULL;
            }

            if(p == q)
            {
                break;
            }
        }
        
        p = head;
        while(p != q)
        {
            p = p->next;
            q= q->next;
        }
        return p;
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
        ListNode* noCycle = detectCycle(head);
        printList(noCycle);
        node3->next = node2;
        head = detectCycle(head);
        cout << head->val << endl;
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
