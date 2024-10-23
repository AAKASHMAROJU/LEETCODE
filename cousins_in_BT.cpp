// link: https://leetcode.com/problems/cousins-in-binary-tree-ii

#define Node TreeNode
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<Node*, int>> q;
        map<int,int> mpp;
        q.push({root, 0});
        while(!q.empty()){
            Node* node=q.front().first;
            int lvl = q.front().second;
            mpp[lvl]+=node->val;
            q.pop();
            if(node->left){
                q.push({node->left, lvl+1});
            }
            if(node->right){
                q.push({node->right, lvl+1});
            }
        }
        queue<pair<Node*, pair<int, int>>> q2;
        q2.push({root,{0, 0}});
        while(!q2.empty()){
            Node* node=q2.front().first;
            int lvl=q2.front().second.first;
            int value=q2.front().second.second;
            node->val= value;
            q2.pop();
            int val=0;
            val+=(node->left)?(node->left->val):0;
            val+=(node->right)?(node->right->val):0;
            val=mpp[lvl+1]-val;
            if(node->left){
                q2.push({node->left,{lvl+1, val}});
            }
            if(node->right){
                q2.push({node->right,{lvl+1, val}});
            }
            
        }
        return root;
    }
};
