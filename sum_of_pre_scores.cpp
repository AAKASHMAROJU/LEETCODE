// Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings
struct Node{
    unordered_map<char,pair<Node*,int>> mpp;
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }  
    void insert(string s){
        Node* temp=root;
        for(auto i:s){
            if(!temp->mpp.count(i)){
                Node* t=new Node();
                temp->mpp[i]={t, 0};
            }
            temp->mpp[i].second++;
            temp=temp->mpp[i].first;
        }
    }
    int query(string s){
        string sub="";
        Node* temp=root;
        int ans=0;
        for(auto i:s){
            sub+=i;
            ans+=temp->mpp[i].second;
            temp=temp->mpp[i].first;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t=new Trie();
        for(auto i:words){
            t->insert(i);
        }
        vector<int> res;
        for(auto i:words){
            res.push_back(t->query(i));
        }
        return res;
    }
};
