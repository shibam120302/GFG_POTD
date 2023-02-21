class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        int ans=0;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				ans=max(ans,abs(x-i)+abs(y-j));
		return ans;
    }
};
