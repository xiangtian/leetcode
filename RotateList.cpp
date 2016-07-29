#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL || k == 0)
        {
            return head;
        }

        ListNode* p = head;
        ListNode* q = head;
        int len = getListLength(head);
        int r = k % len;
        
        if (len <= 1 || r == 0)
        {
            return head;
        }

        r = len - r;

        // find k element prior
        while(--r > 0) {
            p = p->next;
        }

        q = p->next;
        ListNode* tmpHead = q;
        p->next = NULL;

        while(q->next)
        {
            q = q->next;
        }
        
        q->next = head;
        head = tmpHead;

        return head;
    }
private:
    int getListLength(ListNode* head)
    {
        ListNode* p = head;
        int len = 0;
        while(p)
        {
            ++len;
            p = p->next;
        }
        return len;
    }
public:
    void testCase()
    {
        int a[] = {1,2,3,4,5};
        ListNode* head = makeList(a, 5);
        printList(head);
        head = rotateRight(head, 1);
        printList(head);
        head = rotateRight(head, 4);
        printList(head);
        head = rotateRight(head, 2);
        printList(head);

        head = makeList(a, 2);
        printList(head);
        head = rotateRight(head, 0);
        printList(head);

        head = rotateRight(NULL, 0);
        cout << getListLength(NULL);
        
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
