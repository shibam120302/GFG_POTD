class Solution:
    def countSubarray(self, N, A, M): 
        def greaterMedian(m):
            tot = 0
            ans = 0
            pref = [0]*(2*N+1)
            cur = N
            pref[cur] += 1
            for i in A:
            
                x = -1
                if i >= m:
                    x = 1
                if x == 1:
                    tot += pref[cur]
                else:
                    tot -= pref[cur+x]
                ans += tot
                cur += x
                pref[cur] += 1
            return ans
        return greaterMedian(M) - greaterMedian(M+1)
                    
