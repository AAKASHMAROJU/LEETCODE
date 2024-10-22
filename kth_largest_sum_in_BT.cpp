// Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
#define Node TreeNode 
#define ll long long 
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int, ll> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node=q.front().first;
            int lvl=q.front().second;
            mpp[lvl]+=node->val;
            q.pop();
            if(node->left){
                q.push({node->left, lvl+1});
            }
            if(node->right){
                q.push({node->right, lvl+1});
            }
        }
        if(mpp.size()<k) return -1;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        auto itr=mpp.begin();
        for(int i=1;i<=k;i++){
            pq.push(itr->second);
            itr++;
        }
        for(auto i=itr;i!=mpp.end();i++){
            if(pq.top()<i->second){
                pq.pop();
                pq.push(i->second);
            }else{
                continue;
            }
        }
        return pq.top();
    }
};
