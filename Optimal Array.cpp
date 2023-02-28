class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        int sum1=0,sum2=0;
        vector<int> ans;
        int mid=(n+1)/2;
        for(int i=0;i<mid;i++){
            sum1+=a[i];
            if(i*2<n){
                sum2+=a[i*2];
                int diff=((i+1)*a[i])-sum1+((sum2-sum1)-i*a[i]);
                ans.push_back(diff);
            }
            if(i*2+1<n){
                sum2+=a[i*2+1];
                int diff=((i+1)*a[i])-sum1+((sum2-sum1)-(i+1)*a[i]);
                ans.push_back(diff);
            }
        }
        return ans;
    }
};
