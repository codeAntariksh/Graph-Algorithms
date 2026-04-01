#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int target_node; // Node from Which Distances need to be Calclulated
    vector<int> dist(n,-1); // 0 to n-1
    queue<pair<int,int>> q;// {node,dist}
    q.push({target_node,0});
    // BFS Algorithm
    while(!q.empty())
    {   
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        dist[node] = d;
        for(int neigh:adj_list[node])
        {
            if(dist[neigh]==-1)
            {
                q.push({neigh,d+1});
            }
        }
    }
    // Printing
    for(int i=0;i<n;i++)
    {
        cout<<"Distance of Node"<<i<<" from Target Node-"<<target_node<<" is-"<<dist[i]<<endl;
    }



    return 0;
}
