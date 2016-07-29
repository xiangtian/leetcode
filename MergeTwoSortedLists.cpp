#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        return merge(l1, l2);
    }
private:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(!left) {
            return right;
        }
        if(!right) {
            return left;
        }

        ListNode* mergeList = new ListNode(0);
        ListNode* head = mergeList;
        while(left && right) {
            if (left->val <= right->val) {
                mergeList->next = left;
                mergeList = mergeList->next;
                left = left->next;
            }
            else
            {
                mergeList->next = right;
                mergeList = mergeList->next;
                right = right->next;
            }
        }

        if(left)
        {
            mergeList->next = left;
        }

        if(right)
        {
            mergeList->next = right;
        }

        ListNode* node = head->next;
        delete head;
        return node;
    }
public:
    void testCase()
    {
       int array1[] = {1,4,5};
       ListNode* left = makeList(array1, 3);
       printList(left);
       int array2[] = {2,3};
       ListNode* right = makeList(array2, 2);
       printList(right);
       ListNode* mergeList = mergeTwoLists(left, right);
       printList(mergeList);

       int array3[] = {7,8,9};
       ListNode* third = makeList(array3, 3);
       ListNode* thirdMerage = mergeTwoLists(mergeList, third);
       printList(thirdMerage);
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
}

