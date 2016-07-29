#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL) {
            return head;
        }
        

        ListNode* p = head;
        ListNode* prior = NULL;
        bool isDuplicated = false;
        while(p) {
            // judge duplicated
            if(p->next && p->val == p->next->val)
            {
                isDuplicated = true;
                ListNode* q = p->next;
                p->next = q->next;
                delete q;
            }
            else
            {
                if(isDuplicated) {
                    if(p == head) { // head is duplicated element
                        head = p->next;
                    }

                    isDuplicated = false;
                    ListNode* q = p;
                    p = p->next;
                    if(prior) {
                        //first duplicate element's prior
                        prior->next = p;
                    }
                    delete q;
                }
                else
                {
                    prior = p;
                    p = p->next;
                }
            }
        }
        
        return head;
    }

public:
    void testCase() 
    {
        int array1[] = {1,1,2,2,4,5,6,6,6};
        ListNode* list1 = makeList(array1, 9);
        printList(list1);
        list1 = deleteDuplicates(list1);
        printList(list1);

        list1 = makeList(array1, 4);
        printList(list1);
        list1 = deleteDuplicates(list1);
        printList(list1);

        list1 = makeList(array1, 6);
        printList(list1);
        list1 = deleteDuplicates(list1);
        printList(list1);
        
        list1 = makeList(array1, 7);
        printList(list1);
        list1 = deleteDuplicates(list1);
        printList(list1);

        int array2[] = {4,5,6,6,6,7,7};
        list1 = makeList(array2, 4);
        printList(list1);
        list1 = deleteDuplicates(list1);
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
