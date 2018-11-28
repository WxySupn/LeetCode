#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int l = 0;
        vector<int> num;        
        while (x > 0)
        {
            l++;
            num.push_back(x %10);
            x = x / 10;
        }
        for (int i = 0; i < (l/2); i++)
        {
            if (num[i] != num[l - i - 1])
                return false;
        }          
        return true;
    }
};

int main()
{
    int x;
    Solution test;
    while (1 == 1)
    {
        scanf("%d", &x);
        cout<< test.isPalindrome(x) <<endl;
    }
    
    
}