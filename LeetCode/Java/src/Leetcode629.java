/**
 * Created by ganjun on 2017/10/2.
 */
public class Leetcode629 {
    private final int MOD = 1000000007;
    public int kInversePairs(int n, int k) {
        int [] f = new int [k+1];
        int [] sum = new int [k+1];
        for(int i=0 ; i<=k ; i++) {f[i] = 0 ; sum[i] = 1;}
        f[0] = 1;
        for (int i=1 ; i<=n ; i++){
            int index = Math.min(i*(i-1)/2 , k);
            sum[0] = 1;
            for(int j=1 ; j<=k ; j++){
                f[j] = ((sum[j] - (j-i>=0?sum[j-i]:0))%MOD+MOD)%MOD;
            }
            for(int j=1 ; j<=k ; j++) {
                sum[j] = (sum[j-1]+f[j])%MOD;
            }
        }
        return f[k];
    }

    public static void main(String [] args){
        Leetcode629 sol = new Leetcode629();
        System.out.println(sol.kInversePairs(3,3));
    }
}
