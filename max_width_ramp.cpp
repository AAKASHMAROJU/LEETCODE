// Link: https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n, 0);
        v[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            v[i]=max(nums[i], v[i+1]);
        }
        
        int ptr2=1;
        int ptr1=0;
        int ans=0;
        while(ptr2<n){
            if(v[ptr2]>=nums[ptr1]){
                ans=max(ans, ptr2-ptr1);
                ptr2++;
            }
            else{
                ptr1++;
            }
        }
        return ans;
    }
};
