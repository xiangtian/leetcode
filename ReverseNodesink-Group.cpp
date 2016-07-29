#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        if (len < k || k <= 1)
        {
            return head;
        }
        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        ListNode* prior = blankHead;
        for (int i = 0; i < len / k; i++)
        {
            ListNode* p = prior->next;
            int j = 0;
            while (++j < k)
            {
                ListNode* q = p->next;
                p->next = q->next;
                q->next = prior->next;
                prior->next = q;
            }
            prior = p;
        }

        head = blankHead->next;
        delete blankHead;
        return head;
    }

private:
    int getLength(ListNode* node)
    {
        int len = 0;
        ListNode* p = node;
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
        int a[5] = {1, 2, 3, 4, 5};
        ListNode* head = makeList(a, 5);
        printList(head);
        head = reverseKGroup(head, 1);
        printList(head);
    }

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
