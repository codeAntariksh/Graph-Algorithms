#include<bits/stdc++.h>
using namespace std;

void dfs_traversal(int i,vector<vector<int>> &adj_list,vector<vector<int>> &visited,stack<int> &st)
{
    visited[i] = true;
    for(int neigh:adj_list[i])
    {
        if(!visited[neigh])
            dfs_traversal(neigh,adj_list,visited,st);
    }
    st.push(i);
}

void dfs_traversal(int i,vector<vector<int>> &adj_list,vector<int> &visited,vector<vector<int>> ans,int cnt)
{
    visited[i] = true;
    for(int neigh:adj_list[i])
    {
        if(!visited[neigh])
            dfs_traversal(neigh,adj_list,visited,st);
    }
    ans[cnt].push_back(i);
}


int main()
{
    int n; // Edges
    int m; // Vertex
    cin>>n>>m;
    vector<vector<int>> adj_list(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }
    // Now The Algorithm
    // Initial Traversal and Putting in Stack
    vector<int> visited(n,false);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs_traversal(i,adj_list,visited,st);
    }
    // Reverse Connections
    vector<vector<int>> adj_listT(n);
    for(int i=0;i<n;i++)
    {
        for(int node:adj_list[i])
        {
            adj_listT[node].push_back(i);
        }
    }
    // Final Traversal
    vector<vector<int>> ans;
    int cnt = 0;
    for(int i=0;i<n;i++)
        visited[i] = false;
    while(!st.empty())
    {
        int val = st.top();
        st.pop();
        if(!visited[val])
            dfs_traversal(val,adj_listT,visited,ans,cnt);
        cnt++;
    }
    // Results
    cout<<"No of Strongly Connected Components:"<<cnt<<endl;
    cout<<"The Connected Components are-:"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
