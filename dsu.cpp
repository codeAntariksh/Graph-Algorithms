// Disjoint Set Data Structure
#include<bits/stdc++.h>
using namespace std;

int findParent(int u)
{
    if(parent[u]!=u)
        parent[u] = findParent(parent[u]); // Path Compression
    return parent[u];
}

void Union(int u,int v)
{
    int pu = findParent(u);
    int pv = findParent(v);
    if(rank[pu]==rank[pv])
    {
        rank[pu]++;
        parent[pv] = pu;
    }
    else if(rank[pu]>rank[pv])
    {
        parent[pv] = pu;
    }
    else parent[pu] = pv;
}


vector<int> rank(n,0);
vector<int> parent(n);
for(int i=0;i<n;i++)
    parent[i] = i;
