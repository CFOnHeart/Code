#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    
    #define ull unsigned long long 
    const ull base = 299;
    string shortestPalindrome(string s) {
        ull *left = new ull[s.size()+1];
        ull *right = new ull[s.size()+1];
        ull *Mi = new ull[s.size()+1];
        left[0] = right[0] = 0;
        Mi[0]=1;
        for(int i = 1; i<=s.size() ; i++) Mi[i] = Mi[i-1]*base;
        for(int i=0 ; i<s.size() ; i++){
            left[i+1] = left[i]*base+s[i];
            right[i+1] = right[i]*base+s[s.size()-i-1];
        }
        int add = s.size();
        for(int i=s.size() ; i>0 ; i--){
            if(left[i] == right[s.size()]-right[s.size()-i]*Mi[i]){
                add = s.size()-i;
                break;
            }
        }
        string addS = s.substr(s.size()-add);
        for(int i=0 ; i<(addS.size()+1)/2 ; i++){
            char tmp = addS[i];
            addS[i] = addS[addS.size()-i-1];
            addS[addS.size()-i-1]=tmp;
        }
        return addS+s;
    }
};
int main()
{
    Solution sol = Solution();
    cout<<sol.shortestPalindrome(string("bdca"));
}