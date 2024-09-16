// Link: https://leetcode.com/problems/minimum-time-difference/
/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(vs) {
    let n = vs.length;
    vs.sort();
    let res=Number.MAX_SAFE_INTEGER;
    for(let i=1;i<n;i++){
        let hrs = vs[i].substr(0,2)-vs[i-1].substr(0,2);
        let mins = vs[i].substr(3,2) - vs[i-1].substr(3,2);
        res=Math.min(res, hrs*60+mins);
    }
    let s= Number(vs[0].substr(0,2))+24 + ":"+vs[0].substr(3,2);
    let hrs = s.substr(0,2)-vs[n-1].substr(0,2);
    let mins = s.substr(3,2) - vs[n-1].substr(3,2);
    res=Math.min(res, hrs*60+mins);
    console.log(s);
    return res;
    
    
};
