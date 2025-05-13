/*      6 8
        1 2 2
        1 3 4
        2 3 1
        2 4 7
        3 5 3
        5 4 2
        5 6 5
        4 6 1

Adj[1] = { (2,2), (3,4) }
Adj[2] = { (1,2), (3,1), (4,7) }
Adj[3] = { (1,4), (2,1), (5,3) }
Adj[4] = { (2,7), (5,2), (6,1) }
Adj[5] = { (3,3), (4,2), (6,5) }
Adj[6] = { (5,5), (4,1) }

*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>Adj[100];
int n;
void Djikstras_Algorithm(int root)
{
    vector<int>A(n+1,INT_MAX);
    A[root]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,root});

    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();

        int distance=p.first;
        int v=p.second;

        if(distance>A[v])
            continue;

        for(auto x: Adj[v])
        {
            int new_distance=A[v]+x.second;

            if(new_distance<A[x.first])
            {
                pq.push({new_distance,x.first});
                A[x.first]=new_distance;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> "<<A[i]<<endl;
    }
}
int main()
{
    int edges;
    cin>>n>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Adj[u].push_back({v,w});
        Adj[v].push_back({u,w});
    }
    Djikstras_Algorithm(1);
    return 0;
}
