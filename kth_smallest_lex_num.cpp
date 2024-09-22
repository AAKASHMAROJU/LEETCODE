#define ll long long 
// Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
class Solution {
public:
    
    int count(ll value,ll n){
        ll next_val=value+1;
        ll cnt=0;
        while(value<=n){
            cnt+=min(next_val,n+1)-value;
            value*=10;
            next_val*=10;
            
        }
        return cnt;
    }
    
    
    int findKthNumber(int n, int k) {
        ll curr=1;
        int idx=1;
        while(idx<k){
            int steps = count(curr, n);
            if(steps+idx<=k){
                curr+=1;
                idx+=steps;
            }else{
                curr*=10;
                idx++;
            }
        }
        
        return curr;
    }
};
