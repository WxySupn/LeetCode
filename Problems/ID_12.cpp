#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        // M = 1000
        while (num >= 1000)
        {
            s.push_back('M');
            num -= 1000;
        }
        // CM = 900        
        if (num >= 900)
        {
            s.push_back('C');
            s.push_back('M');
            num -= 900;
        }
        // D = 500
        while (num >= 500)
        {
            s.push_back('D');
            num -= 500;
        }        
        // CD = 400
        if (num >= 400)
        {
            s.push_back('C');
            s.push_back('D');
            num -= 400;
        }
        // C = 100
        while (num >= 100)
        {
            s.push_back('C');
            num -= 100;
        }        
        //XC = 90
        if (num >= 90)
        {
            s.push_back('X');
            s.push_back('C');
            num -= 90;
        }
        // L = 50
        while (num >= 50)
        {
            s.push_back('L');
            num -= 50;
        }        
        //XL = 40
        if (num >= 40)
        {
            s.push_back('X');
            s.push_back('L');
            num -= 40;
        }
        // X = 10
        while (num >= 10)
        {
            s.push_back('X');
            num -= 10;
        }        
        //IX = 9
        if (num >= 9)
        {
            s.push_back('I');
            s.push_back('X');
            num -= 9;
        }
        // V = 5
        while (num >= 5)
        {
            s.push_back('V');
            num -= 5;
        }        
        //IX = 4
        if (num >= 4)
        {
            s.push_back('I');
            s.push_back('V');
            num -= 4;
        }
        // I = 1
        while (num >= 1)
        {
            s.push_back('I');
            num -= 1;
        }        
        return s;
    }
};

int main()
{
    int x;
    Solution test;
    while (1 == 1)
    {
        scanf("%d", &x);
        cout<<test.intToRoman(x)<<endl;
    }
}