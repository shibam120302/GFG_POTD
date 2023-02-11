class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        int t=0,i,j;
       for(i=0;i<N-1;i++){
          if(S[i]==S[i+1]) t++;
       }
       if(t==0) return 0;
       else{
          for(i=0;i<N;i++){
             int in=P[i];
             if(in-1>=0 && S[in-1]==S[in]) t--;
             if(in+1<N && S[in]==S[in+1]) t--;
             S[in]='?';
             if(t==0){
                return i+1;
             }
          }
       }
    }
};
