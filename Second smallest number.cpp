class Solution{   
  public:
    string secondSmallest(int S, int D) {
        
        if(S>=D*9 || S==1 || D==1)
            return "-1";
        
        int dup = D;
        
    	S -= 1;
    	string ans = "";
    	for(int i=D-1; i>0; i--)
    	{
    		if(S>9)
    		{
    			ans += '0'+9;
    			S -= 9;
    		}
    		else 
    		{
    			ans += '0'+S;
    			S = 0;
    		}
    	}
    	ans += '0'+(S+1);
    	reverse(ans.begin(),ans.end());
    	
    	int ind = dup-1;
    	for(int i=dup-1; i>=0; i--)
    	{
    	    if(ans[i]=='9')
    	        ind = i;
    	    else
    	        break;
    	}
    	
    	ans[ind] -= 1;
    	ans[ind-1] += 1;
    	
    	return ans;
    }
};
