#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cntfresh= 0;
        //{{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1){cntfresh++;}
            }
        }
        int t=0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int cnt =0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            t = max(time , t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 
                   1 && vis[nrow][ncol] != 2){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
        }
        if(cnt != cntfresh){
            return -1;
        }
        return t;
    }
};