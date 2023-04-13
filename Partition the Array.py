class Solution:
    
    def minDifference(self, N, A): 
        #code here
        x = self.partition(A,N)
        A.reverse()
        y=  self.partition(A,N)
        y.reverse()
        ans = 10**18
        for i in range(1,N-2):
            ans=min(ans,max(x[i][0],x[i][1], y[i+1][0],y[i+1][1]) - min(x[i][0],x[i][1], y[i+1][0],y[i+1][1]))
        return ans
            
    def partition(self,A,n):
        tmp = [(0,0)]
        p = A[:]
        for i in range(1,n):
            p[i] += p[i-1]
        for i in range(1,n):
            diff = 10**18
            hi = i
            lo = 1
            ans = (0,0)
            while lo <= hi:
                mid = (lo + hi) // 2
                x = p[mid-1]
                y = p[i] - x
                if abs(x-y) <diff:
                    diff = abs(x-y)
                    ans = (x,y)
                if x > y:
                    hi = mid-1
                else:
                    lo = mid + 1
            tmp.append(ans)
        return tmp
    
