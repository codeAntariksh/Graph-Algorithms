#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Inputting the Matrix Details
    int m,n; // mXn Matrix
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int> (n,-1));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    // Answer Matrix
     vector<vector<int>> ans(m,vector<int> (n,-1));
    /*
     // Logic for BFS Traversal --> n^4 TC
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==1)
            {
                ans[i][j]=0;
                continue;
            }
            // Else BFS Traversal
            queue<pair<pair<int,int>,int>> q; // Queue<{{x,y},level}>
            q.push({{i,j},0});
            // Visited Array
           vector<vector<bool>> visited(m,vector<bool> (n,false));
           visited[i][j] = true;
            while(!q.empty())
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int lvl = q.front().second;
                q.pop();
                if(matrix[x][y]==1)
                {
                    ans[i][j] = lvl;
                    break;
                }
                for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        if(x+dx<0 || y+dy<0 || x+dx>=matrix.size() || y+dy>=matrix[0].size() || (dx==0 && dy==0) || (dx==1 && dy==1) || (dx==-1 && dy==-1) || (dx==1 && dy==-1) || (dx==-1 && dy==1) || visited[x+dx][y+dy]==true)
                            continue;
                        q.push({{x+dx,y+dy},lvl+1});
                        visited[x+dx][y+dy] = true;
                    }
                }
            }
            // Edge Case --> If Everything is 0 and no 1 then ans should be -1
        }
    }
    */
     // BEST SOLUTION --> TC = O(mXn) + O(mXn)
    vector<vector<bool>> visited(m,vector<bool> (n,false));
    queue<pair<pair<int,int>,int>> q; // Queue<{{x,y},level}> 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==1)
            {
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty())
    {
         int x = q.front().first.first;
         int y = q.front().first.second;
         int lvl = q.front().second;
         q.pop();
        ans[x][y] = lvl;
         for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        if(x+dx<0 || y+dy<0 || x+dx>=matrix.size() || y+dy>=matrix[0].size() || (dx==0 && dy==0) || (dx==1 && dy==1) || (dx==-1 && dy==-1) || (dx==1 && dy==-1) || (dx==-1 && dy==1) || visited[x+dx][y+dy]==true)
                            continue;
                        q.push({{x+dx,y+dy},lvl+1});
                        visited[x+dx][y+dy] = true;
                    }
                }
    }
    // Display the Results
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
