#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int mi[10];
    void init(){
        mi[0] = 1;
        for (int i=1 ; i<10 ; i++){
            mi[i] = mi[i-1]*10;
        }
    }
    int len(int x){
        return (int)(log(x+0.5)/log(10))+1;
    }
    #define LL long long 
    int countDigitOne(int n) {
        if(n<=0) return 0;
        init();
        int l = len(n);
        int k = n / mi[l-1];
        LL ret = 0;
        if(l>=2) ret += (l-1)*(k*mi[l-2]);
        if(k>1) ret += mi[l-1];
        else{ret += n-mi[l-1]+1; }
        //cout<<n<<" "<<l<<" "<<k<<" "<<ret<<" "<<n-k*mi[l-1]<<endl;
        return ret + countDigitOne(n-k*mi[l-1]);
    }
};

int main()
{
    freopen("/Users/ganjun/Desktop/a.in" , "r" , stdin);
    Solution sol ;
    int n;
    cin>>n;
    cout<<sol.countDigitOne(n)<<endl;
    return 0;
}