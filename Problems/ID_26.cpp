#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0)
            return 0;
       for (auto i = nums.begin()+1; i != nums.end();)
       {
           cout << *i << ' ' << *(i-1)<< endl;
           if (*i == *(i-1))
           {
                i = nums.erase(i);
           }
           else
           {
                i ++;
           }
       }
       return nums.size();
    }
};

int main()
{
    int i;
    vector<int> nums;
    for (i = 0; i < 10; i++)
    {
        nums.push_back(i);
        nums.push_back(i);
    }
    Solution test;
    test.removeDuplicates(nums);
    for (i =0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }

    system("pause");
}