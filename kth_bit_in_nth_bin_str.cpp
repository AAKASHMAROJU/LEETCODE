// Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1 && k==1){
            return '0';
        }
        if(k==(1<<(n-1))){
            return '1';
        }
        int mid=(1<<(n-1));
        if(k<mid){
            return findKthBit(n-1, k);
        }
        else{
            return 1-(findKthBit(n-1, (1<<n)-k)-'0')+'0';
        }
    }
};
