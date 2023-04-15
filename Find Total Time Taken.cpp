class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        unordered_map<int,int> hm;
        vector<long long> cache(n);
        hm[arr[0]]=0;
        cache[0]=0;
        for(int i=1;i<n;i++){
            if(hm.count(arr[i])){
                long long currentTime=cache[i-1]+1;
                long long previousTime=cache[hm[arr[i]]];
                long long waited=currentTime-previousTime;
                if(waited<time[arr[i]-1]){
                    currentTime+=time[arr[i]-1]-waited;
                }
                cache[i]=currentTime;
                hm[arr[i]]=i;
            }else{
                hm[arr[i]]=i;
                cache[i]=cache[i-1]+1;
            }
        }
        return cache[n-1];
    }
};
