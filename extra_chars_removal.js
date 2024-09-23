// Link: https://leetcode.com/problems/extra-characters-in-a-string/

/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */

function f(s, idx, dictionary, dp){
    if(idx==s.length) return 0;
    if(dp[idx]!==-1) return dp[idx];
    let sub="";
    let res=Number.MAX_VALUE;
    for(let i=idx;i<s.length;i++){
        sub+=s[i];
        if(dictionary.includes(sub)){
            res=Math.min(res,f(s,i+1, dictionary,dp));
        }else{
            res=Math.min(res,(i-idx+1) + f(s, i+1, dictionary, dp));
        }
    }
    return dp[idx]=res;
}



var minExtraChar = function(s, dictionary) {
    let n=s.length;
    let dp = new Array(n).fill(-1);

    return f(s, 0, dictionary, dp);
};
