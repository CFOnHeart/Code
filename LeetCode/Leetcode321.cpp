#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    void debug(vector<int> &a){
        for(int i=0 ; i<a.size() ; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    //从nums向量中按照顺序选取k个组成最大的数字
    vector<int> getMaxRelativeNumerWithK(vector<int>& nums , int k){
        int n = nums.size();
        int * next = new int[n+1];
        int cur[10] ;
        int first[10] ;
        memset(first, -1 , sizeof(first)); memset(cur , -1 , sizeof(cur));
        for(int i=0 ; i<n ; i++){
            next[i] = -1;
            if(cur[nums[i]] < 0) {
                first[nums[i]] = i;
            }
            else{
                next[cur[nums[i]]] = i;
            }
            cur[nums[i]] = i;
        }
        vector<int> ret;
        int len = 0 , curpos = -1;
        for(int i=0 ; i<=9 ; i++) cur[i] = first[i];
        for(int i=0 ; i<n ; i++){
            if(len >= k) break;
            for(int j=9 ; j>=0 ; j--){
                while(cur[j] >=0 && curpos > cur[j]) cur[j] = next[cur[j]];
                if(cur[j] < 0) continue;
                if(n-cur[j] >= k-len){
                    ret.push_back(j); len++; curpos = cur[j]; cur[j] = next[cur[j]]; 
                    break;
                }
            }
        }
        return ret;
    }
    //将两个满足相对排序的向量数字按照相对顺序组合在一起形成新的向量
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size() , m = nums2.size();
        int p1 = 0  , p2 = 0;
        vector<int> ret;
        for(int i=0 ; i<n+m ; i++){
            if(p1 >= n) ret.push_back(nums2[p2++]);
            else if(p2 >= m) ret.push_back(nums1[p1++]);
            else{
                if(nums1[p1] > nums2[p2]) ret.push_back(nums1[p1++]);
                else if(nums1[p1] < nums2[p2]) ret.push_back(nums2[p2++]);
                else{ 
                    //遇到相同的数字，选择哪一个要根据下一个不同的数字最大的那一个位置考虑，中间相等的那一段可视作等价的
                    int st1 = p1+1 , st2 = p2+1;
                    while(true){
                        if(st1 >= n) {ret.push_back(nums2[p2++]); break;}
                        if(st2 >= m) {ret.push_back(nums1[p1++]); break;}
                        if(nums1[st1] == nums2[st2]) {st1++;st2++;}
                        else {
                            if(nums1[st1] > nums2[st2]) ret.push_back(nums1[p1++]);
                            else ret.push_back(nums2[p2++]);
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
    //选取两个向量数字中更大的那一个
    vector<int> MaxVector(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size() , m = nums2.size();
        if(n>m) return nums1;
        else if(n<m) return nums2;
        for(int i=0 ; i<n ; i++){
            if(nums1[i] == nums2[i]) continue;
            return nums1[i]>nums2[i]?nums1:nums2;
        }
        return nums1;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        int n = nums1.size() , m = nums2.size();
        //将k个数字分到两个向量中，根据得到的最大结果合并来判断
        for(int i=0 ; i<=k ; i++){
            if(n>=i && m>=k-i){
                vector<int> t1 = getMaxRelativeNumerWithK(nums1 , i);
                vector<int> t2 = getMaxRelativeNumerWithK(nums2 , k-i);
                vector<int> t3 = merge(t1 , t2);
                // cout<<"k: "<<i<<endl;
                // debug(t1); debug(t2); debug(t3);
                ret = MaxVector(ret , t3);
            }
        }
        return ret;
    }
};
int main()
{
    freopen("a.in" , "r" , stdin);
    int n , m , k;
    while(cin>>n>>m>>k){
        vector<int> nums1;
        for(int i=0 ; i<n; i++){
            int num1;
            cin>>num1;
            nums1.push_back(num1);
        }
        vector<int> nums2;
        for(int i=0 ; i<m; i++){
            int num2;
            cin>>num2;
            nums2.push_back(num2);
        }
        Solution sol;
        vector<int> ret = sol.maxNumber(nums1 , nums2 , k);
        sol.debug(ret);
    }
    return 0;
}