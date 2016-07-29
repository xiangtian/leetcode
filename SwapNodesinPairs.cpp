#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* blankHead = new ListNode(0);
        // prior of head
        ListNode* prior = blankHead;
        blankHead->next = head;
        ListNode* p = head;
        while(p && p->next)
        {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            prior->next = q;

            prior = p;
            p = p->next;
        }

        head = blankHead->next;
        delete blankHead;
        return head;
    }

public:
    void testCase()
    {
        int a[] = {1,2,3,4,5};
        ListNode* head = makeList(a, 5);
        printList(head);
        head = swapPairs(head);
        printList(head);
        head = swapPairs(head);
        printList(head);

        head = makeList(a, 4);
        printList(head);
        head = swapPairs(head);
        printList(head);
        head = swapPairs(head);
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
