#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<bool>&visited,vector<vector<pair<int,int>>>&adj_list,stack<int>&st)
{
    visited[i] = true;
    for(auto& neigh:adj_list[i])
    {
        if(!visited[neigh.first])
            dfs(neigh.first,visited,adj_list,st);
    }
    st.push(i);
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj_list(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }
    vector<bool> visited(n,false);
    // TopoSort first to Get an Ordering
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(i,visited,adj_list,st);
    }
    
    // Take Nodes Out and Relax Edges
    const int INF = 1e9;
    vector<int> dist(n, INF);
    
    int source = 0;
    dist[source] = 0;

    // 3. Relax Edges in Topological Order
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        // If we have reached this node, relax its neighbors
        if (dist[u] != INF) {
            for(auto &edge : adj_list[u]) {
                int v = edge.first;
                int weight = edge.second;
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    // Printing
    for(int i=0;i<n;i++)
    {
        cout<<"Distance of Node"<<i<<" is-"<<dist[i]<<endl;
    }

    return 0;
}
