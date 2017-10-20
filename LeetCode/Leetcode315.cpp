#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    #define lowbit(x) x&(-x)
    void update(int n , int p , int *sum){
        for(int x=p ; x<=n ; x+=lowbit(x)) sum[x] += 1;
    }
    int query(int p , int *sum){
        int ret = 0;
        for(int x=p ; x>0 ; x-=lowbit(x)){
            ret += sum[x];
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++) tmp.push_back(nums[i]);
        sort(tmp.begin() , tmp.end());
        int unqLen = unique(tmp.begin() , tmp.end())-tmp.begin();
        
       
        for(int i=0 ; i<n ; i++){
            nums[i] = (lower_bound(tmp.begin() , (tmp.begin()+unqLen) , nums[i])-tmp.begin())+1;
        }
        int * sum = new int[n+1];
        for(int i=0 ; i<=n ; i++) sum[i]=0;
        vector<int> ret;
        for(int i=n-1 ; i>=0 ; i--){
            int cnt = query(nums[i]-1 , sum);
            //cout<<cnt<<endl;
            ret.push_back(cnt);
            update(n , nums[i] , sum);
        }
        for(int i=0 ; i<n/2 ; i++){
            int t = ret[i]; ret[i]=ret[n-1-i]; ret[n-1-i]=t;
        }
        delete [] sum;
        return ret;
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
    vector<int> ret = sol.countSmaller(nums);
    for(int i=0 ; i<ret.size() ; i++) cout<<ret[i]<<endl;
    return 0;
}