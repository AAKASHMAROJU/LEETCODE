// Link: https://leetcode.com/problems/flip-equivalent-binary-trees

#define l left 
#define r right
#define v val
#define Node TreeNode 
class Solution {
public:
    
    bool f(Node* r1, Node* r2){
        if(r1==NULL && r2==NULL) return true;
        if(!(r1 && r2) || r1->v != r2->v ) return false;
        return (f(r1->l, r2->l)&& f(r1->r, r2->r)) || (f(r1->r, r2->l)&& f(r1->l, r2->r));
        
        
        
    }
    
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1, root2);
    }
};
