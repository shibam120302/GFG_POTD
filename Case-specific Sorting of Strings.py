class Solution:
    
    #Function to perform case-specific sorting of strings.
    def caseSort(self,s,n):
        
        upper=[]
        lower=[] 
    
        #storing uppercase and lowercase characters in two separate lists.
        for char in s:
            if(self.Case(char)):
                upper.append(char)
            else:
                lower.append(char)
                
        #sorting both the lists.
        upper.sort(reverse=True)
        lower.sort(reverse=True)
    
        sorted_string=""
        
        #iterating over the given string.
        for char in s:
            
            #if current character is in uppercase then we pick character from  
		    #the list containing uppercase characters and add it to result.
            if(self.Case(char)):
                sorted_string+=upper.pop()
                
            #else we pick the character from the sorted list  
		    #containing lowercase characters and add it to result.
            else:
                sorted_string+=lower.pop()
                
        #returning the result.        
        return sorted_string
     
    #Function to return 1 if character is in upper case and 0 for lower case.   
    def Case(self,c):
        
        if(ord(c)<=ord('Z') and ord(c)>=ord('A')):
            return 1
        return 0
