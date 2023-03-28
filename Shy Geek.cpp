#define ll long long
class Solution {
  public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    ll help(int q,map<int,ll> &m, Shop &sp)
    {
        if(m.find(q)!=m.end())return m[q];
        return m[q] = sp.get(q-1);
    }
    long long find(int n, long long k) {
        //code here
        map<int,ll> m;
        long long ans = 0;
        ans += k/help(n,m,this->shop);
        k %= help(n,m,this->shop);
        int l = 0,r = n;
        while(1)
        {
            l = 0;
            while(l+1<r)
            {
                int mid = (l+r)/2;
                if(help(mid,m,this->shop)<=k)l = mid;
                else r = mid;
            }
            if(l==0)break;
            ans += k/help(l,m,this->shop);
            k %= help(l,m,this->shop);
        }
        return ans;
    }
};
