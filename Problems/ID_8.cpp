#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;



class Solution {
public:
    bool Check_1(char c)
    {
        if (c == '+' || c == '-' || ('0' <= c && c <= '9'))
            return false;
        return true;
    }
    bool Check_2(char c)
    {
        if ('0' <= c && c <= '9')
            return true;
        return false;
    }
    int myAtoi(string str) {
        long long p_INT_MAX = ((long long)1<<31) - 1, n_INT_MAX = ((long long)1 << 31), ans = 0;
        // cout<<" p_INT_MAX="<<p_INT_MAX<<endl;
        // cout<<" n_INT_MAX="<<n_INT_MAX<<endl;
        bool p = true;
        int i, length = str.size();
        for ( i = 0; str[i] == ' '; i++){}
        if (Check_1(str[i]))
        {
            // cout<<"Not sky!"<<endl;
            return 0;
        }
        else
        {
            if (str[i] == '-')
            {
                p = false;
                i = i + 1;
            }
            else
            {
                if (str[i] == '+')
                {
                    p = true;
                    i = i + 1;
                }
            }
            // while (str[i] == '-' || str[i] == '+')
            // {
            //     if (str[i] == '-')
            //         p = p^1;
            //     i++;
            // }
            for ( ; Check_2(str[i]); i++)
            {
                ans = ans * 10 + (str[i] - '0');
                if (p)
                {
                     cout<<ans<<endl;
                    if (ans > p_INT_MAX)
                        return p_INT_MAX;
                }
                else
                {
                    // cout<<ans<<endl;
                    if (ans > n_INT_MAX)
                        return -n_INT_MAX;
                }

            }
            if (p == false)
                ans = -ans;
            return ans;
        }
    }
};

int main()
{
    Solution test;
    string s="+2";
    cout<<test.myAtoi(s)<<endl;
    system("pause");
}