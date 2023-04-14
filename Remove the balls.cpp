class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int, int>> st;
        for (int i = 0; i < N; i++) {
            int flag = 1;
            pair<int, int> cur = {color[i], radius[i]};
            while (!st.empty() and st.top() == cur) {
                flag = 0;
                st.pop();
            }
            if (flag == 1) st.push(cur);
        }
        return st.size();
    }
};
