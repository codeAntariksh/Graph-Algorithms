
// Rotten Oranges Problem 
// 2 --> Rotten Orange
// 1 --> Fresh Orange
// 0 --> Empty Cell
// In this Problem to counter this, a Recursive approach involving Graphs must be taken (basically BFS for level Approach). Now To return the No. of Minutes involving the Solution, We need to actually return the depth of the recursion
// 2 2 2
// 2 2 2
// 2 2 2
// depth = 1 + 1 + 1 + 1 = 4
// How can we minimise depth of Recursion?

// BFS (Breadth First Search Traversal)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Take Inputs of the Matrix
    int n,m; //(nXm Matrix)
    cin>>n>>m;
    // The Matrix
    vector<vector<int>> matrix(n,vector<int> (m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    // Visited Array
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    // BFS Traversals 
    // Queue for Processing
    queue<pair<pair<int,int>,int>> q;
    // Breadth First Search Traversal (BFS)
    for(int i=0;i<n;i++)  // TC = O(N^2)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==2) {
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }
    int cnt = 0;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        cnt = t;
        q.pop();
        for(int i=-1;i<=1;i++)
        {   
            for(int j=-1;j<=1;j++)
            {
                if(x+i<0 || y+j<0 || x+i>=n || y+j>=m) continue;
                if((i==0 && j==0) || (i==-1 && j==-1) || (i==1 && j==1) || (i==-1 && j==1) || (i==1 && j==-1)) continue;
                if(matrix[x+i][y+j]!=1 || visited[x+i][y+j]==true) continue;
                q.push({{x+i,y+j},t+1});
                visited[x+i][y+j] = true;
                matrix[x+i][y+j] = 2;
            }
        }
    }
    // Checking for Remaining Oranges --> O(n^2)
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrix[i][j]==1)
                cnt = -1;
    cout<<"Time Needed = "<<cnt<<endl;
    return 0;
}


