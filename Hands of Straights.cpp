class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {

        map<int, int> mp;
        for (int i : hand) mp[i]++;
        for (auto it : mp) {
            if (mp[it.first] > 0) {
                for (int i = groupSize - 1; i >= 0; --i) {
                    if ((mp[it.first + i] -= mp[it.first]) < 0) return false;
                }
            }
        }
        return true;
    }
};
