// Link: https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mpp;
        for(auto i:answers){
            mpp[i]++;
        }
        int cnt=0;
        for(auto i:mpp){
            cnt+=(ceil((float)i.second/(i.first+1))*(i.first+1));
        }
        return cnt;
    }
};
