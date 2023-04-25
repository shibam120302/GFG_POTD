mod = 10**9+7
mapper= [0]*31
prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

for i in range(2, 31):
    if (0 == i % 4 or 0 == i % 9 or 25 == i):
        continue
    mask = 0
    for j in range(10):
        if (0 == i % prime[j]):
            mask |= 1 << j;
        
        mapper[i] = mask;
        
    

class Solution():
    def goodSubsets(self, n, arr):
        one = 0;
        dp = [0]*1024 
        cnt = [0]*31
        dp[0] = 1
        for i in arr:
            if (i == 1):
                one+=1
            elif (mapper[i] != 0):
                cnt[i]+=1
        for i in range(31):
            if (cnt[i] == 0):
                continue;
            for j in range(1024):
                if (0 != (j & mapper[i])):
                    continue;
                dp[j | mapper[i]] = ((dp[j | mapper[i]] + dp[j] * cnt[i]) % mod)

        res = 0
        for i in dp:
            res = (res + i) % mod;
        res-=1
        
        if (one != 0):
            res = res * pow(2,one, mod) % mod;
        return res
        
