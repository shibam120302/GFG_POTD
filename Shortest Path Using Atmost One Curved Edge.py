class Solution:
    def dijkstra(self, u, b, n, adj):
        unused = [] 
        dis = [float('inf')]*(n+1)
        
        dis[u] = 0
        
        unused.append((0,u))
        
        heapify(unused)
        
        while unused:
            x, v = heappop(unused)
         
            if x > dis[v]:
                continue
            
            for edge in adj[v]:
                u = edge[0]
                w = edge[1]
                
                if dis[v] + w < dis[u]:
                    dis[u] = dis[v] + w
                    heappush(unused, (dis[u], u))
        
        return dis
        
    def shortestPath(self, n, m, a, b, edges):
        adj = [[] for i in range(n+1)]
        curved = []
        
        for i in range(m):
            u = edges[i][0]
            v = edges[i][1]
            w = edges[i][2]
            cw = edges[i][3]
            
            adj[u].append((v,w))
            adj[v].append((u,w))
            
            # curved edge weight
            curved.append([u, v, cw])
        
        da = self.dijkstra(a,b,n,adj)
        db = self.dijkstra(b,a,n,adj)
        
        ans = da[b]
        
        # ans = min distance from a -> b with at max one curved edge 
        # current ans without curved edge from a -> b = da[b]
    
        for i in range(m):
            u = curved[i][0]
            v = curved[i][1]
            cw = curved[i][2]
    
            ans = min(ans, da[u] + cw + db[v])
            ans = min(ans, da[v] + cw + db[u])
            
        if ans >= 1000000001:
            return -1
        return ans
