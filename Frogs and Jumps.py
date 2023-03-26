class Solution:
    def unvisitedLeaves(self, N, leaves, frogs):
        
        leaveStatus = [0 for j in range(leaves+1)]
        for i in range(N):
            if frogs[i]<=leaves and leaveStatus[frogs[i]]==0:
                for j in range(frogs[i], leaves+1, frogs[i]):
                    leaveStatus[j] = 1
        
        leafCount = leaves
        for i in leaveStatus:
            if(i):
                leafCount-=1
            
        
        return leafCount
    
