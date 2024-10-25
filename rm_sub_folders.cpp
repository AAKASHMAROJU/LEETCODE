// Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
class Node{
    public:
    map<string, Node*> mpp;
    bool end=false;
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(vector<string> vs){
        Node* temp=root;
        for(auto i:vs){
            cout<<i<<"===="<<endl;
            if(temp->mpp.count(i)==0){
               
                temp->mpp[i]=new Node();
            }
            temp=temp->mpp[i];
        }
        temp->end=true;

    }
    
    void f(Node* root, string& ds, vector<string>& res){
        // if(!root) return;
        if(root->end){
            if(ds.size()){
            ds.pop_back();
            res.push_back(ds);
            }
            return;
                
        }
        for(auto i:root->mpp){
            ds+=i.first;
            if(i.second){
            f(i.second, ds, res);
            }
            ds.pop_back();
        }
    }
    
    
    vector<string> getResult(){
        string ds="";
        vector<string> res;
  
         f(root, ds, res);
        return res;
    }
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* t = new Trie();
        vector<vector<string>> vs;
        for(auto i:folder){
            vector<string> v;
            string s="";
            for(auto j:i){
                if(j!='/'){
                    s+=j;
                }else{
                    v.push_back(s);
                    s="";
                }
            }
            v.push_back(s);
            v.erase(v.begin());
            vs.push_back(v);
        }
        for(auto i:vs){
            
            t->insert(i);
        }
        return t->getResult();
        
        
    }
};
