#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int find_min(vector<int>& nums, int v)
    {
        int r = -1, l = nums.size(), x;
        while (l - r > 1)
        {
            x = (r + l) / 2;
            if (nums[x] < v)
                r = x;
            if (nums[x] >= v)
                l = x;
        }
        return r + 1;
    }
    int find_max(vector<int>& nums, int v)
    {
        int r = -1, l = nums.size(), x;
        while (l - r > 1)
        {
            x = (r + l) / 2;
            if (nums[x] <= v)
                r = x;
            if (nums[x] > v)
                l = x;
        }
        return nums.size() - l;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_1 = nums1.size();
        int length_2 = nums2.size();
        int l1 = -1, r1 = nums1.size(), x1;
        int l2 = -1, r2 = nums2.size(), x2;
        int ans1_w = (length_1 + length_2) / 2 + 1 - ((length_1 +length_2 + 1) & 1);
        int ans2_w = (length_1 + length_2) / 2 + 1;
        int ans1_v = 0, ans2_v =0;
        bool p1 =false, p2=false;
        // cout<<"---------------------------------------------"<<endl;
        // cout<<" ans1_w="<<ans1_w<<endl;
        // cout<<" asn2_w="<<ans2_w<<endl;

        // cout<<"---------------------------------------------"<<endl;
        int min_num, max_num;
        while (p1 == false || p2 == false)
        {
            if (r1 - l1 > 1)
            {
                x1 = (l1 + r1) / 2;
                min_num = find_min(nums1, nums1[x1]) + find_min(nums2, nums1[x1]);
                max_num = find_max(nums1, nums1[x1]) + find_max(nums2, nums1[x1]);
                // cout<<" nums1="<<nums1[x1] << endl;
                // cout<<" min_num="<<min_num<<endl;
                // cout<<" max_num="<<max_num<<endl;
                // cout<<" length_1 + length_2 - ans1_w="<<length_1 + length_2 - ans1_w<<endl;
                // cout<<" length_1 + length_2 - ans2_w="<<length_1 + length_2 - ans2_w<<endl;
                if (min_num < ans1_w)
                    l1 = x1;
                if (max_num < length_1 + length_2 - ans2_w)
                    r1 = x1;
                if (min_num <= (ans1_w - 1) && max_num <= (length_1 + length_2 - ans1_w))
                {
                    p1 = true;
                    ans1_v = nums1[x1];
                    l1 = x1;
                }
                if (min_num <= (ans2_w - 1) && max_num <= (length_1 + length_2 - ans2_w))
                {
                    p2 = true;
                    ans2_v = nums1[x1];
                    r1 = x1;
                }
                // cout<<" ans1_v="<<ans1_v<<endl;
                // cout<<" ans2_v="<<ans2_v<<endl;    
            }
            if (r2 - l2 > 1)
            {
                x2 = (l2 + r2) / 2;
                min_num = find_min(nums1, nums2[x2]) + find_min(nums2, nums2[x2]);
                max_num = find_max(nums1, nums2[x2]) + find_max(nums2, nums2[x2]);
                // cout<<" nums2="<<nums2[x2] << endl;
                // cout<<" min_num="<<min_num<<endl;
                // cout<<" max_num="<<max_num<<endl;
                if (min_num < ans1_w)
                    l2 = x2;
                if (max_num < length_1 + length_2 - ans2_w)
                    r2 = x2;
                if (min_num <= ans1_w - 1 && max_num <= (length_1 + length_2 - ans1_w))
                {
                    p1 = true;
                    ans1_v = nums2[x2];
                    l2 = x2;
                }
                if (min_num <= ans2_w - 1 && max_num <= (length_1 + length_2 - ans2_w))
                {
                    p2 = true;
                    ans2_v = nums2[x2];
                    r2 = x2;
                }
                // cout<<" ans1_v="<<ans1_v<<endl;
                // cout<<" ans2_v="<<ans2_v<<endl;
            }     
            // cout<<" l1="<<l1;
            // cout<<" r1="<<r1<<endl; 
            // cout<<" l2="<<l2;
            // cout<<" r2="<<r2<<endl;           
            
            // cout<<"---------------------------------------------"<<endl;
            //system("pause");
        }
        return (ans1_v + ans2_v) / 2.0;
    }

};

int main()
{
    int n1,n2;
    vector<int> x1,x2;
    int i,num;
    
    scanf("%d",&n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d",&num);
        x1.push_back(num);
    }

    scanf("%d",&n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d",&num);
        x2.push_back(num);
    }

    Solution test;
    //cout<<"min="<<test.find_min(x1,4)<<endl;
    //cout<<"max="<<test.find_max(x1,4)<<endl;
    cout<<test.findMedianSortedArrays(x1,x2)<<endl;
    system("pause");
}