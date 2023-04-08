class Solution {
  public:
    bool check(int a, int b) {
        return ((a < 0 && b >= 0) || (a >= 0 && b < 0));
    }
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> st;
        for (int i = 0; i < arr.size(); ++i) {
            if (!st.empty() && check(st.back(), arr[i]))
                st.pop_back();
            else
                st.push_back(arr[i]);
        }
        return st;
    }
};
