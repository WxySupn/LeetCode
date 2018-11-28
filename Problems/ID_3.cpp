#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1;
        bool p[256];
        int i;
        for (i = 0; i < 256; i++)
            p[i] = false;
        int ans = 0;
        while (r + 1 < int(s.length()))
        {
            r = r + 1;
            if (p[s[r]] == false)
            {
                p[s[r]] = true;
            }
            else
            {
                while (p[s[r]] == true)
                {
                    p[s[l]] = false;
                    l = l + 1;
                }
                p[s[r]] = true;
            }
            if (ans < (r - l) + 1)
                ans = r - l + 1;
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    cout<<"s="<<s<<endl;
    Solution test;
    cout<< test.lengthOfLongestSubstring(s) <<endl;
    system("pause");
}