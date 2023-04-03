class Solution
{

public:
    int xmod11(string x)
    {
        int len = x.length(); 
  
    int num, rem = 0; 
 
    for (int i = 0; i < len; i++) { 
        num = rem * 10 + (x[i] - '0'); 
        rem = num % 11; 
    } 
  
    return rem; 
    
    }
};
