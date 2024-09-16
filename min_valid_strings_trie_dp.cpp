// Link:https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i

struct Node{
    Node* links[26]={NULL};
    bool end=false;
};

class Trie{
    public:
    
    int cnt;
    Node* root;
    Trie(){
        root=new Node();
        cnt=0;
    }
    void insert(string s){
        Node* temp=root;
        for(auto ch:s){
            if(!temp->links[ch-'a']){
                temp->links[ch-'a']=new Node();
            }
            temp=temp->links[ch-'a'];
        }
        temp->end=true;
    }
    int f(int idx, string &s, int n, vector<int>& dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        Node* temp=root;
        for(int i=idx;i<n;i++){
            if(temp->links[s[i]-'a']){
                temp=temp->links[s[i]-'a'];
                int val = f(i+1, s, n, dp);
                if(val!=INT_MAX){
                    ans=min(ans, 1+val);
                }
                
            }else{
                break;
            }
        }
        return dp[idx]=ans;
        
    }
};

class Solution {
public:

    int minValidStrings(vector<string>& words, string target) {
        Trie* trie=new Trie();
        for(auto i:words){
            trie->insert(i);
        }    
        int n=target.length();
        vector<int> dp(n, -1);
        int res =  trie->f(0, target, n, dp);
        return (res==INT_MAX)?-1:(res);
    }
};
