from typing import List

class Solution:
    def getMinimumDays(self, N : int, S : str, P : List[int]) -> int:
        t = 0
        S = list(S)
        for i in range(N - 1):
            if(S[i]==S[i+1]) : t+=1
       
        if t==0 : 
            return 0

        for i in range(N):

            inn=P[i]

            if inn-1>=0 and S[inn-1]==S[inn]: t-=1

            if inn+1<N and S[inn]==S[inn+1]:t-=1

            S[inn]='?'
            if(t==0):
                return i+1
        
