#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,INT_MAX));
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        q.push({{0,0},0});
        visited[0][0] = 0;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(i == 0 && j == 0) continue;
                    if(x+i<0 || x+i>=m || y+j<0 || y+j>=n ||
                    grid[x+i][y+j]==1 || dist + 1 >= visited[x+i][y+j]) continue;
                    visited[x+i][y+j] = dist + 1;
                    q.push({{x+i,y+j},dist+1});
                }
            }
        }
        return (visited[m-1][n-1]==INT_MAX)?-1:visited[m-1][n-1]+1;
     }


int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int> (n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    cout<<"Shortest Binary Path from Top Left to Bottom Right Corner is"<<shortestPathBinaryMatrix(grid);
    return 0;
}
