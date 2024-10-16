// LinK: https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});
        while(!pq.empty()){
            int cnt=pq.top().first;
            char curr = pq.top().second;
            pq.pop();
            if(res.size()>=2 && res.back()==curr && res[res.size()-2]==curr){
                if(pq.empty()) break;
                int nxt_cnt=pq.top().first;
                int nxt_curr=pq.top().second;
                pq.pop();
                res+=nxt_curr;
                nxt_cnt--;
                if(nxt_cnt) pq.push({nxt_cnt, nxt_curr});
                pq.push({cnt, curr});
            }else{
                res+=curr;
                cnt--;
                if(cnt) pq.push({cnt, curr});
            }
        }
        return res;
    }
};
