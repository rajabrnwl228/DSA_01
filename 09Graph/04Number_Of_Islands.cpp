#include<vector>
#include<queue>

//   void findAdjacentLand(vector<vector<char>>&grid,int row,int col,vector<vector<int>>&vis,queue<pair<int,int>>&que){
//       int m=grid.size();
//       int n=grid[0].size();
//       //top
//       if(row>0&&grid[row-1][col]=='1'&&!vis[row-1][col]){
//           que.push({row-1,col});
//           vis[row-1][col]=1;
//       }
//       //bottom
//       if(row<m-1&&grid[row+1][col]=='1'&&!vis[row+1][col]){
//           que.push({row+1,col});
//           vis[row+1][col]=1;
//       }
//       //left
//       if(col>0&&grid[row][col-1]=='1'&&!vis[row][col-1]){
//           que.push({row,col-1});
//           vis[row][col-1]=1;
//       }
//       //right
//       if(col<n&&grid[row][col+1]=='1'&&!vis[row][col+1]){
//           que.push({row,col+1});
//           vis[row][col+1]=1;
//       }
//       //left top diagonal
//       if(row>0&&col>0&&grid[row-1][col-1]=='1'&&!vis[row-1][col-1]){
//           que.push({row-1,col-1});
//           vis[row-1][col-1]=1;
//       }
//       //left bottom
//       if(row<m-1&&col>0&&grid[row+1][col-1]=='1'&&!vis[row+1][col-1]){
//           que.push({row+1,col-1});
//           vis[row+1][col-1]=1;
//       }
//       //right top
//       if(row>0&&col<n-1&&grid[row-1][col+1]=='1'&&!vis[row-1][col+1]){
//             que.push({row-1,col+1});
//           vis[row-1][col+1]=1;
//       }
//       //right bottom
//       if(row<m-1&&col<n-1&&grid[row+1][col+1]=='1'&&!vis[row+1][col+1]){
//       que.push({row+1,col+1});
//           vis[row+1][col+1]=1;
//       }
//   }
  void bfs(vector<vector<char>>&grid,int row,int col,vector<vector<int>>&vis){
      
      int m=grid.size();
      int n=grid[0].size();
      vis[row][col]=1;
      queue<pair<int,int>>que;
      que.push({row,col});
      while(!que.empty()){
          pair<int,int> land=que.front();
          int row=land.first;
          int col=land.second;
          que.pop();
        //   findAdjacentLand(grid,row,col,vis,que);
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                int nrow=row+dr;
                int ncol=col+dc;
                if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    que.push({nrow,ncol});
                }
            }
        }
      }
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }