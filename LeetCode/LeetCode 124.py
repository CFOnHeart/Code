class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        a = self.dfs(root)
        return a[1]

    # 每个节点上返回一个当前节点下方某一侧的最大值路径(不包括自己的),和一个当前节点下方子树所能达到的最优解
    def dfs(self, root):

        lfmx = 0 ; rgmx = 0 ; sum1 = -1000000000 ; sum2 = -1000000000;
        if root.left != None:
            lf = self.dfs(root.left)
            lfmx = max(0, lf[0]+root.left.val)
            sum1 = lf[1]
        if root.right != None:
            rg = self.dfs(root.right)
            rgmx = max(0, rg[0]+root.right.val)
            sum2 = rg[1]

       # print root.val, max(lfmx, rgmx), max(max(sum1, sum2), lfmx+rgmx+root.val)
        ret = []
        ret.append(max(lfmx, rgmx))
        ret.append(max(max(sum1, sum2), lfmx+rgmx+root.val))
        return ret

a = TreeNode(-3)
b = TreeNode(2)
c = TreeNode(3)
# a.left = b
# a.right = c
print Solution().maxPathSum(a)