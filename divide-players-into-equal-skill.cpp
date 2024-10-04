// Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        int n=skill.size();
        unordered_map<int,int> mpp;
        int sum=0;
        for(auto i:skill){
            sum+=i;
            mpp[i]++;
        }
        if(sum%(n/2)!=0) return -1;
        int pair_skill=sum/(n/2);
        for(auto i:skill){
            int partner_skill=pair_skill-i;
            if(mpp.count(partner_skill)==0){
                return -1;
            }else{
                ans+=(i*(long long)partner_skill);
                mpp[partner_skill]--;
                if(mpp[partner_skill]==0){
                    mpp.erase(partner_skill);
                }
            }
        }
        
        return ans/2;
    }
};
