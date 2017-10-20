#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    int dp[505][505];
    int maxCoins(vector<int>& nums) {
        memset(dp , 0 , sizeof(dp));
        int len = nums.size();
        if(len == 0) return 0;
        for(int d=0 ; d<len ; d++){
            for(int i=0 ; i<len ; i++){
                int j = i+d;
                if(j>=len) break;
                for(int k=i ; k<=j ; k++){
                    int ret = nums[k];
                    if(i-1>=0) ret *= nums[i-1];
                    if(j+1<len) ret *= nums[j+1];
                    if(k-1>=i) ret += dp[i][k-1];
                    if(k+1<=j) ret += dp[k+1][j];
                    dp[i][j] = max(dp[i][j] , ret);
                }   
            }
        }
        return dp[0][len-1];
    }
};
int main()
{
    freopen("a.in" , "r" , stdin);
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0 ; i<n; i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    Solution sol;
    cout<<sol.maxCoins(nums)<<endl;
    return 0;
}