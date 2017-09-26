/**
 * Created by ganjun on 2017/9/26.
 */
public class Leetcode87 {
    public boolean isSame(String s1 , String s2){
        int cnt[] = new int[256];
        for(int i=0 ; i<256 ; i++) cnt[i] = 0;
        for(int i=0 ; i<s1.length() ; i++)
            cnt[s1.charAt(i)]++;
        for(int i=0 ; i<s2.length() ; i++){
            cnt[s2.charAt(i)]--;
            if(cnt[s2.charAt(i)]<0) return false;
        }
      //  System.out.println("true");
        return true;
    }

    public boolean isScramble(String s1, String s2) {
     //   System.out.println(s1+" "+s2);
        if(isSame(s1,s2) == false) return false;
        if(s1.length() == 1) return true;
        for(int i=0 ; i<s1.length()-1 ; i++){
            if(isScramble(s1.substring(0,i+1) , s2.substring(0,i+1)) && isScramble(s1.substring(i+1,s1.length()) , s2.substring(i+1,s2.length())))
                return true;
            if(isScramble(s1.substring(0,i+1) , s2.substring(s2.length()-i-1,s2.length())) && isScramble(s1.substring(i+1,s1.length()) , s2.substring(0,s2.length()-i-1)))
                return true;
        }
        return false;
    }
    public static void main(String [] args){
        Leetcode87 sol = new Leetcode87();
        System.out.println(sol.isScramble("abcd" , "bdac"));
    }
}
