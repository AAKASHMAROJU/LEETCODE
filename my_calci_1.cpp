// Link: https://leetcode.com/problems/my-calendar-i
class Node{
    public:
    Node* left;
    Node* right;
    int start;
    int end;
    Node(int s,int e){
        this->left=NULL;
        this->right=NULL;
        this->start=s;
        this->end=e;
    }

};

pair<Node*,bool> insert(Node* mainRoot, int start, int end){
    Node* root=mainRoot;
    if(root==NULL){
        root=new Node(start, end);
        return {root,true};
    }
    while(1){
        if(root->start>=end){
            if(root->left==NULL){
                root->left=new Node(start, end);
                return {mainRoot,true};
            }
            root=root->left;
        }
        else if(root->end<=start){
            if(root->right==NULL){
                root->right=new Node(start, end);
                return {mainRoot,true};
            }
            root=root->right;
        }else{
            return {mainRoot,false};
        }
    }
}


class MyCalendar {
public:
    Node* root;
    MyCalendar() {
        root=NULL;
    }
    
    bool book(int start, int end) {
        pair<Node*, bool> p;
         p=insert(root, start, end);
        root=p.first;
        return p.second;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
