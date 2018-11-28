#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, length = nums.size();
        bool *p = new bool[length+2]{false};
        for (i = 0; i < length; i++)
            if (0 < nums[i] && nums[i] <= length)   
                p[nums[i]] = true;
        for (i = 1; i <= length+1; i++)
            if (p[i] == false)
                return i;
    }
};

int main()
{
    Solution test;
    vector<int> num;
    int n;
    int i,x;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        num.push_back(x);
    }
    cout<<test.firstMissingPositive(num)<<endl;
    system("pause");
}