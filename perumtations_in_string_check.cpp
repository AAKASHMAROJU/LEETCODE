// Link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    
    bool isPossible(vector<int>& v1, vector<int>& v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
    
    
    bool checkInclusion(string s1, string s2) {
        // any of the possible substring of s1 shoukd be available in s2 
        // nlogn or max to max n^2 approach works but can be done in O(n) time 
        // contigueous string of all chars in s2 
        vector<int> v(26, 0);
        for(auto i:s1){
            v[i-'a']++;
        }
        int m=s1.length();
        int n=s2.length();
        if(n<m) return false;
        // find a substring of length m consists of all chars of s1 in s2
        vector<int> curr(26, 0);
        for(int i=0;i<m;i++){
            curr[s2[i]-'a']++;
        }
        if(isPossible(curr, v)) return true;
        for(int i=m;i<n;i++){
            curr[s2[i-m]-'a']--;
            curr[s2[i]-'a']++;
            if(isPossible(curr, v)) return true;
        }
        return false;
    }
};
