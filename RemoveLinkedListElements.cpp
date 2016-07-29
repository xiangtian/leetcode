#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
       ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        ListNode* p = head;
        ListNode* prior = blankHead;
        while(p)
        {
            if(p->val == val) {
                ListNode* tmp = p;
                prior->next = p->next;
                p = p->next;
                delete tmp;
            }
            else
            {
                prior= p;
                p = p->next;
            }
        }

        ListNode* tmp = blankHead->next;
        delete blankHead;
        return tmp;
    }
public:
    void testCase() {
        int a[] = {1,1,2,3,4,4,4};
        ListNode* head = makeList(a,7);
        printList(head);
        head = removeElements(head, 1);
        printList(head);

        head = makeList(a, 3);
        printList(head);
        head = removeElements(head,1);
        printList(head);

        head = makeList(a, 3);
        printList(head);
        head = removeElements(head, 2);
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
