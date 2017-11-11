#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define LL long long

LL fac[5] = {1 , 1 , 2 , 6 , 24};
LL no_match[5]; //no_match[i]表示i个人都不在自己的位置上的方法数
LL combination(int n , int k)
{
    LL ret = 1;
    for(int i=0 ; i<k ; i++) ret = ret*(n-i);
    for(int i=1 ; i<=k ; i++) ret = ret/i;
    return ret;
}
LL getNoCount(int n)
{
    LL ret = 0;
    for(int i=0 ; i<=n ; i++){
        LL flag = i%2==0?1:-1;
        ret += flag*combination(n, i)*fac[n-i];
    }
    return ret;
}

void init()
{
    for(int i=0 ; i<5 ; i++){
        no_match[i] = getNoCount(i);
    }
}

int main()
{
   // freopen("a.in" , "r" , stdin);
    int n , k;
    init();
    while(~scanf("%d%d" , &n , &k)){
        LL ret = 0;
        for(int i=0 ; i<=k ; i++){
            ret = ret + combination(n , i) * no_match[i];
        }
        printf("%lld\n" , ret);
    }
    return 0;
}