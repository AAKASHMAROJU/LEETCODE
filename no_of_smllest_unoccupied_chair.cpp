// Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

#define pipii pair<int, pair<int,int>> 
#define  piipi pair<pair<int,int>, int>
#define pii pair<int,int> 
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int , vector<int>, greater<int>> pq_chairs;
        priority_queue<pii, vector<pii>, greater<pii>> pq_persons;
        vector<piipi> vp;
        int n=times.size();
        vector<int> v(n, -1);
        for(int i=0;i<n;i++){
            pq_chairs.push(i);
        }
        int idx=0;
        for(auto i:times){
            int s=i[0];
            int e=i[1];
            vp.push_back({{s, e}, idx++});
        }
        sort(vp.begin(), vp.end());
        for(auto i:vp){
            int s=i.first.first;
            int e=i.first.second;
            
            int person=i.second;
            
            while(!pq_persons.empty() && s>=pq_persons.top().first){
                int per2=pq_persons.top().second;
                pq_chairs.push(v[per2]);
                pq_persons.pop();
            }
            pq_persons.push({e, person});
            v[person]=pq_chairs.top();
            pq_chairs.pop();
        }
        return v[targetFriend];
    }
    
};
