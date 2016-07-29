#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next)
        {
            return head;
        }
        // add BlankHead
        ListNode* blankHead= new ListNode(0);
        blankHead->next = head;

        ListNode* p = head;
        while(p->next) {
            ListNode* q = blankHead;
            // q should always before p
            while((q!= p) && (q->next->val <= p->next->val))
            {
                q = q->next;
            }
            
            // if insert happens, pointer p had changed to p->next
            if(q != p)
            {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                tmp->next = q->next;
                q->next = tmp;
            }
            else
            {
                p = p->next;
            }

            q = blankHead->next;
        }

        head = blankHead->next;
        delete blankHead;
        return head;
    }
public:
    void testCase()
    {
        int test1[3] = {5,4,3};
        ListNode* linkedList = makeList(test1, 3);
        printList(linkedList);
        ListNode *sortList = insertionSortList(linkedList);
        printList(sortList);
        destoryList(sortList);

        int test2[3] = {1,2,3};
        linkedList = makeList(test2, 3);
        printList(linkedList);
        sortList = insertionSortList(linkedList);
        printList(sortList);
        destoryList(sortList);
        
        int test3[1] = {1};
        linkedList = makeList(test3, 1);
        printList(linkedList);
        sortList = insertionSortList(linkedList);
        printList(sortList);
        destoryList(sortList);

        int test4[5] = {1,5,4,2,3};
        linkedList = makeList(test4, 5);
        printList(linkedList);
        sortList = insertionSortList(linkedList);
        printList(sortList);
        destoryList(sortList);
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

    void destoryList(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = p;
        while(p)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }
};

int main(void)
{
    Solution s;
    s.testCase();

    return 1;
}
