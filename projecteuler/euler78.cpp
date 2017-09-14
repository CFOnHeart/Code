#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long 

namespace euler78{
    LL p[100000+5];
    #define a(x) (3*x-1)*x/2
    #define b(x) (3*x+1)*x/2
    // 初始化计算前n个划分函数，对mod取模
    void init_p(int n, int mod){
        p[0] = p[1] = 1;
        for(int i=2 ; i<=n ; i++){
            p[i] = 0;
            for(int j=0 ; ; j++){
                int k1 = a(j) , k2 = b(j);
                if(k1 > i) break;
                int mul = (j&1)?1:-1;
                if(k1<=i) p[i] = ((p[i]+mul*p[i-k1])%mod+mod)%mod;
                if(k2<=i) p[i] = ((p[i]+mul*p[i-k2])%mod+mod)%mod;
            }
            //cout<<i<<" "<<p[i]<<endl;
        }
    }
    int solve(int mod)
    {
        init_p(100000, mod);
        for(int i=2 ; i<=100000 ; i++)
            if(p[i] == 0) return i;
        return -1;
    }
}
int main()
{
    using namespace euler78;
    cout<<euler78::solve(1000000);
    return 0;
}