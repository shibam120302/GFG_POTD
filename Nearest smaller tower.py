class Solution:
    def nearestSmallestTower(self,arr):
        #code here
        suff=[]
        n=len(arr)
        findsuff=[0]*n #building suffix
        for i in range(n-1,-1,-1):
            if len(suff)==0:
                findsuff[i]=-1
                suff.append([arr[i],i])
            else:
                while suff:
                    if suff[-1][0]<arr[i]:
                        findsuff[i]=suff[-1][1]
                        break
                    suff.pop()
                if len(suff)==0:
                    findsuff[i]=-1
                suff.append([arr[i],i])
        pre=[]
        findpre=[0]*n #building prefix
        for i in range(n):
            if len(pre)==0:
                findpre[i]=-1
                pre.append([arr[i],i])
            else:
                while pre:
                    if pre[-1][0]<arr[i]:
                        findpre[i]=pre[-1][1]
                        break
                    pre.pop()
                if len(pre)==0:
                    findpre[i]=-1
                pre.append([arr[i],i])
        new=[0]*n #comparing both
        for i in range(n):
            if findsuff[i]==-1:
                new[i]=findpre[i]
                continue
            if findpre[i]==-1:
                new[i]=findsuff[i]
                continue
            if abs(findsuff[i]-i)==abs(findpre[i]-i):
                if arr[findsuff[i]]>=arr[findpre[i]]:
                    new[i]=findpre[i]
                else:
                    new[i]=findsuff[i]
            elif abs(findsuff[i]-i)>abs(findpre[i]-i):
                new[i]=findpre[i]
            else:
                new[i]=findsuff[i]
        return new  
