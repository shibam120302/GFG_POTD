class Solution{
public:
    int solve(int idx,int n,vector<int> &arr,vector<int> &dp){
        if(idx>=n or idx<0) return 1;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=0;
        return dp[idx]=solve(idx+arr[idx],n,arr,dp);
    }
    int goodStones(int n,vector<int> &arr){
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            solve(i,n,arr,dp);
        }
        return accumulate(dp.begin(),dp.end(),0);
    } 
};
