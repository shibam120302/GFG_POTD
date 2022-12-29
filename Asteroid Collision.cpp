class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int>& asteroids) {
        stack<int> s;
        for (int i = 0; i < N; i++) {
            if (asteroids[i] > 0 || s.empty()) {
                s.push(asteroids[i]);
            } else {
                while (!s.empty() and s.top() > 0 and
                       s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if (!s.empty() and s.top() == abs(asteroids[i])) {
                    s.pop();
                } else {
                    if (s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> res(s.size());
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
