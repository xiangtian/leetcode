#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* p = head;
        while(p)
        {
            ListNode* q = p->next;
            while (q && p->val == q->val) {
                ListNode* tmp = q;
                q = q->next;
                p->next = q;
                delete tmp;
            }
            p = q;
        }
        return head;
    }
public:
    void testCase() {
        int a[] = {1,1,2,3,4,4,4};
        ListNode* head = makeList(a,7);
        printList(head);
        deleteDuplicates(head);
        printList(head);

        head = makeList(a, 1);
        printList(head);
        deleteDuplicates(head);
        printList(head);

        head = makeList(a, 2);
        printList(head);
        deleteDuplicates(head);
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
