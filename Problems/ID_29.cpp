#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long did = dividend;
        long long dis = divisor;
        long long sign;
        long long ans = 0;
        if (did * dis > 0){
            sign = 1;
        }
        else{
            sign = -1;
        }

        did = labs(did);
        dis = labs(dis);
        while (did >= dis)
        {
            long long temp = dis;
            long long tans = 1;
            while (did >= (temp << 1))
            {
                temp <<= 1;
                tans <<= 1;
            }
            did -= temp;
            ans += tans;
        }

        ans = ans * sign;
        if (ans < -2147483648 || ans > 2147483647)
            ans = 2147483647;
        return ans;
    }
};

int main()
{

    int x,y;
    cin >> x >> y;
    
    Solution test;
    cout << test.divide(x,y) << endl;
    system("pause");

}