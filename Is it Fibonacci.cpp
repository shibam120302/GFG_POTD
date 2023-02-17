class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        long long sum = 0;
        vector<long long> vec;
        

        for (auto it : GeekNum) sum += it, vec.push_back(it);

        int beg = 0;
        while (vec.size() < N) {
            vec.push_back(sum);
            sum -= vec[beg];
            sum += vec.back();
            beg++;
        }

        return vec[N - 1];
    }
};
