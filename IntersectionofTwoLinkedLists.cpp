#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        {
            return NULL;
        }

        ListNode* pA = headA;
        while(pA->next !=NULL) {
            pA = pA->next;
        }
        ListNode* pAEnd = pA;
        
        // link listA end to head
        pA->next = headA;

        ListNode* fast = headB;
        ListNode* slow = headB;
        ListNode* meet = NULL;
        while(fast && slow)
        {
            // move two steps each time
            fast = fast->next;
            // caution: fast is null
            if (fast && fast->next)
            {
                fast = fast->next;
            }
            else
            {
                pAEnd->next = NULL;
                return NULL;
            }

            // move once each time
            slow = slow->next;

            // meet
            if (fast == slow){
                meet = fast;
                break;
            }
        }

        fast = headB;
        slow = meet;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        pAEnd->next = NULL;
        return slow;
    }
public:
    void testCase() 
    {
        ListNode* listA = new ListNode(0);
        listA->next = new ListNode(1);
        printList(listA);

        ListNode* listB = new ListNode(3);
        listB->next = new ListNode(4);
        listB->next->next = new ListNode(5);
        printList(listB);

        ListNode* mList = getIntersectionNode(listA, listB);
        printList(mList);

        ListNode* listC = new ListNode(7);
        listC->next = new ListNode(8);
        listC->next->next = new ListNode(9);
        printList(listC);

        listA->next->next = listC;
        printList(listA);
        listB->next->next->next = listC;
        printList(listB);
        mList = getIntersectionNode(listA, listB);
        printList(mList);

        
    }

private:
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










