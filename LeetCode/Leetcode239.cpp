#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    #define pb push_back
    #define mp make_pair
    int que[100005];
    int head , tail;
    void push(int x){
        cout<<"push: "<<x<<endl;
        while(tail > head && que[tail-1] < x){
            tail--;
        }
        que[tail++] = x;
    }
    void pop(int x){
        if(tail>head && que[head] == x) head++;
    } 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        head = tail = 0;
        int len = nums.size();
        vector<int> ret ;
        if(len == 0) return ret;
        for(int i=0 ; i<k; i++){
            push(nums[i]);
        }
        ret.pb(que[head]);
        for(int i=k ; i<len ; i++){
            pop(nums[i-k]);
            push(nums[i]);
            ret.pb(que[head]);
        }
        return ret;
    }

};

int main()
{
    freopen("/Users/ganjun/Desktop/a.in" , "r" , stdin);
    Solution sol ;
    int n , k;
    cin>>n>>k;
    vector<int> val;
    int x;
    for(int i=0 ; i<n; i++){
        cin>>x;
        val.pb(x);
    }
    vector<int> ret = sol.maxSlidingWindow(val,k);
    for(int i=0 ; i<ret.size() ; i++) cout<<ret[i]<<endl;
    return 0;
}