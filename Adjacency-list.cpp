/* n = 5 (vertices), edges = 6
   Edges:
         1 2
         2 4
         1 3
         3 4
         1 4
         5 3
*/
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,edges;
    cin>>n>>edges;
    vector<int>Adj[n+1];
    for(int i=1; i<=edges; i++)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<endl<<"Vertex "<<i<< " : ";
        for(auto x:Adj[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}*/
// Adjacency list of weighted undirected graph:
/*
n = 5 (vertices), edges = 6
Edges with weights:
1 2 3
2 4 5
1 3 2
3 4 4
1 4 1
5 3 6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,edges;
    cin>>n>>edges;
    vector<pair<int,int>>Adj[n+1];
    for(int i=1; i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Adj[u].push_back({v,w});
        Adj[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++)
    {
        cout<<"Vertex "<<i<< " : ";
        for(auto x : Adj[i])
        {
            cout<<"->("<<x.first<<", weight="<< x.second << ")";
        }
        cout<<endl;
    }
    return 0;
}
