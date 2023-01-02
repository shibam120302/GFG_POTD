class Solution:
    
    def solve(self,node,level,answer):
        if node is None:
            return
        if level==len(answer):
            answer.append(node.data)
        else:
            answer[level]=max(answer[level],node.data)
        self.solve(node.left,level+1,answer)
        self.solve(node.right,level+1,answer)
        
    # complete the function to get Largest value at each level of Binary Tree 
    def maximumValue(self,node):
        answer=[]
        self.solve(node,0,answer);
        return answer
