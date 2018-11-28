#include <iostream>
#include <stdlib.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *last = NULL, *aim, *end;
        end = head;
        int i;
        for(i = 0; i < n; i++)
            end = end->next;
        aim = head;
        while (end != 0)
        {
            end = end->next;
            last = aim;
            aim = aim->next;
        }
        if (head == aim)
        {
            head = head-> next; 
            return head;
        }
        else
        {
            last->next = aim->next;
            return head;
        }
    }
};

int main()
{
    ListNode *head=NULL, *now_node=NULL;
    int n, m;
    int val;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (head == NULL)
        {
            head = new ListNode(val);
            now_node = head;
        }
        else
        {
            now_node -> next = new ListNode(val);
            now_node = now_node ->next;
        }
    }
    Solution test;
    while (head != NULL)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    head = test.removeNthFromEnd(head, m);
    while (head != NULL)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    system("pause");
}