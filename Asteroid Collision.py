from collections import deque
class Solution:
    def asteroidCollision(self, n, a):
        st = deque()
        
        for val in a:
            if val > 0:
                st.append(val)
            else:
                while st and st[-1] > 0 and st[-1] < -val:
                    st.pop()
                if st and st[-1] == -val:
                    st.pop()
                elif not st or st[-1] < -val:
                    st.append(val)
            
        return st
