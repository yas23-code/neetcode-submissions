#include <cstring>

class Solution {
public:
int t[201][201];
int solve(int i,int j,int m, int n,vector<vector<int>>& grid){
    if(i<0||j<0||i>=m||j>=n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    
    if(i==m-1){
        return t[i][j]= grid[i][j]+solve(i,j+1,m,n,grid);
    }
    else if(j==n-1){
        return t[i][j]=grid[i][j]+solve(i+1,j,m,n,grid);
    }else{
        return t[i][j]= grid[i][j]+ min(solve(i+1,j,m,n,grid),solve(i,j+1,m,n,grid));
    }
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n,grid);
        
    }
};