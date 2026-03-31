// Detection of Cycle in Directed Graph using DFS
#include<bits/stdc++.h>
using namespace std;

bool dfs_traversal(int node,vector<bool> &visited,vector<bool> &pathvisited,vector<vector<int>> &adj_list)
{
    visited[node] = true;
    pathvisited[node] = true;
    for(int x:adj_list[node])
    {
        if(!visited[x])
        {
            if(dfs_traversal(x,visited,pathvisited,adj_list)==true)
                return true;
        }
        else if(pathvisited[x])
        {
            return true;
        } 
    }
    pathvisited[node] = false;
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
    }
    // Visited Array
    vector<bool> visited(n+1,false);
    vector<bool> pathvisited(n+1,false);
    // The DFS Algorithm for Detecting Cycle
    bool cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true)
            continue;
        cycle = dfs_traversal(i,visited,pathvisited,adj_list);
        if(cycle)
            break;
        // fill(pathvisited.begin(),pathvisited.end(),false);
    }
    // Solution
    if(cycle)
        cout<<"The Graph Contains a Cycle"<<endl;
    else 
        cout<<"The Graph Does not Contain a Cycle"<<endl;
    return 0;
}




