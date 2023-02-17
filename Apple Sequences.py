class Solution:
    def appleSequences(self, n, m, arr):
        start=0
        end=0
        curr=0
        maxx=0
        while end<n:
            if arr[end]=="A":
                maxx=max(maxx,end-start+1)
            if arr[end]=="O":
                curr+=1
                if curr>m:
                    while start<end and arr[start]!="O":
                        start+=1
                        
                    start+=1
                maxx=max(maxx,end-start+1)
            end+=1
        return maxx
