#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
namespace euler114{
    // 这道题目也可以很容易用矩阵快速幂来进行求解
    LL dp[1005][55];
    LL solve(int m , LL limit){
        dp[0][0] = 1;
        for(int i=1 ; i<=m ; i++) dp[0][i] = 0;
        for(int i=1 ; i<1005 ; i++){
            dp[i][0] = dp[i-1][0]+dp[i-1][m];
            for(int j=1 ; j<m ; j++)
                dp[i][j] = dp[i-1][j-1]; 
            dp[i][m] = dp[i-1][m-1]+dp[i-1][m];
            if(dp[i][0]+dp[i][m] > limit) return i;
        }
        return -1;
    }
}
int main()
{
    cout<<euler114::solve(50 , 1000000)<<endl;
    return 0;
}