#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>edge_list;
vector<int>parent;
vector<int>Rank;
int n,e;
int Find(int root)
{
    if(parent[root]!=root)
    {
        parent[root]=Find(parent[root]);
    }
    return parent[root];
}
bool Union(int u,int v)
{
    int root_u=Find(u);
    int root_v=Find(v);

    if(root_u==root_v)
        return 0;
    if(Rank[root_u]>Rank[root_v])
        parent[root_v]=root_u;
    else if(Rank[root_v]>Rank[root_u])
        parent[root_u]=root_v;
    else
    {
        parent[root_v]=root_u;
        Rank[root_u]++;
    }
    return 1;
}
void Kruskal()
{
    int mst=0;
    for(auto x : edge_list)
    {
        int u=x.second.first;
        int v=x.second.second;
        int w=x.first;
        if(Union(u,v)==1)
        {
            mst+=w;
        }
    }
    cout<<"Shortest Distance : "<<mst;
}
int main()
{
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge_list.push_back({w,{u,v}});
    }
    sort(edge_list.begin(),edge_list.end());
    parent.resize(n+1);
    Rank.resize(n+1,0);
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
    Kruskal();

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
