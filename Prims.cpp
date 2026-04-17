// Prims Algorithm
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n; // m-->edges and n-->vertices
    cin>>m;
    cin>>n;
    vector<vector<pair<int,int>>> adj_list(n);
    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj_list[u].push_back({v,weight});
        adj_list[v].push_back({u,weight});
    }
    // The Prims Algorithm for MST
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<bool> visited(n,false);
    pq.push({0,{0,-1}});
    vector<pair<int,int>> MST;
    int total_mst_weight = 0;  
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int vertex = pq.top().second.first;
        int parent = pq.top().second.second;
        
        pq.pop(); 
        
        if(visited[vertex] == true) {
            continue;
        }
        
        visited[vertex] = true;
        
        if(parent != -1) {
            MST.push_back({parent, vertex});
            total_mst_weight += wt;
        }
        
        for(auto it : adj_list[vertex]) {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(!visited[adjNode]) {
                pq.push({edgeWeight, {adjNode, vertex}});
            }
        }
    }
    
    // Print the MST
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for(auto edge : MST) {
        cout << edge.first << " - " << edge.second << endl;
    }
    cout << "Total MST Weight: " << total_mst_weight << endl;    return 0;
}



























