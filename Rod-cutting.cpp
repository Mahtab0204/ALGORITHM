#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>price(n),A(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            A[i]=max(A[i],price[j-1]+A[i-j]);
        }
    }
    cout<<A[n]<<endl;
    return 0;
}
