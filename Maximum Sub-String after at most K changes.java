We have a string s of length n, which contains only UPPERCASE characters and we have a number k (always less than n). We can make at most k changes in our string. In one change, you can replace any s[i] (0<= i < n) with any uppercase character (from 'A' to 'Z'). After k changes, find the maximum possible length of the sub-string which have all same characters.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Change 2 'B' into 'A'. 
Now s = "AAAA"

Example:

Input: s = "ADBD", k = 1
Output: 3
Explanation: Change 'B' into 'D'.
Now s = "ADDD"

Your Task:
You don't need to read or print anything. Your task is to complete the function characterReplacement() which takes s and k as input parameters and returns the maximum length of sub-string after doing k changes.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(26)
 

Constraints:
1 <= n <= 105
0 <= k < n

------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution
{
    public int characterReplacement(String s, int k)
    {
        // code here
        int[]arr=new int[26];
        int prev=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'A']++;
            int curr=find(arr,k);
            if(curr==-1){
                arr[s.charAt(prev++)-'A']--;
            }else{
                ans=Math.max(ans,curr);
            }
        }
        return ans;

    }
    int find(int[]arr,int k){
        int same=0;
        int diff=0;
        for(int i:arr){
            if(i>same){
                diff+=same;
                same=i;
            }else{
                diff+=i;
            }
        }
        return diff<=k? same+diff : -1;
    }
}
