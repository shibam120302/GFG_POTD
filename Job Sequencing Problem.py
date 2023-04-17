class Solution:
    
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Jobs,n):
        
        res,count = 0,0
        
        #sorting all jobs according to decreasing order of profit.
        Jobs = sorted(Jobs , key = lambda x: x.profit, reverse=True)
        
        #array to store result (Sequence of jobs).
        result = [0 for i in range(n)]
        #boolean array to keep track of free time slots 
        #and initializing all slots to free.
        slot = [False for i in range(n)]
    
        
        #iterating through all given jobs.
        for i in range(n):
            
            #finding a free slot for current job (Note that we start 
        	#from the last possible slot).
            for j in range(Jobs[i].deadline-1,-1,-1):
                
                #if free slot is found, we add current job to result array
        		#and make the current slot occupied.
                if not slot[j]:
                    result[j] = i
                    slot[j] = True 
                    break
                
        #if slot is occupied, we update the counter and 
	    #add its profit in final result.
        for i in range(n):
            if slot[i]:
                res+=Jobs[result[i]].profit
                count+=1
    
        #storing the count of jobs and max profit in a list and returning it.
        ans = []
        ans.append (count)
        ans.append (res)
        return ans
        
