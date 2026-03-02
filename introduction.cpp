// Introduction to Graphs
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Representation
    int n; // No of Nodes
    int m; // No of Edges
    cin>>n>>m;
    // Adjacency Matrix --> O(n^2)
    vector<vector<int>> adj_mat(n+1,vector<int> (n+1,0));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }
    // Using Adjacency Lists for Inputs of Edges --> O(2N)
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // For directed Graphs
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_matrix[u][v] = 1;
        adj_list[u].push_back(v);
    }

    // For Weighted Graphs
    vector<vector<pair<int,int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj_list[u].push_back({v,weight});
        adj_matrix[u][v] = weight;
    }
    return 0;
}
