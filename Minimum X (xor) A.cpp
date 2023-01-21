class Solution {
  public:
    int minVal(int a, int b) {
        // Count of set-bits in bit
        int setBits = __builtin_popcount(b);
        int setBits1 = __builtin_popcount(a);
        int ans = 0;

        for (int i = 0; i <= 31; i++) {
            int mask = 1 << i;
            int set = a & mask;

            // If i'th bit is set also set the
            // same bit in the required number
            if (set == 0 && setBits > setBits1) {
                ans |= (mask);
                setBits--;
            } else if (set && setBits1 > setBits) {
                setBits1--;
            } else {
                ans |= set;
            }
        }

        return ans;
    }
};
