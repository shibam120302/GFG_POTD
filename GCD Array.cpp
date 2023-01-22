class Solution{
    
    public:
    int solve (int N, int K, vector<int> A) {
        int total = 0;
        for(int x:A)total+=x;
        vector < int > divisors;
        int m = sqrt(total);
        for(int i = 1;i <= m+1;i++){
            if(total%i == 0){
                divisors.push_back(i);
                if(i!=total/i)divisors.push_back(total/i);
            }
        }
        sort(divisors.begin(),divisors.end());
        reverse(divisors.begin(),divisors.end());
        for(int i = 1;i<N;i++){
            A[i]+=A[i-1];
        }
        int out = 1;
        for(int x:divisors){
            int cnt = 0;
            for(int y:A){
                if(y%x == 0)cnt++;
            }
            if(cnt >= K) {
                out = x;
                break;
            }
        }
        return out;
   
    }

};
