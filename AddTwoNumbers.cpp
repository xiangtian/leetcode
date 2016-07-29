#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        if (p == NULL) {
            return p;
        }

        if (q == NULL) {
            return q;
        }

        ListNode* blankHead = new ListNode(0);
        ListNode* r = blankHead;

        int carry = 0;
        while(p && q)
        {
            int result = carry + p->val + q->val;
            carry = result / 10;
            result = result % 10;
            r->next = new ListNode(result);

            r = r->next;
            p = p->next;
            q = q->next;
        }

        if(p || q){
            ListNode* tmp = NULL;
            if (p) {
                tmp = p;
            }
            else
            {
                tmp = q;
            }

            while(tmp) {
                int result = carry + tmp->val;
                carry = result / 10;
                result = result % 10;
                r->next = new ListNode(result);
                r = r->next;
                tmp = tmp->next;
            }
        }


        if(carry != 0 ){
            r->next = new ListNode(carry);
        }

        ListNode* head = blankHead->next;
        delete blankHead;
        return head;
    }
public:
    void testCase()
    {
        int a[] = {1,8,9};
        ListNode* l1 = makeList(a, 3);
        printList(l1);
        int b[] = {2,3,5};
        ListNode* l2 = makeList(b, 3);
        printList(l2);
        ListNode* l3 = addTwoNumbers(l1,l2);
        printList(l3);

        int c[] = {2, 3};
        ListNode* l4  = makeList(c, 2);
        printList(l4);
        l3 = addTwoNumbers(l1, l4);
        printList(l3);

        l4 = new ListNode(0);
        l2 = new ListNode(0);
        l3 = addTwoNumbers(l4, l2);
        printList(l3);

        int d[] = {9,9,9,9,9};
        ListNode* l5 = makeList(d,5);
        l2 = new ListNode(1);
        l3 = addTwoNumbers(l5,l2);
        printList(l3);
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
