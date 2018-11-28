#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ans, right, left;

        if (N == 0) return ans;
        if (N == 1) 
        {
            TreeNode* now = new TreeNode(0);
            ans.push_back(now);
            return ans;
        }
        if (N == 2) return ans;
        int a,b;
        for (int i = 0; i < N-1; i++)
        {
            a = i + 1;
            b = N - a - 1;
            right = allPossibleFBT(a);
            left  = allPossibleFBT(b);
            for (auto p1:right)
                for (auto p2:left){
                    TreeNode* n1 = new TreeNode(0);
                    n1->left = p1;
                    n1->right = p2;
                    ans.push_back(n1);
                }
        }
        return ans;
    }
};

int main()
{
    int N;
    cin >> N;
    Solution test;
    vector<TreeNode*> ans = test.allPossibleFBT(N);
    int n;
    cout << "n=" << n << endl;
    system("pause");
}