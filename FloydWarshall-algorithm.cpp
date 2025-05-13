/*    4 7
      1 2 3
      1 4 7
      2 1 8
      2 3 2
      3 1 5
      3 4 1
      4 1 2
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>A;
int v,e;
void FloydWarshall()
{
    for(int k=1; k<=v; k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(A[i][k]==INT_MAX || A[k][j]==INT_MAX)
                    continue;
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(A[i][j]==INT_MAX)
                cout<<"INF ";
            else
                cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>v>>e;

    A.resize(v+1,vector<int>(v+1,INT_MAX));
    for(int i=1; i<=v; i++)
    {
        A[i][i]=0;
    }
    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        A[u][v]=min(A[u][v],w);
    }
    FloydWarshall();
    return 0;
}
