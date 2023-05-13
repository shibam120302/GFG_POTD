class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        int cn=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]!=arr[n-1-i]) cn++;
        }
        return (cn+1)/2;
    }
};
