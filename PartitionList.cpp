#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return NULL;
        }

        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        ListNode* p = head;
        ListNode* prior = blankHead;
        while(p && p->val < x){
            prior = p;
            p = p->next;
        }

        ListNode* q = prior;
        while(p)
        {
            if ( p->val < x) {
                ListNode* tmp = p->next;
                q->next = tmp;
                p->next = prior->next;
                prior->next = p;
                prior = prior->next;

                p = tmp;
                continue;
            }
            q = p;
            p = p->next;
        }

        head = blankHead->next;
        delete blankHead;
        return head;
    }

public:
    void testCase() 
    {
        int a[] = {1,2,7,6,4,5};
        ListNode* head = makeList(a, 6);
        printList(head);
        head = partition(head, 8);
        printList(head);
        head = partition(head, 5);
        printList(head);
        head = partition(head, 6);
        printList(head);
        head = partition(head, 7);
        printList(head);
        head = partition(head, 0);
        printList(head);
        head = partition(head, 8);
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
