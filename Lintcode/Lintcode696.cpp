#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /*
     * @param : duration and close day of each course
     * @return: the maximal number of courses that can be taken
     */
    #define pii pair<int,int>
    #define X first
    #define Y second
    int scheduleCourse(vector<vector<int> > &courses) {
        // write your code here
        int dp[10005]; //dp[i]表示恰好在第i天前能上的课程数的最大值
        pii val[10005];
        memset(dp , 0 , sizeof(dp));
        for(int i=0 ; i<courses.size() ; i++){
            val[i].X = courses[i][1] , val[i].Y = courses[i][1]-courses[i][0];
        }
        sort(val , val+courses.size());
        for(int i=0 ; i<courses.size() ; i++){
            int t = val[i].X-val[i].Y , d = val[i].X;
            for(int j=10000 ; j>=t ; j--){
                dp[j] = max(dp[j] , dp[j-1]);
                if(j<=d) dp[j] = max(dp[j] , dp[j-t]+1);
            }
        }
        int ret = 0;
        for(int i=0 ; i<=10000 ; i++) ret = max(ret , dp[i]);
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > courses;
    #define pb push_back
    vector<int> a;
    a.pb(100); a.pb(200);
    courses.pb(a);
    vector<int> b;
    b.pb(200); b.pb(1300);
    courses.pb(b);
    vector<int> c;
    c.pb(1000);c.pb(1240);
    courses.pb(c);
    vector<int> d;
    d.pb(2000); d.pb(3200);
    courses.pb(d);
    cout<<sol.scheduleCourse(courses);
}