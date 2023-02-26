import collections
from collections import deque
from collections import defaultdict

class Solution:
    def dfs(self,v,adj,visited):
        visited[v]=1
        self.vertices+=1
        self.edges+=len(adj[v])
        for to in adj[v]:
            if not visited[to]:
                self.dfs(to,adj,visited)
                
        
    def findNumberOfGoodComponent(self, V, adj):
        ans=0
        visited=[0]*(V+1)
        for i in range(1,V+1):
            if not visited[i]:
                self.vertices=0
                self.edges=0
                self.dfs(i,adj,visited)
                self.edges//=2
                if (self.edges==(self.vertices*(self.vertices-1))//2):
                    ans+=1
        return ans
