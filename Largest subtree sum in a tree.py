class Solution:
    def findLargestSubtreeSumUtil(self,root):
        if root==None:
            return 0
        else:
            currsum=root.data+self.findLargestSubtreeSumUtil(root.left)+self.findLargestSubtreeSumUtil(root.right)
            self.ans=max(self.ans,currsum)
            return currsum
        
    def findLargestSubtreeSum(self, root ) -> int:
        self.ans=-float("inf")
        if root==None:
            return 0
        self.findLargestSubtreeSumUtil(root)
        return self.ans
