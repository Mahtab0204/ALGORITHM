/*
Given the weights and profits of N items, in the form of {profit, weight}
put these items in a knapsack of capacity W to get the maximum total
profit in the knapsack. In Fractional Knapsack, we can break items for
maximizing the total value of the knapsack.
Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
Output: 240
Explanation: By taking items of weight 10 and 20 kg and 2/3
fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) =

3 50
60 100 120
10 20 30   */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>prof(n),weight(n);
    vector<pair<float,int>>A(n);
    for(int i=0; i<n; i++)
    {
        cin>>prof[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int i=0; i<n; i++)
    {
        A[i].first=(float)prof[i]/weight[i];
        A[i].second=weight[i];
    }

    sort(A.begin(),A.end(),greater<pair<float,int>>());

    float profit=0;

    for(int i=0; i<n; i++)
    {
        if(w==0)
        {
            break;
        }
        if(A[i].second<=w)
        {
            profit+=A[i].first*A[i].second;
            w-=A[i].second;
        }
        else
        {
            profit+=w*A[i].first;
            w=0;
        }
    }
    cout<<profit<<endl;
    return 0;
}
