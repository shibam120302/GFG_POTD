class Solution:
    def countBits(self, N : int) -> int:
        count = 0
        for i in range(31):
            x = 1 << i # calculate the ith bit
            y = (N + 1) // (x * 2) * x # count the number of set bits up to the ith bit
            z = (N + 1) % (x * 2) - x # count the number of set bits in the ith bit
            count += y + max(z, 0) # add the counts to the total
        return count
