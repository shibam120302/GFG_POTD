class Solution:
    def try_kunh(self, u, G, used, mt):
        for v in range(len(G[0])):
            if(G[u][v] and used[v] == False):
                used[v] = True
                if(mt[v] < 0 or self.try_kunh(mt[v], G, used, mt)):
                    mt[v] = u
                    return True
        return False
    def maximumMatch(self, G):
        m = len(G)
        n = len(G[0])
        N = max(n,m)
        ans = 0
        mt = [-1 for i in range(N)]
        for i in range(m):
            used = [False for j in range(N)]
            if(self.try_kunh(i, G, used, mt)):
                ans = ans+1
        return ans
