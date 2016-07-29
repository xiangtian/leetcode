#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;

        ListNode* p = blankHead;
        ListNode* q = head;
        // q move n step first
        while(--n >= 0)
        {
            q = q->next;
        }

        while(q)
        {
            q = q->next;
            p = p->next;
        }

        // move Nth Element
        ListNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;

        tmp = blankHead->next;
        delete blankHead;
        return tmp;
    }
public:
    void testCase() {
        int a[] = {1,1,2,3,4,4,4};
        ListNode* head = makeList(a,7);
        printList(head);
        head = removeNthFromEnd(head, 3);
        printList(head);

        head = makeList(a, 7);
        printList(head);
        head = removeNthFromEnd(head, 3);
        printList(head);

        head = makeList(a, 7);
        printList(head);
        head = removeNthFromEnd(head, 5);
        printList(head);

        head = makeList(a, 1);
        printList(head);
        head = removeNthFromEnd(head, 1);
        printList(head);
    }

private:
    ListNode* makeList(int a[], int len)
    {
        ListNode* head = new ListNode(a[0]);
        if(len == 1)
        {
            return head;
        }

        ListNode* p = head;
        for(int i = 1; i < len; i++) {
            ListNode* node = new ListNode(a[i]);
            p->next = node;
            p = node;
        }
        return head;
    }

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
