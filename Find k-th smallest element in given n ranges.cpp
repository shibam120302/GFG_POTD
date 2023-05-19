class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        
        vector<int>v = intervals[0];
        vector<vector<int>>ans;
        for(int i = 1; i < intervals.size(); i++){ 
            if(v[1]>=intervals[i][0]){
                v[1] = max(v[1], intervals[i][1]);
            }
            else{
                ans.push_back(v);
                v = intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
    int find_kth(vector<vector<int>>&merged, int k){
        int n = merged.size();
        for (int j = 0; j < n; j++)
        {
            if (k <= abs(merged[j][1] -
                         merged[j][0] + 1))
                return (merged[j][0] + k - 1);
 
            k = k - abs(merged[j][1] - merged[j][0] + 1);
        }
 
        if (k)
            return -1;
    }
   vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<vector<int>>merged = merge(range);
        vector<int>ans;
        for(int i = 0 ; i < queries.size(); i++){
            int res = find_kth(merged, queries[i]);
            ans.push_back(res);
        }
        return ans;
    }
};
