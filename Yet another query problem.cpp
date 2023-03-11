class Solution {
public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        vector<int> ans;
        vector<vector<int>> pre(N+1,vector<int>(N+1,0));
        for(int i=0;i<N;i++){
            int cnt=0;
            for(int j=i;j<N;j++){
                if(A[i]==A[j]){
                    cnt++;
                }
            }
            pre[i][cnt]++;
        }
        for(int i=0;i<N+1;i++){
            for(int j=1;j<N;j++){
                pre[j][i]+=pre[j-1][i];
            }
        }
        for(int i=0;i<num;i++){
            int L=Q[i][0];
            int R=Q[i][1];
            int K=Q[i][2];
            ans.push_back((L==0?pre[R][K]:pre[R][K]-pre[L-1][K]));
        }
        return ans;
    }
};
