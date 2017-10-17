#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set> 
#include <queue>
using namespace std;

class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int dir[2][2] = {{0,1},{1,0}};
        int n = dungeon.size();
        int m = dungeon[0].size();
        int **b = new int*[n]; 
        for(int i=0 ; i<n ; i++)
            b[i] = new int [m];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                b[i][j] = 0x7fffffff;
        b[n-1][m-1] = 1;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(i-1>=0){
                    b[i-1][j] = min(b[i-1][j] , b[i][j]-dungeon[i][j]<=0?1:b[i][j]-dungeon[i][j]);
                }
                if(j-1>=0){
                    b[i][j-1] = min(b[i][j-1] , b[i][j]-dungeon[i][j]<=0?1:b[i][j]-dungeon[i][j]);
                }
            }
        }
        return b[0][0]-dungeon[0][0]<=0?1:b[0][0]-dungeon[0][0];
    }
};

int main()
{
    freopen("a.in" , "r" , stdin);
    int n , m;
    scanf("%d%d" , &n,&m);
    vector<vector<int> > dungeon;
    for(int i=0 ; i<n ; i++){
        vector<int> a ;
        int x;
        for(int i=0 ; i<m ; i++){
            scanf("%d" , &x);
            a.push_back(x);
        }
        dungeon.push_back(a);
    }
    Solution sol;
    printf("%d\n" , sol.calculateMinimumHP(dungeon));
    return 0;
}