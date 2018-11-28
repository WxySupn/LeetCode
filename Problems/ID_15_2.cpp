#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> t_num(3,0);
        int n = nums.size();
        int t_n;
        int i, l ,r;
        for (i = 0; i < n-2; i++)
        {
            cout << i << endl;
            if (i != 0 && nums[i-1] == nums[i]) continue;
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                cout << l << " " << r << endl;
                if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                    while (nums[l-1] == nums[l] && l < r) l ++;
                    continue;
                } 
                if (nums[i] + nums[l] + nums[r] > 0) 
                {
                    r--;
                    while (nums[r] == nums[r+1] && l < r) r --;
                    continue;
                }
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    t_num[0] = nums[i];
                    t_num[1] = nums[l];
                    t_num[2] = nums[r];
                    l = l + 1;
                    r = r - 1;
                   
                    t_n = ans.size() - 1;
            
                    if (t_n != -1 && ans[t_n][0] == t_num[0] && ans[t_n][1] == t_num[1] && ans[t_n][2] == t_num[2]) 
                        continue;
                    ans.push_back(t_num);
                } 
            }
        }
        cout << "Success" << endl;
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
    num_ans = test.threeSum(nums);
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
