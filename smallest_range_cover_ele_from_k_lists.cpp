// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#define pipii pair<int,pair<int,int>> 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        int k=nums.size();
        vector<int> sizes;
        for(auto i:nums){
            sizes.push_back(i.size());
        }
        int max_ele=INT_MIN;
        int min_ele = INT_MAX;
        for(int i=0;i<k;i++){
            max_ele=max(max_ele, nums[i][0]);
            min_ele = min(min_ele, nums[i][0]);
        }
        
        for(int i=0;i<k;i++){
            pq.push({nums[i][0], {i,0}});
        }
        int curr_max_ele=max_ele;
        int curr_min_ele=min_ele;
        while(pq.top().second.second+1<sizes[pq.top().second.first]){
            int x=pq.top().second.first;
            int y = pq.top().second.second;
            int ele=pq.top().first;
            pq.pop();
            y++;
            pq.push({nums[x][y], {x, y}});
            curr_max_ele=max(curr_max_ele, nums[x][y]);
            curr_min_ele=pq.top().first;
            // cout<< curr_min_ele<<" , "<< curr_max_ele<<endl;
            if(max_ele-min_ele>curr_max_ele-curr_min_ele){
                max_ele=curr_max_ele;
                min_ele=curr_min_ele;
            }
        }
        
        return {min_ele, max_ele};
    }
};
