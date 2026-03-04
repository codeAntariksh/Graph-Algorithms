// Detect Cycle Using BFS Algorithm
#include<bits/stdc++.h>
using namespace std;
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
    // The BFS Algorithm for Detecting Cycle
    queue<pair<int,int>> q; // q signifies <vertex info,parent>
    bool cycle = false;
    for(int start=1;start<=n;start++)
    {
        if(visited[start]) continue;
        q.push({start,-1});
        visited[start] = true;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            int sz = adj_list[node].size();
            for(int i=0;i<sz;i++)
            {
                if(!visited[adj_list[node][i]])
                {
                    visited[adj_list[node][i]] = true;
                    q.push({adj_list[node][i],node}); 
                }
                else if(adj_list[node][i]!=parent)
                {
                    cycle = true;
                    break;
                }
            }
        }
    }
        // Solution
    if(cycle) 
        cout<<"The Graph Contains a Cycle"<<endl;
    else 
        cout<<"The Graph Does Not Contain a Cycle"<<endl;
    return 0;
}
