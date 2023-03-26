class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        
        vector<int> leaveStatus (leaves + 1, 0);
		for (int i = 0; i < N; i++) {
			if (frogs[i] <= leaves && leaveStatus[frogs[i]] == 0) {
				for (int j = frogs[i]; j <= leaves; j += frogs[i]) {
					leaveStatus[j] = 1;
				}
			}
		}
		int leafCount = leaves;
		for (int i : leaveStatus) {
			if (i) {
				leafCount--;
			}
		}
		return leafCount;
    }
};
