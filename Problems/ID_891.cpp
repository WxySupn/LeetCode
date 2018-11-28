#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        int **min = new int*[n];
        int **max = new int*[n];
        int i,z;
        int ans = 0;
        for (i = 0; i < n; i++)
        {
            min[i] = new int[n];
            max[i] = new int[n];
            min[i][i] = A[i];
            max[i][i] = A[i];
        }
        for (i = 0; i < n; i ++)
            for (z = i+1; z < n; z++)
            {
                if (min[i][z-1] > A[z])
                    min[i][z] = A[z];
                if (max[i][z-1] < A[z])
                    max[i][z] = A[z];
                ans += max[i][z] - min[i][z];
            }
        return ans; 
    }
};

int main()
{

}