class Solution{   
public:
    int addMinChar(string str){    
        string rev=str;
        reverse(rev.begin(),rev.end());
        string s=str+'$'+rev;
        int n=s.length();
		int lps[n];
		lps[0]=0;
		int i=1,len=0;
    	while(i<n)
    	{
        	if(s[i]==s[len])
        	{
            	len++;
            	lps[i] = len;
            	i++;
        	}
        	else
        	{
            	if (len!=0)
                	len=lps[len - 1];
            	else
            	{
                	lps[i]=0;
                	i++;
            	}
    		}
    	}
    	return str.length()-lps[n-1];
    }
};
