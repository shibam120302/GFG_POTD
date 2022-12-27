class Solution{
public:
    vector<int> findRange(string str, int n) {
        int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
        bool allOne = true;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') allOne = false;
        }
    
        vector<int> ans;
        if (allOne) {
            ans.push_back(-1);
            return ans;
        }
        for (int i = 0; i < n; i++) {
            max_ending_here += (str[i] == '1' ? -1 : 1);
    
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
    
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
    
        ans.push_back(start + 1);
        ans.push_back(end + 1);
    
        return ans;
    }
};
