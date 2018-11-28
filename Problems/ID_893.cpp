#include <vector>
#include <string>
using namespace std;



class Ans_class
{
public:
    int l;
    int a[26];
    int b[26];
     Ans_class()
     {
         l = 0;
         for (int i = 0; i < 26; i++)
        {
            a[i] = 0;
            b[i] = 0;
        }
     }
    Ans_class(Ans_class* t)
    {
        l = t->l;
        for (int i = 0; i < 26; i++)
        {
            a[i] = t->a[i];
            b[i] = t->b[i];
        }
    };
private:
};

class Solution {
public:
    Ans_class* Test_string(string s)
    {
        Ans_class* t = new Ans_class();
        t -> l = s.length();
        int i;
        for (i = 0; i< t->l; i++)
        {
            if (i % 2 == 0)
            {
                t->a[s[i]-'a']++;
            }   
            else
            {
                t->b[s[i]-'a']++;
            } 
        }
        return t;    
    }
    bool Compar_class(Ans_class* t1, Ans_class* t2)
    {
        if (t1->l != t2->l) return false;
        int i;
        for (i = 0; i < 26; i++)
        {
            if (t1 -> a[i] != t2 -> a[i])
                return false;
            if (t1 -> b[i] != t2 -> b[i])
                return false;
        }
        return true;

    }
    int numSpecialEquivGroups(vector<string>& A) {
        int n = A.size();
        int i, z;
        int ans = 0;
        vector<Ans_class> ans_class;
        for (i = 0; i < n; i++)
        {
            bool p = true;
            Ans_class *t = Test_string(A[i]);
            for (z = 0; z < ans; z++)
            {
                if (Compar_class(t, &ans_class[z]))
                {
                    p = false;
                    break;
                }
            }
            if (p == true)
            {
                ans_class.push_back(t);
                ans++;
            }
        }
        return ans;
    }
};