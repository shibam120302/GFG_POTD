Given a number N. Find if it can be expressed as sum of two prime numbers.

Example 1:

Input: N = 34
Output: "Yes" 
Explanation: 34 can be expressed as 
sum of two prime numbers.
Example 2:

Input: N = 23
Output: "No"
Explanation: 23 cannnot be expressed as
sum of two prime numbers. 

Your Task:  
You dont need to read input or print anything. Complete the function isSumOfTwo() which takes N as input parameter and returns "Yes" if can be expressed as sum of two prime numbers. else return "No".

Expected Time Complexity: O(N*sqrt(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
  
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  class Solution {
    static String isSumOfTwo(int N){
        // code here
        boolean[]primes=new boolean[N];
        Arrays.fill(primes,true);

        for(int i=2;i*i<=N;i++){
            if(primes[i]){
                for(int j=i*i;j<N;j+=i){
                    primes[j]=false;
                }
            }
        }

        for(int i=2;i<=N/2;i++){
            if(primes[i] && primes[N-i]){
                return "Yes";
            }
        }
        return "No";
    }
}
  
