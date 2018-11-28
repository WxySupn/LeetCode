#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool find(vector<int> nums, int aim, int fix)
    {
        //cout << "aim:" << aim << endl;
        int l = fix, r = nums.size();
        int x;
        while (r - l - 1 > 0)
        {
            x = (l + r) >> 1;
            if (nums[x] == aim)
            {
                return true;
            }
            else
            {
                if (nums[x] < aim)
                    l = x;
                if (nums[x] > aim)
                    r = x;
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, z;
        int num_ans = 0;
        int n = nums.size();
        vector<vector<int>> nums_ans;
        vector<int> t_num = {0,0,0};
        sort(nums.begin(), nums.begin()+nums.size());
        //for (i = 0; i < nums.size(); i++)
        //    cout << nums[i] << ' ';
        //cout << endl;
        for (i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return nums_ans;
            if (i >= 1 && nums[i] == nums[i-1])
                continue;
            for (z = i + 1; z < n; z++)
            {
                if (-(nums[i] + nums[z]) > nums[n-1]) 
                {
                    continue;
                }
                if (find(nums,-(nums[i]+nums[z]), z) && ((num_ans == 0) || (nums[i] != nums_ans[num_ans-1][0]) || (nums[z] != nums_ans[num_ans-1][1]) ||(-(nums[i]+nums[z]) != nums_ans[num_ans-1][2]) ))
                {
                    t_num[0] = nums[i];
                    t_num[1] = nums[z];
                    t_num[2] = -(nums[i] + nums[z]);
                    nums_ans.push_back(t_num);
                    num_ans++;    
                }
            }
        }
       return nums_ans;
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
