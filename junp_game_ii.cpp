// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    
    
    int  f(int idx, vector<int>& nums, int n, vector<int>& dp){
        if(idx==n-1){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int ans=25000;
        for(int j=1;j<=nums[idx]&&idx+j<n;j++){
            ans=min(ans, 1+f(idx+j,nums,n, dp));
        }
        return dp[idx]=ans;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        int near=0,far=0,jumps=0;
        while(far<n-1){
            int farthest=0;
            for(int idx=near;idx<=far;idx++){
                farthest=max(farthest, idx+nums[idx]);
            }
            near=far+1;
            far=farthest;
            jumps++;
        }
        return jumps;
    }
};
