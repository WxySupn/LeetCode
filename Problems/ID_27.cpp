#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        for (auto i = nums.begin(); i != nums.end();)      
        {
            if (*i == val)
            {
                i = nums.erase(i);
            }
            else
            {
                i++;
            }
        }  
        return nums.size();
    }
};

int main()
{

}