// Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/
#define ll long long 
class Solution {
public:
    
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll, ll> mpp;
        ll ans=0;
        for(auto i:nums){
            int curr_gcd = gcd(i, k);
            for(auto j:mpp){
                if((j.first*curr_gcd)%k==0){
                   ans+=j.second; 
                }
            }
            mpp[curr_gcd]++;
        }
        return ans;
    }
};
