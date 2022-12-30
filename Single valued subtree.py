#User function Template for python3

'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''

class Solution:
    def countSingleRec(self,root , count):
        #code here
        if root is None :
            return True
 
        # Recursively count in left and right subtress also
        left = self.countSingleRec(root.left , count)
        right = self.countSingleRec(root.right , count)
     
        # If any of the subtress is not singly, then this
        # cannot be singly
        if left == False or right  == False :
            return False
     
        # If left subtree is singly and non-empty , but data
        # doesn't match
        if root.left and root.data != root.left.data:
            return False
 
        # same for right subtree
        if root.right and root.data != root.right.data:
            return False
 
        # If none of the above conditions is True, then
        # tree rooted under root is single valued,increment
        # count and return true
        count[0] += 1
        return True
    
    def singlevalued(self, root):
        #code here
        count = [0]
 
        # Recursive function to count
        self.countSingleRec(root , count)
 
        return count[0]
        
