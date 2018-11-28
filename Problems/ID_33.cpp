#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        int mid;

        if (target == nums[0]){
            return 0;
        }
        else
        {
            if (target < nums[0])
            {
                while (l < r)
                {
                    mid = (l + r) / 2;
                    if (target == nums[mid])
                        return mid;
                    if (nums[0] < nums[mid])
                    {
                        l = mid;
                    }
                    else{
                        if (nums[mid] < target)
                            l = mid;
                        if (target < nums[mid])
                            r = mid;
                    }
                }
            }
            if (target > nums[0])
            {
                while (l < r)
                {
                    mid = (l + r) / 2;
                    if (target == nums[mid])
                        return mid;
                    if (nums[0] > nums[mid])
                    {
                        r = mid;
                    }
                    else{
                        if (nums[mid] < target)
                            l = mid;
                        if (target < nums[mid])
                            r = mid;
                    }
                }

            }
        }
        return -1;
    }
};

int main(){
    
}