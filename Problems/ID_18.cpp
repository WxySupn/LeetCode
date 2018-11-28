#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());    
        int n = nums.size();
        int i,z,l,r;
        vector<int> t_new(4);
        vector<int> :: iterator t_end;
        vector<vector<int>> ans;
        for (i = 0; i < n-3; i++)
        {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (z = i+1; z < n-2; z++)
            {
                if (z != i+1 && nums[z] == nums[z-1]) continue;
                l = z+1;
                r = n-1;
                cout << i << ' ' << z << ' ' << l << ' ' << r << endl;
                while (l < r)
                {
                    if (l < r && nums[i] + nums[z] + nums[l] + nums[r] - target < 0) 
                    {
                        l++;
                        continue;
                    }
                    if (l < r && nums[i] + nums[z] + nums[l] + nums[r] - target > 0) 
                    {
                        r--;
                        continue;
                    }
                    if (nums[i] + nums[z] + nums[l] + nums[r] - target == 0)
                    {
                        t_new[0] = nums[i];
                        t_new[1] = nums[z];
                        t_new[2] = nums[l];
                        t_new[3] = nums[r];
                        l++;
                        r--;
                        if (ans.size() != 0)
                            t_end = (ans.end()-1)->begin();
                        if (ans.size() != 0 && t_new[0] == t_end[0] && t_new[1] == t_end[1] && t_new[2] == t_end[2] && t_new[3] == t_end[3])
                            continue;
                        ans.push_back(t_new);
                    }
                }
            }  
        }
        return ans;
    }
};

int main()
{
    int n,x;
    int i;
    vector<int> nums;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        nums.push_back(x);
    }
    
    Solution test;
    vector<vector<int>> num_ans;
    num_ans = test.fourSum(nums,0);
    int l = nums.size();
    for (i = 0; i < l; i++)
    {
        x = num_ans[i].size();
        for (int z = 0; z < x; z++)
            cout << num_ans[i][z] << ' ';
        cout << endl;
    }
    system("pause");
    return 0;
}
