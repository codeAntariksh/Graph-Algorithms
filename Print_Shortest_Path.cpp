#include<bits/stdc++.h>
using namespace std;

// Djikstra's Algorithm for Printing Shortest Path


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
    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;
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
                parent[vertex] = el;
                pq.push({dist[vertex],vertex});
            }
        }
    }
    // Print Results
    int reachnode;
    cin>>reachnode;
    vector<int> ans;
    if(dist[reachnode]==INT_MAX)
    {
        cout<<"Not Reachable"<<endl;
        return 0;
    }
    ans.push_back(reachnode);
    while(parent[reachnode]!=reachnode)
    {
        reachnode = parent[reachnode];
        ans.push_back(reachnode);
    }
    reverse(ans.begin(),ans.end());
    for(int &x:ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
