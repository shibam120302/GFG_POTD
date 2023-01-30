class Solution:
    
    def dfs(self, adj, src, par, val):
        for v in adj[src]:
            if v!=par:
                self.dfs(adj,v,src,val)
        
        for v in adj[src]:
            if v!=par:
                val[src][0] += val[v][1];
                val[src][1] += min(val[v][1],val[v][0])

    def countVertex(self, N, edges):
        adj=[[] for i in range(N+1)]
        for i in range(N-1):
            adj[edges[i][0]].append(edges[i][1])
            adj[edges[i][1]].append(edges[i][0]) 
        
        val=[[] for i in range(N+1)]
        for i in range(1,N+1):
            val[i] = [0,1]
        
        self.dfs(adj,1,1,val)
        
        return min(val[1][0],val[1][1])
