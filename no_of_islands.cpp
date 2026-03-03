// No.of.islands Problem
// Also can be referred as No.of.Connected Components Problem
#include<bits/stdc++.h>
using namespace std;


void dfs(pair<int,int> node,vector<vector<int>> &matrix,vector<vector<bool>> &visited)
{
    // Base Conditions
    if(node.first<0 || node.second<0 || node.first>=matrix.size() || node.second>=matrix[0].size())
        return;
    // Rest logic of DFS
    if(matrix[node.first][node.second] == 0 || visited[node.first][node.second]) return;
    visited[node.first][node.second] = true;
    // Run the 8 Loops
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;
            dfs({node.first+i,node.second+j},matrix,visited);
        }
    }
}


int main()
{
    // Taking a Matrix as an input
    int n,m; // (nXm Matrix)
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int> (m,-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    // Building Visited Array
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    int cnt = 0;
    // We Would be Following DFS Traversal
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j]==1 && visited[i][j]==false) {
                dfs({i,j},matrix,visited);
                cnt++;
            }
        }
    }
    cout<<"No of Connected Components/Islands = "<<cnt<<endl;
    return 0;
}
