#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
public:
    struct Side{
        int x , y , op;
        Side(int x=0 , int y=0 , int op=0):x(x),y(y),op(op){}
        bool operator<(const Side a) const {
            return x<a.x || (x==a.x && op*y < a.op*a.y);//横坐标相同，希望添加的顺序一定是左侧的边越大优先入set，右侧的 边越小优先出set才不会影响最大值
        }
        bool operator==(const Side a) const {
            return x==a.x && y==a.y && op==a.op;
        }
    }sides[100005];
    
    multiset<int> st;
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        
        int n = buildings.size();
        for(int i=0 ; i<n ; i++){
            sides[i*2] = Side(buildings[i][0] , buildings[i][2] , -1);
            sides[i*2+1] = Side(buildings[i][1] , buildings[i][2] , 1);
        }
        sort(sides , sides+(n*2));

        vector<pair<int,int> > ret;
        st.clear();
        int val;
        int last = -1;
        for(int i=0 ; i<n*2 ; i++){
           // cout<<"test: "<<sides[i].x<<" "<<sides[i].y<<" "<<sides[i].op<<endl;
            if(sides[i].op == 1){
                st.erase(st.lower_bound(sides[i].y));
                if(st.size()>0) val = *(--st.end());
                else val = 0;
            }
            else{
                st.insert(sides[i].y);
                val = *(--st.end());
                
            }
         //   cout<<"cur val : "<<val<<endl;
            if(val != last){
                ret.push_back(make_pair(sides[i].x , val));
                last = val;
            }
        }
        return ret;
    }
};
int main()
{
    vector<vector<int> > buildings;
    
    //[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]
    // vector<int> a ;
    // a.push_back(2);a.push_back(9);a.push_back(10);
    // buildings.push_back(a);
    // vector<int> b;
    // b.push_back(3);b.push_back(7);b.push_back(15);
    // buildings.push_back(b);
    // vector<int> c;
    // c.push_back(5);c.push_back(12);c.push_back(12);
    // buildings.push_back(c);
    // vector<int> d;
    // d.push_back(15);d.push_back(20);d.push_back(10);
    // buildings.push_back(d);
    // vector<int> e;
    // e.push_back(19); e.push_back(24); e.push_back(8);
    // buildings.push_back(e);

    vector<int> a ;
    a.push_back(1);a.push_back(2);a.push_back(1);
    buildings.push_back(a);
    vector<int> b;
    b.push_back(1);b.push_back(2);b.push_back(2);
    buildings.push_back(b);
    vector<int> c;
    c.push_back(1);c.push_back(2);c.push_back(3);
    buildings.push_back(c);
    Solution sol;
    vector<pair<int,int> > ret;
    ret = sol.getSkyline(buildings);
    for(int i=0 ; i<ret.size() ; i++){
        cout<<ret[i].first<<" "<<ret[i].second<<endl;
    }
    return 0;
}