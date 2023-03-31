class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            int i = 0;
            while(i < n){
                int j;
                for(j = i + 1; j  <n && a[j]%2 == a[j-1]%2; j++){}
                sort(a.begin() + i, a.begin() + j, greater <int>());
                i = j;
            }
            return a;
        }
};
