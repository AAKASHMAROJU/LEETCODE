// Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    
    int findTheLongestSubstring(string s) {
        map<char, int> mpp;
        mpp['a']=1;
        mpp['e']=2;
        mpp['i']=4;
        mpp['o']=8;
        mpp['u']=16;
        int res=0;
        map<int, int> pattern;
        pattern[0]=-1;
        int xor1=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                xor1^=mpp[s[i]];
                if(pattern.count(xor1)){
                    cout<<"Heyy"<<endl;
                    res=max(res, i-pattern[xor1]);
                }else{
                    pattern[xor1]=i;
                }
            }else{
                 res=max(res, i-pattern[xor1]);
            }
        }
        
        return res;
    }
    
};
