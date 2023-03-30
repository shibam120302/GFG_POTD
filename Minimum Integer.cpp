class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        // code here
        int mmin = 1e9;
        long long sum = 0;
        for(int i:A)sum += i;
        for (int i:A)
        {
            if (i*1LL*N >= sum)
            {
                mmin = min(mmin, i);
            }
        }
        return mmin;
    }
};
