#define ll long long
// Link: https://leetcode.com/problems/longest-duplicate-substring
class Solution {
public:
    ll MOD=1e9+9;
    ll BASE = 256;
    // ll BASE2 = 8861;
    vector<ll> powers;
    // vector<ll> 
    
    int value(char ch){
        return ch-'a'+1;
    }
    
    string isFeasible(string s, int size, int n){
        if(size==0 ) return "";
        ll hash=0;
        unordered_map<ll, vector<int>> mpp;
        for(int i=0;i<size;i++){
            hash = (hash+value(s[i])*powers[size-i-1])%MOD;
        }
        // st.insert(hash);
        mpp[hash]={0};
        int p1=0;
        int p2=size;
        while(p2<n){
            hash = (((hash - value(s[p1])*powers[size-1])*BASE)%MOD + value(s[p2])+MOD)%MOD;
            p1++;
            if(mpp.count(hash)){
                for(auto idx:mpp[hash]){
                    if(s.substr(idx, size)==s.substr(p1, size)){
                        return s.substr(idx, size);
                    }
                }
            }
            // st.insert(hash);
            mpp[hash].push_back(p1);
            p2++;
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        int n=s.length();
        powers.resize(n);
        powers[0]=1;
        for(int i=1;i<n;i++){
            powers[i]=(powers[i-1]*BASE)%MOD;
        }
        
        int low=0;
        int high=n;
        string ans="";
        while(low<=high){
            int mid=(low+high)/2;
            string res=isFeasible(s, mid, n);
            if(res==""){
                high=mid-1;
            }else{
                ans=res;
                low=mid+1;
            }
        }
        return ans;
    }
};
