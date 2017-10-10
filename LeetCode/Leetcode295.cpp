#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> small , large;

    MedianFinder() {
        small.clear();
        large.clear();
    }
    
    void addNum(int num) {
        if(small.size()>0 && num <= *(--small.end())) small.insert(num);
        else large.insert(num);
        if(large.size()  >= 2+small.size()){
            small.insert(*(large.begin()));
            large.erase(large.begin());
        }
        if(small.size() > large.size()){
            large.insert(*(--small.end()));
            small.erase(--small.end());
        }
    }
    
    double findMedian() {
        if(large.size() == 0) return 0;
        if(large.size() > small.size()) return *(large.begin());
        else{
            return (*(large.begin())+*(--small.end()))/2.0;
        }
    }
};

int main()
{
    freopen("/Users/ganjun/Desktop/a.in" , "r" , stdin);
    /*
    data
    2
    1 -1
    2
    1 -2
    2
    1 -3
    2
    1 -4
    2
    1 -5
    2
    */
    int op , x;
    MedianFinder sol = MedianFinder();
    while(cin>>op){
        if(op == 1){
            cin >> x;
            sol.addNum(x);
        }
        else{
            cout<<sol.findMedian()<<endl;
        }
    }
    return 0;
}