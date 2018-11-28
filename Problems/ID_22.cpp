#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(int w,int n,int sum, string s)
    {
        //cout << s << ' ' << sum << endl;
        if (w == n)
        {
            if (sum == 0)
                ans.push_back(s);
            return ;
        }
        s[w] = '(';
        dfs(w+1, n, sum+1, s);
        if (sum > 0)
        {
            s[w] = ')';
            dfs(w+1,n,sum-1,s);
        }
    }
    vector<string> generateParenthesis(int n) {
        n = n * 2;
        string s(n,'*');

        dfs(0,n,0,s);
        return ans; 
    }
};

int main()
{
    Solution test;
    test.generateParenthesis(3);
}