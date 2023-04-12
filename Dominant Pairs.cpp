class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(),arr.begin()+(n/2));
        sort(arr.begin()+(n/2),arr.end());
        int ans=0;
        int right=n/2;
        for(int left=0;left<n/2;left++){
            while(right<n && arr[left]>=5*arr[right]){
                right++;
            }
            ans+=right-n/2;
        }
        return ans;
    }  
};
