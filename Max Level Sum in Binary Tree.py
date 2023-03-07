class Solution:
    def maxLevelSum(self, root):
        # Code here
        if root is None:
            return 0
        result = root.data
        q = []
        q.append(root)
        while q!=[]:
            c = len(q)
            res = 0
            while c!=0:
                c-=1
                temp = q[0]
                q.pop(0)
                res=res+temp.data
                if temp.left is not None:
                    q.append(temp.left)
                if temp.right is not None:
                    q.append(temp.right)
            result = max(res, result)
        return result
