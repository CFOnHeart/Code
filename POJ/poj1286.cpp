#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
#define pli pair<LL,int>
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
    for(int i=1 ; i<=n ; i++){
        ret += mi[gcd(n,i)];
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
    //freopen("in.txt" , "r" , stdin);
    int n;
    init_mi();
    while(~scanf("%d" , &n) && n!=-1){
        if(n<=0) {cout<<0<<endl;continue;}
        pli v1 = rotate(n);
        pli v2 = symmetry(n);
        cout<<(v1.first+v2.first)/(v1.second+v2.second)<<endl;
    }
    return 0;
}