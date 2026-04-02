#include<bits/stdc++.h>
using namespace std;

// Djikstra's Algorithm


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
        adj_list[v].push_back({u,w});
    }
    
    int target;
    cin>>target;
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,target});
    dist[target] = 0;
    while(!pq.empty())
    {
        int d = pq.top().first;
        int el = pq.top().second;
        pq.pop();
        for(auto &it:adj_list[el])
        {
            int vertex = it.first;
            int edgeWeight = it.second;
            if(dist[el]+edgeWeight<dist[vertex])
            {
                dist[vertex] = dist[el] + edgeWeight;
                pq.push({dist[vertex],vertex});
            }
        }
    }
    // Print Results
    for(int i=0;i<n;i++)
    {
        cout<<"Distance of Node-"<<i<<" from Target Node-"<<target<<" is-"<<dist[i];
    }
    return 0;
}
