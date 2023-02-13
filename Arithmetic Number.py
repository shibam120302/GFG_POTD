class Solution():
    def inSequence(self, A, B, C):
        d = (B - A)
        if d == 0:
            return 1
        if d < 0:
            if C >= 0:
                return 0
            if d%C == 0:
                return 1
            return 0
        else:
            if C <= 0:
                return 0
            if d%C == 0:
                return 1
            return 0
        return
