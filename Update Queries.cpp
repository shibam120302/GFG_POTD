class Solution{
    public:
    vector<int> int_to_bin(int n){
        vector<int> binary;
        for(int i = 31; i >=0; i--){
            int temp = ((n>>i) & 1);
            binary.push_back(temp);
        }
        return binary;
    }
    int bin_to_int(vector<int> &bin){
        int ans = 0;
        for(int i =0; i < 32; i++){
            ans = ans << 1;
            if(bin[i] > 0){
                ans = ans + 1;
            }
        }
        return ans; 
    }
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> hash(N, vector<int>(32, 0));
            for(int i = 0; i< Q; i++){
                int l = U[i][0] - 1;
                int r = U[i][1];
                int x = U[i][2];
                
                vector<int> temp = int_to_bin(x);
                for(int j = 0; j< 32; j++){
                    hash[l][j] += temp[j];
                    if(r != N){
                        hash[r][j] -= temp[j];
                    }
                }
            }
            vector<int> ans;
            vector<int> cur_bin(32, 0);
            for(int i = 0; i< N; i++){
                for(int j = 0; j <32; j++){
                    cur_bin[j]+=hash[i][j];
                }
                ans.push_back(bin_to_int(cur_bin));
            }
            return ans;
        }
};
