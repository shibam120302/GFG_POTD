class Solution {
  public:
    int solve(int a, int b) {
        // code here


        if (a == b)
            return 0;
        else if ((a & b) == min(a, b))
            return 1;
        else
            return 2;
    }
};
