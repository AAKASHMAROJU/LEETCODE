// Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int cnt;
    
    void f(int idx, int curr_or, vector<int>& nums, int n, int max_or){
        
        if(idx==n){
            if(curr_or==max_or){
                cnt++;
            }
            return;
        }
        // Pick 
        f(idx+1, curr_or|nums[idx], nums, n, max_or);
        f(idx+1, curr_or, nums, n, max_or);
        
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or=0;
        for(auto i:nums){
            max_or|=i;
        }
        int n=nums.size();
        cnt=0;
        f(0, 0,nums, n, max_or);
        return cnt;
    }
};
