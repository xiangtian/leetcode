#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n){
            return head;
        }
        // add blank head
        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        
        // find m prior
        ListNode* prior = blankHead;
        for(int i = 0; i < (m-1); i++)
        {
            prior = prior->next; 
        }
       
        // reverse
        ListNode* cur = prior->next;
        while(m < n) 
        {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = prior->next;
            prior->next = tmp;
            m++;
        }
        
        head = blankHead->next;
        delete blankHead;
        return head;
    }

public:
    void testCase() 
    {
        int array1[] = {1,2,3,4,5};
        ListNode* list1 = makeList(array1, 5);
        printList(list1);

        list1 = reverseBetween(list1, 1, 1);
        printList(list1);

        list1 = reverseBetween(list1, 3, 4);
        printList(list1);
        list1 = reverseBetween(list1, 3, 4);
        printList(list1);

        list1 = reverseBetween(list1, 1, 5);
        printList(list1);
        list1 = reverseBetween(list1, 1, 5);
        printList(list1);

        list1 = reverseBetween(list1, 2, 4);
        printList(list1);
        list1 = reverseBetween(list1, 2, 4);
        printList(list1);
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
