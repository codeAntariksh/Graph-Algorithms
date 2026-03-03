// Flood Fill Algorithm
#include<bits/stdc++.h>
using namespace std;


void dfs_traversal(pair<int,int> coordinate,int color,int newcolor,vector<vector<int>> &matrix)
{
    // Check Condition
    if(coordinate.first<0 || coordinate.second<0 || coordinate.first>=matrix.size() || coordinate.second>=matrix[0].size() || matrix[coordinate.first][coordinate.second]!=color)
        return;
    // Color Cells
    matrix[coordinate.first][coordinate.second] = newcolor;
    // Primary Recursions
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;
            dfs_traversal({coordinate.first+i,coordinate.second+j},color,newcolor,matrix);
        }
    }
}

int main()
{
    // Taking Inputs for the Color Matrix
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int> (m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    // Requested Coordinate and Color Input
    int color,x,y;
    cin>>x>>y>>color;
    // The Algorithm
    if(matrix[x][y]==color)
        return 0;
    dfs_traversal({x,y},matrix[x][y],color,matrix);
    // Printing the Colored Matrix
    // Edge Case Cover
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
