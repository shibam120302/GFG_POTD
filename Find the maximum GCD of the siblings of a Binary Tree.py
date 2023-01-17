from math import gcd
class Solution:
    def maxGCD(self, root):
        # code here
        return self.solve(root)[1]
    
    def solve(self,node):
            if node is None:
                return (0,0)
            x = (0,0)
            if node.left and node.right:
                x = (gcd(node.left.data, node.right.data),node.data)
            y = self.solve(node.left)
            z = self.solve(node.right)
            return max(x,y,z)
