class Solution:
    def search(self,root,target,ans):
        if not root:
            return None
        if root.data==target:
            return root
        self.ans+=root.data
        if target>root.data:
            return self.search(root.right,target,ans)
        else:
            return self.search(root.left,target,ans)
    def dfs(self,node):
        res=node.data
        mn=10**9
        if node.left:
            mn=min(mn,self.dfs(node.left))
        if node.right:
            mn=min(mn,self.dfs(node.right))
        if mn==10**9:
            return res
        else:
            return res+mn
            
    def maxDifferenceBST(self,root, target):
        self.ans=0
        node=self.search(root,target,self.ans)
        if node==None:
            return -1
        self.ans-=self.dfs(node)-node.data
        return self.ans
