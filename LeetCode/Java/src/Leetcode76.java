/**
 * Created by ganjun on 2017/9/26.
 */
import java.util.*;
public class Leetcode76 {
    final int INF = 100000000;
    public String minWindow(String s, String t) {
        Vector<Integer> [] vec = new Vector[256];
        for(int i=0 ; i<256 ; i++)
            vec[i] = new Vector<Integer>();
        int [] cnt1 = new int[256];
        int [] cnt2 = new int[256];
        int point [] = new int [256];
        Vector<Integer> use = new Vector<>();
        for(int i=0 ; i<256 ; i++){
            cnt1[i] = cnt2[i] = 0;
            point[i] = -1;
        }
        for(int i=0 ; i<t.length() ; i++){
            if(cnt2[t.charAt(i)] == 0) use.add((int)(t.charAt(i)));
            cnt2[t.charAt(i)]++;
        }

        int length = INF ;
        int left = 0 ;
        int right = 0;

        for(int i=0 ; i<s.length() ; i++){
            char ch = s.charAt(i);
            if(cnt2[ch] == 0) continue;
            vec[ch].add(i);
            cnt1[ch] ++;
            if(cnt1[ch] >= cnt2[ch]){
                if(cnt1[ch]>cnt2[ch]){
                    vec[ch].remove(0);
                }
                int minn = INF;
                for(int index:use){
                    if(vec[index].size() < cnt2[index]) {minn = -1;break;}
                    else minn = Math.min(vec[index].get(0) , minn);
                }
                if(minn >= 0 && minn <= INF){
                    int ll = i - minn+1;
                    if(ll < length){
                        length = ll ; left = minn ; right = i;
                    }
                   // System.out.println(left+" "+right);
                }
            }
        }
        if(length == INF) return "";
        return s.substring(left , right+1);
    }
    public static void main(String [] args){
        Leetcode76 sol = new Leetcode76();
        System.out.println(sol.minWindow("abc","aabc"));
    }
}
