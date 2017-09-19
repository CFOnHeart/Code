/**
 * Created by ganjun on 2017/9/19.
 */
public class Leetcode84 {
    class Tuple{
        int X;
        int Y;
        public Tuple(int X , int Y){
            this.X = X;
            this.Y = Y;
        }
    }
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Tuple [] stack = new Tuple[n+1];
        int top = 0;
        int mxsum = 0;
        for(int i=0 ; i<=n ; i++){
            int val = 0;
            if(i < n) val = heights[i];
            int cnt = 0;
            while(top>0 && val<=stack[top-1].X){
                mxsum = Math.max(mxsum , stack[top-1].X*(stack[top-1].Y+cnt));
                cnt += stack[top-1].Y;
                top --;
            }
            stack[top++] = new Tuple(val , cnt+1);
        }
        return mxsum;
    }
    public static void main(String [] args){

        Leetcode84 sol = new Leetcode84();
        int [] heights = {2,1,5,6,2,3};
        System.out.println(sol.largestRectangleArea(heights));
    }
}
