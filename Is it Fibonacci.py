class Solution():
    def solve(self, N, K, GeekNum):
        sumo = 0
        for i in GeekNum:
            sumo += i
        beg = 0
        while len(GeekNum) < N:
            GeekNum.append(sumo)
            sumo -= GeekNum[beg]
            sumo += GeekNum[-1]
            beg += 1
        return GeekNum[N-1]
