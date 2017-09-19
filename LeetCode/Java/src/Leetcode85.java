/**
 * Created by ganjun on 2017/9/19.
 */
public class Leetcode85 {
    private class Tuple{
        int X;
        int Y;
        private Tuple(int X , int Y){
            this.X = X;
            this.Y = Y;
        }
    }
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        if(n==0) return 0;
        int m = matrix[0].length;
        if(m==0) return 0;
        int colCnt[][] = new int[n][m]; //colCnt[i][j]表示当前位置所在列之前都对应多少个连续的1
        int rowCnt[][] = new int[n][m];
        for(int i=0 ; i<m ; i++){
            int cnt = 0;
            for(int j=0 ; j<n ; j++){
                if(matrix[j][i] == '0') cnt = 0;
                else cnt++;
                colCnt[j][i] = cnt;
            }
        }
        int ret = 0;
        for(int i=0 ; i<n ; i++){
            ret = Math.max(ret , largestRectangleArea(colCnt[i]));
        }
        return ret;
    }
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Tuple[] stack = new Tuple[n+1];
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
            stack[top++] = new Tuple(val,cnt+1);
        }
        return mxsum;
    }
    public static void main(String [] args){
        char [][] matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        Leetcode85 sol = new Leetcode85();
        System.out.println(sol.maximalRectangle(matrix));
    }
}
