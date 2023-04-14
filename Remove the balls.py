from typing import List


class Solution:
    def finLength(self, N : int, color : List[int], radius : List[int]) -> int:
        stack=[]#creating a stack
        for i in range(N):
            if not stack:#if no element currently in stack than directly add this element 
                stack.append([color[i],radius[i]])
            else :
                if stack[-1][0]==color[i] and stack[-1][1]==radius[i]:#if color and radius matches last element just pop
                    stack.pop()
                else :
                    stack.append([color[i],radius[i]])#else add this element in stack
        return len(stack)#return the final length of stack
