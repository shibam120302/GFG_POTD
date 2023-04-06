class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        vector<int> pre(N+1),suf(N+1);
        for(int i=1;i<=N;i++){
            pre[i]=pre[i-1]+A[i-1];
        }
        for(int i=N-1;i>=0;i--){
            suf[i]=suf[i+1]+A[i];
        }
        for(int i=1;i<=N;i++){
            if(pre[i-1]==suf[i]){
                return i;
            }
        }
        return -1;
    }
};
