/**
 * Created by ganjun on 2017/9/29.
 */
import java.util.*;

public class Leetcode140 {
    Set<String> st = new HashSet<>();
    Map<String, LinkedList<String>> mp = new HashMap<String, LinkedList<String>>();
    List<String> list = new ArrayList<>();
    public void dfs(String s){
        //System.out.println(s);
        if(mp.containsKey(s)) return;
        if(s.length() == 0){
            return;
        }
        LinkedList<String> ret = new LinkedList<String>();
        for(int i=0 ; i<s.length() ; i++) {
            String str = s.substring(0, i + 1);

            if (st.contains(str)) {
                if(i+1 >= s.length()) {ret.add(s);break;}
                if(!mp.containsKey(s.substring(i + 1))){
                    dfs(s.substring(i + 1));
                }
                for(String val : mp.get(s.substring(i + 1))){
                    ret.add(str+" "+val);
                }
            }
        }
        mp.put(s, ret);
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        st.clear();
        for(String val: wordDict){
            st.add(val);
        }
        list.clear();
        if(s.length() == 0){return list;}
        dfs(s);
        return mp.get(s);
    }
    public static void main(String [] args){
      //  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             //   ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
        Leetcode140 sol = new Leetcode140();
        String words[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        List<String> wordList = new ArrayList<>();
        for(String val:words){
            wordList.add(val);
        }
        List<String> list = sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" , wordList);
        Collections.sort(list);
        for(String val: list){
            System.out.println(val);
        }
    }
}
