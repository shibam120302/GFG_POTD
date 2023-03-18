class Solution {
  public:
    long long solve(int &n,vector<int> &a, int m){
    int mp[2*n+1];
    memset(mp,0,sizeof(mp));
    long long cur=n,tot=0,ans=0;
    mp[cur]++;
    for(int i=0;i<n;i++){
      int x=-1;
      if(a[i]>=m)
        x=1;
      if(x==-1){
        tot-=mp[cur+x];
      }
      else{
        tot+=mp[cur];
      }
      cur+=x;
      ans+=tot;
      mp[cur]++;
    }
    return ans;
  }
 
    long long countSubarray(int N,vector<int> A,int M) {
        return solve(N,A,M)-solve(N,A,M+1);
    }
};
