from typing import Optional

class Solution:
    def isPrime(self,n):
        nn = int(n**0.5) + 1
        for i in range(2 , nn):
            if n%i == 0:return False
        return True
            
            
    def primeList(self, head : Optional['Node']) -> Optional['Node']:
        temp = head
        while temp:
            
            if temp.data == 1:
                temp.data = 2
            else:
                num = temp.data
                num1 = temp.data
                num2 = temp.data
                while not self.isPrime(num1): num1-=1
                while not self.isPrime(num2): num2+=1
                
                if num - num1 <= num2 - num:
                    temp.data = num1
                else:
                    temp.data = num2
            temp = temp.next
        return head
        
