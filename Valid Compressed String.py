class Solution:
    def checkCompressed(self, s, t):
        n = 0
        flag = 1
        j = 0
        i = 0
        while i<len(t):
            if t[i].isnumeric():
                n *= 10
                if n>100000:
                    return 0
                n += int(t[i])
                j -= 1
            else:
                j += n
                if (t[i]!=s[j]):
                    flag = 0
                    break
                n = 0
            j += 1
            i += 1
        j += n
        if(j != len(s)):
            flag = 0
        if(flag):
            return 1
        else:
            return 0
