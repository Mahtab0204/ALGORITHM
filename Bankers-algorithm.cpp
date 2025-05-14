#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of processes and resources: ";
    cin >> n >> m;

    vector<vector<int>> allocated(n, vector<int>(m));
    vector<vector<int>> maximum(n, vector<int>(m));
    vector<int>available(m);

    cout << "Enter allocated resources matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> allocated[i][j];

    cout << "Enter maximum resources matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> maximum[i][j];

    cout << "Enter available resources:\n";
    for(int i = 0; i < m; i++)
        cin >> available[i];

    vector<vector<int>> need(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocated[i][j];

    vector<bool>finished(n, false);
    vector<int>safeSequence;

    while(true)
    {
        bool progress = false;
        for(int i = 0; i < n; i++)
        {
            if(finished[i])
                continue;

            bool canRun = true;
            for(int j = 0; j < m; j++)
            {
                if(need[i][j] > available[j])
                {
                    canRun = false;
                    break;
                }
            }

            if(canRun)
            {
                for(int j = 0; j < m; j++)
                    available[j] += allocated[i][j];

                finished[i] = true;
                safeSequence.push_back(i);
                progress = true;
            }
        }
        if(!progress) break;
    }

    if(safeSequence.size() == n)
    {
        cout << "Safe\nSafe sequence: ";
        for(int i : safeSequence)
            cout << i << " -> ";
        cout << "end\n";
    }
    else
    {
        cout << "Unsafe\n";
    }

    return 0;
}
