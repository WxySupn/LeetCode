#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
//KMP
class Solution {
public:
    int* getNext(string ps)
    {
        int* next = new int[ps.length()];
        next[0] = -1;
        int j = 0;
        int k = -1;
        while (j < ps.length() - 1)
        {
            if (k == -1 || ps[j] == ps[k])
            {
                next[++j] = ++k;
            }else
            {
                k = next[k];
            }
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();

        int *next = getNext(needle);

        int i = 0;
        int j = 0;
        while (i < l1 && j < l2)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        
        if (j == l2)
        {
            return i-j;
        }
        else
        {
            return -1;
        }



    }
};

int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    Solution test;
    cout << test.strStr(s1,s2);
    system("pause");
}