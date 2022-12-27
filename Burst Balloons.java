class Solution {
  public static int maxCoins(int N, int[] b) {
    // code here
        int n=b.length;
        int a[]=new int[n+2];
        n=a.length;
        a[0]=a[n-1]=1;
        for(int i=1;i<n-1;i++) a[i]=b[i-1];
        dp=new int[n][n];
        for(int e[]:dp) Arrays.fill(e,-1);
        return fun(a,0,n-1);
  }
  static int dp[][];
 static int fun(int a[],int l,int r)
  {
      if(r-l<=1) return 0;
      if(dp[l][r]!=-1) return dp[l][r];
      
      int ans=0;
      for(int m=l+1;m<r;m++)
      {
         int temp=a[l]*a[m]*a[r]+fun(a,l,m)+fun(a,m,r);
         ans=Math.max(ans,temp);
      }
     return dp[l][r]=ans;
  }   
}
     
