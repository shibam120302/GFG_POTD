from collections import Counter

class Solution():
    def solve(self, a, b, c):
        prev = -1
        v = [a, b, c]

        ans = ""

        while (1):
            ma = 0
            cur = 0

            for i in range(3):
                if (prev != i + 97 and ma < v[i]):
                    ma = v[i]
                    cur = i + 97

            if (ma == 0):
                break

            ans += chr(cur)
            v[cur - 97]-=1
            if (ma >= 2 and (prev == -1 or ma > v[prev - 97])):
                ans += chr(cur)
                v[cur - 97]-=1
            prev = cur
            n=len(ans)
            
        if n != a + b + c:
            return -1

        return n
