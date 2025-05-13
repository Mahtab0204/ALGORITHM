/*          7 10
            1 2 6
            1 3 5
            1 4 5
            3 2 -2
            2 5 -1
            3 5 1
            4 3 -2
            4 6 -1
            5 7 3
            6 7 3
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>Edge_list;
vector<int>weight;
int n,e;
void BellmanFord(int root)
{
    vector<int>distance(n+1,INT_MAX);
    distance[root]=0;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<e; j++)
        {
            int u=Edge_list[j].first;
            int v=Edge_list[j].second;
            if(distance[u]==INT_MAX)
                continue;
            if((distance[u]+weight[j])<distance[v])
            {
                distance[v]=distance[u]+weight[j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (distance[i]==INT_MAX)
            cout<<i<<" -> "<<"INF"<<endl;
        else
            cout<<i<<" -> "<<distance[i]<<endl;
    }
}
int main()
{
    cin>>n>>e;
    Edge_list.resize(e);
    weight.resize(e);
    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge_list[i]= {u,v};
        weight[i]=w;
    }
    BellmanFord(1);
}
