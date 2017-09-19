#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
namespace euler114{
    // 这道题目也可以很容易用矩阵快速幂来进行求解
    LL dp[1005][4];
    LL solve(int n){
        dp[0][0] = 1; dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for(int i=1 ; i<=n ; i++){
            dp[i][0] = dp[i-1][0]+dp[i-1][3];
            dp[i][1] = dp[i-1][0];
            dp[i][2] = dp[i-1][1];
            dp[i][3] = dp[i-1][2]+dp[i-1][3];
        }
        return dp[n][0]+dp[n][3];
    }
}
int main()
{
    cout<<euler114::solve(50)<<endl;
    return 0;
}