class Solution():
    def isValid(self, arr, val, w, m):
        n = len(arr)
        difSum = [0]*n
        pref = 0
        for i in range(n):
            pref -= difSum[i]
            req = max(0, val - arr[i]-pref)
            m-=req
            pref += req
            if i+w< n:
                difSum[i+w] +=  req
        if m < 0:
            return False
        return True

    def maximizeMinHeight(self, n, k, w,a):
        l = 0
        r = 10**9+1
        while l < r-1:
            mid = (l+r)//2
            if self.isValid(a, mid, w, k):
                l = mid
            else:
                r = mid - 1
        while r>=l:
            if self.isValid(a, r, w, k):
                return r
            r -= 1
