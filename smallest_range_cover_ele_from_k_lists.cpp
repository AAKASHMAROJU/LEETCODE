// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#define ll long long
class Solution {
public:
    ll ga;
    ll gb;
    void f(vector<vector<int>>& v,int n, int idx, int a,int b, vector<int> &dp){
        if(idx==n){
            if(gb-ga>b-a){
                gb=b;
                ga=a;
            }
            else if(gb-ga==b-a){
                if(ga>a){
                    ga=a;
                    gb=b;
                }
            }
            return;
            
        }
        if(dp[idx]!=-1) return;
        if(v[idx].size()==2){
            // considertaking v[idx][0]
            int temp_a=a;
            int temp_b=b;
            a=min(a, v[idx][0]);
            b=max(b, v[idx][0]);
            f(v, n, idx+1, a, b,dp);
            a=min(temp_a, v[idx][1]);
            b=max(temp_b, v[idx][1]);
            f(v, n, idx+1, a, b,dp);
        }
        else{
            a=min(a, v[idx][0]);
            b=max(b, v[idx][0]);
            f(v, n, idx+1, a, b,dp);
        }
        
    }
    
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int> sizes;
        for(auto i:nums){
            sizes.push_back(i.size());
        }
        ll final_a=INT_MAX;
        ll final_b=INT_MIN;
        vector<vector<vector<int>>> choices;
        for(int i=0;i<nums[0].size();i++){
            vector<vector<int>> ch;
            int curr=nums[0][i];
            ch.push_back({nums[0][i]});
            for(int j=1;j<k;j++){
                vector<int> v;
                // nums[j] is a sorted array
                int idx1=lower_bound(nums[j].begin(), nums[j].end(), curr)-nums[j].begin();
                int idx2=upper_bound(nums[j].begin(), nums[j].end(), curr)-nums[j].begin();
                if(idx2>=0 && idx2<sizes[j]){
                    // valid upper bound
                    v.push_back(nums[j][idx2]);
                }
                if(idx1>=0 && idx1<sizes[j]){
                    if(nums[j][idx1]==curr){
                        
                            v.push_back(nums[j][idx1]);
                        
                    }
                    else{
                        if(idx1-1>=0 && idx1-1<sizes[j]){
                        v.push_back(nums[j][idx1-1]);
                            }
                    }
                    // valid lower bound
                    
                }else if(idx1==sizes[j]){
                    v.push_back(nums[j][idx1-1]);
                }
                ch.push_back(v);
            }
            choices.push_back(ch);
            
        }
        vector<vector<int>> vp;
        ga=0;
            gb=INT_MAX;
        for(auto i:choices){
            int curr_a=i[0][0];
            int curr_b=i[0][0];
            vector<int> dp(k,-1);
            // vector<vector<int>>
            f(i,k,1, curr_a, curr_b, dp );
        }
        return {(int)ga,(int)gb};
    }
};
