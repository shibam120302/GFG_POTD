'''
class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None
'''

class Solution:
    def verticallyDownBST(self, root, target):
        
        def down(node, direction):
            nonlocal res
            if node:
                if direction == 0:
                    res += node.data
                down(node.left, direction-1)
                down(node.right, direction+1)
            
        
        def find(node, target):
            nonlocal target_node
            if target_node == None:
                if node:
                    if node.data > target:
                        find(node.left, target)
                    elif node.data < target:
                        find(node.right, target)
                    else:
                        target_node = node
                        down(node, 0)
        
        res = -target
        target_node = None
        find(root, target)
        if res == -target:
            return -1
        return res
                
                
                
