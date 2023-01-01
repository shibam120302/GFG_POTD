class Solution{
	public:
	using ll = long long int;
	ll mod = 1e9 + 7;
	ll modpow(ll a, ll b)
	{
	    ll x = 1%mod;
	    a %= mod;
	    while(b)
	    {
	        if(b&1)
	            x = (x*a)%mod;
	        a = (a*a)%mod;
	        b >>= 1;
	    }
	    return x;
	}
	ll modinverse(ll a)
	{
	    return modpow(a,mod-2);
	}
	int compute_value(int n)
	{
		if(n==1)
		return 2;
		ll val=2;
		for(ll i=1;i<n;i+=1)
		{
			//cout<<val<<" "<<i<<endl;
		   val=(val%mod*((2*i)%mod+1)%mod*2)%mod;
		   ll x=modinverse(i+1);
		   val=(val*x)%mod;
		}
		return (int)val;
	}
};
