#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define N 45

struct Edge{
    int u , v , d;
    Edge(int u=0 , int v=0 , int d=0):u(u),v(v),d(d){}
    bool operator<(const Edge &m)const {
        return d<m.d;
    }
}e[N*N];

int fa[N] , tot;
void init(int n){
    tot = 0;
    for(int i=0 ; i<n ; i++) fa[i] = i;
}

int get_head(int x){return fa[x] == x?x:fa[x]=get_head(fa[x]);}

bool Union(int x , int y)
{
    int fax = get_head(x);
    int fay = get_head(y);
    fa[fax] = fay;
    return fax != fay;
}

void build(int n)
{
    string s ;
    int u = 0;
    int dis ;
   // cout<<"in"<<endl;
    while(cin>>s){
        int pi = 0;
        int i=0;
        while(pi<s.size()){
            
            if(s[pi] == '-'){
                pi += 2;
                //cout<<"here: 0" <<i<<endl;
            }
            else{
                dis = 0;
                while(pi<s.size() && s[pi]!=','){
                    dis = dis*10 + (s[pi] - '0');
                   // cout<<s[pi]<<" "<<dis<<endl;
                    pi ++;
                }
                pi ++;
                e[tot++] = Edge(u , i , dis);
               // cout<<u<<"->"<<i<<" "<<dis<<endl;
            }
            i++;
        }
        u ++;
        // cout<<endl;
    }
}

int main()
{
    freopen("p107_network.txt" , "r" , stdin);

    init(40);
    build(40);
    sort(e , e+tot);
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0 ; i<tot ; i++){
       // cout<<i<<" "<<e[i].d<<endl;
        if(Union(e[i].u , e[i].v)){
            sum2 += e[i].d;
        }
        sum1 += e[i].d;
    }
   // cout<<sum1/2<<" "<<sum2<<endl;
    printf("%d\n" , sum1/2-sum2);
    return 0;
}