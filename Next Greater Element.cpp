class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<long long > s;
        vector<long long > res (n);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
                
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
                
            s.push (arr[i]);
        }
        return res;
    }
};
