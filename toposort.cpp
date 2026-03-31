#include<bits/stdc++.h>
using namespace std;

// Topological Sorting for DAG (Directed Acyclic Graphs)

void dfs_traversal(int i,vector<bool> &visited,vector<vector<int>>&adj_list,stack<int> &st)
{
    if(visited[i]) return;
    visited[i] = true;
    for(int neigh:adj_list[i])
    {
        dfs_traversal(neigh,visited,adj_list,st);
    }
    st.push(i);
    return;
}



int main()
{
    int n,m;
    cin>>n>>m;
    // Directed Graph
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }
    // Visited Array
    vector<bool> visited(n+1,false);
    // Ans Array
    vector<int> ans;
    stack<int> st;
    // DFS Algorithm
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs_traversal(i,visited,adj_list,st);
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    // Displaying the Solution
    for(int &x:ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
