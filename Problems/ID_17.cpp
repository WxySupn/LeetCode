#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> ans;
    void dfs(string digits,string now_string, int w, int n)
    {
        if (w == n)
        {
            ans.push_back(now_string);
            return ;
        }
        if (digits[w] == '1')
        {
            now_string[w] = '*';
            dfs(digits, now_string, w+1, n);  
        }
        if (digits[w] == '2')
        {
            now_string[w] = 'a';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'b';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'c';
            dfs(digits, now_string, w+1, n);    
        }
        if (digits[w] == '3')
        {
            now_string[w] = 'd';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'e';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'f';
            dfs(digits, now_string, w+1, n);  
        }
        if (digits[w] == '4')
        {
            now_string[w] = 'g';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'h';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'i';
            dfs(digits, now_string, w+1, n);  
            
        }
        if (digits[w] == '5')
        {
            now_string[w] = 'j';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'k';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'l';
            dfs(digits, now_string, w+1, n);  
            
        }
        if (digits[w] == '6')
        {
            now_string[w] = 'm';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'n';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'o';
            dfs(digits, now_string, w+1, n);  
        }
        if (digits[w] == '7')
        {
            now_string[w] = 'p';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'q';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'r';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 's';
            dfs(digits, now_string, w+1, n);  
        }
        if (digits[w] == '8')
        {
            now_string[w] = 't';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'u';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'v';
            dfs(digits, now_string, w+1, n);  
        }
        if (digits[w] == '9')
        {
            now_string[w] = 'w';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'x';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'y';
            dfs(digits, now_string, w+1, n);  
            now_string[w] = 'z';
            dfs(digits, now_string, w+1, n);     
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) return ans;
        string now_string(n,42);
        dfs(digits,now_string,0,n);
        return ans;
    }
};