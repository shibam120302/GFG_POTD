class Solution {
  public:
    long long int minOperations(int N) {
        long long int ans = N / 2;
        ans *= (N + 1) / 2;
        return ans;
    }
};
