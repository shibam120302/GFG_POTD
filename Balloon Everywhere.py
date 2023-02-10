class Solution:
    def maxInstance(self, s : str) -> bool:
        # code here
        diction = {"b":0,"a":0,"l":0,"o":0,"n":0}
        for i in s:
            if i in diction:
                diction[i]+=1
        diction["l"]//=2
        diction["o"]//=2
        return min(diction.values())
        
