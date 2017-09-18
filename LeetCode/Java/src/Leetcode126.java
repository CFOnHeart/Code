/**
 * Created by ganjun on 2017/9/19.
 */
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Leetcode126 {
    boolean edge[][] ;
    int distance [] ;
    // len(a) = len(b)
    public int diff(String a , String b){
        int dif = 0;
        for(int i=0 ; i<a.length() ; i++)
            if(a.charAt(i)!=b.charAt(i)) dif++;
        return dif;
    }
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        int n = wordList.size();
        int st = n;
        int en = -1;
        edge = new boolean[n+1][n+1];
        for(int i=0 ; i<=n ; i++)
            for(int j=0 ; j<=n ; j++) edge[i][j] = false;

        for(int i=0 ; i<n ; i++){
            String s1 = wordList.get(i);
            if(s1.compareTo(endWord) == 0){
                en = i;
            }
            if(diff(s1 , beginWord) == 1) edge[i][n] = edge[n][i] = true;
            for(int j=i+1 ; j<n ; j++){
                String s2 = wordList.get(j);
                if(diff(s1 , s2) == 1){
                    edge[i][j] = edge[j][i] = true;
                }
            }
        }
        calMinDis(n+1 , n);
        List<List<String>> lists = new ArrayList<List<String>>();
        if(en < 0) return lists;

        wordList.add(beginWord);

        List<String> list = new ArrayList<String>();
        list.add(endWord);
        dfs(lists , list , en , distance[en] , wordList);
        return lists;
    }
    public void calMinDis(int n , int st){
        distance = new int[n];
        for(int i=0 ; i<n ; i++) distance[i] = 0x7fffffff;
        distance[st] = 0;
        Queue<Integer> que = new LinkedList<Integer>();
        que.add(st);
        while(que.isEmpty() == false){
            int u = que.poll();
            for(int i=0 ; i<n ; i++){
                if(edge[u][i] && distance[i] > distance[u]+1){
                    distance[i] = distance[u]+1;
                    que.add(i);
                }
            }
        }
    }
    public void dfs(List<List<String>> lists , List<String> list , int cur , int dis , List<String> wordList){
        if(dis == 0){
            List<String> newList = new ArrayList<String>(list);
            for(int i=0 ; i<newList.size()/2 ; i++){
                String tmp = newList.get(i);
                newList.set(i, newList.get(newList.size()-i-1));
                newList.set(newList.size()-i-1, tmp);
            }
//            for(String val: newList) System.out.println(val);
//            System.out.println("");
            lists.add(newList);
            return;
        }
        for(int i=0 ; i<wordList.size() ; i++){
            if(edge[cur][i] && distance[i]==dis-1){
                list.add(wordList.get(i));
                dfs(lists , list , i , dis-1 , wordList);
                list.remove(wordList.get(i));
            }
        }
    }
    public static void main(String [] args){
        String beginword = "hit";
        String endword = "cog";
        List<String> words = new ArrayList<>();
        words.add("hot");
        words.add("dot");
        words.add("dog");
        words.add("lot");
        words.add("log");
        words.add("cog");
        Leetcode126 sol = new Leetcode126();
        List<List<String>> lists = sol.findLadders(beginword,endword,words);
        for(List<String> list : lists){
            for(String val : list){
                System.out.printf(val+" ");
            }
            System.out.println();
        }
    }
}
