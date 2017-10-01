/**
 * Created by ganjun on 2017/10/2.
 */
import java.util.*;
public class Leetcode386 {
    List<Integer> list;
    public void dfs(int u , int n){
        if(u <=n) list.add(u);
        else return;
        for(int i=0 ; i<10 ; i++){
            dfs(u*10+i , n);
        }
    }

    public List<Integer> lexicalOrder(int n) {
        list = new ArrayList<>();
        for(int i=1 ; i<10 ; i++) dfs(i, n);
        return list;
    }
    public static void main(String [] args){

    }
}
