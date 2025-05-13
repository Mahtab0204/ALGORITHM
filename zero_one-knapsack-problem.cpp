#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>profits(n),weight(n);
    for(int i=0; i<n; i++)
    {
        cin>>profits[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    vector<vector<int>>A(n+1,vector<int>(w+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0)
            {
                A[i][j]=0;
            }
            else if(j>=weight[i-1])
            {
                A[i][j]=max(A[i-1][j],A[i-1][j-weight[i-1]]+profits[i-1]);
            }
            else
            {
                A[i][j]=A[i-1][j];
            }
        }
    }
    cout<<A[n][w]<<endl;
    return 0;
}
