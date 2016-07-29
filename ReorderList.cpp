#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        int len = lenghtOfList(head);
        if (len <= 2) {
            return;
        }

        // move to mid node
        int mid = (len + 1) / 2;
        ListNode* p = head;
        int i = 1;
        while(i < mid) 
        {
            p = p->next;
            ++i;
        }
        
        // p is mid node
        p = reverseList(p, p->next);
        
        ListNode* q = head;
        while(q != p) 
        {
            ListNode* tmp = q->next;
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = tmp;
            q = tmp;
        }
    }
private:
    int lenghtOfList(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            ++len;
        }
        return len;
    }

    ListNode* reverseList(ListNode* head, ListNode* node) {
        while(node->next) 
        {
            ListNode* tmp = node->next;
            node->next = tmp->next;
            tmp->next = head->next;
            head->next = tmp;
        }
        return head;
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

public:
    void testCase(){
        int a[] = {1, 2, 3, 4, 5, 6};
        ListNode* head = makeList(a, 6);
        cout << lenghtOfList(head) << endl; 
        reorderList(head);
        printList(head);
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
