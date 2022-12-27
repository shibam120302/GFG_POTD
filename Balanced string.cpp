class Solution {
  public:
    string BalancedString(int N) {
        string ans = "", full = "";
        for (char ch = 'a'; ch <= 'z'; ch++) full += ch;
        int a = N / 26, b = N % 26, i;
        while (a--) // appending a-z to answer as many times as possible
            ans += full;
        // when N is even
        if (N % 2 == 0) {
            for (i = 0; i < b / 2; i++) ans += (char)('a' + i);
            for (i = 26 - b / 2; i < 26; i++) ans += (char)('a' + i);
        }
        // when N is odd
        else {
            int SumOfdigits = 0, temp = N;
            // calculating sum of digits of N
            while (temp) {
                SumOfdigits += temp % 10;
                temp /= 10;
            }
            // when sum of digits is even
            if (SumOfdigits % 2 == 0) {
                for (i = 0; i < (b + 1) / 2; i++) ans += (char)('a' + i);
                for (i = 26 - b / 2; i < 26; i++) ans += (char)('a' + i);
            }
            // when sum of digits is odd
            else {
                for (i = 0; i < b / 2; i++) ans += (char)('a' + i);
                for (i = 26 - (b + 1) / 2; i < 26; i++) ans += (char)('a' + i);
            }
        }
        return ans;
    }
};
