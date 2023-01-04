class Solution {
  public:
    int find_nearest_equal_or_greater(int start, int end, int value, int n,
                                      vector<vector<int>> &intervals) {

        // If nothing found, position will be n.
        int position = n;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (intervals[mid][0] >= value) {
                position = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return position;
    }

    int maximum_profit_helper(int index, int n, vector<vector<int>> &intervals,
                              vector<int> &dp) {
        if (index >= n) {
            return 0;
        }

        // `dp[index]` stores the maximum profit one can get by choosing
        // non-overlapping intervals from `index` to `n - 1`.
        if (dp[index] != -1) {
            return dp[index];
        }

        int answer = maximum_profit_helper(index + 1, n, intervals, dp);
        int new_index = find_nearest_equal_or_greater(
            index + 1, n - 1, intervals[index][1], n, intervals);
        answer =
            max(answer, intervals[index][2] +
                            maximum_profit_helper(new_index, n, intervals, dp));

        return dp[index] = answer;
    }

    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, -1);
        return maximum_profit_helper(0, n, intervals, dp);
    }
};
