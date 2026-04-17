// Krushkal Algorithm
#include<bits/stdc++.h>
using namespace std;

// Find
int find(int u,vector<int>&parent)
{
    if(parent[u]!=u)
        parent[u] = find(parent[u],parent);
    return parent[u];
}

// union
void Union(int u,int v,vector<int>& parent,vector<int>& rnk)
{
    int pu = find(u,parent);
    int pv = find(v,parent);
    if(rnk[pu]>rnk[pv])
        parent[pv] = pu;
    else if(rnk[pv]>rnk[pu])
        parent[pu] = pv;
    else
    {   
        parent[pv] = pu;
        rnk[pu]++;
    }   
}

int main()
{
    int m,n; // m-->edges and n-->vertices
    cin>>m;
    cin>>n;
    vector<vector<pair<int,int>>> adj_list(n);
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj_list[u].push_back({v,weight});
        adj_list[v].push_back({u,weight});
        edges.push_back({weight,{u,v}});
        edges.push_back({weight,{v,u}});
    }
    sort(edges.begin(),edges.end());
    vector<int> rnk(n,0);
    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;
    int totalWeight = 0;
    for(int i=0;i<edges.size();i++)
    {
        int wt = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u,parent)==find(v,parent))
            continue;
        Union(u,v,parent,rnk);
        totalWeight+=wt;
    }
    cout<<"Total Weight:"<<totalWeight<<endl;
    return 0;
}

