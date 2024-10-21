// Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

int f(string s, int idx, int n, map<string, int>& mpp){
    if(idx==n) return 0;
    int cnt=0;
    string temp="";
    for(int i=idx;i<n;i++){
        temp+=s[i];
        if(mpp.count(temp)==0){
            mpp[temp]++;
            cnt=max(cnt, 1+f(s, i+1, n, mpp));
            mpp[temp]--;
            if(mpp[temp]==0){
                mpp.erase(temp);
            }
        }
    }
    return cnt;
}


class Solution {
public:
    int maxUniqueSplit(string s) {
        int n=s.length();
        map<string, int > mpp;
        return  f(s, 0, n, mpp);
        
    }
};
