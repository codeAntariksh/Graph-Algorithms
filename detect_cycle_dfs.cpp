// Detection of Cycle using DFS
#include<bits/stdc++.h>
using namespace std;

bool dfs_traversal(int node,int parent,vector<bool> &visited,vector<vector<int>> &adj_list)
{
    visited[node] = true;
    for(int x:adj_list[node])
    {
        if(!visited[x])
        {
            if(dfs_traversal(x,node,visited,adj_list)==true)
                return true;
        }
        else if(x!=parent)
            return true;
    }
    return false;
}

int main()
{
    int n; // No.of Vertexes
    int m; // No.of Edges
    cin>>n>>m;
    // Declaring Adjacency List and Taking input Graph Information
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // Visited Array
    vector<bool> visited(n+1,false);
    // The DFS Algorithm for Detecting Cycle
    bool cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true)
            continue;
        cycle = dfs_traversal(i,-1,visited,adj_list);
        if(cycle)
            break;
    }
    // Solution
    if(cycle)
        cout<<"The Graph Contains a Cycle"<<endl;
    else 
        cout<<"The Graph Does not Contain a Cycle"<<endl;
    return 0;
}










