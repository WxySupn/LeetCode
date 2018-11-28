#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool compare(char c1, char c2)
    {
        if (c1 == '('  && c2 == ')') return true;
        if (c1 == '['  && c2 == ']') return true;
        if (c1 == '{'  && c2 == '}') return true;
        return false;
    }
    bool isValid(string s) {
        int i,n = s.size();
        vector<char> queue;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
                queue.push_back(s[i]);
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (i == 0)
                    return false;
                if (compare(queue.back(), s[i]))
                {
                    queue.erase(queue.end()-1);
                }
                else
                    return false;
            }
        }
        if (queue.size() != 0)
            return false;
        return true;     
    }
};

int main()
{

}