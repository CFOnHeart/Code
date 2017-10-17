#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector> 
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    #define eps 1e-8
    
    struct Po{
        int x;
        int y;
        double dis;
        Po() : x(0), y(0), dis(0) {}
        Po(int a, int b , double dis) : x(a), y(b), dis(dis){}
        bool operator<(const Po m) const{
            return dis-m.dis<-eps || (fabs(dis-m.dis)<eps && x<m.x) || (fabs(dis-m.dis)<eps && x==m.x && y<m.y);
        }
    };
    double caldis(Point a , Point b){
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        Po * po = new Po[points.size()];
        for(int i=0 ; i<points.size() ; i++){
            po[i] = Po(points[i].x , points[i].y , caldis(origin,points[i]));
        }
        sort(po , po+points.size());
        vector<Point> rets;
        for(int i=0 ; i<k ; i++) rets.push_back(Point(po[i].x,po[i].y));
        return rets;
    }
};
int main()
{
    freopen("a.in" , "r" , stdin);
    vector<Point> points;
    Point origin;
    scanf("[%d,%d]",&origin.x,&origin.y);
    while(true){
        int x , y;
        if(~scanf(",[%d,%d]" , &x,&y)){
            cout<<x<<" "<<y<<endl;
            points.push_back(Point(x,y));
        }
        else break;
    }
    Solution sol;
    vector<Point> ret = sol.kClosest(points , origin , 3);
    int k=3;
    cout<<"KClosest : "<<k<<endl;
    for(int i=0 ; i<ret.size() ; i++){
        cout<<ret[i].x<<" "<<ret[i].y<<endl;
    }    
    return 0;
}