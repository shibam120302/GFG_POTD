class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        char prev = '0';
        vector<int> v = {a, b, c};

        string ans;

        while (1) {
            int ma = 0;
            char cur;

            for (int i = 0; i < 3; i++)
                if (prev != char(i + 'a') && ma < v[i])
                    ma = v[i], cur = i + 'a';

            if (ma == 0)
                break;

            ans += cur;
            v[cur - 'a']--;
            if (ma >= 2 && (prev == '0' || ma > v[prev - 'a'])) {
                ans += cur;
                v[cur - 'a']--;
            }
            prev = cur;
        }
        int n=ans.length();
        if(n!=a+b+c) return -1;
        return n;
    }
};
