// Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt=0;
        priority_queue<int, vector<int>,greater<int>> pq_min;
        for(auto i:intervals){
            int e=i[1];
            pq_min.push(e);
        }
        int max_cnt=0;
        for(auto i:intervals){
            int s=i[0];
            
            while(!pq_min.empty() && s>pq_min.top()){
                pq_min.pop();
                cnt--;
            }
            cnt++;
            max_cnt=max(max_cnt, cnt);
        }
        return max_cnt;
    }
};
