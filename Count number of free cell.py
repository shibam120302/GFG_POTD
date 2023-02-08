class Solution():
    def countZero(self, n, k ,arr):
        rowSet = set()
        colSet = set()
        ans = []
        for i in arr:
            rowSet.add(i[0])
            colSet.add(i[1])
            ct1 = (n*len(rowSet))+(n*len(colSet)) - len(rowSet)*len(colSet)
            ans.append(n**2 - ct1)
        return ans
