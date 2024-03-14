void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int sr, int sc, int m, int n, int oldcol, int newcol)
{
    ans[sr][sc] = newcol;
    //  top
    if (sr > 0 && image[sr - 1][sc] == oldcol && ans[sr - 1][sc] != newcol)
    {
        dfs(image, ans, sr - 1, sc, m, n, oldcol, newcol);
    }
    // bottom
    if (sr < m - 1 && image[sr + 1][sc] == oldcol && ans[sr + 1][sc] != newcol)
    {
        dfs(image, ans, sr + 1, sc, m, n, oldcol, newcol);
    }
    // left
    if (sc > 0 && image[sr][sc - 1] == oldcol && ans[sr][sc - 1] != newcol)
    {
        dfs(image, ans, sr, sc - 1, m, n, oldcol, newcol);
    }
    // right
    if (sc < n - 1 && image[sr][sc + 1] == oldcol && ans[sr][sc + 1] != newcol)
    {
        dfs(image, ans, sr, sc + 1, m, n, oldcol, newcol);
    }
}
// void dfs2(vector<vector<int>>& image,vector<vector<int>>&ans, int sr, int sc,int m,int n,int *dr,int *dc,int oldcol, int newColor){
//     ans[sr][sc]=newcol;

//     for(int i=0;i<4;i++){
//         int nrow=sr+dr[i];
//         int ncol=sc+dc[i];
//         if(nrow>0&&nrow<m-1&&ncol>0&&ncol<n-1&&grid[sr-1][sc]==oldcol&&ans[sr-1][sc]!=newcol){
//              dfs(image,ans,nrow,ncol,,m,n,dr,dc,oldcol,newcol);
//         }
//     }
// }

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here
    int oldcol = image[sr][sc];
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> ans = image;
    dfs(image, ans, sr, sc, m, n, oldcol, newColor);
    // int dr[]={-1,0,1,0};
    // int dc[]={0,-1,0,1};
    // dfs2(image,ans,sr,sc,m,n,dr,dc,oldcol,newcol);
    return ans;
}