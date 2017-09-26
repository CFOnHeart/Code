/**
 * Created by ganjun on 2017/9/26.
 */
public class Leetcode72 {
    //不同，dp[i+1][j+1] = min(update:dp[i][j]+1, del:dp[i+1][j]+1, add:dp[i][j+1]+1)
    //相同，dp[i+1][j+1] = min(dp[i][j], del:dp[i+1][j]+1, add:dp[i][j+1]+1)
    //最长公共子序列
    public int LCS(String s1 , String s2){
        int dp [][] = new int [s1.length()+1][s2.length()+1];
        for(int i=0 ; i<=s1.length() ; i++)
            for(int j=0 ; j<=s2.length() ; j++) dp[i][j] = 0;
        for(int i=0 ; i<s1.length() ; i++){
            for(int j=0 ; j<s2.length() ; j++){
                dp[i+1][j+1]=Math.max(dp[i][j+1] , dp[i+1][j]);
                if(s1.charAt(i) == s2.charAt(j)){
                    dp[i+1][j+1] = Math.max(dp[i][j]+1 , dp[i+1][j+1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    public int minDistance(String word1, String word2) {
        int dp [][] = new int [word1.length()+1][word2.length()+1];
        for(int i=0 ; i<=word1.length() ; i++)
            for(int j=0 ; j<=word2.length() ; j++) dp[i][j] = 0x7fffffff;
        dp[0][0] = 0;
        for(int i=0 ; i<=word1.length() ; i++) dp[i][0] = i;
        for(int i=0 ; i<=word2.length() ; i++) dp[0][i] = i;
        for(int i=0 ; i<word1.length() ; i++) {
            for (int j = 0; j < word2.length(); j++) {
                dp[i + 1][j + 1] = Math.min(dp[i + 1][j] + 1, dp[i][j + 1] + 1);
                if (word1.charAt(i) == word2.charAt(j)) {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j]);
                } else {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j] + 1);
                }
               // System.out.println(i+" "+j+" "+dp[i+1][j+1]);
            }

        }
        return dp[word1.length()][word2.length()];
    }
    public static void main(String [] args){
        Leetcode72 sol = new Leetcode72();
        System.out.println(sol.minDistance("abc" , "adeca"));
    }
}
