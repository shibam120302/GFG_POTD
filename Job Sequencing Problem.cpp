class Solution 
{
    public:
    //function used for sorting all jobs according to decreasing profit.
    static bool comparison(Job a, Job b) 
    { 
    	return (a.profit > b.profit); 
    } 
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int res = 0, count = 0;
        
    	//sorting all jobs according to decreasing order of profit.
    	sort(arr, arr+n, comparison); 
    
        //array to store result (Sequence of jobs). 
    	int result[n];
    	//boolean array to keep track of free time slots.
    	bool slot[n]; 
    
    	//initializing all slots to free.
    	for (int i=0; i<n; i++) 
    		slot[i] = false; 
    
    	//iterating through all given jobs.
    	for (int i=0; i<n; i++) 
    	{ 
        	//finding a free slot for current job (Note that we start 
        	//from the last possible slot). 
        	for (int j= arr[i].dead-1; j>=0; j--) 
        	{ 
        		//if free slot is found, we add current job to result array
        		//and make the current slot occupied. 
        		if (slot[j]==false) 
        		{ 
        			result[j] = i;  
        			slot[j] = true; 
        			break; 
        		} 
        	} 
    	} 
    
    	for (int i=0; i<n; i++)
    	{ 
    	    //if slot is occupied, we update the counter and 
    	    //add its profit in final result.
        	if (slot[i]) {
        	    count++;
        	    res += arr[result[i]].profit;
        	}
    	}
    	
    	//storing the count of jobs and max profit in a list and returning it.
    	vector<int> ans;
    	ans.push_back(count);
    	ans.push_back(res);
    	return ans;
    } 
};
