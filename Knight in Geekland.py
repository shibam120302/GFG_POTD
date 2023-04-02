from collections import deque
class Solution:
    def knightInGeekland(self, arr, start):
        q = deque([(start[0], start[1])])
        n = len(arr)
        m = len(arr[0])
        s = set()
        s.add((start[0], start[1]))
        dist = [[-1,-2], [1,-2], [2,-1], [2,1], [1,2], [-1,2], [-2,1], [-2,-1]]
        points = []
        res = 0
        mmax = -1e9
        cnt = 1

        def isSafe(a,b):
            if a >= 0 and a < m and b >= 0 and b <= n:
                return True
            return False
        
        while q:
            temp = 0
            for _ in range(cnt):
                x,y = q.popleft()
                temp += arr[x][y]
                for a,b in dist:
                    if ((x+a) >= 0 and (x+a) < n and (y+b) >= 0 and (y+b) < m) and (x+a,y+b) not in s:
                        s.add((x+a, y+b))
                        res += 1
                        q.append((x+a, y+b))
            cnt = len(q)
            points.append(temp)
        
        for i in range(len(points)-1, -1, -1):
            if i + points[i] < len(points):
                points[i] += points[i+points[i]]
        
        for i in range(len(points)):
            if mmax >= points[i]:
                continue
            else:
                res = i
                mmax = points[i]
        
        return res
