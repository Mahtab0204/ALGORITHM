#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>>Adj_list;
vector<bool>visited;
int n,e;

void Prims(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,start});
    int mst=0;

    while(!pq.empty())
    {
        auto[w,u]=pq.top();
        pq.pop();

        if(visited[u])
            continue;

        visited[u] = true;
        mst+=w;

        for(auto x : Adj_list[u])
        {
            int v=x.first;
            int w=x.second;
            if(!visited[v])
            {
                pq.push({w,v});
            }
        }
    }

    cout << "Shortest Distance : " << mst;
}

int main()
{
    cin>>n>>e;
    Adj_list.resize(n+1);
    visited.resize(n+1,false);

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin >>u>>v>>w;
        Adj_list[u].push_back({v, w});
        Adj_list[v].push_back({u, w});
    }

    Prims(1);

    return 0;
}
/*   7 9
     1 6 10
     4 3 12
     2 7 14
     2 3 16
     4 7 18
     4 5 22
     5 7 24
     5 6 25
     1 2 28    */
