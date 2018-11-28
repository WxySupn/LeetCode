#include <iostream>
using namespace std;


 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *end;
        head = new ListNode(0);
        end = head;
        while (l1 != NULL || l2 != NULL)
        {
            
            if (l1 == NULL)
            {
                end->next = new ListNode(l2->val);
                l2 = l2->next;
                end = end->next;
                continue;
            }
            if (l2 == NULL)
            {
                end->next = new ListNode(l1->val);
                l1 = l1->next;
                end = end->next;
                continue;
            }
            if (l1->val <= l2->val)
            {
                end->next = new ListNode(l1->val);
                l1 = l1->next;
                end = end->next;
            }
            else
            {
                end->next = new ListNode(l2->val);
                l2 = l2->next;
                end = end->next;
            }
        }
        head = head->next;
        return head;    
    }
};