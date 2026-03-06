/* Some Minor Tweaks just needed in the Problem i.e basically we can say that no.of enclaves = The Unvisited 1's */



#include<bits/stdc++.h>
using namespace std;


void dfs_traversal(int x,int y,vector<vector<int>> &matrix,vector<vector<bool>> &visited)
{
    if(matrix[x][y] == 0 || visited[x][y])
        return;
    visited[x][y] = true;
     for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        if(x+dx<0 || y+dy<0 || x+dx>=matrix.size() || y+dy>=matrix[0].size() || (dx==0 && dy==0) || (dx==1 && dy==1) || (dx==-1 && dy==-1) || (dx==1 && dy==-1) || (dx==-1 && dy==1))
                            continue;
                        dfs_traversal(x+dx,y+dy,matrix,visited);
                    }
                }
}

int main()
{
    int m,n; // mXn Matrix
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int> (n,-1));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    // Algorithm--> Move through the Boundaries i.e (matrix[0][0] --> matrix[m-1][0] && matrix[m-1][0] --> matrix[m-1][n-1] && matrix[m-1][n-1] --> matrix[0][n-1] && matrix[0][n-1] --> matrix[0][0]) and apply dfs to the position if we encounter a "O" and mark them as "0" bcz they cannot be marked X and then we re-iterate the matrix and we mark all remaining positions as "X"
   vector<vector<bool>> visited(m,vector<bool> (n,false));
   for(int i=0;i<m;i++)
   {
       if(!visited[i][0] && matrix[i][0] == 1)
            dfs_traversal(i,0,matrix,visited);
   }
   for(int i=0;i<n;i++)
   {
       if(!visited[m-1][i] && matrix[m-1][i] == 1)
            dfs_traversal(m-1,i,matrix,visited);
   }
   for(int i=m-1;i>=0;i--)
   {
       if(!visited[i][n-1] && matrix[i][n-1] == 1)
            dfs_traversal(i,n-1,matrix,visited);
   }
   for(int i=n-1;i>=0;i--)
   {
       if(!visited[0][i] && matrix[0][i] == 1)
            dfs_traversal(0,i,matrix,visited);
   }
   // No.of enclaves is basically the remaining unvisited ones(1)
   int cnt = 0;
   for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
           if(!visited[i][j] && matrix[i][j]==1)
               cnt++;
   cout<<"No of Enclaves is = "<<cnt;
    return 0;
}
