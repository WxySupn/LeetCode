#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       if (nums.size() == 1) 
            return ;
        vector<int>::iterator t, w;
        
        t = nums.end() - 2;
        while (*(t) >= *(t+1) && t != nums.begin()) 
            t--;
        cout <<"t=" << *t << endl;
        
        if (t == nums.begin() && *t > *(t+1))
        {
            cout << "true" << endl;
            sort(nums.begin(), nums.end());
            return ;
        }

        w = t+1;
        while (w != (nums.end()-1) && *(w+1) > *t)
            w++;
        //cout <<"w=" << *w << endl;
        
        int tt;
        tt = *t;
        *t = *w;
        *w = tt;

        //sort(nums.begin(), nums.end(), greater<int>());
        //sort(nums.begin(), nums.end(), cmp);
        sort(t+1, nums.end(), less<int>());
        return ;
    }
};



int main()
{
    vector<int> nums{5, 1, 1};
    Solution test;
    test.nextPermutation(nums);
    for (auto t = nums.begin(); t != nums.end(); cout<<*t<<' ',t++);
    system("pause");  
}