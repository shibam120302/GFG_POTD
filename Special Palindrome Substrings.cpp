class Solution{
    public:
    int specialPalindrome(string s1, string s2){
        int l1=s1.length(),l2=s2.length();
        int ans=INT_MAX;
        for(int i=0 ; i<l1-l2+1 ; i++){
    
            string temp=s1.substr(0,i)+s2+s1.substr(i+l2); // place s2 in all possible positions in s1
            int cost=0;
            // calculate cost to place s2
            for(int j=i ; j<i+l2 ; j++){
    
                if(s1[j]!=temp[j])
                    cost++;
            }
            int z=0;
            // find the cost to convert new string to palindrome
            for(int j=0 ; j<ceil(l1/2.0) ; j++){
    
                if((j<i || j>=i+l2) && temp[j]!=temp[l1-j-1]) // if s2 is in the first half of new string
                    cost++;
                else if(temp[j]!=temp[l1-j-1] && (l1-j-1<i || l1-j-1>=i+l2)) // if s2 is in the second half of new string
                    cost++;
                else if(temp[j]!=temp[l1-j-1]){ // if s2 is in both halves
    
                    z=1;
                    break;
                }
            }
            if(z==0)
                ans=min(ans,cost);
        }
        if(ans == INT_MAX){
          return -1;
        }
        return ans;
    }
};
