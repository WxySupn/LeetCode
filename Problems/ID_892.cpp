#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0 || m == 0)  return 0;
        int i, z;
        int u,d,l,r,now;
        int ans = 0;

        for (i = 0; i < n; i++)
        {
            for (z = 0; z < m; z++)
            {
                now = grid[i][z];
                if (now == 0)
                    continue;
                u = (i == 0) ? 0 : grid[i-1][z];
                d = (i == n-1) ? 0 : grid[i+1][z];
                l = (z == 0) ? 0 : grid[i][z-1];
                r = (z == m-1) ? 0 : grid[i][z+1];
                ans = ans + 2;
                ans += (now > u) ? now-u : 0;
                ans += (now > d) ? now-d : 0;
                ans += (now > l) ? now-l : 0;
                ans += (now > r) ? now-r : 0;
            }
        }
        return ans;      
    }
};

int main()
{

}