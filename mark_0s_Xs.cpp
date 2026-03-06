#include<bits/stdc++.h>
using namespace std;


void dfs_traversal(int x,int y,vector<vector<char>> &matrix,vector<vector<char>> &ans,vector<vector<bool>> &visited)
{
    if(matrix[x][y] == 'X' || visited[x][y])
        return;
    ans[x][y] = 'O';
    visited[x][y] = true;
     for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        if(x+dx<0 || y+dy<0 || x+dx>=matrix.size() || y+dy>=matrix[0].size() || (dx==0 && dy==0) || (dx==1 && dy==1) || (dx==-1 && dy==-1) || (dx==1 && dy==-1) || (dx==-1 && dy==1))
                            continue;
                        dfs_traversal(x+dx,y+dy,matrix,ans,visited);
                    }
                }
}

int main()
{
    int m,n; // mXn Matrix
    cin>>m>>n;
    vector<vector<char>> matrix(m,vector<char> (n,'X'));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    // Algorithm--> Move through the Boundaries i.e (matrix[0][0] --> matrix[m-1][0] && matrix[m-1][0] --> matrix[m-1][n-1] && matrix[m-1][n-1] --> matrix[0][n-1] && matrix[0][n-1] --> matrix[0][0]) and apply dfs to the position if we encounter a "O" and mark them as "0" bcz they cannot be marked X and then we re-iterate the matrix and we mark all remaining positions as "X"
   vector<vector<char>> ans(m,vector<char> (n,'K'));
   vector<vector<bool>> visited(m,vector<bool> (n,false));
   for(int i=0;i<m;i++)
   {
       if(!visited[i][0] && matrix[i][0] == 'O')
            dfs_traversal(i,0,matrix,ans,visited);
   }
   for(int i=0;i<n;i++)
   {
       if(!visited[m-1][i] && matrix[m-1][i] == 'O')
            dfs_traversal(m-1,i,matrix,ans,visited);
   }
   for(int i=m-1;i>=0;i--)
   {
       if(!visited[i][n-1] && matrix[i][n-1] == 'O')
            dfs_traversal(i,n-1,matrix,ans,visited);
   }
   for(int i=n-1;i>=0;i--)
   {
       if(!visited[0][i] && matrix[0][i]=='O')
            dfs_traversal(0,i,matrix,ans,visited);
   }
   // Marking the rest as "X"
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
            if(!visited[i][j]) 
                ans[i][j] = 'X';
            else 
                ans[i][j] = 'O';
       }
    }
   // ans array is the Solution
    return 0;
}
