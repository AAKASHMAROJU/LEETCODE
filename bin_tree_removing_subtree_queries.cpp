// Link: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define Node TreeNode 
class Solution {
public:    
    
    int getHeights(Node* root, map<int,int>& heights){
        if(!root) return -1;
        return heights[root->val]=1+max(getHeights(root->left, heights), getHeights(root->right, heights));
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
       queue<pair<Node*,int>> q;
        q.push({root, 0});
        map<int, priority_queue<pair<int,int>>> mpp;
        map<int,int> mpp2;
        map<int,int> heights;
        vector<int> res;
        getHeights(root, heights);
        while(!q.empty()){
            Node*  node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            mpp[lvl].push({heights[node->val], node->val});
            mpp2[node->val]=lvl;
            if(node->left){
                q.push({node->left, lvl+1});
            }
            if(node->right){
                q.push({node->right, lvl+1});
            }
        }
        
        for(auto i:queries){
            int lvl=mpp2[i];
            int max_h = mpp[lvl].top().first;
            int node=mpp[lvl].top().second;
            if(node==i){
                mpp[lvl].pop();
                if(mpp[lvl].empty()){
                    res.push_back(lvl-1);
                }else{
                    int sec_max_h=mpp[lvl].top().first;
                    res.push_back(sec_max_h+lvl);
                    
                }
                mpp[lvl].push({max_h, node});
            }else{
                res.push_back(lvl+max_h);
            }
        }
        return res;
        
    }
};
