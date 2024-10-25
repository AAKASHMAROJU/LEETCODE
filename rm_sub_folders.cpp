// Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
struct Node{
    map<string, Node*> mpp;
    bool end=false;
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        s+="/";
        Node* temp=root;
        int m=s.length();
        string s1="";
        for(int i=1;i<m;i++){
            if(s[i]!='/'){
                s1+=s[i];
            }
            else{
                if(temp->mpp.count(s1)==0){
                    temp->mpp[s1]=new Node();
                }
                temp=temp->mpp[s1];
                s1="";
            }
        }
        temp->end=true;
    }
    
    string query(string s){
        s+="/";
        Node* temp=root;
        int m=s.length();
        string s1="";
        string res="";
        for(int i=1;i<m;i++){
            if(s[i]!='/'){
                s1+=s[i];
            }
            else{
                if(temp->end==false){
                    res+="/";
                    res+=s1;
                    temp=temp->mpp[s1];
                }
                else{
                    break;
                }
                 s1="";
            }
        }
        return res;
    }        
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        Trie* t=new Trie();
        for(int i=0;i<n;i++){
            t->insert(folder[i]);
        }
        set<string> res;
        for(auto i:folder){
            res.insert(t->query(i));
        }
        return vector<string>(res.begin(), res.end());
    }
};
