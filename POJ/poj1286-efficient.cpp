#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long
#define pli pair<LL,int>
namespace prime{
    #define N 10000
    int pri[N+5] , tot , phi[N+5];
    bool vis[N+5];
    void init_phi(){
        memset(vis , 0 , sizeof(vis));
        phi[0] = 0 , phi[1] = 1;
        for(int i=2 ; i<=N ; i++){
            if(!vis[i]){
                pri[tot++] = i;
                phi[i] = i-1;
            }
            for(int j=0 ; j<tot ; j++){
                if(pri[j]*i > N) break;
                vis[pri[j]*i] = true;
                if(i%pri[j] == 0){phi[pri[j]*i] = pri[j]*phi[i] ; break;}
                else phi[pri[j]*i] = phi[i]*phi[pri[j]];
            }
        }
    }
}
using namespace prime;
LL mi[30];
void init_mi()
{
    mi[0] = 1;
    for(int i=1 ; i<30 ; i++)
        mi[i] = mi[i-1]*3;
}
int gcd(int x, int y){return y==0?x:gcd(y,x%y);}

pli rotate(int n)
{
    LL ret = 0;
    int tmp = sqrt(n+0.5);
    
    for(int d=1 ; d<=tmp ; d++){
        if(n%d == 0){
            ret += phi[n/d]*mi[d];
            if(n/d!=d) ret += phi[d]*mi[n/d];
        }
    }
    return make_pair(ret,n);
}
pli symmetry(int n)
{
    LL ret = 0;
    if(n&1){
        ret += mi[n/2+1]*n;
        return make_pair(ret, n);
    }
    else{
        ret += mi[n/2]*n/2; //对称轴不在点上
        ret += mi[n/2+1]*n/2; //对称轴在点上
        return make_pair(ret, n);
    }
}
int main()
{
   // freopen("in.txt" , "r" , stdin);
    int n;
    init_phi();
    init_mi();
    while(~scanf("%d" , &n) && n!=-1){
        if(n<=0) {cout<<0<<endl;continue;}
        pli v1 = rotate(n);
        pli v2 = symmetry(n);
        cout<<(v1.first+v2.first)/(v1.second+v2.second)<<endl;
    }
    return 0;
}