#include <bits/stdc++.h>
using namespace std;

vector<int> PID, AT, BT, RT, WT, TT, RPT, PR;
int n;

void waiting_time()
{
    vector<bool> check(n, false);
    vector<bool> responded(n, false);
    int t = 0, completed = 0;

    priority_queue<pair<int, int>> pq;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= t && !check[i])
            {
                pq.push({PR[i], i});
                check[i] = true;
            }
        }

        if (!pq.empty())
        {
            int idx = pq.top().second;
            pq.pop();

            if (!responded[idx])
            {
                RPT[idx] = t - AT[idx];
                responded[idx] = true;
            }

            RT[idx]--;
            t++;

            if (RT[idx] == 0)
            {
                WT[idx] = t - BT[idx] - AT[idx];
                completed++;
            }
            else
            {
                pq.push({PR[idx], idx});
            }
        }
        else
        {
            t++;
        }
    }
}

void turnaround_time()
{
    for (int i = 0; i < n; i++)
        TT[i] = BT[i] + WT[i];
}

void find_avg_time()
{
    waiting_time();
    turnaround_time();

    float total_wt = 0, total_tt = 0, total_resp = 0;

    cout << "\n  PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t Response Time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt += WT[i];
        total_tt += TT[i];
        total_resp += RPT[i];
        cout << "   " << PID[i] << "\t\t" << AT[i] << "\t\t"
             << BT[i] << "\t\t" << WT[i] << "\t\t" << TT[i] << "\t\t\t" << RPT[i] << "\n";
    }

    cout << "\nAverage Waiting time = " << total_wt / n;
    cout << "\nAverage Turnaround time = " << total_tt / n;
    cout << "\nAverage Response time = " << total_resp / n << endl;
}

int main()
{
    cout << "Enter number of processes: ";
    cin >> n;

    PID.resize(n);
    AT.resize(n);
    BT.resize(n);
    RT.resize(n);
    WT.resize(n, 0);
    TT.resize(n);
    RPT.resize(n, -1);
    PR.resize(n);

    cout << "Enter the process IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> PID[i];
    }
    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; i++)
    {
         cin >> AT[i];
    }
    cout << "Enter the burst times: ";
    for (int i = 0; i < n; i++)
    {
        cin >> BT[i];
        RT[i] = BT[i];
    }
    cout << "Enter the priorities : ";
    for (int i = 0; i < n; i++)
    {
        cin >> PR[i];
    }
    find_avg_time();

    return 0;
}
