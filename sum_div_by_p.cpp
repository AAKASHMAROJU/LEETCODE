// Link: https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();  
        int sum=0;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
        }
        if(sum==0) return 0;
        int rem=sum;
        int s=0;
        int len=n;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            s=(s+nums[i])%p;
            if(mpp.count((s-rem+p)%p)){
                len=min(len, i-mpp[(s-rem+p)%p]);
            }
            mpp[s]=i;
        }
        return len==n?-1:len;
    }
};
