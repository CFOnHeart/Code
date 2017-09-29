/**
 * Created by ganjun on 2017/9/29.
 */
import java.util.Vector;
public class Leetcode135 {
    public int candy(int[] ratings) {
        if(ratings.length==0) return 0;
        int left [] = new int[ratings.length];
        int right [] = new int[ratings.length];
        left[0] = 0;
        for(int i=1 ; i<ratings.length ; i++){
            left[i] = ratings[i]>ratings[i-1]?left[i-1]+1:0;
        }
        right[ratings.length-1] = 0;
        for(int i=ratings.length-2 ; i>=0 ; i--){
            right[i] = ratings[i]>ratings[i+1]?right[i+1]+1:0;
        }
        int ret = 0;
        for(int i=0 ; i<ratings.length ; i++){
            ret += Math.max(left[i] , right[i]);
        }
        return ret+ratings.length;
    }
    public static void main(String [] args){
        Leetcode135 sol  = new Leetcode135();
        int [] rating = {0};
        System.out.println(sol.candy(rating));
    }
}
