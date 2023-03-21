class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int mn=1e9;
        for(int i=0;i<N;i++){
            int dist=abs(pos[i]-cur);
            mn=min(mn,dist*time[i]);
        }
        return mn;
    }
};
