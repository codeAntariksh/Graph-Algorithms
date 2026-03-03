// Problem --> No.of Provinces
// Depth First Search Traversal
#include<bits/stdc++.h>
using namespace std;


void dfs_traversal(int target_node,vector<bool> &visited,vector<vector<int>> &adj_list)
{
    if(visited[target_node]) return;
    visited[target_node] = true;
    cout<<target_node<<" ";
    for(int i=0;i<adj_list[target_node].size();i++)
    {       
        dfs_traversal(adj_list[target_node][i],visited,adj_list);
    }
}

int main()
{
    // Setting Up Input Space

    // Setting Up Graph Information
    int n,m;
    cin>>n>>m;
    // Now M vertices stored in Adjancency List
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // Saving the Visited Vector
    vector<bool> visited(n+1,false);



    int cnt = 0;
    // Now Writing the DFS Algorithm
    // Start from Visited Node 1
    // If We Want to Traverse throughout all Nodes
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            dfs_traversal(i,visited,adj_list);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
