class Solution:
    def compute_value(self, n):
        mod=10**9+7
        if n==1:
            return 2
        val=2
        for i in range(1,n):
            val=(val*((2*i)+1)*2)%mod
            x=pow(i+1,mod-2,mod)
            val=(val*x)%mod
        return val
