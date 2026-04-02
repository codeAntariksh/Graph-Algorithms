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
    set<pair<int,int>> st;
    st.insert({0,target});
    dist[target] = 0;
    while(!st.empty())
    {
        auto it1 = st.begin();
        int d = it1->first;
        int el = it1->second;
        st.erase(st.begin());
        for(auto &it:adj_list[el])
        {
            int vertex = it.first;
            int edgeWeight = it.second;
            if(dist[el]+edgeWeight<dist[vertex])
            {
                if(dist[vertex]!=INT_MAX) st.erase({dist[vertex],vertex});
                dist[vertex] = dist[el] + edgeWeight;
                st.insert({dist[vertex],vertex});
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
