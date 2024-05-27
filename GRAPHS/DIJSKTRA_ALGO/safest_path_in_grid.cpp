#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-safest-path-in-a-grid/
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // multi source bfs to calculate how far we are from thief nearest 
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i, j}, 0});
                    grid[i][j]=INT_MAX;
                }
            }
        }
        // vector<vector<bool>> vis(n, vector<int>(n, false));
        vector<int> dx={-1, 0, 1, 0};
        vector<int> dy={0, 1, 0, -1};
        while(!q.empty()){
            int dist=q.front().second;
            int x=q.front().first.first;
            int y=q.front().first.second;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && x1< n && y1<n && y1>=0 && grid[x1][y1]==0){
                    grid[x1][y1]=dist+1;
                    q.push({{x1, y1}, dist+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    grid[i][j]=0;
                }
            }
        }
        priority_queue<pair<int, pair<int,int>>> pq;
        // maxHeap 
        pq.push({grid[0][0], {0, 0}});
        int ans=grid[0][0];
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0]=1;
        while(!pq.empty()){
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==n-1){
                return dist;
            }
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && x1<n && y1>=0 && y1<n && !vis[x1][y1]){
                    pq.push({min(dist, grid[x1][y1]), {x1, y1}});
                    vis[x1][y1]=1;
                }
            }
        }
        return ans;
        
        
        
        return 0;
        
        
    }
};