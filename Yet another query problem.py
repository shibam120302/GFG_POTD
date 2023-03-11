from typing import List

class Solution:
    def solveQueries(self, N : int, num : int, A : List[int], Q : List[List[int]]) -> List[int]:
        ans=[]
        pre=[[0]*(N+1) for _ in range(N+1)]
        for i in range(N):
            cnt=0
            for j in range(i,N):
                if A[i]==A[j]:
                    cnt+=1
            pre[i][cnt]+=1
        for i in range(N):
            for j in range(1,N):
                pre[j][i]+=pre[j-1][i]
        for i in range(num):
            L=Q[i][0]
            R=Q[i][1]
            K=Q[i][2]
            if L==0:
                ans.append(pre[R][K])
            else :
                ans.append(pre[R][K]-pre[L-1][K])
        return ans
