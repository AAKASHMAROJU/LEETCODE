// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int lc=0;
        int rc=0;
        for(auto i:s){
            if(i=='('){
                lc++;
            }else{
                if(lc>0){
                    lc--;
                }
                    
                else
                    rc++;
            }
        }
        return lc+rc;
    }
};
