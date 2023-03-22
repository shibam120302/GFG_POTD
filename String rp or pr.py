class Solution:
    def solve (self, X, Y, S):
        #code here
        answer=0
        a='pr'
        b='rp'
        if X<Y:
            X,Y=Y,X
            a,b=b,a
        st=[]
        for i in range(len(S)-1,-1,-1):
            if len(st)>0 and S[i]==a[0] and st[-1]==a[1]:
                st.pop(len(st)-1)
                answer+=X
            else:
                st.append(S[i])
        S=''
        while len(st)>0:
            S+=st[-1]
            st.pop(len(st)-1)
        for i in range(len(S)-1,-1,-1):
            if len(st)>0 and S[i]==b[0] and st[-1]==b[1]:
                st.pop(len(st)-1)
                answer+=Y
            else:
                st.append(S[i])
        return answer
