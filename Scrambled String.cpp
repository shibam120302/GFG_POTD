class Solution{
    public:
    unordered_map<string,int> mp;
    bool isScramble(string s1, string s2){
        // Equal strings are scramble strings
        if(s1 == s2){
            return true;
        }
        // Strings of non-equal length
        // cant' be scramble strings
        if(s1.size() != s2.size()){
            return false;
        }
        if(mp.find(s1+" "+s2)!=mp.end()){
            return mp[s1+" "+s2];
        }
        int n = s1.size();
        for(int i=1;i<s1.size();i++){
            // Check if S2[0...i] is a scrambled
        // string of S1[0...i] and if S2[i+1...n]
        // is a scrambled string of S1[i+1...n]
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) and 
            isScramble(s1.substr(i,n-i),s2.substr(i,n-i))){
                return mp[s1+" "+s2] = true;
            }
            // Check if S2[0...i] is a scrambled
        // string of S1[n-i...n] and S2[i+1...n]
        // is a scramble string of S1[0...n-i-1]
            else if(isScramble(s1.substr(0,i), s2.substr(n-i,i)) and 
            isScramble(s1.substr(i,n-i),s2.substr(0,n-i))){
                return mp[s1+" "+s2] = true;
            }
        }
        // If none of the above
     // conditions are satisfied
        return mp[s1+" "+s2] = false;
    }
};
