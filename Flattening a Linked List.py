
def merge(a,b):
    if a is None:
        return b
        
    if b is None:
        return a
        
    
    result=None
    
    if a.data<b.data:
        result=a
        result.bottom=merge(a.bottom,b)
    else:
        result=b
        result.bottom=merge(a,b.bottom)
    return result
    
    
class Solution():
        
    def flatten(self,root):
        if root is None or root.next is None:
            return root
            
        root.next=self.flatten(root.next)
        root=merge(root,root.next)
        return root
