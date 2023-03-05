class Solution:
    def avoidExlosion(self, mix, n, danger, m):
        #code here
        
        def find(x):
            if par[x] != x:
                par[x] = find(par[x])
            return par[x]
        
        def union(u,v):
            u = par[u]
            v = par[v]
            if (rank[u] > rank[v]):
                par[v] = u
            elif (rank[u] < rank[v]):
                par[u] = v
            else:
                par[u] = v
                rank[v] += 1
                
            # par[find(a)] = find(b)
        
        ans = []
        par = [0] * (n+1)
        rank = [0] * (n+1)
        
        for i in range(n+1):
            par[i] = i
        
        for i in range(n):
            x = mix[i][0]
            y = mix[i][1]
            px,py = find(x),find(y)
            boolean = True
            
            for j in range(m):
                a,b = danger[j][0],danger[j][1]
                pa,pb = find(a),find(b)
                if (px == pa and py == pb) or (px == pb and py == pa):
                    boolean = False
            
            if (boolean):
                union(x,y)
                
            if (boolean):
                ans.append("Yes")
            else:
                ans.append("No")
        
        return ans
        
