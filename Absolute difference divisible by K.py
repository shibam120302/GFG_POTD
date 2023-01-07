class Solution:
    def countPairs(self, n, arr, k):
        
        # intialize the count
        cnt = 0
      
        # making every element of arr in
        # range 0 to k - 1
        for i in range(n):
            arr[i] = (arr[i] + k) % k
      
        # create an array hash
        hash = [0]*k
      
        # store to count of element of arr
        # in hash
        for i in range(n):
            hash[arr[i]] += 1
      
        # count the pair whose absolute
        # difference is divisible by k
        for i in range(k):
            cnt += (hash[i] * (hash[i] - 1)) // 2
      
        # return the value of count
        return cnt
