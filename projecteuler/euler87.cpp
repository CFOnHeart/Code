#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define LL long long 

namespace euler87{
    #define MAXN 50000000
    bool vis[MAXN+5];
    int pri[MAXN/10] , tot;
    map<int,int> mp;

    void init(){
        memset(vis , 0 , sizeof(vis)); tot =0 ;
        for(int i=2 ; i<=MAXN ; i++){
            if(!vis[i]) pri[tot++] = i;
            for(int j=0 ; j<tot ; j++){
                if((LL)pri[j]*i > MAXN) break;
                vis[pri[j]*i] = true;
                if(i % pri[j] == 0) break;
            }
        }
    }

    LL solve(LL n){
        init();
        LL ret = 0;
        for(int i=0 ; i<tot ; i++){
            LL cur1 = (LL)pri[i]*pri[i];
            if(cur1 > n) break;
            for(int j=0 ; j<tot ; j++){
                LL cur2 = cur1+(LL)pri[j]*pri[j]*pri[j];
                if(cur2 > n) break;
                for(int k=0 ; k<tot ; k++){
                    LL cur3 = cur2+(LL)pri[k]*pri[k]*pri[k]*pri[k];
                    if(cur3 > n) break;
                
                    if(mp[cur3]==0) ret ++;
                    else mp[cur3]++;
                    //cout<<pri[i]<<" "<<pri[j]<<" "<<pri[k]<<" "<<cur3<<endl;
                }
            }
        }
        return ret;
    }
}

int main()
{
    using namespace euler87;
    cout<<solve(MAXN-1)<<endl;
}