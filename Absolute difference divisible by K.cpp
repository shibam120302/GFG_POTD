class Solution {
    #define ll long long
  public:
    ll countPairs(int n, int arr[], int k) {
        
        // intialize the count
        ll cnt = 0;
      
        // making every element of arr in
        // range 0 to k - 1
        for (ll i = 0; i < n; i++) {
            arr[i] = (arr[i] + k) % k;
        }
      
        // create an array hash[]
        ll hash[k] = { 0 };
      
        // store to count of element of arr
        // in hash[]
        for (ll i = 0; i < n; i++) {
            hash[arr[i]]++;
        }
      
        // count the pair whose absolute
        // difference is divisible by k
        for (ll i = 0; i < k; i++) {
            cnt += (hash[i] * (hash[i] - 1)) / 2;
        }
      
        // return the value of count
        return cnt;
    }
};
