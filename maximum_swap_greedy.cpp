// Link: https://leetcode.com/problems/maximum-swap

class Solution {
public:
    // 2736
    // 7632
    int maximumSwap(int num) {
        // get the first unsorted idx and then sort it 
        string s=to_string(num);
        string s2=s;
        sort(s2.begin(), s2.end());
        reverse(s2.begin(), s2.end());
        int n=s.length();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]==s2[i]){
                continue;
            }else{
                // get that bit find the right most guy and replace it 
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return num;
        }
        for(int i=n-1;i>=0;i--){
            if(s2[idx]==s[i]){
                // swap idx, i
                swap(s[idx], s[i]);
                break;
            }
        }
        return stoi(s);
    }
};
