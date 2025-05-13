/*   n = 10 (nodes), edges = 13
Edges:
1 2
1 4
2 3
4 3
3 9
3 10
2 5
2 7
2 8
5 6
5 7
7 8
5 8     */
#include<bits/stdc++.h>
using namespace std;
vector<int>Adj[100];
vector<bool>visited;
void DFS(int root)
{
    visited[root]=true;
    cout<<root<<" ";
    for(int x: Adj[root])
    {
        if(!visited[x])
        {
            DFS(x);
        }
    }
}
int main()
{
    int n,edges;
    cin>>n>>edges;
    visited.resize(n+1,false);
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
}
