/**
 * Created by ganjun on 2017/9/26.
 */
import java.util.*;
public class Leetcode97 {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        Set<Integer> vec = new LinkedHashSet<>();
        vec.add(0);
        for(int i=0 ; i<s3.length() ; i++){
            LinkedHashSet<Integer> newvec = new LinkedHashSet<Integer>();
            for(int val:vec){
                if(i-val>=0 && i-val<s2.length() && s2.charAt(i-val) == s3.charAt(i)){
                    newvec.add(val);
                }
                if(val<s1.length() && s1.charAt(val) == s3.charAt(i)) newvec.add(val+1);
            }

            if(newvec.size() == 0)return false;
            vec = newvec;
        }
        return true;
    }

    public static void main(String [] args){
        Leetcode97 sol = new Leetcode97();
        System.out.println(sol.isInterleave("aabcc","dbbca","aadbbcbcac"));
        System.out.println(sol.isInterleave("aabcc","dbbca","aadbbbaccc"));
    }
}
