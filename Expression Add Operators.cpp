class Solution {
  public:
    vector<string> ans;
    void f(int i, string s, long sum, long prev, string &num, int target) {
        if (i == num.size()) {
            if (sum == target) {
                ans.push_back(s);
                return;
            }
        }
        for (int j = i; j < num.size(); ++j) {
            if (j > i && num[i] == '0') break;
            long number = stol(num.substr(i, j - i + 1));
            if (i == 0)
                f(j + 1, s + num.substr(i, j - i + 1), number, number, num,
                  target);
            else {
                f(j + 1, s + "+" + num.substr(i, j - i + 1), sum + number,
                  number, num, target);
                f(j + 1, s + "-" + num.substr(i, j - i + 1), sum - number,
                  -number, num, target);
                f(j + 1, s + "*" + num.substr(i, j - i + 1),
                  sum - prev + prev * number, prev * number, num, target);
            }
        }
    }

    vector<string> addOperators(string S, int target) {
        f(0, "", 0, 0, S, target);
        return ans;
    }
};
