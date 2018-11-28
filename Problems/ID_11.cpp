#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, z;
        int max1 = 0, max2 = 0;
        int w1,w2;
        int l = height.size();
        for (i = 0; i < l; i++)
        {
            if (max2 < height[i])
            {
                max2 = height[i];
                w2 = i;
                if (max1 < height[i])
                {
                    max2 = max1;
                    max1 = height[i];
                    w2 = w1;
                    w1 = i;
                }
            }
        }
        int ans = max2 * (w2 - w1);
        for (i = 0; i < l; i++)
        {
            if (height[i] == 0)
                continue;
            for (z = i + (ans / height[i]) + 1; z < l ;z++)
            {
                max1 = height[i] < height[z] ? height[i]:height[z];
                if (ans < max1 * (z - i))
                    ans = max1 * (z - i);
            }
        }
        return ans;
    }
};

int main()
{
    int n, x;
    scanf("%d", &n);
    vector<int> num;
    Solution test;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        num.push_back(x);
    }
    cout << test.maxArea(num) << endl;
    system("pause");
}