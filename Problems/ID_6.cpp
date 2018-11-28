#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows == 0)
            return "";
        if (numRows == 1)
            return s;
        string *ans = new string[numRows];
        int i;
        bool p=true;
        int w = 0;
        for (i = 0; i < s.length(); i++)
        {
            ans[w].push_back(s[i]);
            if (p)
            {
                w = w + 1;
                if (w == numRows)
                {
                    p = false;
                    w = w - 2;
                }
            }
            else
            {
                w = w - 1;
                if (w == -1)
                {
                    p = true;
                    w = 1;
                }
            }
        }
        string ans_true;
        for (i = 0; i < numRows; i++)
            ans_true = ans_true + ans[i];
        return ans_true;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    Solution test;
    cout<<test.convert(s,4);
    system("pause");
}