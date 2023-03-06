class Solution:
    def noConseBits(self, n : int) -> int:
        set=[0]*(35)#to keep the track of which bits we have 
        for j in range(30,-1,-1):
            if n&(1<<j):#if bit set mark it as one 
                set[j]=1
        fin_ans=0#final_answer
        for j in range(30,1,-1):
            if set[j]==1:#
                fin_ans|=1<<j
                if set[j-1]==1:# if a jth bit and (j-1)th bit set than make (j-2)th
                #bit should be zero if it was one 
                    set[j-2]=0
        if set[1]==1:#checking if 1th bit is set than include in answer 2(2^1)
            fin_ans|=2
        if set[0]==1:
            fin_ans|=1#checking if 0th bit is set than include in answer 1(2^0)
        return fin_ans
