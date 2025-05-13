/* You are given n activities with their start and finish times. Your program
should output the maximum number of activities that can be performed by
a single person, assuming that a person can only work on a single activity
at a time.

Input: start[] = {3, 1, 0, 5, 8, 5}, finish[] = {4, 2, 6, 7, 9, 9};
Output: 4
Explanation: Activity 1, 2, 4 and 5 were selected as they do not overlap.
Input:
6
3 1 0 5 8 5
4 2 6 7 9 9
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>start(n);
    vector<int>finish(n);
    vector<pair<int,int>>A(n);
    for(int i=0; i<n; i++)
    {
        cin>>start[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>finish[i];
    }
    for(int i=0; i<n; i++)
    {
        A[i].first=finish[i];
        A[i].second=start[i];
    }
    sort(A.begin(),A.end());
    int count=1;
    int prev=A[0].first;
    for(int i=1; i<n; i++)
    {
        if(A[i].second>=prev)
        {
            count++;
            prev=A[i].first;
        }
    }
    cout<<count;
    return 0;
}
