class Solution{
public:
    long long int gcd(long long int n, long long int m){
        if(m == 0)
            return n;
        return gcd(m, n%m);
    }

    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long int x = gcd(L, B);
        vector<long long int> ans;
        ans.push_back((L*B)/(x*x));
        ans.push_back(x);
        return ans;
    }
};
