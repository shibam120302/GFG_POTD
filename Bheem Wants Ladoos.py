class Solution:
    def add_subtree(self, n, dist):
        if n is None or dist<0:
            return 0
        return n.data + self.add_subtree(n.left,dist-1) + self.add_subtree(n.right,dist-1)
    
    def traverse(self, n ,target, k):
        if n is None:
            return (0,-1)
        if n.data==target:
            return (self.add_subtree(n,k), k-1)
            # adding all nodes within range in the sub tree below
            # and returning sum
        
        Sum,dist = self.traverse(n.left, target, k)
        if Sum>0:
            # Sum>0 indicates target was found in left subtree
            if dist==-1:
                return (Sum,dist)
            return ( Sum+n.data + self.add_subtree(n.right,dist-1) , dist-1 )
            # adding values from right sub tree
        
        Sum,dist = self.traverse(n.right, target, k)
        if Sum>0:
            # Sum>0 indicates target was found in right subtree
            if dist==-1:
                return (Sum,dist)
            return ( Sum+n.data + self.add_subtree(n.left,dist-1) , dist-1 )
            # adding values from left sub tree
        
        return (0,-1)
    
    def ladoos(self, root, home, k):
        Sum,dist = self.traverse(root, home, k)
        return Sum
