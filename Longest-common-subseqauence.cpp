#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    //int A[s1.size()+1][s2.size()+1];
    vector<vector<int>>A(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            if(i==0 || j==0)
            {
                A[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                A[i][j]=1+A[i-1][j-1];
            }
            else
            {
                A[i][j]=max(A[i-1][j],A[i][j-1]);
            }
        }
    }
    cout<<A[s1.size()][s2.size()];
}
