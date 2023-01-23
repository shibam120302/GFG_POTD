class Solution:
    
    #Function to remove pair of duplicates from given string using Stack.
    def removePair(self,s):
        
        stack = [] 
    
        #pushing the first character of the string into the stack.
        stack.append(s[0]) 
    
        curr_index = 1 
    
        #iterating over the string.
        while curr_index < len(s):
            
            if len(stack) == 0:
                stack.append(s[curr_index])
            
            #if current character of string is equal to the character at top 
            #of stack, we pop it from stack and continue iterating.
            elif s[curr_index] == stack[-1]: 
                stack.pop()
            #else we push the current character into the stack.
            else:
                stack.append(s[curr_index]) 
            curr_index += 1
    
        ans = "" 
        
        #adding all characters in the stack to the answer and returning it.
        for char in stack:
            ans+=char 
            
        if len(ans) ==0 :
            ans="-1"
        
        return ans
