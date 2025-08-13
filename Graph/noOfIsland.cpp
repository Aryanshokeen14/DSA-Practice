#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int m = grid.size(); // total row of grid
        int n = grid[0].size(); // total col of grid

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in neighbours if it is a land
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

    }
    public:
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size(); // total row of grid
        int n = grid[0].size(); // total col of grid
        vector<vector<int>> vis(m , vector<int>(n,0));
        int count = 0;
        for(int row = 0; row<m; row++){
            for(int col = 0; col<n; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};

int main(){
    Solution a;
    vector<vector<char>> grid = {{'1', '0', '1'},
    {'0', '0', '0'},
    {'1', '1', '1'},
    {'0', '0', '0'},
    {'1', '1', '1'}};
    cout<<a.numIslands(grid);
return 0;       
}