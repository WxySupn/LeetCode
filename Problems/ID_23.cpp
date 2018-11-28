#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct cmp{
        bool operator() (const ListNode &a, const ListNode &b)
        {
            return a.val > b.val;
        }    
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        priority_queue<ListNode, vector<ListNode> , cmp> queue;    
        ListNode *head, *end, *t_node;
        head = new ListNode(0);
        end = head;
        int i, n = lists.size();
        for (i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
                queue.push(*lists[i]);
        }
        while (!queue.empty())
        {
            t_node = new ListNode(queue.top().val);
            t_node -> next = queue.top().next;
            end->next = new ListNode(t_node->val);
            end = end->next;
            queue.pop();
            if (t_node -> next != NULL)
            {
                queue.push(*t_node -> next);
            }
        }
        head = head->next;
        return head;
    }
};

int main()
{
    int i, n;
    int *num = new int[n];
    for (i = 0; i < n; i++)
        cin >> num[i];
    
}