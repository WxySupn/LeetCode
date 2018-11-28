#include <stdio.h>
#include <iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        x = n>=0 ? x : 1.0/x;
        n = n>=0 ? n : -n;
        if (n == 0 )
            return 1.0;
        if (n == 1)
            return x;
        double t;
            t = myPow(x, n >> 1);
        cout << "x=" << x << " n=" << n << " t=" << t << endl;
        if (isinf(t))
            t = 0.0;
        if (n & 1){
            return t*t*x;
        }
        else{
            
            return t*t;
        }
    }
};