import java.util.ArrayList;

/**
 * Created by ganjun on 2017/9/30.
 */
import java.util.*;
public class Leetcode145 {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if(root == null) return list;
        if(root.left != null){
            List<Integer> lf = postorderTraversal(root.left);
            for(Integer val: lf){
                list.add(val);
            }
        }
        if(root.right != null){
            List<Integer> rg = postorderTraversal(root.right);
            for(Integer val: rg){
                list.add(val);
            }
        }
        list.add(root.val);
        return list;
    }
    public void main(String [] args){

    }
}
