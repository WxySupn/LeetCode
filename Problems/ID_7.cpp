#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool p1 = true;
        unsigned int max_int = (1 << 31);
        if (x < 0)
        {
            p1 =false;
            max_int = max_int - 1;
            x = -x;
        }
        int num_x[10] = {0}, i_x = 0;
        int num_max[10] = {0}, i_max = 0;
        int num_ans[10] = {0}, i_ans = 0;
        while (x > 0)
        {
            num_x[i_x] = x % 10;
            x = x / 10;
            i_x++;
        }
        while (max_int > 0)
        {
            num_max[i_max] = max_int % 10;
            max_int = max_int / 10;
            i_max++;
        }
        int i;
        for (i = 0; i < i_x; i++)
            num_ans[i] = num_x[i_x - i - 1];
        
        // for (i = 0; i < 10; i++)
        //     cout<<num_x[i];
        // cout<<endl;
        //  for (i = 0; i < 10; i++)
        //     cout<<num_max[i];
        // cout<<endl;
        //  for (i = 0; i < 10; i++)
        //     cout<<num_ans[i];
        // cout<<endl;
        i = 9;
        while (i >= 0 && num_ans[i] == num_max[i])
        {
            i = i - 1;
        }
        if (i >= 0 && num_ans[i] > num_max[i])
            return 0;
        int ans = 0;
        for (i = 0; i < i_x; i++)
        {
            ans = ans * 10 + num_x[i];
        }
        if (p1 == false)
            ans = -ans;
        return ans;
    }
};

int main()
{
    Solution test;
    int n;
    while (1 == 1)
    {
        scanf("%d", &n);
        cout<<test.reverse(n)<<endl;
    }
    system("pause");
}