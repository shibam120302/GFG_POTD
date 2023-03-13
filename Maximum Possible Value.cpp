class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long x,y,mn=1e10,ans=0,tot=0;
        for(int i=0;i<N;i++){
            x=A[i];
            y=B[i];
            if(y%2)
                y--;
            if(y>=2){
                mn=min(mn,x);
            }
            ans+=y*x;
            tot+=y;
        }
        if(tot%4!=0){
           ans-=2*mn;
        }
        return ans;
    }
};
