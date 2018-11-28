#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k = 0)
            return head;
        ListNode *ans;
        ans = new ListNode(0);
        ans->next = head;

        ListNode *ll, *l, *r, *t;
        int i;
        ll = ans;
        l = head;
        r = head;
        for (i = 0; i < k && r != NULL; i++)
            r = r->next;
        
        while (i != k)
        {
            for (i = 0; i < k; i++)
            {
                t = l->next;  
                l->next = r;
                r = l;
                l = t;                  
            } 
            ll -> next = r;
            t = l;
            l = r;
            r = t;

            for (i = 0; i < k && r != NULL; i++)
            {
                ll = ll->next;
                l = l->next;
                r = r->next;
            }
        }
        ans = ans->next;
        return ans;
    }
};

int main()
{

}