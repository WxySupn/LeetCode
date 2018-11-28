#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strs[0];
        //cout << "n=" << n << endl;
        string s;
        bool p = true;
        int w = 0;
        while (p)
        {
            //cout << "w=" << w << endl;
            for (int i = 0; i < n; i++)
            {
                if (strs[0][w] != strs[i][w])
                    p = false;    
            }
            if (p)
            {
                s.push_back(strs[0][w]);
                w = w + 1;
            }
        }
        return s;
    }
};

int main()
{
    vector<string> strs;
    string s;
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        strs.push_back(s);
    }  
    Solution test;
    cout << test.longestCommonPrefix(strs);
    system("pause");
}