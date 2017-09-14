#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10000
namespace euler77{
    int pri[MAXN+5] , tot , vis[MAXN+5];
    int ways[1000+5][200]; //ways[i][j]presents how many ways can constitute number i with the smallest prime number pri[j]
    int sum[1000+5][200]; //sum[i][j] = ways[i][j]+ways[i][j+1]+ways[i][j+2]+...+ways[i][maxn]
    void init()
    {
        memset(vis , 0 , sizeof(vis)); tot =0 ;
        for(int i=2 ; i<=MAXN ; i++){
            if(!vis[i]) pri[tot++] = i;
            for(int j=0 ; j<tot ; j++){
                if(pri[j]*i > MAXN) break;
                vis[pri[j]*i] = 1;
                if(i % pri[j] == 0) break;
            }
        }
    }
    int get_ways(int x){
        if(!vis[x]) ways[x][lower_bound(pri,pri+tot,x)-pri] = 1;
        
        for(int i=0 ; i<tot ; i++){
            if(pri[i]>=x) break;
            ways[x][i] = sum[x-pri[i]][i];
        }
        for(int i=lower_bound(pri+0,pri+tot,x)-pri ; i>=0 ; i--){
            sum[x][i] = sum[x][i+1]+ways[x][i];
        }
        return sum[x][0];
    }
}
int main()
{
    using namespace euler77;
    init();
    for(int i=2 ; i<=10000 ; i++){
        int tmp;
        if((tmp=get_ways(i)) >= 5000){
            cout<<i<<" "<<tmp<<endl;
            break;
        }
    }
}