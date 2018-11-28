#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *ll, *l, *r, *t, *ans;    
        l = head;
        r = head -> next;
        ll = new ListNode(0);
        ll -> next = head;
        head = ll;
        while (r != NULL)
        {
            ll->next = r;
            l->next = r->next;
            r->next = l;

            t = l;
            l = r;
            r = t;

            ll = r;
            l = l->next->next;
            if (r->next != NULL)
            {
                r = r->next->next;
            }
            else
            {
                r = NULL;
            }
        }
        head = head->next;
        return head;
    }
};

int main()
{

}